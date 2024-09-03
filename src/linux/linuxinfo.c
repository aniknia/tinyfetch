#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>
#include <linux/sysctl.h>
#include "linuxinfo.h"

char* getname() {
	return getenv("USER");
}

void gethost(char* host) {
	char hostname[1024];
	gethostname(hostname, sizeof(hostname));
	strcpy(host, hostname);
}

void getos(char* distro) {
	FILE* fp;
	char distroName[128];

	if((fp = fopen("/etc/os-release", "r")) == NULL) {
		perror("Error opening /etc/*-release");
	} else {
		int c;
		int i = 0;
		char str[1024];
		while ((c = getc(fp)) != EOF) {
			if (c == '\n') {
				memset(str, 0, sizeof(str));
				i = 0;
			} else {
				
				if (strcmp(str, "PRETTY_NAME=\"") == 0) {
					int j = 0;
					while (c != 34) {
						distroName[j++] = c;
						c = getc(fp);
					}
					break;
				}
				str[i++] = c;
			}
		}
	}
	fclose(fp);

	strcpy(distro, distroName);
}

void getkernel(char* kernel) {
	struct utsname uts;
	if(uname(&uts) < 0) {
		perror("uname() error");
	} else {
		strcpy(kernel, uts.sysname);
		strcat(kernel, " ");
		strcat(kernel, uts.release);
	}
}

void getuptime() {
}

void getpackages() {
}

void getshell() {
}

void getresolution() {
}

void getwm() {
}

void getwmtheme() {
}

void gettheme() {
}

void geticons() {
}

void getterminal() {
}

void getterminalfont() {
}

void getcpu(char* cpu) {
	FILE* fp;
	char cpuName[128];

	if((fp = fopen("/proc/cpuinfo", "r")) == NULL) {
		perror("Error opening /proc/cpuinfo");
	} else {
		int c;
		int i = 0;
		char str[1024];
		while ((c = getc(fp)) != EOF) {
			if (c == '\n') {
				memset(str, 0, sizeof(str));
				i = 0;
			} else {
				if (strcmp(str, "model name\t: ") == 0) {
					int j = 0;
					while (c != 10) {
						cpuName[j++] = c;
						c = getc(fp);
					}
					break;
				}
				str[i++] = c;
			}
		}
	}
	fclose(fp);

	strcpy(cpu, cpuName);
}

void getgpu(char* gpu) {
	FILE* fp;
	char gpuname[128] = {0};

	if ((fp = popen("lspci -mm | grep \"VGA\"", "r")) == NULL) {
		perror("Error calling lspci");
	} else {
		int i, j, c, recording, matched = 0;
		char str[128] = {0};
		while ((c = getc(fp)) != 10) {
			if (c == '"') {
				if (recording) {
					if (matched) {
						if (j > 2) {
							break;
						}
						strcat(gpu, str);
						j++;
					}
					if (strcmp(str, "VGA compatible controller") == 0) {
						matched = 1;
					}
					recording = 0;
				} else {
					recording = 1;
				}
				memset(str, 0, sizeof(str));
				i = 0;
			} else {
				str[i++] = c;
			}
		}
	}
	pclose(fp);

	strcpy(gpu, gpuname);
}

void getmemory() {
}
