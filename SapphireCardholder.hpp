#ifndef SAPPHIRECARDHOLDER_HPP
#define SAPPHIRECARDHOLDER_HPP

#include "Cardholder.hpp"

class SapphireCardholder : public Cardholder 
{
    public:
    // Constructor
    SapphireCardholder(std::string acctNumberIn, std::string nameIn);
    // Destructor
    virtual ~SapphireCardholder() {}

    // Overrides
    int purchasePoints() const override; //overridden to return 1 point(s) per dollar spent

    private:
    int pointsPerDollar = 1; // Sapphire members earn 1 point per dollar spent
};
#endif // SAPPHIRECARDHOLDER_HPP