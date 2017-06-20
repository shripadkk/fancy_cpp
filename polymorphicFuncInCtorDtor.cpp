//This one is contributed by Suyash
#include <iostream>


class Base {
    public:
        int a;
        Base() { foo(); }
        virtual ~Base(){};
        virtual void foo() { std::cout<< "In Base Class";}
};

class Der : public Base 
{
    void foo () override { std::cout<<"In derived Class"<<std::endl; }
};


int main() {
    Base *ptr = new Der();
    delete ptr;
}
