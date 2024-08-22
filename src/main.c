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
	
	char distribution[1024];
	getos(distribution);
	
	char kernel[1024];
	getkernel(kernel);

	char cpu[1024];
	getcpu(cpu);

	printf("tinyfetch\n");
	printf("%s@%s \n", username, hostname);
	printf("OS: %s \n", distribution);
	printf("Kernel: %s \n", kernel);
	printf("CPU: %s \n", cpu);

	return 0;
}
