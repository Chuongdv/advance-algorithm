#include <iostream>

using namespace std;



int main()
{

enum hihi : int {one = 1, two = 2, three = 3};
    hihi a = two;
    switch (a)
    {
    case one:
        cout << "one" << endl;
        break;
    case two:
        cout << "two" << endl;
    }
    return 0;
}

