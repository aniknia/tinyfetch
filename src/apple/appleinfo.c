#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/sysctl.h>
#include "appleinfo.h"

char* getname() {
	return getenv("USER");
}

void gethost(char* host) {
	char hostname[1024];
	gethostname(hostname, sizeof(hostname));
	strcpy(host, hostname);

	//Can also use uts.nodename
}

void getos(char* distro) {
	FILE *fp;
	int major, minor, rev, matched = 0;
	char majorVersion[3], minorVersion[3], revVersion[3] = {0};
	char osName[128], versionName[128] = {0};

	if ((fp = fopen("/System/Library/CoreServices/SystemVersion.plist", "r")) == NULL){
		perror("Error opening SystemVersion.plist");
	} else {
		int c;
		int i = 0;
		char str [512];
		while ((c = getc(fp)) != EOF) {
			if (c == '\n') {
				if(strcmp(str, "\t<key>ProductVersion</key>") == 0) {
					matched = 1;
					fscanf(fp, "\t<string>%d.%d.%d</string>", &major, &minor, &rev);
					break;
				}
				memset(str, 0, sizeof(str));
				i = 0;
			} else {
				if (i > sizeof(str) - 1) {
					break;
				}
				str[i++] = c;
			}
		}
	}
	fclose(fp);

	if (matched == 1) {
		strcpy(osName, "macOS");
		switch (major) {
			case 10: {		 
				switch (minor) {
					case 0: strcpy(osName, "Mac OS X"); strcpy(versionName, "Cheetah"); break;
					case 1: strcpy(osName, "Mac OS X"); strcpy(versionName, "Puma"); break;
	            	case 2: strcpy(osName, "Mac OS X"); strcpy(versionName, "Jaguar"); break;
					case 3: strcpy(osName, "Mac OS X"); strcpy(versionName, "Panther"); break;
					case 4: strcpy(osName, "Mac OS X"); strcpy(versionName, "Tiger"); break;
            		case 5: strcpy(osName, "Mac OS X"); strcpy(versionName, "Leopard"); break;
           			case 6: strcpy(osName, "Mac OS X"); strcpy(versionName, "Snow Leopard"); break;
            		case 7: strcpy(osName, "Mac OS X"); strcpy(versionName, "Lion"); break;
            		case 8: strcpy(osName, "OS X"); strcpy(versionName, "Mountain Lion"); break;
            		case 9: strcpy(osName, "OS X"); strcpy(versionName, "Mavericks"); break;
            		case 10: strcpy(osName, "OS X"); strcpy(versionName, "Yosemite"); break;
            		case 11: strcpy(osName, "OS X"); strcpy(versionName, "El Capitan"); break;
            		case 12: strcpy(versionName, "Sierra"); break;
            		case 13: strcpy(versionName, "High Sierra"); break;
            		case 14: strcpy(versionName, "Mojave"); break;
            		case 15: strcpy(versionName, "Catalina"); break;
        		}
			}
			case 11: strcpy(versionName, "Big Sur"); break;
			case 12: strcpy(versionName, "Monterey"); break;
			case 13: strcpy(versionName, "Ventura"); break;
			case 14: strcpy(versionName, "Sonoma"); break;
			case 15: strcpy(versionName, "Sequoia"); break;
			default: strcpy(osName, "Unknown OS version"); strcpy(versionName, "Unknown version name");
		}

		sprintf(majorVersion, "%d", major);
		sprintf(minorVersion, "%d", minor);
		sprintf(revVersion, "%d", rev);

		strcpy(distro, osName);
		strcat(distro, " ");
		strcat(distro, majorVersion);
		strcat(distro, ".");
		strcat(distro, minorVersion);
		strcat(distro, ".");
		strcat(distro, revVersion);
		strcat(distro, " (");
		strcat(distro, versionName);
		strcat(distro, ")");
	} else {
		strcpy(distro, "Uknown distribution");
	}
}

void getkernel(char* kernel) {
	struct utsname uts;
	if (uname(&uts) < 0) {
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
    size_t len;
    char cpu_brand[256] = {0};

    len = sizeof(cpu_brand);
    if (sysctlbyname("machdep.cpu.brand_string", &cpu_brand, &len, NULL, 0) == -1) {
        perror("sysctlbyname() error");
    } else {
		strcpy(cpu, cpu_brand);
	}

	struct utsname uts;
	
	if(uname(&uts) < 0) {
		perror("uname() error");
	} else {
		strcat(cpu , " (");
		strcat(cpu, uts.machine);
		strcat(cpu, ")");
	}

}

void getgpu(char* gpu) {
	FILE *fp;
	char str[128] = {0};
	char line[256];
	int matched = 0;

	if ((fp = popen("system_profiler SPDisplaysDataType | grep 'Chipset Model'", "r")) == NULL) {
		perror("system_profile failed to run");
	} else {
		int c, i = 0;
		while ((c = getc(fp)) != 10) {
			if (strcmp(str, "      Chipset Model: ") == 0) {
				matched = 1;
				memset(str, 0, sizeof(str));
				i = 0;
			}
			if (i > sizeof(str) - 1) {
				break;
			}
			str[i++] = c;
		}
	}
	pclose(fp);
	
	if (matched == 1) {
		strcpy(gpu, str);
	} else {
		strcmp(gpu, "Unkown GPU");
	}
}

void getmemory() {
}
