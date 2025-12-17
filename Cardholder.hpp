#ifndef CARDHOLDER_HPP
#define CARDHOLDER_HPP

#include <string>
#include <vector>
#include "constants.hpp"

//using namespace std; // All std tools are now available globally in this file (not reccommended when using multi-namespaces)

class Cardholder {
public:
// Constructor
Cardholder(std::string accNumberIn, std::string nameIn);
//Destructor
virtual ~Cardholder() {}

//getters (Marked as 'const' because they don't modify the object)
std::string getCategory() const;
std::string getAcctNumber() const;
std::string getName() const;
double getPrevBalance() const;
double getPayment() const;
std::vector<double> getPurchases() const;

//setters
void setCategory(std::string categoryIn);
void setAcctNumber(std::string acctNumIn);
void setName(std::string nameIn);
void setPrevBalance(double prevBalanceIn);
void setPayment(double paymentIn);
void setPurchases(std::vector<double> purchasesIn);

//methods
void addPurchase(double priceIn); //adds a single purchase to the vector
void addPurchases(std::vector<double> pricesIn); //adds puliple purchases to the vector
void deletePurchases(std::vector<double> pricesIn); //removes found values from the purches vector list

double interest() const; //Retunres '(prevBalance - payment) * INTEREST_RATE'
double totalPurchases() const; //Returns the sum of all values in the purchases vector
double balance() const; //returns '(prevBalance + interest + totalPurchases)'
double currentBalance() const; // returns (prevBalance - payement + interest + totalPurchases)
double minPayment() const; //returns 3% of the current balance
virtual int purchasePoints() const; //returns members purchas points (overridden based on membere status)
virtual std::string toString() const; //will be used to convert numbers to string values for printing


protected:
std::string category;
std::string acctNumber;
std::string name;
double prevBalance;
double payment;
std::vector<double> purchases;

private:
// no private members in base class

};

#endif