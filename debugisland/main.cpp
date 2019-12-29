#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<string> island;
int maxisland = 0;
int number = 0;
int n, m;
queue<int> qx;
queue<int> qy;

void detectMaxIsland()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {

            if(island[i][j] == '1')
            {
                number++;
                island[i][j] = '0';

                qx.push(i);
                qy.push(j);
                int ajx;
                int ajy;
                int cou = 1;
                while(!qx.empty())
                {
                    ajx = qx.front();
                    ajy = qy.front();
                    qx.pop();
                    qy.pop();
                    for(int ii = -1; ii <= 1; ii++)
                    {
                        for(int jj = -1; jj <= 1; jj++)
                        {
                            if((ii != -1 && jj == 0) ||
                               (ii != 1 && jj == 0) ||
                               (jj != -1 && ii == 0) ||
                               (jj != 1 && ii == 0)
                               )
                            if((ii + ajx) < n &&
                               (ii + ajx) >= 0 &&
                               (jj + ajy) >= 0 &&
                               (jj + ajy) < m )
                            {
                                if(island[ii + ajx][jj + ajy] == '1')
                                {
                                    qx.push(ii + ajx);
                                    qy.push(jj + ajy);
                                    cou++;
                                    island[ii + ajx][jj + ajy] = '0';
                                }
                            }

                        }
                    }

                }

                 if(cou > maxisland)
                    maxisland = cou;

            }
        }
    }
}


int main()
{
    cin>>n >> m;

    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        island.push_back(temp);
    }


    detectMaxIsland();


    cout << number << endl << maxisland;
    return 0;
}
