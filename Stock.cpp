#include<iostream>
#include "Stock.h"

/**
 * @brief Construct a new Stock:: Stock object
 * 
 * @param sym 
 * @param p 
 * @param q 
 */
Stock::Stock(std::string sym, double p, int q){
    symbol = sym;
    price = p;
    quantity = q;
}
/**
 * @brief get symbol for stock
 * 
 * @return std::string 
 */
std::string Stock::getSymbol(){
    return symbol;
}
/**
 * @brief get price of stock
 * 
 * @return double 
 */
double Stock::getPrice(){
    return price;
}
/**
 * @brief get quantity
 * 
 * @return int 
 */
int Stock::getQuantity(){
    return quantity;
}
/**
 * @brief remove stock quantity
 * 
 * @param quan 
 */
void Stock::removeQuantity(int quan){
    quantity -= quan;
}





