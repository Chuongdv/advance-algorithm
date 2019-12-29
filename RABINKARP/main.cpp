#include <bits/stdc++.h>

using namespace std;

long const prime = 101;

long const base = 26;



int countMaching(string text, string patterm)
{
    int counter = 0;
    int lt = text.length();
    int lp = patterm.length();

    //preprocessor
    vector<long> ht;
    long hp = 0;
    // calculate hash of patterm
    int b = 1;
    ht.push_back(0);
    for(int i = 0; i < lp; i++)
    {
        hp = ((hp*base + patterm[i])) % prime;
        ht.at(0) = ((ht.at(0) * base) + text.at(i)) % prime;
    }

    for(int i = 0; i < lp - 1; i++)
        b = (b*base) % prime;


    for(int i = 1; i <= lt - lp; i++)
    {
       long tmp = (ht.at(i - 1) - b*text[i - 1]) * base + text.at(i + lp - 1);
       tmp %= prime;
       if(tmp < 0)
        tmp += prime;
       ht.push_back(tmp);
    }

    for(int i = 0; i <= lt - lp; i++)
    {
        if(ht.at(i) == hp)
        {
            int j = 0;
            for(; j < lp; j++)
            {
                if(text[i + j] != patterm[j])
                    break;
            }
            if(j == lp)
                counter++;
        }
    }

    return counter;
}


int main()
{
    string text, patterm;
    int n;
    cin >> patterm;
    cin>> n;
    for(int i = 0; i < n; i++)
    {
        cin>> text;
        cout << countMaching(text, patterm) << endl;
    }
}
