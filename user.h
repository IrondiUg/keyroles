#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
using namespace std;

struct user
{
    string username;
    string password;
    string rank;
    string department;
};

extern vector<user> users;

#endif
