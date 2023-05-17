#include "User.h"
#include <unordered_map>

class Database {
private:
    std::unordered_map<std::string, User> users;
public:
    void addUser(std::string username, std::string password) {
        User newUser(username, password);
        users.insert(std::make_pair(username, newUser));
    }
    User* findUser(std::string username) {
        auto iter = users.find(username);
        if (iter == users.end()) {
            return nullptr;
        } else {
            return &iter->second;
        }
    }
};