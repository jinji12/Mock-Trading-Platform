#include "Portfolio.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
/**
 * @brief Construct a new Portfolio:: Portfolio object
 * 
 */
Portfolio::Portfolio(){ 
    balance = 0.0;
}
/**
 * @brief returns user balance
 * 
 * @return double 
 */
double Portfolio::getBalance(){
    return balance;
}
/**
 * @brief adds amount to user balance
 * 
 * @param amount 
 */
void Portfolio::deposit(double amount){
    balance += amount;
}
/**
 * @brief this takes an amount from user balance
 * 
 * @param amount 
 */
void Portfolio::withdraw(double amount){
    if(amount > balance){
        cout << "Error: insufficient funds" << "\n";
    } else{
        balance -= amount;
    }
}
/**
 * @brief this adds stock to the user portfolio and returns a bool if it was done or not 
 * 
 * @param symbol 
 * @param price 
 * @param quanitiy 
 * @return true 
 * @return false 
 */
bool Portfolio::addStock(std::string symbol, double price, int quanitiy){
    double cost = price * quanitiy;
    
    if (balance >= cost && cost != 0 && quanitiy != 0){
        balance -= cost;
        Stock newStock(symbol,price,quanitiy);
        stocks.push_back(newStock);
        return true;
    } else if (cost < balance){
        return false;
    } else{
        return false;
    }
}
/**
 * @brief this will remove a stock from the portfolio returns true or false if its done
 * 
 * @param sym 
 * @param quan 
 * @return true 
 * @return false 
 */
bool Portfolio::removeStock(std::string sym, int quan){
    std::string temp;
    bool valid = false;
    
    for(int i = 0; i < stocks.size(); i++){
        if (stocks[i].getSymbol() == sym)
        {
            temp = sym;
            valid = true;

            if(stocks[i].getQuantity() < quan){
                return false;
            }
            if((stocks[i].getQuantity() > quan) && (stocks[i].getQuantity() != quan)){
                balance += stocks[i].getPrice() * quan;
                stocks[i].removeQuantity(quan);
                return true;
            }

            balance += stocks[i].getPrice() * stocks[i].getQuantity();
            stocks.erase(stocks.begin()+i);
        }
    }
    return valid;
}
/**
 * @brief This will calculate the value of the users portfolio 
 * 
 * @return double 
 */
double Portfolio::calculateValue(){
    double value = 0.0;
    for(Stock s : stocks){
        value += s.getPrice() * s.getQuantity();
    }
    return value;
}
/**
 * @brief this will return the users stock 
 * 
 * @return std::vector<Stock> 
 */
std::vector<Stock> Portfolio::getStockVector(){
    return stocks;
}
/**
 * @brief this will output a csv file of the users portfolio
 * 
 */
void Portfolio::outputCSV(){
    ofstream out;
    out.open("portfolio.csv");
    out << "Symbol,Price,Quantity,Value" << endl;
    for(Stock s: stocks){
        out<< s.getSymbol() << "," << s.getPrice() << "$," << s.getQuantity() << ","  << s.getPrice()*s.getQuantity() << "$" << endl;
    }
    out << "Buying Power," << balance << ",,Portfolio Value," << calculateValue(); 
}

