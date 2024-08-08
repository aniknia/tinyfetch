#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
#define PLATFORM "windows"
#include "windows/windowsinfo.h"
#elif defined(__linux__)
#define PLATFORM "linux"
#include "linux/linuxinfo.h"
#elif defined(__APPLE__)
#define PLATFORM "apple"
#include "apple/appleinfo.h"
#else
#define PLATFORM "none"
#endif

int main()
{
	char *username = getname();
	char hostname[1024];
	gethost(hostname);
	char distrobution[1024];
	getos(distrobution);

	printf("tinyfetch\n");
	printf("%s@%s \n", username, hostname);
	printf("OS: %s \n", distrobution);
	return 0;
}
