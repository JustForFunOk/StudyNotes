#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(3);

    sort(vec.begin(), vec.end()); // 1 2 3 4

    sort(vec.begin(), vec.end(), [&](int i, int j) -> bool {return i > j;});

    for_each(vec.begin(), vec.end(), [&](int ele){cout << ele << " ";});


    return 0;
}