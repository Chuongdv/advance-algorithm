#include <iostream>
#include <vector>

using namespace std;
vector<int> index;

void print(vector<int> &a)
{
    for(int i = 0; i < a.size(); i++)
    {

        cout << a.at(i) << " ";

    }
    cout << endl;
}
void print1()
{
    for(int i = 0; i < index.size(); i++)
    {

        cout << index.at(i) << " ";

    }
    cout << endl;
}

int partion(vector<int> &a, int start, int end)
{
    int pivot = a.at(end);
    int i = start - 1, j = start;
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
    cout << i  << ": " << endl;
    print(a);
    print1();
    return i;
}


void quicksort(vector<int> &a, int start, int end)
{
    int pivot;
     cout << "start " << start << "  "<< end << endl;
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

    int firt;
    int last;
    int dup = 0;

    for(int i = 0; i < a.size() - 1; i++)
    {

        if(a.at(i) == a.at(i+1))
        {
            if(dup == 0)
            {
                if(index.at(i) > index.at(i+1))
                {
                    last = index.at(i);
                    firt = index.at(i+1);
                }
                else
                {
                    last = index.at(i+1);
                    firt = index.at(i);
                }

            }
            else
            {
                if(index.at(i+1) < firt)
                {
                    last = firt;
                    firt = index.at(i+1);
                }
                else if(index.at(i+1) > firt && index.at(i + 1) < last)
                {
                    last = index.at(i+1);
                }
            }
            result = (result > last)?last:result;
            cout << "re: " << result << endl;
            dup = 1;
        }
        else
            dup = 0;
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
    vector<int> a = {1, 2, 1, 2, 3, 3};
    cout << "complete: ";
   cout <<  firstDuplicate(a);


}

