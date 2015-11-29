#include <iostream>

template <typename T>
void func(const T& val)
{
    static int count = 0;
    std::cout <<"Entered val: "<<val<<" value of count is "<<count++<<std::endl;
}

int main()
{
    /* Pretty interesting stuff with static and object instantiation*/
    double val1 = 1.1;
    double val2 = 1.15;
    int val3 =  1;

    /* Keep an eye on the value of count
     * one will notice when the value of
     * count gets incremented
     */
    func(val3);
    func(val2);
    func(val1);
}
