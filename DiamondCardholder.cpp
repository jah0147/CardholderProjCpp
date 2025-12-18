#include "DiamondCardholder.hpp"
#include <sstream>
#include <iomanip>

DiamondCardholder:: DiamondCardholder(std::string acctNumIn, std::string nameIn) 
    : Cardholder(acctNumIn, nameIn) 
{
    category = "Diamond Cardholder";
}

/**
 * \details Calculates the total purchases with a 5% discount applied.
 * \return total purchases after discount
 */
double DiamondCardholder::totalPurchases() const
{
    return Cardholder::totalPurchases() * (1.0 - discountRate); //Loops through base class method and applies discount
}

/**
 * \details Calculates the purchase points for Diamond cardholders.
 * \return total purchase points
 */
int DiamondCardholder::purchasePoints() const
{
    return (int)(totalPurchases() * pointsPerDollar); //cast to int to avoid fractional points
}

/**
 * \details Converts Diamond cardholder details to a string representation.
 * \return string representation of the Diamond cardholder
 */
std::string DiamondCardholder::toString() const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    
    // Get the standard report from the base class first
    ss << Cardholder::toString();
    
    // Append Diamond-specific details
    ss << "(includes " << (discountRate * 100) << "% discount)\n";
    
    return ss.str();
}