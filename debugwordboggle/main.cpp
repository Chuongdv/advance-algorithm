#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

using namespace std;


char result[100][100];
char board[100][100];
char words[100][100];
int candidateX[100];
int candidateY[100];
bool mapp[100][100];
int listUcvK[100][100];
int counter[100];
int nWord;
int n;


bool checkvalid(int x, int y, int k)
{
    if((y) >= 0 && (y) < n)
    {
        if(mapp[x][y])
            return false;
        int update = 0;
        for(int i = 0; i < counter[k-1]; i++)
        {
            if(words[listUcvK[k-1][i]][k] == board[x][y])
            {
                listUcvK[k][update] = listUcvK[k-1][i];
                update += 1;
            }
        }
        if(update > 0)
        {
            counter[k] = update;
        }
        else
        {
            return false;
        }
        return true;
    }
    else
        return false;

}


bool isolution(int k)
{
    for(int i = 0; i < counter[k]; i++)
    {
        if(words[listUcvK[k][i]][k + 1] == '\0')
            return true;
    }
    return false;
}


void printSolution(int k)
{
    for(int i = 0; i <= k; i++)
        cout << board[candidateX[i]][candidateY[i]] << " ";
    cout << endl;
}

void backtrack(int k)
{
    int x, y;
    for(int i = -1; i <= 1; i++)
    {
        x = candidateX[k - 1] + i;
        if(x >= 0 && x < n)
        for(int j = -1; j <=1; j++)
        {
            y = candidateY[k - 1] + j;
           if((i != 0 || j != 0) && checkvalid(x, y, k))
           {
               mapp[x][y] = true;
               candidateX[k] = x;
               candidateY[k] = y;
                if(isolution(k))
                {
                    printSolution(k);
                }
                else
                {
                    backtrack(k+1);
                }
               mapp[x][y] = false;
           }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        cin >> board[i][j];
        for(int i = 0; i < n; i++)
       {
           for(int j = 0; j < n; j++)
        cout << board[i][j] << " ";
        cout << endl;
       }
    cin >> nWord;
    getchar();

    for(int i = 0; i < nWord; i++)
        {
            gets(words[i]);

        }
         for(int i = 0; i < nWord; i++)
        {
            cout << words[i] << endl;
        }

    int tmpc = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
    {
        tmpc = 0;
        candidateX[0] = i;
        candidateY[0] = j;
        for(int ii = 0; ii < n; ii++)
            for(int jj = 0; jj < n; jj++)
                mapp[ii][jj] = false;
        mapp[i][j]=true;


        for(int iter = 0; iter < nWord; iter++)
        {
            if(words[iter][0] == board[i][j])
                {
                    listUcvK[0][tmpc] = iter;
                    tmpc++;
                }

        }

        counter[0] = tmpc;
        backtrack(1);
    }

}
