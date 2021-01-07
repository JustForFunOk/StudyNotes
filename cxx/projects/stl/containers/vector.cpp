// g++ -o vector vector.cpp -std=c++11
#include <vector>  // vector
#include <iostream>
#include <algorithm> // for_each

using namespace std;

int main()
{
    // Constructor

    // [1] default
    // 空的vector
    // explict vector();
    vector<int> vec1;

    // [2] fill
    // 指定数量的vector

    // explict vector(size_type n);
    // 0 0 0 0 0
    cout << "vec1_1:" << endl;
    vector<int> vec2_1(5);  // 包含5个int的vector, 初始化为0
    for_each(vec2_1.begin(), vec2_1.end(), [](int ele){cout << ele << " ";});
    cout << endl << endl;

    // vector(size_type n, const value_type& val);
    // 1 1 1 1 1
    cout << "vec2_2:" << endl;
    vector<int> vec2_2(5, 1);  // 包含5个int的vector, 值均为1
    for_each(vec2_2.begin(), vec2_2.end(), [](int ele){cout << ele << " ";});
    cout << endl << endl;

    // [3] range
    // 用另一串来构造vector
    // template <class InputIterator>
    // vector(InputIterator first, InputIterator last);

    cout << "vec3_1:" << endl;
    vector<int> vec3_1(vec2_2.begin(), vec2_2.end());
    for_each(vec3_1.begin(), vec3_1.end(), [](int ele){cout << ele << " ";});
    cout << endl << endl;

    cout << "vec3_2:" << endl;
    int arr[] = {1, 1, 1, 1, 1};
    vector<int> vec3_2(arr, arr+sizeof(arr)/sizeof(arr[0]));
    for_each(vec3_2.begin(), vec3_2.end(), [](int ele){cout << ele << " ";});
    cout << endl << endl;

    // [4] copy
    // 拷贝构造
    // vector(const vector& x);
    cout << "vec4:" << endl;
    vector<int> vec4(vec3_1);
    for_each(vec4.begin(), vec4.end(), [](int ele){cout << ele << " ";});
    cout << endl << endl;

    // [5] move c++11
    // 移动构造
    // vector(vector&& x);
    cout << "vec5:" << endl;
    vector<int> vec5(move(vec4));
    for_each(vec5.begin(), vec5.end(), [](int ele){cout << ele << " ";});
    cout << endl << endl;
    cout << "after move vec4:" << endl;
    for_each(vec4.begin(), vec4.end(), [](int ele){cout << ele << " ";});
    cout << endl << endl;

    // [6] initialize list c++11
    // 列表初始化
    // vector(initializer_list<value_type> il);
    // 0 1 2 3 4
    cout << "vec6:" << endl;
    // 以下三种写法等效
    vector<int> vec6_1 = {0, 1, 2, 3, 4};
    vector<int> vec6_2({0, 1, 2, 3, 4});
    vector<int> vec6_3{0, 1, 2, 3, 4};

    for_each(vec6_1.begin(), vec6_1.end(), [](int ele){cout << ele << " ";});
    cout << endl;
    for_each(vec6_2.begin(), vec6_2.end(), [](int ele){cout << ele << " ";});
    cout << endl;
    for_each(vec6_3.begin(), vec6_3.end(), [](int ele){cout << ele << " ";});
    cout << endl;

    // 0 1 2 3 4
    // 5 6 7 8 9
    cout << "vector_2d:" << endl;
    vector<vector<int>> vector_2d = {{0, 1, 2, 3, 4},
                                     {5, 6, 7, 8, 9}};
    for_each(vector_2d.begin(), vector_2d.end(), [](vector<int> vec){
        for_each(vec.begin(), vec.end(), [](int ele){cout << ele << " ";});
        cout << endl;
    });


    return 0;
}