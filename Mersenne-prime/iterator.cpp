#include<iostream>
#include<vector>

int main()
{
    using namespace std;
    vector<int> arr = {2,54848,4,5,6,7,8,9,10,11,15};

    auto beg = arr.begin();
    auto sec = arr.begin() + 1;
    auto end = arr.end();

    cout << "end - beg = " << end - beg << endl;
    cout << "sec - beg = " << sec - beg << endl;
    return 0;
}