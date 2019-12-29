#include <iostream>
#include <stack>
#include <string>

using namespace std;



int check(string a)
{
    stack<char> s;
    char temp;
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] == '{' || a[i] == '[' || a[i] == '(')
            s.push(a[i]);
        else{
            if(s.empty())
            {
                cout << 0 << endl;
                return 0;
            }
            else
            {
                temp = s.top();
                s.pop();
                if(
                   (temp == '{' && a[i] != '}') ||
                   (temp == '[' && a[i] != ']') ||
                   (temp == '(' && a[i] != ')')
                   )
                {cout << 0 << endl;
                return 0;
                }
            }

        }
    }

    if(s.empty())
        cout << 1 << endl;
    return 0;
}


int main()
{
    int n;
    string a[1000];

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >>a[i];
    }

    for(int i = 0; i < n; i++)
    {
       check(a[i]);
    }





return 0;
}
