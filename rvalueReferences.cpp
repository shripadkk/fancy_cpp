#include <iostream>

//I wish to understand and demo the capability of rvalue reference constructors

//Command to run: g++ -std=c++0x -o out rvalueReferences.cpp 

using namespace std;

class SomeClass {
    public:
        SomeClass(string &myName) :mName(myName){}
        SomeClass(SomeClass &) = delete;

        SomeClass(SomeClass &&otherClass) {
            mName = std::move(otherClass.mName);
            cout<<"R value Reference construct is being used"<<endl;
        }

        string mName;

        SomeClass& operator=(SomeClass &&otherClass) {
            mName = std::move(otherClass.mName);
            otherClass.mName="";
            cout<<"R value Reference operators is being used"<<endl;
            return *this;
        }

        SomeClass& operator=(SomeClass &otherClass) = delete;
};



int main()
{
    //object allocation with a rvalue reference construct
    string className("Test1");
    SomeClass testObj(className);

    cout<<"Testing for R val reference construct"<<endl;
    SomeClass testWithRvalConstruct(std::move(testObj));

    //move is being used
    cout<<"Testing with R val reference operator"<<endl;
    testObj = std::move(testWithRvalConstruct);
}
