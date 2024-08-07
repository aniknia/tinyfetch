#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "unixinfo.h"

char* getname() {
	return getenv("USER");
}

char* gethost() {
	char* host = "";
	char hostname[1024];
	gethostname(hostname, sizeof(hostname));
	host = hostname;
	return host;
}

char* getos() {
}

char* getkernal() {
}

char* getuptime() {
}

char* getpackages() {
}

char* getshell() {
}

char* getresolution() {
}

char* getwm() {
}

char* getwmtheme() {
}

char* gettheme() {
}

char* geticons() {
}

char* getterminal() {
}

char* getterminalfont() {
}

char* getcpu() {
}

char* getgpu() {
}

char* getmemory() {
}
