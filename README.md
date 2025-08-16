KeyRoles – C++ Role-Based Access Control System

KeyRoles is a robust C++ Role-Based Access Control (RBAC) system designed for organizations with multiple departments and ranks. It ensures secure, structured, and auditable access for all users.

Core Functionality

Secure Login Authentication: Users can only access the system with valid credentials.

Department-Specific Dashboards: Each department has a customized interface tailored to its roles.

Rank-Based Permissions: User actions are controlled based on their rank within the department.

Activity Logging: Logs all user actions, including login, logout, session duration, and performed tasks.

Key Features

Role-Based Access: Each user’s permissions are determined by their department and rank, ensuring proper access control.

Custom Dashboards: Personalized dashboards for each role provide relevant tools and information.

Time-Based Login Restrictions: Users can only log in during working hours (8 AM–4 PM) unless granted admin authorization.

Comprehensive Activity Tracking: Every login, logout, and action is recorded for audit and accountability purposes.

---
# Requirements

- C++17 or later
- GNU Make
- OpenSSL (`libssl`, `libcrypto`)
- MinGW (for Windows users) or GCC/Clang (Linux/macOS)

# Setup & Build

### Clone the repository
```
git clone https://github.com/IrondiUg/keyroles.git
cd keyroles
```
### Build (for linux/macOS and windows respectively)
```
make
```
```
mingw32-make
```
### Run (for linux/macOS and windows respectively)
```
./project
```
```
./project.exe
```
---

## PROJECT STRUCTURE
```
RBAC-System/                   
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
