#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>
#include "appleinfo.h"

char* getname() {
	return getenv("USER");
}

void gethost(char* host) {
	char hostname[1024];
	gethostname(hostname, sizeof(hostname));
	strcpy(host, hostname);
}

void getos(char* distro) {
	struct utsname uts;
	if (uname(&uts) < 0) {
		perror("uname() error");
	} else {
		strcpy(distro, uts.release);
	}
}

void getkernal() {
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

void getcpu() {
}

void getgpu() {
}

void getmemory() {
}
