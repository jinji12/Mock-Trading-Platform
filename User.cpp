#include <iostream>
#include <string>
#include "User.h"
#include "Portfolio.h"
using namespace std;
/**
 * @brief Construct a new User:: User object
 * 
 * @param uname 
 * @param pwd 
 */
User::User(std::string uname, std::string pwd){
    username = uname;
    password = pwd;
}
/**
 * @brief this will return the users username
 * 
 * @return std::string 
 */
std::string User::getUsername(){
    return username;
}
/**
 * @brief this will check if the users password is the same as the input
 * 
 * @param pwd 
 * @return true 
 * @return false 
 */
bool User::checkPassword(std::string pwd){
    return password == pwd;
}
/**
 * @brief This will returns the users portfolio
 * 
 * @return Portfolio* 
 */
Portfolio* User::getPortfolio(){
    return &portfolio;
}



