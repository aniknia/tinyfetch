#include <unistd.h>
#include "unixinfo.h"

char* getname() {
	return getenv("USER");
}

char* gethost() {
	char hostname[1024];
	gethostname(hostname, sizeof(hostname));
	return hostname;
}