#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")
#include "windowsinfo.h"

char* getname() {
	char *username = "";
	username = getenv("username");
	return username;
}

void gethost(char* host) {
	char hostname[1024];
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	gethostname(hostname, sizeof(hostname));
	strcpy(host, hostname);
	WSACleanup();
}
