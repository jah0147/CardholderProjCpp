#include "Exceptions.hpp"

// Constructor for FileException
FileException::FileException(const std::string& filename) 
    : std::runtime_error("CRITICAL ERROR: Could not open file '" + filename + "'. Check if the file exists.") {}

// Constructor for DataFormatException
DataFormatException::DataFormatException(const std::string& detail, int lineNum) 
    : std::runtime_error("DATA ERROR (Line " + std::to_string(lineNum) + "): " + detail) {}