#include <string>

using namespace std;

void testConstCast(string& _str)
{

}



int main()
{
    string str("Hello");
    const string& str_ref = str;
//  testConstCast(str_ref);  // 错
    testConstCast(const_cast<string&>(str_ref));

    return 0;
}