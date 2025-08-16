#include "database.h"
#include "dashboards.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int select;
    string input;
    do
    {
        cout << "\n1. LOGIN" << endl;
        cout << "2. SIGN UP" << endl;
        cout << "3. EXIT" << endl;
        getline(cin >> ws, input);
        if (input.empty() || all_of(input.begin(), input.end(), ::isspace))
        {
            cout << "Input cannot be empty or blank. Please enter a number.\n";
            continue;
        }
        try
        {
            select = stoi(input);
        }
        catch (...)
        {
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        switch (select)
        {
        case 1:
            login();
            break;
        case 2:
            addUser();
            break;
        case 3:
            cout << "EXITING" << endl;
            return 0;
        default:
            cout << "INVALID INPUT" << endl;
        }

    } while (select != 3);
    return 0;
}
