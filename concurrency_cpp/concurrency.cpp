#include <iostream>
#include <thread>
#include <vector>

//Use threads so that all the letters of my name 
// are printed one after the other

class printLetter
{
    public:
    printLetter(char a) : my_letter(a) {}

    void operator() (){
        std::cout <<my_letter;
    }

    private:
    char my_letter;

};

int main()
{
    std::vector<std::thread*> threads;
    std::string name("shripad");
    for (auto &c : name) {
        threads.emplace_back(new std::thread(*(new printLetter(c))));
    }

    for (auto &th: threads) {
        th->join();
    }
}

