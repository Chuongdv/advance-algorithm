#include <bits/stdc++.h>

using namespace std;

int last(string patterm, int lengthP, int c)
{
    int i = lengthP;
    while(i >= 0)
    {
        if(c == patterm[i])
            break;
        i--;
    }
    if(i == -1)
        return 0;
    else
        return i;
}

int countMatchingString(string text, string patterm)
{
    int counter = 0;
    int n = text.length();
    int m = patterm.length();

    int i = 0;
    while(i <= (n - m))
    {
        int j = m - 1;
        for(; j >= 0; j--)
        {
            if(text.at(i+j) != patterm.at(j))
                break;
        }

        if(j == -1)
        {
            counter ++;
            i++;
        }
        else
        {
            i+= max(1, j - last(patterm, m - 1, text.at(j + i)));
        }
    }

    return counter;

}


int main()
{
    string text;
    string patterm;
    int n;
    cin>> patterm;
    cin>> n;
    for(int i = 0; i < n; i++)
    {
        cin >> text;
        cout << countMatchingString(text, patterm) << endl;
    }
}
