#include <iostream>
using namespace std;

int global_1;
int global_2;

int global_init_1 = 1;
int global_init_2 = 2;




int main()
{
    static int static_1;
    static int static_2;

    int local_1;
    int local_2;

    cout << "global_1:" << &global_1 << endl;
    cout << "global_2:" << &global_2 << endl;
    cout << "static_1:" << &static_1 << endl;
    cout << "static_2:" << &static_2 << endl;
    cout << "global_init_1:" << &global_init_1 << endl;
    cout << "global_init_2:" << &global_init_2 << endl;
    cout << "local_1:" << &local_1 << endl;
    cout << "local_2:" << &local_2 << endl;


    return 0;
}


// class FUck
// {

//     public:
//     FUck()
//     {}
// };

// FUck fck;
// class Fuck2
// {
// Fuck2()
// {
//     fck;
// }
// }

// Fuck2 fck2;