#include <iostream>
#include <stack>
#include <string>

using namespace std;

std::string reverseInParentheses(std::string inputString) {
std::string result;
std::string temp;
for(int i = 0; i < inputString.size(); i++)
{
    if(inputString[i] == ')')
    {

        for(int j = result.size() - 1; j >= 0; j--)
        {
            if(result.at(j) != '(')
            {
                temp.push_back(result.at(j));
                result.pop_back();
            }
            else
            {
                result.pop_back();
                break;
            }
        }

        for(int j = 0; j < temp.size(); j++)
        {
            result.push_back(temp[j]);
        }
        temp.clear();
    }
    else
    {
        result.push_back(inputString.at(i));
    }
}
return result;
}

int main()
{
    string hihi;
    getline(cin, hihi);
    cout << reverseInParentheses(hihi);
    return 0;
}
