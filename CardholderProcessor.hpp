#ifndef CARDHOLDERPROCESSOR_HPP
#define CARDHOLDERPROCESSOR_HPP

#include "Cardholder.hpp"
#include <vector>
#include <string>

class CardholderProcessor 
{
    public:
    // Constructor
    CardholderProcessor();
    // Destructor
    virtual ~CardholderProcessor();

    // Methods
    void readData(std::string filenameIn); //reads cardholder data from a file
    void generateReport(); //generates a report of all cardholders
    
    protected:
    std::vector<Cardholder*> cardholders;
};
#endif // CARDHOLDERPROCESSOR_HPP