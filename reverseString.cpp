#include <iostream>

using namespace std;

string reverseString (const string& str) {
    string temp;
    for (auto &c : str) {
        temp = c + temp;
    }
    return temp;
}

int main(void) {
    cout << reverseString("Shripad");
    return 0;
}
