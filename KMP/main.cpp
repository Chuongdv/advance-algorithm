#include <bits/stdc++.h>

using namespace std;

int KMP(string text, string patterm)
{
    int lt = text.length();
    int lp = patterm.length();
    int counter = 0;

    //preprocessing
    vector<int> prefix;
    int k = -1;
    prefix.push_back(-1);
    for(int i = 1; i < lp; i++)
    {
        if(patterm[i] == patterm[k+1])
        {
            k+= 1;
            prefix.push_back(k);
        }
        else
        {
            //giam can
            while(k > -1 && patterm[i] != patterm[k + 1])
            {
                k = prefix.at(k);
            }
            if(patterm[i] == patterm[k+1])
                k+=1;
            prefix.push_back(k);
        }
    }

    // compare
    k = -1;
    for(int i = 0; i < lt; i++)
    {
        if(patterm[k+1] == text[i])
            k++;
        else
        {
            while(k > -1 && text[i] != patterm[k + 1])
            {
                k = prefix.at(k);
            }
            if(text[i] == patterm[k+1])
                k+=1;
        }

        if(k == (lp - 1))
        {
            counter++;
        }
    }
    return counter;
}




int main()
{
    string text, patterm;
    int n;
    cin>> patterm;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> text;
        cout << KMP(text, patterm) << endl;
    }
}
