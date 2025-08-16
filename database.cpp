#include "database.h"
#include "dashboards.h"
#include "sha256.h"
#include <limits>
#include <algorithm>
#include <iostream>
using namespace std;

vector<user> users{
    {"John", "9b8769a4a742959a2d0298c36fb70623f2dfacda8436237df08d8dfd5b37374c", "ADMIN", "IT"},
    {"Ugo", "e31967baa9b0d85f78e8c5e7e4b462e4d288f32717fa29f40812454b3302d8a4", "ENGINEER", "IT"},
    {"Ada", "003256b33c9147bf54d8a27969ed9d23afdfd1788ee23ca8e5c7f728737dd81c", "INTERN", "IT"},
    {"Mary", "b5692500175fad6bb2b306aa20ff58423c79b130ef310fb3caa924e0f28bc61d", "MANAGER", "HR"},
    {"Amaka", "23451295638d10360ab15da4ccbffb5cbd5f5875e8402ffced8bc343344581c5", "RECRUITER", "HR"},
    {"Chioma", "2fd69b6b1427d290a8c41d9a4cc224cdf37a1d831ffeefaa7421ea7129ef662f", "CLERK", "HR"},
    {"Alice", "a78d06f1caed28609f707393e4b1dac1ba2caa8177d8683fe195294f8e17f34b", "DIRECTOR", "FINANCE"},
    {"Joshua", "37e5c685fa7c5720ac9faca399a3a24e993954a8be2c40771128c0ab376833e5", "ACCOUNTANT", "FINANCE"},
    {"Favour", "d6351f23cd88fe7d6a6d803e07b45f66e63c8113b0725ac03c0f6e081096f4a3", "CLERK", "FINANCE"},
};

void dataBase()
{
    cout << "USER DATABASE" << endl;
    for (const auto &u : users)
    {
        cout << "Username: " << u.username
             << "| Role: " << u.rank
             << "| Dept: " << u.department << endl;
    }
}

void login()
{
    string uname, pwd;
    bool found = false;
    do
    {
        cout << "ENTER USERNAME:(Case sensitive)_";
        getline(cin >> ws, uname);
        cout << "ENTER PASSWORD:(Case sensitive)_";
        getline(cin >> ws, pwd);
        for (const auto &u : users)
        {
            if (u.username == uname && u.password == sha256(pwd))
            {
                cout << "\nLOGIN SUCCESSFUL, WELCOME [" << u.username << "]" << endl;
                if (u.rank == "ADMIN" && u.department == "IT")
                    ITadminDashboard(u);
                else if (u.rank == "ENGINEER" && u.department == "IT")
                    ITengineerDashboard(u);
                else if (u.rank == "INTERN" && u.department == "IT")
                    ITinternDashboard(u);
                else if (u.rank == "MANAGER" && u.department == "HR")
                    HRmanagerDashboard(u);
                else if (u.rank == "RECRUITER" && u.department == "HR")
                    HRrecruiterDashboard(u);
                else if (u.rank == "CLERK" && u.department == "HR")
                    HRclerkDashboard(u);
                else if (u.rank == "DIRECTOR" && u.department == "FINANCE")
                    FinanceDirDashboard(u);
                else if (u.rank == "ACCOUNTANT" && u.department == "FINANCE")
                    FinanceAcctDashboard(u);
                else if (u.rank == "CLERK" && u.department == "FINANCE")
                    FinanceClerkDashboard(u);
                else
                    cout << "\nNo dashboard assigned for this role.\n";
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "\nINVALID USERNAME OR PASSWORD" << endl;
        }
    } while (!found);
}
void addUser()
{
    int deptSelect;
    string input_addUser;
    do
    {
        cout << "SELECT YOUR DEPARTMENT" << endl;
        cout << "1. IT" << endl;
        cout << "2. HR" << endl;
        cout << "3. FINANCE" << endl;
        cout << "4. GO BACK" << endl;

        cin >> input_addUser;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (input_addUser.empty() || all_of(input_addUser.begin(), input_addUser.end(), ::isspace))
        {
            cout << "Input cannot be empty or blank. Please enter a number.\n";
            continue;
        }
        try
        {
            deptSelect = stoi(input_addUser);
        }
        catch (...)
        {
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (deptSelect < 1 || deptSelect > 4)
        {
            cout << "INVALID INPUT. PLEASE SELECT A VALID OPTION." << endl;
            continue;
        }

        switch (deptSelect)
        {
        case 1:
        {
            cout << "PLEASE ENTER RANK UNDER IT DEPARTMENT" << endl;
            cout << "1. ADMIN" << endl;
            cout << "2. ENGINEER" << endl;
            cout << "3. INTERN" << endl;
            string itSelect;
            int itInput;
            cin >> itSelect;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (itSelect.empty() || all_of(itSelect.begin(), itSelect.end(), ::isspace))
            {
                cout << "Input cannot be empty or blank. Please enter a number.\n";
                continue;
            }
            try
            {
                itInput = stoi(itSelect);
            }
            catch (...)
            {
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            if (itInput < 1 || itInput > 3)
            {
                cout << "INVALID INPUT. PLEASE SELECT A VALID OPTION." << endl;
                continue;
            }
            switch (itInput)
            {
            case 1:
                pass_and_username("IT", "ADMIN");
                break;
            case 2:
                pass_and_username("IT", "ENGINEER");
                break;
            case 3:
                pass_and_username("IT", "INTERN");
                break;
            default:
                cout << "INVALID INPUT" << endl;
            }
        }
        break;
        case 2:
        {
            cout << "PLEASE ENTER RANK UNDER HR DEPARTMENT" << endl;
            cout << "1. MANAGER" << endl;
            cout << "2. RECRUITER" << endl;
            cout << "3. CLERK" << endl;
            string hrSelect;
            int hrInput;
            cin >> hrSelect;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (hrSelect.empty() || all_of(hrSelect.begin(), hrSelect.end(), ::isspace))
            {
                cout << "Input cannot be empty or blank. Please enter a number.\n";
                continue;
            }
            try
            {
                hrInput = stoi(hrSelect);
            }
            catch (...)
            {
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            if (hrInput < 1 || hrInput > 3)
            {
                cout << "INVALID INPUT. PLEASE SELECT A VALID OPTION." << endl;
                continue;
            }
            switch (hrInput)
            {
            case 1:
                pass_and_username("HR", "MANAGER");
                break;
            case 2:
                pass_and_username("HR", "RECRUITER");
                break;
            case 3:
                pass_and_username("HR", "CLERK");
                break;
            default:
                cout << "INVALID INPUT" << endl;
            }
        }
        break;
        case 3:
        {
            cout << "PLEASE ENTER RANK UNDER FINANCE DEPARTMENT" << endl;
            cout << "1. DIRECTOR" << endl;
            cout << "2. ACCOUNTANT" << endl;
            cout << "3. CLERK" << endl;
            string finSelect;
            int finInput;
            cin >> finSelect;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (finSelect.empty() || all_of(finSelect.begin(), finSelect.end(), ::isspace))
            {
                cout << "Input cannot be empty or blank. Please enter a number.\n";
                continue;
            }
            try
            {
                finInput = stoi(finSelect);
            }
            catch (...)
            {
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            if (finInput < 1 || finInput > 3)
            {
                cout << "INVALID INPUT. PLEASE SELECT A VALID OPTION." << endl;
                continue;
            }
            switch (finInput)
            {
            case 1:
                pass_and_username("FINANCE", "DIRECTOR");
                break;
            case 2:
                pass_and_username("FINANCE", "ACCOUNTANT");
                break;
            case 3:
                pass_and_username("FINANCE", "CLERK");
                break;
            default:
                cout << "INVALID INPUT" << endl;
            }
        }
        break;
        case 4:
            return; // Go back to the previous menu
        default:
            cout << "INVALID INPUT" << endl;
        }
    } while (deptSelect != 4);
}

void pass_and_username(const string &department, const string &rank)
{
    user newUser;
    newUser.department = department;
    newUser.rank = rank;
    while (true)
    {
        cout << "ENTER NEW USERNAME:_" << endl;
        getline(cin >> ws, newUser.username);
        if (newUser.username.empty() || all_of(newUser.username.begin(), newUser.username.end(), ::isspace))
        {
            cout << "USERNAME CANNOT BE EMPTY. PLEASE TRY AGAIN." << endl;
            continue;
        }
        bool exists = false;
        for (const auto &existingUser : users)
        {
            if (existingUser.username == newUser.username)
            {
                exists = true;
                cout << "USERNAME ALREADY EXISTS. PLEASE CHOOSE A DIFFERENT ONE." << endl;
                break;
            }
        }
        if (!exists)
            break;
    }
    while (true)
    {
        cout << "ENTER NEW PASSWORD:_" << endl;
        getline(cin >> ws, newUser.password);
        newUser.password = sha256(newUser.password);
        if (newUser.password.empty() || all_of(newUser.password.begin(), newUser.password.end(), ::isspace))
        {
            cout << "PASSWORD CANNOT BE EMPTY. PLEASE TRY AGAIN." << endl;
            continue;
        }
        break;
    }
    cout << "\n--- USER DETAILS ---" << endl;
    cout << "USERNAME: " << newUser.username << endl;
    cout << "DEPARTMENT: " << newUser.department << endl;
    cout << "ROLE/RANK: " << newUser.rank << endl;

    users.push_back(newUser);
    cout << "SUCCESSFULLY ADDED " << newUser.username << " PLEASE ALWAYS REMEMBER YOUR PASSWORD" << endl;
}
