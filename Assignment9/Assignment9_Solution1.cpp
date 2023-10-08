#include <iostream>
using namespace std;

int factorial(int num)
{
    if (num < 0)
        throw 1;
    if (num == 0)
        return 1;

    return (int)num * (int)factorial(num - 1);
}

int main()
{
    int flag;
    while (true)
    {
        cout << "Enter 0 to exit or anything else to calculate factorial :  ";
        cin >> flag;

        if (flag == 0)
            break;

        cout << "---------------" << endl;
        cout << "Enter the number : ";
        cin >> flag;
        try
        {
            cout << "The factorial is : " << factorial(flag) << endl;
            cout << "----------------" << endl;
        }
        catch (int e)
        {
            cout << "DONT ENTER A NEGATIVE NUMBER " << '\n';
        }
    }

    return 0;
}