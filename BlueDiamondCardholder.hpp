#ifndef BLUEDIAMONDCARDHOLDER_HPP
#define BLUEDIAMONDCARDHOLDER_HPP
#include "DiamondCardholder.hpp"

class BlueDiamondCardholder : public DiamondCardholder
{
    public:
    // Constructor
    BlueDiamondCardholder(std::string acctNumberIn, std::string nameIN);
    // Destructor
    virtual ~BlueDiamondCardholder() {};

    // Overrides
    int purchasePoints() const override; //implements 5 points per dollar spent before discount
    std::string toString() const override; //overridden to include category info

    protected:
    // declare in constructor: pointsPerDollar = 5;  // 5 points per dollar spent
    //declare in constructor: discountRate = 0.10f; // 10% discount on purchases
    const int bonusPoints = 2500; // intitial bonus points for Blue Diamond members
};

#endif // BLUEDIAMONDCARDHOLDER_HPP