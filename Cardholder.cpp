#include "Cardholder.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

// Constructor
Cardholder::Cardholder(std::string acctNumberIn, std::string nameIn) 
{
    // Initialize your members here
}

// Getters
std::string Cardholder::getCategory() const 
{
    return category;
}

std::string Cardholder::getAcctNumber() const 
{
    return acctNumber;
}

std::string Cardholder::getName() const 
{
    return name;
}

double Cardholder::getPrevBalance() const 
{
    return prevBalance;
}

double Cardholder::getPayment() const 
{
    return payment;
}

std::vector<double> Cardholder::getPurchases() const 
{
    return purchases;
}

// Setters
void Cardholder::setCategory(std::string categoryIn) 
{
    category = categoryIn;
}

void Cardholder::setAcctNumber(std::string acctNumIn) 
{
    acctNumber = acctNumIn;
}

void Cardholder::setName(std::string nameIn) 
{
    name = nameIn;
}

void Cardholder::setPrevBalance(double prevBalanceIn) 
{
    prevBalance = prevBalanceIn;
}

void Cardholder::setPayment(double paymentIn) 
{
    payment = paymentIn;
}

void Cardholder::setPurchases(std::vector<double> purchasesIn) 
{
    purchases = purchasesIn;
}

// Logic Methods
void Cardholder::addPurchase(double price) 
{
}

void Cardholder::addPurchases(std::vector<double> prices) 
{
}

void Cardholder::deletePurchases(std::vector<double> prices) 
{
}

double Cardholder::interest() const 
{
    return 0.0;
}

double Cardholder::totalPurchases() const 
{
    return 0.0;
}

double Cardholder::balance() const 
{
    return 0.0;
}

double Cardholder::currentBalance() const 
{
    return 0.0;
}

double Cardholder::minPayment() const 
{
    return 0.0;
}

// String Representation
std::string Cardholder::toString() const 
{
    return "";
}