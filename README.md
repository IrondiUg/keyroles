This project is a C++ Role-Based Access Control (RBAC) system designed for organizations with multiple departments and ranks.
It provides:
-Secure login authentication
-Department-specific dashboards
-Rank-based permissions within departments
-Activity logging (user, role, action)

Features
-Role-Based Access: Each user’s access is defined by their department and rank.
-Custom Dashboards: Unique dashboard views per role and rank.
-Login Restrictions: Only accessible during working hours unless authorized by an admin.
-Activity Logging: Tracks login, logout, actions taken, and session durations.

Departments & Ranks:
IT Department
-Admin
-IT Engineer
-IT Intern

HR Department
-HR Manager
-HR Recruiter
-Clerk

Finance Department
-Director
-Accountant
-Clerk
## PROJECT STRUCTURE
'''RBAC-System/                   
│
├── data/                        
│   └── users.txt                 # Default login credentials for testing
│
├── include/                     
│   ├── user.h
│   ├── database.h
│   ├── dashboards.h
│   └── sha256.h
│
├── src/                         
│   ├── main.cpp
│   ├── database.cpp
│   ├── dashboards.cpp
│   └── sha256.cpp
│
├── Makefile                     # Build instructions
├── README.md                    # Project documentation
└── LICENSE                      
