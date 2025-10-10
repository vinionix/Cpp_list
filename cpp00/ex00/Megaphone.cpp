#include <iostream>

int main(int argc, char *argv[])
{
    std::string args;
    
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; argv[i]; i++)
    {
        args = argv[i];
        for(int i = 0; args[i]; i++)
            args[i] = toupper(args[i]);
        std::cout << args;
    }
}
