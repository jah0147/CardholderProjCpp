#include "CardholderProcessor.hpp"
#include "SapphireCardholder.hpp"
#include "DiamondCardholder.hpp"
#include "BlueDiamondCardholder.hpp"
#include <iostream>
#include <fstream> 
#include <sstream>
#include "Exceptions.hpp"

// Constructor
CardholderProcessor::CardholderProcessor() 
{
    // Initialization if needed
}

/**
 * Desctructor
 * \details Cleans up dynamically allocated Cardholder objects.
 */
CardholderProcessor::~CardholderProcessor()
{
    for (Cardholder* ch : cardholders)
    {
        delete ch;
    }
}

/**
 * \details Reads cardholder data from a specified file and populates the cardholders vector.
 * \param filenameIn Name of the file containing cardholder data
 */
void CardholderProcessor::readData(std::string filenameIn)
{
    std::ifstream inputFile(filenameIn);
    std::string line;

    if (!inputFile.is_open()) {
        throw FileException(filenameIn); //Throws a file error
    }

    int currentLine = 0; //current line counter

    while (std::getline(inputFile, line))
    {
        currentLine++; //add to line counter
        if(line.empty()) continue;

        std::stringstream ss(line); //reads line by line

        // Reads until semicolon if we were using something to section off numbers, 
        // names/strings, etc. Commented out bc our txt file is not in this format currently
        // std::getline(ss >> std::ws, name, ';');

        int type;
        std::string acctNum, name;
        double prevBal, payAmt; // Standard files usually have both
        Cardholder* ch = nullptr;

        // Extraction
        // We assume file is always in the same format for every line.
        // For this part of the project, it's fine.
        // In future part, we may change this and input file type (ini or spreadsheet for example)
        // 1. Extract the data in clear steps
        // ss >> type >> acctNum >> name >> prevBal >> payAmt;

        // // 2. Explicitly ask the stream: "Did that actually work?"
        // if (ss.fail()) 
        // {
        //     // If we reach here, it means the line was empty, 
        //     // or 'prevBal' wasn't a number, etc.
        //     std::cerr << "Error: Skipping malformed line." << std::endl;
        //     continue; // Jump to the next line in the file
        // }
        //This is a cleaner way of writing the above if ss.fail()
        if (!(ss >> type >> acctNum >> name >> prevBal >> payAmt))
        {
            throw DataFormatException("Invalid or missing data format", currentLine); //throws exception and gives line error occured
        }

        //Using a switch statement to determin what cardholder to create
        switch (type)
        {
            case 1: ch = new SapphireCardholder(acctNum, name); break;
            case 2: ch = new DiamondCardholder(acctNum, name); break;
            case 3: ch = new BlueDiamondCardholder(acctNum, name); break;

            default: 
                //Throw if cardholder type is not reccognized
                throw DataFormatException("Unknown cardholder type: " + std::to_string(type), currentLine);
        }

        // Transfer the values into the new object
        if (ch != nullptr) 
        {
            ch->setPrevBalance(prevBal);
            ch->setPayment(payAmt);

            double tempPurchase;
            while (ss >> tempPurchase) //this should read the rest of the line for all purchases
            {
                ch->addPurchase(tempPurchase); // We are adding each purchase to the function to be stored
            }

            cardholders.push_back(ch); //adds the cardholder to the vector list to save
        }
    }
    inputFile.close(); //closing the file
}

/**
 * \details Generates a report of all cardholders by printing their details to the console.
 */
void CardholderProcessor::generateReport()
{
    for (Cardholder* ch : cardholders)
    {
        std::cout << ch->toString() << "\n";

        // Optional: Add a divider for better readability
        std::cout << "--------------------------" << std::endl;
    }
}