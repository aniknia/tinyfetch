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
	struct utsname uts;
	if (uname(&uts) < 0) {
		perror("uname() error");
	} else {
		strcpy(distro, uts.sysname);
		strcat(distro, " ");
		strcat(distro, uts.release);
		strcat(distro, " ");
		//strcat(distro, uts.machine);
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
    char cpu_brand[256];

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
}

void getmemory() {
}
