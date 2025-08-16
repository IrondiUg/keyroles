#ifndef DASHBOARDS_H
#define DASHBOARDS_H

#include "user.h"

void login();
void addUser();
void ITadminDashboard(const user &u);
void ITengineerDashboard(const user &u);
void ITinternDashboard(const user &u);
void HRmanagerDashboard(const user &u);
void HRrecruiterDashboard(const user &u);
void HRclerkDashboard(const user &u);
void FinanceAcctDashboard(const user &u);
void FinanceDirDashboard(const user &u);
void FinanceClerkDashboard(const user &u);

#endif