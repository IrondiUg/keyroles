#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>

struct LogEntry
{
    std::string timestamp;
    std::string user;
    std::string role;
    std::string action;
};

class Logger
{
public:
    static void setUser(const std::string &username, const std::string &role);
    static void clearUser();
    static void logAction(const std::string &action);
    static void showLogs();
    static void exportLogs(const std::string &filename);

private:
    static std::string currentUser;
    static std::string currentRole;
    static std::vector<LogEntry> logs;
    static std::string getTimestamp();
};

#endif
