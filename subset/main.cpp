#include <iostream>

using namespace std;
int a[100];
int n;
int result[100];
int loop[100];
int cou = 0;
int f = 0;
int sum;


void preprocess()
{
    int pivot = -1;
    for(int i = 0; i < n; i++)
        loop[i] = -1;

    for(int i = 0; i < n - 1; i++)
    {
        if(a[i] == a[i+1])
        {
            if(pivot = -1)
            {
                pivot = i;
                loop[i+1] = pivot;
            }
            else
            {
                loop[i] = pivot;
                loop[i+1] = pivot;
            }
        }
        else
        {
            pivot = -1;
        }
    }
}

// check loop
int check(int i, int cou)
{
    for(int j = 0; j < cou; j++)
    {
        if(i == result[j])
            return 1;
    }
    return 0;
}

void printResult()
{
    for(int i = 0; i < cou ; i++)
    {
        cout << a[result[i]] << " ";
    }
    cout << endl;
}

void backtrack(int k)
{
    for(int i = k; i < n; i++)
    {
        if((f + a[i]) <= sum)
        {
            if ((loop[i] == -1)||
                (loop[i] != -1 && check(loop[i], cou))
                )
            {
                f+= a[i];
                result[cou] = i;
                cou ++;
                if(f == sum)
                {
                    printResult();
                }
                else
                {
                    backtrack(i+1);
                }
                f-= a[i];
                cou--;
            }
        }
    }
}



int main()
{
    cin >> n >> sum;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    preprocess();
    backtrack(0);
    return 0;
}
