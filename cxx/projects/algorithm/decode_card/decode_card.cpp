#include <iostream>
#include <vector>

using namespace std;

vector<int> decodeCard(vector<int>& _result)
{
    vector<int> tmp;
    tmp.push_back(_result[_result.size()-1]);
    for(int i = _result.size()-2; i > -1; --i)
    {
        tmp.push_back(tmp[0]);
        tmp.erase(tmp.begin());

        tmp.push_back(_result[i]);
    }
    return tmp;
}

int main()
{
    int card[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    vector<int> card_result(card, card+sizeof(card)/sizeof(int));
    for(const auto& ele : card_result)
    {
        cout << ele << " ";
    }
    cout  << endl;
    vector<int> raw = decodeCard(card_result);
    for(const auto& ele : raw)
    {
        cout << ele << " ";
    }
    cout  << endl;
    return 0;
}