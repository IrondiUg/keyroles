#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void login();
void addUser();
void dataBase();
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
int main()
{
    int select;
    do
    {
        cout << "1. LOGIN" << endl;
        cout << "2. SIGN UP" << endl;
        cout << "3. EXIT" << endl;
        cin >> select;
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
        cout << "Username" << u.username
             << "| Role: " << u.rank
             << "| Dept: " << u.department << endl;
    }
}
void login()
{
    string uname, pwd;
    cout << "ENTER USERNAME:(Case sensitive)_";
    cin >> uname;
    cout << "ENTER PASSWORD:(Case sensitive)_";
    cin >> pwd;
    bool found = false;
    for (const auto &u : users)
    {
        if (u.username == uname && u.password == pwd)
        {
            cout << "\nLOGIN SUCCESSFUL, WELCOME [" << u.username << "]" << endl;
            if (u.rank == "ADMIN" && u.department == "IT")
            {
                ITadminDashboard(u);
            }
            else if (u.rank == "ENGINEER" && u.department == "IT")
            {
                ITengineeerDashboard(u);
            }
            else if (u.rank == "INTERN" && u.department == "IT")
            {
                ITinternDashboard(u);
            }

            else if (u.rank == "MANAGER" && u.department == "HR")
            {
                HRmanagerDashboard(u);
            }
            else if (u.rank == "RECRUITER" && u.department == "HR")
            {
                HRrecruiterDashboard(u);
            }
            else if (u.rank == "CLERK" && u.department == "HR")
            {
                HRclerkDashboard(u);
            }

            else if (u.rank == "DIRECTOR" && u.department == "FINANCE")
            {
                FinanceDirDashboard(u);
            }
            else if (u.rank == "ACCOUNTANT" && u.department == "FINANCE")
            {
                FinanceAcctDashboard(u);
            }
            else if (u.rank == "CLERK" && u.department == "FINANCE")
            {
                FinanceClerkDashboard(u);
            }

            else
            {
                cout << "\nNo dashboard assigned for this role.\n";
            }
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "\nINVALID USERNAME OR PASWORD" << endl;
        login();
    }
}
void addUser()
{
    user newUser;
    cout << "ENTER NEW USERNAME:_" << endl;
    cin >> newUser.username;
    cout << "ENTER NEW PASSWORD:_" << endl;
    cin >> newUser.password;
    cout << "ENTER ROLE:_" << endl;
    cin >> newUser.rank;
    transform(newUser.rank.begin(), newUser.rank.end(), newUser.rank.begin(), ::toupper);
    cout << "ENTER DEPARTMENT:_" << endl;
    cin >> newUser.department;
    transform(newUser.department.begin(), newUser.department.end(), newUser.department.begin(), ::toupper);
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
void ITengineeerDashboard(const user &u)
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
    cout << "\n=== EMPLOYEE DASHBOARD ===\n";
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
