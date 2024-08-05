#include <stdio.h>

#if defined(_WIN32)
        #define PLATFORM "windows"
#elif defined(_WIN64)
        #define PLATFORM "windows"
#elif defined(__linux__)
        #define PLATFORM "linux"
#elif defined(__APPLE__)
        #define PLATFORM "apple"
#else
        #define PLATFORM "none"
#endif

int main(){
	printf("tinyfetch\n");
	printf("platform: %s \n", PLATFORM);
	return 0;
}
