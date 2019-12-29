#include <bits/stdc++.h>

using namespace std;

int maxximum(int a, int b)
{
    return (a > b)?a:b;
}


int houseRobber(std::vector<int> a) {
    std::vector<int> memo(a.size());
    int max = 0;

    for(int i = 0; i < a.size(); i++)
    {
        cout << i << endl;
        memo.at(i) = a.at(i);
        if(i > 2)
        {
            memo.at(i) = memo.at(i - 2) + a.at(i);
        }
        max = maxximum(max, memo.at(i));
    }

    return max;

}


int main()
{
    vector
    vector<int> a;
    int n = 10;
    for(int i = 0; i < n; i++)
        a.push_back(i);
    cout <<  houseRobber(a);
    return 0;
}
