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

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int main()
{
	char *username = getname();
	
	char hostname[1024] = "host";
	gethost(hostname);
	
	char distribution[1024] = "distro";
	getos(distribution);
	
	char kernel[1024] = "kernel";
	getkernel(kernel);

	char cpu[1024] = "cpu";
	getcpu(cpu);

	char gpu[1024] = "gpu";
	getgpu(gpu);

	printf(RED "User > " RESET "%s@%s \n", username, hostname);
	printf(GRN "OS > " RESET "%s \n", distribution);
	printf(BLU "Kernel > " RESET "%s \n", kernel);
	printf(CYN "CPU > " RESET "%s \n", cpu);
	printf(YEL "GPU > " RESET "%s \n", gpu);

	return 0;
}
