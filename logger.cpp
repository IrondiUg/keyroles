#include "logger.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

// initialize statics
string Logger::currentUser = "Unknown";
string Logger::currentRole = "Unknown";
vector<LogEntry> Logger::logs;

string Logger::getTimestamp()
{
    time_t now = time(nullptr);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}

void Logger::setUser(const string &username, const string &role)
{
    currentUser = username;
    currentRole = role;
    logAction("Logged in");
}

void Logger::clearUser()
{
    logAction("Logged out");
    currentUser = "Unknown";
    currentRole = "Unknown";
}

void Logger::logAction(const string &action)
{
    logs.push_back({getTimestamp(), currentUser, currentRole, action});
}

void Logger::showLogs()
{
    for (auto &log : logs)
    {
        cout << "[" << log.timestamp << "] "
             << "User: " << log.user
             << " | Role: " << log.role
             << " | Action: " << log.action << endl;
    }
}

void Logger::exportLogs(const string &filename)
{
    ofstream file(filename);
    for (auto &log : logs)
    {
        file << "[" << log.timestamp << "] "
             << "User: " << log.user
             << " | Role: " << log.role
             << " | Action: " << log.action << endl;
    }
    file.close();
}