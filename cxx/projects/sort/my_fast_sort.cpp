#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int partition(vector<int>& vec, int left, int right)
{
    // 选取最后一个元素为pivot
    int pivot = vec[right];

    //还未进行遍历前, i指向最左元素的左边
    int i = left -1;

    // 遍历到right-1, right为pivot所在位置,不参与比较
    for(int j = left; j <= right-1; ++j)
    {
        if(vec[j] <= pivot)  // <还是<=都行,只是决定与pivot相等的数放在pivot的左边还是右边
        {
            i++;
            swap(vec[i], vec[j]);
            // 交换完毕, i永远指向遍历过程中最后一个小于等于pivot的数, 故i+1必指向大于pivot的数
        }
    }

    // 将pivot与第一个大于pivot的数进行交换, i+1指向第一个大于pivot的数
    swap(vec[right], vec[i+1]);

    // 返回pivot所在的位置
    return (i+1);
}

void quickSort(vector<int>& vec, int left, int right)
{
    // 递归结束条件
    if(right <= left)
    {
        return;
    }

    // 以pivot为界,将数据分为两批
    int pivot_idx = partition(vec, left, right);

    // pivot所在的位置已经固定无需参与比较
    quickSort(vec, left, pivot_idx-1);
    quickSort(vec, pivot_idx+1, right);
}

int main()
{
    int arr[] = {8, 2, 4, 3, 6, 5, 7, 1};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));

    quickSort(vec, 0, vec.size()-1);

    for_each(vec.begin(), vec.end(), [&](int ele){cout << ele << " ";});

    return 0;
}