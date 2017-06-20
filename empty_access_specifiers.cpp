#include <iostream>


void speak() {
    std::cout <<"Outside all of it"<<std::endl;
}

class base {
    public:
        virtual void speak(void) {
            std::cout <<"Is Base class"<<std::endl;
        }

        ~base() {
        }
};


class derived : base {
    public:
        void speak() {
            std::cout <<"Is Derived class";
        }

        void tell() {
            base::speak();
            ::speak();
        }
};

int main() {

    derived obj;
    obj.tell();
}
