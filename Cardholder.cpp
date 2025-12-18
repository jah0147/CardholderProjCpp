#include "Cardholder.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

// Constructor
Cardholder::Cardholder(std::string acctNumberIn, std::string nameIn) : acctNumber(acctNumberIn), name(nameIn), prevBalance(0.0), payment(0.0)
{
    // Initialize your members here
}

// Getters
/**
 * \details Returns the category of the cardholder.
 * \return category of the cardholder
 */
std::string Cardholder::getCategory() const 
{
    return category;
}

/**
 * \details Returns the account number of the cardholder.
 * \return account number of the cardholder
 */
std::string Cardholder::getAcctNumber() const 
{
    return acctNumber;
}

/**
 * \details Returns the name of the cardholder.
 * \return name of the cardholder
 */
std::string Cardholder::getName() const 
{
    return name;
}

/**
 * \details Returns the previous balance of the cardholder.
 * \return previous balance of the cardholder
 */
double Cardholder::getPrevBalance() const 
{
    return prevBalance;
}

/**
 * \details Returns the payment made by the cardholder.
 * \return payment made by the cardholder
 */
double Cardholder::getPayment() const 
{
    return payment;
}

/**
 * \details Returns the purchases made by the cardholder.
 * \return vector of purchases made by the cardholder
 */
std::vector<double> Cardholder::getPurchases() const 
{
    return purchases;
}

// Setters
/**
 * \details Sets the category of the cardholder.
 * \param categoryIn New category to set
 */
void Cardholder::setCategory(std::string categoryIn) 
{
    category = categoryIn;
}

/**
 * \details Sets the account number of the cardholder.
 * \param acctNumIn New account number to set
 */
void Cardholder::setAcctNumber(std::string acctNumIn) 
{
    acctNumber = acctNumIn;
}

/**
 * \details Sets the name of the cardholder.
 * \param nameIn New name to set
 */
void Cardholder::setName(std::string nameIn) 
{
    name = nameIn;
}

/**
 * \details Sets the previous balance of the cardholder.
 * \param prevBalanceIn New previous balance to set
 */
void Cardholder::setPrevBalance(double prevBalanceIn) 
{
    prevBalance = prevBalanceIn;
}

/**
 * \details Sets the payment made by the cardholder.
 * \param paymentIn New payment to set
 */
void Cardholder::setPayment(double paymentIn) 
{
    payment = paymentIn;
}

/**
 * \details Sets the purchases made by the cardholder.
 * \param purchasesIn New vector of purchases to set
 */
void Cardholder::setPurchases(std::vector<double> purchasesIn) 
{
    purchases = purchasesIn;
}

// Logic Methods
/**
 * \details Adds a single purchase to the purchases vector.
 * \param priceIn Price of the purchase to add
 */
void Cardholder::addPurchase(double price) 
{
    purchases.push_back(price);
}

/**
 * \details Adds multiple purchases to the purchases vector.
 * \param pricesIn Vector of prices to add
 */
void Cardholder::addPurchases(std::vector<double> prices) 
{
    // This says: "For every element inside 'prices', create a copy called 'price' 
    // and execute the code block."
    for (double price : prices) 
    {
        purchases.push_back(price);
    }
}

/**
 * \details Deletes specified purchases from the purchases vector.
 * \param pricesIn Vector of prices to delete
 */
void Cardholder::deletePurchases(std::vector<double> prices) 
{
    for (double price : prices)
    {
        //checks for all instances of price and removes them
        purchases.erase(std::remove(purchases.begin(), purchases.end(), price), purchases.end());
    }
}

/**
 * \details calculates the interest based on previous balance and payment.
 * \return calculated interest
 */
double Cardholder::interest() const 
{
    return INTEREST_RATE * (prevBalance - payment);
}

/**
 * \details the total amount of purchases.
 * \return sum of all values in purchases vector
 */
double Cardholder::totalPurchases() const 
{
    double total = 0.0; //ensure total starts at 0 every time
    for (double price : purchases) 
    {
        total += price; //add each price to total
    }

    return total;
}

/**
 * \details calculates the balance based on previous balance, interest, and total purchases.
 * \return calculated balance
 */
double Cardholder::balance() const 
{
    return prevBalance + interest() + totalPurchases();
}

/**
 * \details calculates the current balance based on previous balance, payment, interest, and total purchases.
 * \return calculated current balance
 */
double Cardholder::currentBalance() const 
{
    return prevBalance - payment + interest() + totalPurchases();
}

/**
 * \details calculates the minimum payment as 3% of the current balance.
 * \return calculated minimum payment
 */
double Cardholder::minPayment() const 
{
    return currentBalance() * MIN_PAYMENT_RATE; // 3% of current balance
}

/**
 * \details Converts a double number to a string with fixed precision.
 * \param numIn Number to convert
 * \return string representation of the number
 */
std::string Cardholder::toString() const 
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    
    ss << category << "\n";
    ss << "AcctNo/Name: " << getAcctNumber() << " " << getName() << "\n";
    ss << "Previous Balance: $" << getPrevBalance() << "\n";
    ss << "Payment: ($" << getPayment() << ")\n";
    ss << "Interest: $" << interest() << "\n";
    ss << "New Purchases: $" << totalPurchases() << "\n";
    ss << "Current Balance: $" << currentBalance() << "\n";
    ss << "Minimum Payment: $" << minPayment() << "\n";
    ss << "Purchase Points: " << purchasePoints(); // Polymorphic call
    
    return ss.str();
}