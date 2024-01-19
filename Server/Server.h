#include <iostream>
#include <thread>

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
using std::cout;
using std::thread;

class Server
{

private:
	#ifdef _WIN32
	WSADATA wsa;
	#endif

	sockaddr_in saddr;
	thread* th;
	int server_socket;

public:
	Server();
	void Listen();
	static void ReadSocket(int client_socket);
};

