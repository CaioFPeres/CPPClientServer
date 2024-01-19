#include "Client.h"

// please pass client ID as arg
#ifdef _WIN32
int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd) {

    //wstring converter
    std::wstring string_to_convert;
    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;

    std::string clientID = converter.to_bytes( lpCmdLine );

    if(clientID.size() == 0){
        std::cout << "Please provide client ID";
        return 0;
    }

    std::cout << "Running\n";
    Client cl;

    while(true){
        Sleep(1000);
        cl.Send("Client" + clientID, false);
    }

    return 0;
}
#endif

#ifdef linux
int main(int argc, char** argv){

    if(argc <= 1){
        std::cout << "Please provide client ID\n";
        return 0;
    }

    std::cout << "Running\n";
    Client cl;

    while(true){
        sleep(1000);
        cl.Send("Client" + string(argv[1]), false);
    }

    return 0;
}
#endif
