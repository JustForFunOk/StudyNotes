#include <string>
#include <iostream>
using namespace std;

void testConstCast(string& _str)
{
    _str[0] = 'h';
}

const string str("Hello");

int main()
{
    const string& str_ref = str;
//  testConstCast(str_ref);  // 错
    testConstCast(const_cast<string&>(str_ref));
    cout << str << endl;

    // const char* const_str_ptr = "Hello";
    // char* str_ptr = const_cast<char*>(const_str_ptr);
    // str_ptr[0] = 'h';


    return 0;
}