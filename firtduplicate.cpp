#include <iostream>
#include <vector>

using namespace std;
vector<int> index;

int partion(vector<int> &a, int start, int end)
{
    int pivot = a.at(end);
    int i = -1, j = 0;
    while(j < end)
    {
        if(a.at(j) < pivot)
        {
            i++;
            swap(a.at(i), a.at(j));
            swap(index.at(i), index.at(j));
        }
        j++;
    }

    i++;
    swap(a.at(i), a.at(end));
    swap(index.at(i), index.at(end));
    return i;
}


void quicksort(vector<int> &a, int start, int end)
{
    int pivot;
    if(start < end)
    {
        pivot = partion(a, start, end);
        if(pivot > start)
        {
            quicksort(a, start, pivot - 1);
        }
        if(pivot < end)
        {
            quicksort(a, pivot + 1, end);
        }
    }
}

int firstDuplicate(std::vector<int> &a) {
    for(int i = 0; i < a.size(); i++)
    {
        index.push_back(i);
    }
    quicksort(a, 0, a.size() - 1);
    int result = a.size();






    for(int i = 0; i < a.size() - 1; i++)
    {
        if(a.at(i) == a.at(i+1))
        {
            if(index.at(i+1) < result)
            {
                result = i+1;
            }
        }
    }
    if(result != a.size())
    {
        return a.at(result);
    }
    else
        return -1;
}

int main()
{
    vector<int> a;
    a.push_back(8);
     a.push_back(4);
      a.push_back(6);
       a.push_back(2);
        a.push_back(6);
         a.push_back(4);
          a.push_back(7);
           a.push_back(9);
            a.push_back(5);
             a.push_back(8);
    firstDuplicate(a);
}
