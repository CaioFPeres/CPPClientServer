#include "Server.h"

Server::Server() {

    server_socket = 0;
    saddr = { 0 };

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

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    bind(server_socket, (sockaddr*)&saddr, sizeof(saddr));
    listen(server_socket, 5);
}


void Server::Listen() {

    string res;
    char buff;

    while (true) {
        th = new thread(ReadSocket, accept(server_socket, NULL, NULL));
    }

    #ifdef _WIN32
    closesocket(server_socket);
    #endif
    #ifdef linux
    close(server_socket)
    #endif
}

void Server::ReadSocket(int client_socket){

    string res;
    char buff;

    while (recv(client_socket, &buff, sizeof(char), 0) > 0) {
        res += buff;

        if (buff == '\0') {
            cout << res << "\n";
            res.clear();
        }
    }

    #ifdef _WIN32
    closesocket(client_socket);
    #endif
    #ifdef linux
    close(client_socket)
    #endif
}