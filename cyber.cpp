#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
struct user
{
    string username;
    string password;
    string rank;
    string department;
};
vector<user> users{
    {"John", "pass123", "ADMIN", "IT"},
    {"Ugo", "ugo123", "ENGINEER", "IT"},
    {"Ada", "ada123", "INTERN", "IT"},
    {"Mary", "secure123", "MANAGER", "HR"},
    {"Amaka", "amaka123", "RECRUITER", "HR"},
    {"Chioma", "chioma123", "CLERK", "HR"},
    {"Alice", "sale001", "DIRECTOR", "FINANCE"},
    {"Joshua", "joshua001", "ACCOUNTANT", "FINANCE"},
    {"Favour", "favour001", "CLERK", "FINANCE"},
};
void login();
void addUser();
void dataBase();
void ITadminDashboard(const user &u);
void ITengineerDashboard(const user &u);
void ITinternDashboard(const user &u);
void HRmanagerDashboard(const user &u);
void HRrecruiterDashboard(const user &u);
void HRclerkDashboard(const user &u);
void FinanceAcctDashboard(const user &u);
void FinanceDirDashboard(const user &u);
void FinanceClerkDashboard(const user &u);
void pass_and_username(const string &department, const string &rank);

int main()
{
    int select;
    string input;
    do
    {
        cout << "1. LOGIN" << endl;
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
        cin >> uname;
        cout << "ENTER PASSWORD:(Case sensitive)_";
        cin >> pwd;
        for (const auto &u : users)
        {
            if (u.username == uname && u.password == pwd)
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
            break;
        case 2:
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
            break;
        case 3:
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

void ITadminDashboard(const user &u)
{
    cout << "\n=== ADMIN DASHBOARD ===\n";
    cout << "Welcome, " << u.username << " (" << u.rank << ")\n";
    cout << "1. View All Users\n";
    cout << "2. Manage System Settings\n";
    cout << "3. Logout\n";
}
void ITengineerDashboard(const user &u)
{
}
void ITinternDashboard(const user &u)
{
}

void HRmanagerDashboard(const user &u)
{
    cout << "\n=== MANAGER DASHBOARD ===\n";
    cout << "Welcome, " << u.username << " (" << u.rank << ")\n";
    cout << "1. View Sales Reports\n";
    cout << "2. Approve Requests\n";
    cout << "3. Logout\n";
}
void HRrecruiterDashboard(const user &u)
{
}
void HRclerkDashboard(const user &u)
{
}

void FinanceDirDashboard(const user &u)
{
    cout << "\n=== DIRECTOR DASHBOARD ===\n";
    cout << "Welcome, " << u.username << " (" << u.rank << ")\n";
    cout << "1. View Tasks\n";
    cout << "2. Submit Report\n";
    cout << "3. Logout\n";
}
void FinanceAcctDashboard(const user &u)
{
}
void FinanceClerkDashboard(const user &u)
{

}

