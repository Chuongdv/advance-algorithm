/*#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    unsigned long long int a, b;
    unsigned long long base, modul;
    cin >> a >> b;
    base = a/1000000000 + b/1000000000;
    modul = a%1000000000 + b%1000000000;
    if(modul > 1000000000)
    {
        base += 1;
        modul -= 1000000000;
    }
    if((base) > 0)
    {
        cout << base;
        printf("%09ld", modul);
    }
    else
        cout << (a + b);
}
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    unsigned long long int a, b;
    unsigned long long baseA, baseB, modulA, modulB;
    cin >> a >> b;
    baseA = a/1000000000;
    baseB = b/1000000000;
    modulA = a%1000000000;
    modulB = b%1000000000;

    if((baseA + baseB) > 0)
    {
        cout << ((baseA + baseB) + (modulA + modulB)/ 1000000000);
        printf("%09ld", ((modulA + modulB)% 1000000000);
    }
    else
        cout << a + b;
}
