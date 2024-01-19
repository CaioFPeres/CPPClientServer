#include "Server.h"

#ifdef _WIN32
int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd) {

    std::cout << "Running\n";

    Server sv;
    sv.Listen();

    printf("\n");
    system("pause");
    return 0;

}
#endif

#ifdef linux
int main(int argc, char** argv){

    std::cout << "Running\n";

    Server sv;
    sv.Listen();

    printf("\n");
    system("pause");
    return 0;
}
#endif