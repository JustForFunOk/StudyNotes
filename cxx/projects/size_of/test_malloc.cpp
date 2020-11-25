#include <iostream>

using namespace std;

int main()
{
    int* a = (int*)malloc(10);
    cout << sizeof(a) <<endl;
    cout << sizeof(*a) << endl;
    return 0;
}