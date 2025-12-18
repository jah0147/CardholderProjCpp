#ifndef DIAMONDCARDHOLDER_HPP
#define DIAMONDCARDHOLDER_HPP
#include "Cardholder.hpp"

class DiamondCardholder : public Cardholder
{
public:
    // Constructor
    DiamondCardholder(std::string accNumberIn, std::string nameIn);
    //destructor
    virtual ~DiamondCardholder() {};
    
    // Overrides
    double totalPurchases() const override; //inplements 5% discount on purchases
    int purchasePoints() const override; //inplements 3 points per dollar spent
    std::string toString() const override; //overridden to include category info

    protected:
    //class variables
    float discountRate = 0.05; // 5% discount on purchases
    int pointsPerDollar = 3;  // 3 points per dollar spent
};

#endif // DIAMONDCARDHOLDER_HPP