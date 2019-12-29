#include <bits/stdc++.h>

using namespace std;


char text[2000000];
char patterm[1000000];

int countMatching(char t[], char p[])
{
    int counter = 0;
    for(int i = 0; i <= (strlen(t) - strlen(p)); i++)
    {
        int j = 0;
        for(j = strlen(p) - 1; j >= 0; j--)
        {
            if(t[i+j] != p[j])
                break;
        }
        if(j == -1)
        counter ++;
    }
    return counter;
}



int main()
{
    int n = 0;
    cin>> patterm;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin >> text;
        cout << countMatching(text, patterm) << endl;
    }

}
