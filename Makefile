windows: windowsServer windowsClient

linux: linuxServer linuxClient

windowsServer:
	g++ Server/main.cpp Server/Server.cpp -o Server -municode -l ws2_32

windowsClient:
	g++ Client/main.cpp Client/Client.cpp -o Client -municode -l ws2_32

linuxServer:
	g++ Server/main.cpp Server/Server.cpp -o LinuxServer

linuxClient:
	g++ Client/main.cpp Client/Client.cpp -o LinuxClient