#include "SapphireCardholder.hpp"

// Constructor
SapphireCardholder::SapphireCardholder(std::string acctNumberIn, std::string nameIn) 
    : Cardholder(acctNumberIn, nameIn) 
{
    category = "Sapphire Cardholder";
}

// Overrides
int SapphireCardholder::purchasePoints() const 
{
    return (int)(totalPurchases() * pointsPerDollar); //cast to int to avoid fractional points
}