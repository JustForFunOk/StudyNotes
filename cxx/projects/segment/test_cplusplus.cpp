#include <string>
#include <iostream>

using namespace std;

const char* p = "Hello";
const string str("Hello");
const string str1("Hello1");
const string str2("Hello1");

int main()
{
    cout << &p << endl;
    cout << &str << endl;
    return 0;
}