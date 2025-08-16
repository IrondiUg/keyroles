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
### Build
``` Linux/macOS
make
```
``` Windows(using MinGW)
mingw32-make
```
### Run
```Linux/macOS
./project
```
```Windows
./peoject.exe
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
