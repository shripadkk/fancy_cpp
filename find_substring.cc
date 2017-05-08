#include <iostream>


bool isPresent(std::string &str, std::string &find) {

    if(str.length() == 0 || str.length() < find.length())
        return false; 

    for(int j = 0;j < str.length() - find.length();j++) {
        int k = 0;
        bool found = true;
        for (char &c : find) {
            std::cout<<" c: "<<c<<" "<<str[j + k]<<std::endl;
            if(c != str[j + k++]) {
                found = false;
                break;
            }
        }
        if(found)
            return true;
    }

    return false;
}

bool isPresent(const char*  arg1, const char*  arg2) {
    std::string str(arg1);
    std::string find(arg2);
    return isPresent(str,find);
}

int main()
{
    std::cout<<"IsPresent: "<<isPresent("shrikjasdkasj","shri")<<std::endl;
}
