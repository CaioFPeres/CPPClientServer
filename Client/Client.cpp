#include "Client.h"

Client::Client() {

    client_socket = 0;
    connection_status = 0;
    saddr = {0};

    // Windows only: initializing WSA
    #ifdef _WIN32
    if (WSAStartup(MAKEWORD(2, 0), &wsa) != 0) {
        wprintf(L"Erro: %ld\n", WSAGetLastError());
        WSACleanup();
        return;
    }
    #endif
    //////////////////////

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(2000);
    #ifdef _WIN32
    InetPton(AF_INET, L"127.0.0.1", &saddr.sin_addr.s_addr);
    #endif
    #ifdef linux
    inet_pton(AF_INET, "127.0.0.1", &saddr.sin_addr.s_addr);
    #endif

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    Connect();
}

void Client::Connect() {
    connection_status = connect(client_socket, (struct sockaddr*)&saddr, sizeof(saddr));

    //checks connection
    #ifdef _WIN32
    if (connection_status == SOCKET_ERROR) {
        wprintf(L"Error: %ld\n", WSAGetLastError());
        connection_status = closesocket(client_socket);
        WSACleanup();
        return;
    }
    #endif

    #ifdef linux
    if(connection_status == -1){
        std::cout << "Error: " + std::to_string(connection_status) << '\n';
    }
    #endif
}

void Client::Send(string msg, bool closeSocket) {
    send(client_socket, msg.c_str(), msg.length() + 1, 0);
    if(closeSocket){
        #ifdef _WIN32
        closesocket(client_socket);
        #endif
        #ifdef linux
        close(client_socket)
        #endif
    }
}