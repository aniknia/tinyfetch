#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
	#define PLATFORM "windows"
#elif defined(__linux__)
	#define PLATFORM "linux"
	#include <unistd.h>
#elif defined(__APPLE__)
	#define PLATFORM "apple"
#else
	#define PLATFORM "none"
#endif

int main()
{
	char *username = "";
	char hostname[1024];
	
	gethostname(hostname, sizeof(hostname));

	if (strcmp(PLATFORM, "windows") == 0)
	{
		username = getenv("username");
	}
	else
	{
		username = getenv("USER");
	}

	printf("tinyfetch\n");
	printf("%s@%s \n", username, hostname);
	printf("platform: %s \n", PLATFORM);
	return 0;
}
