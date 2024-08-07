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
