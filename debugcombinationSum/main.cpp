#include <iostream>
#include <string>
#include <vector>

using namespace std;

string result;
vector<int> a;
vector<int> temp;
/*
void print()
{
    cout << "temp : " ;
    for(auto i = temp.begin(); i != temp.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}
*/

void backtrack(int sum, int k)
{
    for(int i = k; i < a.size(); i++)
    {
        if(a.at(i) == sum)
        {
            temp.push_back(a.at(i));
            result.push_back('(');
            for(int j = 0; j < temp.size(); j++)
            {
                result.push_back('0' + temp.at(j));
                result.push_back(' ');
            }
            result.pop_back();
            result.push_back(')');
            temp.pop_back();
        }
        else if(a.at(i) < sum)
        {
        temp.push_back(a.at(i));
            sum -= a.at(i);
            backtrack(sum, i);
            sum += a.at(i);
            temp.pop_back();
        }

    }
}




std::string combinationSum(std::vector<int> &b, int sum) {
    int loop = a.size();
    for(int i = 0;i < loop; i++)
    {
        for(int j = i + 1; j < a.size(); j++)
        {
            if(a.at(i) > a.at(j) )
            {
                swap(a.at(i), a.at(j));
                        cout << "loop: " << loop << ": ";
        for(int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
        cout << endl;
            }
            else if(a.at(i) == a.at(j))
            {
                a.at(j) = 1000000 + a.size() - loop;
                loop -= 1;
        cout << "loop: " << loop << ": ";
        for(int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
        cout << endl;
            }
        }
//        cout << "loop: " << loop << ": ";
//        for(int i = 0; i < a.size(); i++)
//        cout << a.at(i) << " ";
//        cout << endl;
    }
    a.resize(loop);

    for(int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout << endl;

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
