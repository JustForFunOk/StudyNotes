#include <vector>  // vector
#include <algorithm>  // for_each
#include <iostream>  // cout

using namespace std;

int partition(vector<int>& vec, int left, int right)
{
    int pivot = vec[left];  // choose left element as pivot
    bool right_handle = true;  // start from right

    while(left < right)
    {
        if(right_handle)
        {
            if(vec[right] > pivot)
            {
                right--;
            }
            else
            {
                vec[left] = vec[right];
                right_handle = false;
                left++;
            }
        }
        else
        {
            if(vec[left] < pivot)
            {
                left++;
            }
            else
            {
                vec[right] = vec[left];
                right_handle = true;
                right--;
            }
        }
    }

    vec[left] = pivot;

    return left;
}

void quick_sort(vector<int>& vec, int left, int right)
{
    if(left >= right)
    {
        return;
    }

    // partition
    int pivot_idx = partition(vec, left, right);

    quick_sort(vec, left, pivot_idx-1);
    quick_sort(vec, pivot_idx+1, right);
}

int main()
{
    vector<int> vec = {4, 6, 7, 2, 8, 9, 2, 9, 14, 54};

    quick_sort(vec, 0, vec.size()-1);

    for_each(vec.begin(), vec.end(), [&vec](int ele){cout << ele << " ";});

    return 0;
}