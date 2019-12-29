#include <iostream>
#include <string>
#include <vector>

using namespace std;

string result;
vector<int> a;
vector<int> temp;

void backtrack(int sum, int k)
{
    for(int i = k; i < a.size(); i++)
    {
        if(a[i] == sum)
        {
            temp.push_back(a.at(i));
            result.push_back('(');
            for(int j = 0; j < temp.size(); j++)
            {
                result.push_back('0' + temp[j]);
            }
            result.push_back(')');
            temp.clear();
        }
        else if(a[i] < sum)
        {
        //    temp.push_back(a[i]);
        temp.push_back(a.at(i));
            sum -= a.at(i);
            backtrack(sum, i);
            sum += a.at(i);
            temp.pop_back();
        }

    }
}




std::string combinationSum(std::vector<int> &b, int sum) {
    backtrack(sum, 0);
    return result;
}


int main()
{
    int sum;
    int n;
    cin >> n >> sum;
    int tmp;
    for(int i = 0; i < n; i++)
    {
         cin >> tmp;
         a.push_back(tmp);

    }

    combinationSum(a, sum);
    cout << result;
    return 0;
}
