#include "Database.cpp"
#include "Portfolio.h"
#include "Stock.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void printMainLogin(){ // This function prints the main login screen
    cout << "------------------------------------------------" << endl;
    cout << "|       Welcome to the Stock Mangagement UI    |" << endl;
    cout << "------------------------------------------------" << endl;
    cout << endl << endl;
    cout << "  ----------------------------------- " << endl;
    cout << "  | (1) Login                        |" << endl;
    cout << "  -----------------------------------" << endl;
    cout << "  -----------------------------------" << endl;
    cout << "  | (2) Create an account            |" << endl;
    cout << "  -----------------------------------" << endl;
    cout << "  -----------------------------------" << endl;
    cout << "  | (3) Exit                         |" << endl;
    cout << "  -----------------------------------" << endl;
}

void loginScreen(){ // This function prints the 2nd log in screen
    cout << "                  Welcome Back                  " << endl;
    cout << "------------------------------------------------" << endl;
    cout << endl << endl;
}

void bankingScreen(){ // This function prints the banking screen
    cout << "-----------------------------------------" << endl;
    cout << "|                Banking                |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl << endl;
}

void registerScreen(){ // This function prints the registerScreen
    cout << "               Create an account                " << endl;
    cout << "------------------------------------------------" << endl;
    cout << endl << endl;
}

void exitScreen(){ // This prints the goodbye screen
    cout << "------------------------------------------------" << endl;
    cout << "|   Thank you for using Stock Mangagement UI    |" << endl;
    cout << "------------------------------------------------" << endl;
}

int main(){
    bool running = true; // Declaring that the program is running 
    User* currentUser = nullptr; // This sets currentUser to nullptr because no one should be logged in let
    Database userList; // Creates a database to store users

    while(running){
        printMainLogin(); // Display main menu

        int choice; // This is first seeing if the user wants to log in create an account or exit the program
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cout << "That's not an choice! Please try again." << endl;
            cout << "------------------------------------------------" << endl;
            cin.clear(); // clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the input buffer
            cout << "Enter your choice: ";
        }
        cout << "------------------------------------------------" << endl;


        switch(choice){
            case 1: { // This is the screen to login
                string username;
                string password;
                loginScreen();

                cout << "Enter Username: ";  // Getting user credentials
                cin >> username;
                cout << "Enter Password: ";
                cin >> password;

                User* user = userList.findUser(username); // This searches for the user in the data base

                if(user == nullptr){ // If the user is still set to nullptr that means that the username wasnt found 
                    cout << "Invalid username or password. Please try again." << endl;
                    cout << "------------------------------------------------" << endl;
                    break;
                } else if(user->checkPassword(password) == false){ // when password is false it will get rid of the username information as well so user does not know if they put in the wrong username or password
                    cout << "Invalid username or password. Please try again." << endl;
                    cout << "------------------------------------------------" << endl;
                    user = nullptr;
                    break;
                }
                
                if(user->checkPassword(password) == true){ // This checks the usernames password to see if it matches 
                    currentUser = user; // Once security is granted it will set the currentUser to the User
                    cout << "Logged in as " << currentUser->getUsername() << endl;
                    cout << "------------------------------------------------" << endl;
                    break;
                } else {
                    cout << "Invalid username or password. Please try again." << endl;
                    cout << "------------------------------------------------" << endl;
                    break;
                }

            }
            case 2:{ // This is for creating an account 
                string username;
                string password;
                string confirmPassword;

                registerScreen();

                cout << "Enter a Username: "; // Asking for user credentails
                cin >> username;
                cout << "Enter a Password: ";
                cin >> password;
                cout << "Confirm Your Password: "; // Will ask for user to verify password
                cin >> confirmPassword;

                if (userList.findUser(username) != nullptr) // Checks if username is already in the system
                {
                    cout << "Username taken. Please try again." << endl;
                    cout << "------------------------------------------------" << endl;
                    break;
                }
                
                if (password == confirmPassword) // If passwords match than a user is created
                {
                    userList.addUser(username,password); //added to the database
                    currentUser = userList.findUser(username); // logs in the user 
                    cout << "Account made Successfully!" << endl;
                    cout << "------------------------------------------------" << endl;
                    break;
                } else if(password != confirmPassword){
                    cout << "Confirmation Password does not match Password. Please try again." << endl;
                    cout << "------------------------------------------------" << endl;
                    break;
                } 
            }
            case 3:{ // exits the program
                running = false;
                exitScreen();
                break;
            }
            default:{ // no option was selected 
                cout << "Invalid input. Please try again." << endl;
                cout << "------------------------------------------------" << endl;
                break;
            }
        }

        while(currentUser != nullptr){ // Checks if a user is logged in
            // sets env for user
            Portfolio* currentPortfolio = currentUser->getPortfolio();
            vector<Stock> currentStockList = currentPortfolio->getStockVector();
            cout << "Portfolio for " << currentUser->getUsername() << ":" << endl;

            for (Stock s: currentStockList) // goes into user portfolio and prints out each stock they own
            {
                cout << "-" << s.getSymbol() << " " << "$" << s.getPrice() << " "<< s.getQuantity() << " Shares" << endl;
            }

            cout << "Buying Power: $" << currentPortfolio->getBalance() << endl; // display buying power
            cout << "Portfolio Value: $" << currentPortfolio->calculateValue() << endl << endl; // displays portfolio value
            cout << "1. Buy Stock" << endl;
            cout << "2. Sell Stock" << endl;
            cout << "3. Withdraw" << endl;
            cout << "4. Deposit" << endl;
            cout << "5. Export portfolio" << endl;
            cout << "6. Log out" << endl;
            cout << endl << endl;

            int choice ;
            cout << "Enter your choice: ";

            while (!(cin >> choice)) { // getting user choice and making sure that it isnt a letter or number that won't convert into one 
                cout << "That's not an choice! Please try again." << endl;
                cout << "------------------------------------------------" << endl;
                cin.clear(); // clear the error flag on cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the input buffer
                cout << "Enter your choice: ";
            }
            cout << "------------------------------------------------" << endl;

            switch(choice){
                case 1:{ // This is for a user buying stock 
                    string symbol;
                    double price;
                    int quanitiy = 0;

                    cout << "Enter the stock symbol: "; // User will enter the symbol, price, and quantity
                    cin >> symbol;
                    cout << "Enter the stock price: ";
                    cin >> price;
                    cout << "Enter the quantity: ";
                    cin >> quanitiy;

                    if(currentPortfolio->addStock(symbol, price, quanitiy)==true){ // This will check if the user has enough balance to buy the stock. 
                        cout << "Stock bought successfully!" << endl;
                        cout << "------------------------------------------------" << endl;
                        break;
                    } else{
                        cout << "Not enough buying power." << endl;
                        cout << "------------------------------------------------" << endl;
                        break;
                    } 
                }
                case 2:{ // This is for selling the stock 
                    string symbol;
                    int quantity = 0;

                    cout << "Enter the stock symbol to sell: ";
                    cin >> symbol; 
                    cout << "Enter the quantiity to sell: ";
                    cin >> quantity; 

                    if(currentPortfolio->removeStock(symbol,quantity) == true){ // This sells the stock and then adds the value back into the users portfolio
                        cout << "Sold " << quantity << " shares of " << symbol << " successfully!" << endl;
                        cout << "------------------------------------------------" << endl;
                        break;
                    } else if (currentPortfolio->removeStock(symbol,quantity) == false){ // This will detect if the stock they ask or the amount they asked to sell wasnt valid
                        cout << "No " << symbol << " found or " << quantity << " of " << symbol << " owned." << endl;
                        cout << "------------------------------------------------" << endl;
                        break;
                    } else{
                        break;
                    }

                }
                case 3:{ // This is for a user to take out monkey from thier portfolio
                    double withdrawlAmount;

                    bankingScreen();
                    cout << "Your Buying Power is $" << currentPortfolio->getBalance() << endl;
                    cout << "Enter the amount you would like to withdraw: ";
                    while (!(cin >> withdrawlAmount)) { // getting user choice and making sure that it isnt a letter or number that won't convert into one 
                    cout << "That's not an amount! Please try again." << endl;
                    cout << "------------------------------------------------" << endl;
                    cin.clear(); // clear the error flag on cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the input buffer
                    cout << "Enter your amount: ";
                    }
                    currentPortfolio->withdraw(withdrawlAmount); // This includes logic for if users amount asked to withdraw is too high 
                    cout << "------------------------------------------------" << endl;
                    break;
                }
                case 4:{
                    double depositAmount;

                    bankingScreen();
                    cout << "Your Buying Power is $" << currentPortfolio->getBalance() << endl;
                    cout << "Enter the amount you would like to Deposit: ";

                    while (!(cin >> depositAmount)) { // getting user choice and making sure that it isnt a letter or number that won't convert into one 
                    cout << "That's not an amount! Please try again." << endl;
                    cout << "------------------------------------------------" << endl;
                    cin.clear(); // clear the error flag on cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the input buffer
                    cout << "Enter your amount: ";
                    }

                    currentPortfolio->deposit(depositAmount); // deposits user input into thier account 
                    cout << "------------------------------------------------" << endl;
                    break;
                }
                case 5:{
                    currentPortfolio->outputCSV(); // Outputs users portfolio onto a csv file 
                    break;
                }
                case 6:{
                    // log out of the current account 
                    currentUser = nullptr;
                    currentPortfolio = nullptr;
                    currentStockList.clear();
                    cout << "Logged out successfully!" << endl;
                    break;
                }
                default:{
                    // invalid input
                    cout << "Invalid input. Please try again."<< endl;
                    cout << "------------------------------------------------" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
