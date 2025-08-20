#include "dashboards.h"
#include "logger.h"
#include <iostream>
using namespace std;

void ITadminDashboard(const user &u)
{
    cout << "\n=== ADMIN DASHBOARD ===\n";
    cout << "Welcome, " << u.username << " (" << u.rank << ")\n";
    cout << "1. View All Users\n";
    cout << "2. Manage System Settings\n";
    cout << "3. Logout\n\n";
    Logger::showLogs(); // this is just to print logs, it shouldn't be here, but just for testing
}

void ITengineerDashboard(const user &u) {}
void ITinternDashboard(const user &u) {}

void HRmanagerDashboard(const user &u)
{
    cout << "\n=== MANAGER DASHBOARD ===\n";
    cout << "Welcome, " << u.username << " (" << u.rank << ")\n";
    cout << "1. View Sales Reports\n";
    cout << "2. Approve Requests\n";
    cout << "3. Logout\n";
}
void HRrecruiterDashboard(const user &u) {}
void HRclerkDashboard(const user &u) {}

void FinanceDirDashboard(const user &u)
{
    cout << "\n=== DIRECTOR DASHBOARD ===\n";
    cout << "Welcome, " << u.username << " (" << u.rank << ")\n";
    cout << "1. View Tasks\n";
    cout << "2. Submit Report\n";
    cout << "3. Logout\n";
}
void FinanceAcctDashboard(const user &u) {}
void FinanceClerkDashboard(const user &u) {}
