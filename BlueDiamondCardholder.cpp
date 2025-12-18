#include "BlueDiamondCardholder.hpp"
#include <sstream>
#include <iomanip>

BlueDiamondCardholder::BlueDiamondCardholder(std::string acctNumIn, std::string nameIn)
    : DiamondCardholder(acctNumIn, nameIn)
    {
        category = "Blue Diamond Cardholder";
        discountRate = 0.10f; // 10% discount on purchases
        pointsPerDollar = 5;  // 5 points per dollar spent
    }
    /**
     * \details Calculates the purchase points for Blue Diamond cardholders
     *          per dollar spent before discount, plus bonus points.
     * 
     * \return total purchase points
     */
    int BlueDiamondCardholder::purchasePoints() const
    {
        //Using base class method to get points before discount. This is unique to Blue Diamond members vs. Diamond members.
        return (int)(Cardholder::totalPurchases() * pointsPerDollar) + bonusPoints; //cast to int to avoid fractional points
    }

    std::string BlueDiamondCardholder::toString() const
    {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2);
        
        // Get the standard report from the base class first
        ss << Cardholder::toString();
        
        // Append Blue Diamond-specific details
        ss << "(includes " << (discountRate * 100) << "% " << "discount and " << bonusPoints << " bonus points)\n";
        
        return ss.str();
    }