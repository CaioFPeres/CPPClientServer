#include "Server.h"

Server::Server() {

    client_socket = 0;
    server_socket = 0;
    saddr = { 0 };

    //initializing WSA windows
    if (WSAStartup(MAKEWORD(2, 0), &wsa) != 0) {
        wprintf(L"Erro: %ld\n", WSAGetLastError());
        WSACleanup();
        return;
    }
    //////////////////////


    saddr.sin_family = AF_INET;
    InetPton(AF_INET, L"127.0.0.1", &saddr.sin_addr.s_addr);
    saddr.sin_port = htons(2000);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    bind(server_socket, (sockaddr*)&saddr, sizeof(saddr));
    listen(server_socket, 5);
}


void Server::Listen() {


    while (true) {
        client_socket = accept(server_socket, NULL, NULL);

        string res;
        char buff;

        while (recv(client_socket, &buff, sizeof(char), 0) > 0) {
            res += buff;
        }

        cout << res << "\n\n";
        res.clear();
        closesocket(client_socket);
    
    }

    closesocket(server_socket);


    
}