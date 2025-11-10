
abg — 21:11
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Replace.hpp>


int main()
{
    std::ifstream file("../../cub3d.excalidraw");
    std::string line;
    std::vector < std::string > save;
    size_t pos = 0;
    while(std::getline(file, line))
    {
        if (line.find("text") != std::string::npos && line.find("textAlign") == std::string::npos &&
            line.find("type") == std::string::npos)
            save.push_back(line);
    }
    for (size_t i = 0; i < save.size(); i++)
    {
        save[i].erase(0, 14);
        save[i].erase(save[i].end() - 2, save[i].end());
        save[i].erase(save[i].begin());
    }
    for (int i = 0; i < save.size(); i++)
    {
        pos = save[i].find("\n");
        if (pos != std::string::npos)
            save[i].replace(pos, 2, "\n");
    }

    for (int i = 0; i < save.size(); i++)
        std::cout << save[i] << std::endl;
}