#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")
#include "windowsinfo.h"

char* getname() {
	return getenv("username");
}

char* gethost() {
	char hostname[1024];
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	gethostname(hostname, sizeof(hostname));
	WSACleanup();
	return hostname;
}