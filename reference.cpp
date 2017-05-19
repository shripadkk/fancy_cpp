#include <iostream>


void modifyString(std::string& name)
{
    name = "Shripad K";
    {
        std::string& str = name;
        str = "Shripad K K";
    }
}

int main()
{
    std::string name = "Shripad";
    modifyString(name);
    std::cout <<name<<std::endl;
}
