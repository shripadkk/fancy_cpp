#include <iostream>

//as Mr Scott Meyers says user operator or no like a Pro

using namespace std;
template  <typename T>
class Rational
{
    private:
        T real;
        T imaginary;
    public:
        Rational(T x, T y)
        {
            real = x;
            imaginary = y;
        }

        Rational& operator+ (const Rational &rad)
        {
            real += rad.real;
            imaginary += rad.imaginary;
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Rational &R)
        {
            os <<"Real: "<<R.real<<" Imaginary:"<<R.imaginary<<std::endl;
            return os;
        }
};

int main()
{
    Rational<int> r1(10,20), r2(30,40), r3(0,0);
    r3 = r1 + r2;
    cout <<"Operator"<<r3<<endl;
}
