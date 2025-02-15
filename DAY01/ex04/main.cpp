

#include <iostream>
#include <string>
#include <fstream>


void    replace_string(std::string& line, std::string& s1, std::string& s2) {
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int ac, char **av)
{

    std::string filename;
    std::string s1, s2;
    if (ac != 4)
    {
        std::cerr << "Usage : " << av[0] << " <filename> <S1> <S2>" << std::endl;
        return 1;
    }
    filename = av[1];
    s1 = av[2];
    s2 = av[3];

    if (s1.empty())
    {
        std::cerr << "String to replace <s1> must not be empty" << std::endl;
        return 1;
    }
    std::ifstream InFile(filename.c_str());
    if (!InFile.is_open())
    {
        std::cerr << "Can't open file : " << filename << std::endl;
        return 1;
    }
    std::ofstream OuFile((filename + ".replace").c_str());
    if (!OuFile.is_open())
    {
        std::cerr << "Can't open file : " << filename + ".replace" << std::endl;
        InFile.close();
        return 1;
    }
    std::string line ;
    while (std::getline(InFile, line)) {
        replace_string(line, s1, s2);
        OuFile << line << std::endl ;
    }
    InFile.close();
    OuFile.close();
    return 0;
}