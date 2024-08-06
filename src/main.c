#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
#define PLATFORM "windows"
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")
#elif defined(__linux__)
#define PLATFORM "linux"
#include <unistd.h>
#elif defined(__APPLE__)
#define PLATFORM "apple"
#include <unistd.h>
#else
#define PLATFORM "none"
#endif

int main()
{
	char *username = "";
	char hostname[1024];

	if (strcmp(PLATFORM, "windows") == 0)
	{
		WSADATA wsaData;
		WSAStartup(MAKEWORD(2, 0), &wsaData);
		username = getenv("username");
		gethostname(hostname, sizeof(hostname));
		WSACleanup();
	}
	else
	{
		username = getenv("USER");
		gethostname(hostname, sizeof(hostname));
	}

	printf("tinyfetch\n");
	printf("%s@%s \n", username, hostname);
	printf("platform: %s \n", PLATFORM);
	return 0;
}
