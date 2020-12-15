#include <vector>
#include <iostream>
using namespace std;

vector<int> sortArray(vector<int> _input)
{
    // choose a pivot
    //choose the middle element as pivot
    int pivot = _input[_input.size() / 2];
    int* left = &_input[0];  // first element
    int* right = &_input[_input.size()-1];  // last element
    bool left_handle = true;

    while(left != right)
    {
        if(left_handle)
        {
            if(*left < pivot)
            {
                left++;
            }
            else
            {
                int tmp = *left;
                *left = *right;
                *right = tmp;
                left_handle = false;
            }
        }
        else
        {
            if(*right > pivot)
            {
                right--;
            }
            else
            {
                int tmp = *right;
                *right = *left;
                *left = tmp;
                left_handle = true;
            }
        }



    }
    // sort
}

int main()
{
    int arr[] = {5, 1, 7, 9, 4, 5};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(arr[0]));
    for(const auto& ele : vec)
    {
        cout << ele << " ";
    }
    vector<int> sorted_vec;
    sorted_vec = sortArray(vec);
    return 0;
}