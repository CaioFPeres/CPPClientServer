#include <iostream>
#include <locale>
#include <codecvt>

#ifdef _WIN32
#include <WinSock2.h>
#include <ws2tcpip.h>
#endif

#ifdef linux
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#endif

using std::string;

class Client
{

private:
	#ifdef _WIN32
	WSADATA wsa;
	#endif
	
	sockaddr_in saddr;
	int client_socket;
	int connection_status;
	void Connect();

public:
	Client();
	void Send(string msg, bool close);
};

