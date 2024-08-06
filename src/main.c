#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
#define PLATFORM "windows"
#include "windows/windowsinfo.h"
#else
#include "unix/unixinfo.h"
#if defined(__linux__)
#define PLATFORM "linux"
#elif defined(__APPLE__)
#define PLATFORM "apple"
#else
#define PLATFORM "none"
#endif
#endif

int main()
{
	char *username = "";
	username = getname();
	char *hostname = "";
	hostname = gethost();

	printf("tinyfetch\n");
	printf("%s@%s \n", username, hostname);
	printf("platform: %s \n", PLATFORM);
	return 0;
}
