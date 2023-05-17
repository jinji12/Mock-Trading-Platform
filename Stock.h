#include<iostream>
#ifndef STOCK_H
#define STOCK_H

class Stock{
    public:
        Stock(std::string sym, double p, int q);
        /**
         * @brief Get the Symbol object
         * 
         * @return std::string 
         */
        std::string getSymbol();
        /**
         * @brief Get the Price object
         * 
         * @return double 
         */
        double getPrice();
        /**
         * @brief Get the Quantity object
         * 
         * @return int 
         */
        int getQuantity();
        /**
         * @brief removes stock quanitity
         * 
         */
        void removeQuantity(int quan);
    private:
        std::string symbol;
        double price;
        int quantity;
};

#endif
