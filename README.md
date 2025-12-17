# 1.0
A project to hit the basics and cover coding structure/format for C++

## Info
This is the basic structire of Cardholder base class.

## Task
Create an abstract class named Cardholder. 
##### Member Variables (Protected): 
- category (string) 
- acctNumber (string) 
- name (string) 
- prevBalance (double) 
- payment (double) 
- purchases (std::vector<double>) - Note: The Java requirement forced Arrays, but std::vector is preferred in C++ for dynamic purchase lists. 

#### Constants: 
- INTEREST_RATE: static constant set to 0.01. 
#### Methods: 
- Constructor: Accepts Account Number and Name. Initialize purchases as empty. 
- Getters/Setters: For all fields. 
- addPurchase(double price): Adds a single purchase to the vector. 
- addPurchases(std::vector<double> prices): Adds multiple purchases. 
- deletePurchases(std::vector<double> prices): Removes found values from the list. 
- interest(): Returns (prevBalance - payment) * INTEREST_RATE. 
- totalPurchases(): Returns the sum of all values in the purchases vector. 
- balance(): Returns prevBalance + interest + totalPurchases. 
- currentBalance(): Returns prevBalance - payment + interest + 
totalPurchases. 
- minPayment(): Returns 3% of the current balance. 
- toString(): Returns a formatted string (Use std::stringstream to format currency). 
- purchasePoints(): Pure Virtual Function. Returns an int. 
#### C++ Hint: Virtual Destructors 
Since this class is intended to be a base class, you must declare the destructor as virtual ~Cardholder() {}. If you don't, deleting a derived object via a base pointer will cause undefined behavior. 
