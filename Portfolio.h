#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "Stock.h"
#ifndef PORTFOLIO_H
#define PORTFOLIO_H


class Portfolio {
    public:
        /**
         * @brief Construct a new Portfolio object
         * 
         */
        Portfolio();
        /**
         * @brief Get the Balance object
         * 
         * @return double 
         */
        double getBalance();
        /**
         * @brief 
         * 
         * @param amount 
         */
        void deposit(double amount);
        /**
         * @brief 
         * 
         * @param amount 
         */
        void withdraw(double amount);
        /**
         * @brief 
         * 
         * @param symbol 
         * @param price 
         * @param quantity 
         */
        bool addStock(std::string symbol, double price, int quantity);
        /**
         * @brief 
         * 
         * @param bool
         */
        bool removeStock(std::string sym, int quan);
        /**
         * @brief 
         * 
         * @return double 
         */
        double calculateValue();
        /**
         * @brief Get the Buying Power object
         * 
         * @return double 
         */
        double getbuyingPower();
        /**
         * @brief Get the Stock Vector object
         * 
         * @return std::vector<Stock> 
         */
        std::vector<Stock> getStockVector();
        /**
         * @brief outputs csv file
         * 
         */
        void outputCSV();
    private:
        std::vector<Stock> stocks;
        double balance;
};


#endif