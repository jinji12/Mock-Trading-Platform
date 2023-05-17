#include <iostream>
#include <string>
#include "Portfolio.h"
#ifndef USER_H
#define USER_H
class User
{
private:
    std::string username;
    std::string password;
    Portfolio portfolio;
public:
    User(std::string uname, std::string pwd);
    /**
     * @brief Get the Username object
     * 
     * @return std::string 
     */
    std::string getUsername();
    /**
     * @brief 
     * 
     * @param pwd 
     * @return true 
     * @return false 
     */
    bool checkPassword(std::string pwd);
    /**
     * @brief Get the Portfolio object
     * 
     * @return Portfolio* 
     */
    Portfolio* getPortfolio();
};

#endif