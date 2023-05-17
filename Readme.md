Title: Mock Stock Trading Platform

Project Description: I intend to create a program that generates a user interface for a 
stock management system similar to a very rudimentary version of Robinhood. Users will
be able to connect to the software using a username and password, building their own 
portfolio to which their accounts will be linked. When logged in, users can add stocks
to their portfolio using the stock symbol, price, and quantity, deposit money into 
their portfolio, withdraw money back into their imaginary bank account, see available
buying power, and see portfolio value. They can also remove stocks from their portfolio,
log out, and get an output of a CSV file of thier entire portfolio.

List Data Structure: I choose to use an unorderedmap because this allowed me to easily search for
usernames and passwords in the project.

Tests:

Test 1: showcasing logging in incorretly (userinput) // (what it should do)
1 (return)// should go to log in and ask for prompt
bob (return)// enter bob
123 (return) // enter 123
// should show Invalid username or password.Please try again
2 (return)// should bring to create account
bob (return) // should be inputting the username
123 (return) // should be entering password
125 (return) // purposely enters wrong password
// should say Confirmation Password does not match Password. Please try again. 
3 (return)
// displays thank you for using stock management using using UI 
// main.cpp returns 0;

Test 2: showcasing multiuser functionality (userinput) // (what it should do)
2 (return) // brings create an account screen
bob (return) // enter bob
123 (return) // enter 123
123 (return) // enter 123
// should say account made successfully!
// should show porfolio for bob and a bunch of options with the buying power at 0 and porfolio value at 0
4 (return)// should bring it to banking screen 
100 (return) // enter 100
//should have bobs buying power at $100 now 
6(return) // should say logged out successfully! should log out back to main screen
1(return) // should go to log in screen
bob(return) // enter bob
124(return) // enter 124
// should say invalid password or username and return to main screen
2(return) // should go to the create an account screen
bob(return) // enter bob
123(return) // enter 123
123(return) // enter 123
// should say Username taken. Please try again. 
2(return) // should go to the create an account screen
notBob(return) // enter notBob
123(return) // enter 123
123(return) // enter 123
// should say account made successfully and show portfolio for notBob with buying power $0. 
6(return) // should say logged out successfully
1(return) // should go to log in screen
bob(return) // enter bob
123(return) // enter 123
// should say logged in as bob and show porfolio for bob with the $100 in the portfolio. 
6 (return) // should say logged out successfully!
3 (return) // should exit the program display thanks for using screen and main.cpp should return 0. 

Test 3: (showing full scope of banking features) (userinput) // (what it should do)
2(return) // should go to create an account screen
compscita (return) // enter compscita
hi(return) // enter hi
hi(return) // enter hi
// should say account made successfully and show portfolio for compscita and show options and balance and value at $0
3(return) // should go to banking withdraw screen and shows buying power
100(return) // should say error insufficient funds and go back to a screen with the buying power of still $0
4(return) // should go to banking deposit screen should show buying power at 0$
100(return) // should add 100 should bring back to portfolio screen with 100$ for buying power
3(return) // should go to banking withdraw screen
120(return) // should say insufficient funds 
3(return) // should go to banking withdraw screen
80(return) // should now show that buying power is $20
6(return) // should bring back to main menu screen
3(return) // should say thanks screen and main.cpp should return 0;

Test 4: (showing full scope of buying selling and csv functionality) (userinput) // (what it should do)
2(return) // should go to the create an account screen 
compscita(return) // enter compscita
hello(return) // enter hello
hello(return) // enter hello
// should say logged in as compscita and show avalible balance and portfolio at 0. 
1(return) // should show buy stock screen
APPL(return) // enter APPL
170.83 // enter 170.83
3 // enter 3
// should say not enough buying power. and bring back to main screen
4(return) // should go to deposit banking screen
2000(return) // should go back to portfolio screen and have $2000 for buying power
1(return) // should go to buying stock screen
APPL(return) // enter APPL
170.23(return) // enter 170.23
3(return) // enter 3
//should now show -APPL $170.23 3 Shares and haveing buying power at 1489.31 and portfolio value at 510.69
1(return) // should go to buy stock screen
SPY(return) // enter spy
415.93(return) // enter 415.93
2(return) // enter 2
//should now show appl and spy at thier respective prices and should change the buying power to 657.45 and 1342.55 for the portfolio Value:
2(return) // should go to sell stock
APPL(return) // enter APPL
2(return) // enter 2 
// should say 2 shars of appl sold 
// should reflect on the portfolio and show appl at 1 share and buying power now at 997.91 and portfolio value at 1002.09
2(return) // should go to sell stock screen
APPL(return) // enter APPL
2(return) // should say not enough owned 
2(return) should go to sell stock screen
APPL(return) // enter APPL
1(return) // enter 1 
// should sell 1 share of appl and no more appl will be seen on the portfolio
1(return) // should go to buy Stock screen
APPL(return) // enter appl
173.2(return) // enter 173.2
4(return) // enter 4
// should now reflect spy and appl stocks and buying power at 475.34 and portfolio value at 1524.66
5(return) // should say exported portfolio to csv
//should now see an outputted portfolio.csv file where every stock is shown and the header is created and buying power and portfolio value is shown and each value of each stock is shown. 
6(return) // should say logged out successfully!
3(return) // should say thank you screen and main.cpp should return 0

Test 5: (this should test reduntancy and make sure that false user inputs wont be counted as valid ) (userinput) // (what it should do)
z(return) // enter z 
// should say that this is not a choice and to try again
4(return) // enter 4
should say that this is not a choice and to try again
2(return) // should go to create an account screen
compscita(return) // enter compscita
123(return) // enter 123
123(return) // enter 123
// should now be logged in as compscita and should be in the portfolio screen with buying power at 0 and portfolio value at 0 
z(return) // should say that is not a choice try again
3(return) // should go to the withdraw banking screen
z(return) // enter z
//should say that that is not an amount please try again
3(return) // should say error insufficient funds
4(return) // should go to deposit baking screen
z(return) // enter z 
// should say that that is not an amount and please try again
2(return) // enter 2
// should show a portfolio screen with the amount 2 for buying power now 
2(return) // should go to sell stock screen
NONE(return) // enter NONE
z(return) // should say no NONE found or 0 or NONE owned and say that is not a choice
// should now be back on portfolio screen
1(return) // should go to buy stock screen
NONE(return) // enter NONE
z(return) // enter z
// should say that that is not a choice and to please try again
6(return) // should say successfully logged out return to welcome screen
3(return) // should show thanks screen and main.cpp should return 0. 

Reflection: 
I throughly enjoyed working on this project, despite the challenges it presented.
One particularly difficult aspect was figuring out how to store all the users' data
together, which ended up taking a significatn amount of time. Additionally, ensuring
that the program could handle edge case inputs was also time-consuming. Despite this,
it was incredibly rewarding to see the final product come together. Unfortunatly, I was 
unable to add a feature where stock prices would change randomly, but I have plans to 
expand the project in the future, such as by integrating a stock API or adding a large 
file of stock data. I realize that planning ahead and exploring potential systems before
diving into the project would have saved me time and made implementing features more
efficient. Overall, I found this project to be a avaluable learning experience and 
looking forward to further developing it. 










 
