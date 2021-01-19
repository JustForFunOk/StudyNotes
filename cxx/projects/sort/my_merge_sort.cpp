#include <vector>  // vector
#include <algorithm>  // for_each
#include <iostream>  // cout

using namespace std;

vector<int> tmp;  // 需要额外的空间来临时储存排序过程中顺序

void merge_sort(vector<int>& vec, int left, int right)
{
    if(left >= right)
    {
        return;
    }

    // 归
    int mid = left + (right - left) / 2;
    merge_sort(vec, left, mid);
    merge_sort(vec, mid+1, right);

    // 并
    // 合并两个有序数组(双指针)
    int i = left;  // 指针1
    int j = mid+1; // 指针2
    int cnt = 0;

    while(i<=mid && j<=right)
    {
        if(vec[i] < vec[j])
        {
            tmp[cnt++] = vec[i++];
        }
        else
        {
            tmp[cnt++] = vec[j++];
        }
    }

    while(i <= mid)
    {
        tmp[cnt++] = vec[i++];
    }

    while(j <= right)
    {
        tmp[cnt++] =  vec[j++];
    }

    for(int i = 0; i < right-left+1; ++i)
    {
        vec[i+left] = tmp[i];
    }

    return;
}

int main()
{
    vector<int> vec = {4, 6, 7, 2, 8, 9, 2, 9, 14, 54};

    tmp.resize(vec.size(), 0); // 初始化为与待排数组同样的尺寸

    merge_sort(vec, 0, vec.size()-1);

    for_each(vec.begin(), vec.end(), [&vec](int ele){cout << ele << " ";});

    return 0;
}