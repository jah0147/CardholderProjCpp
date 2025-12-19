#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

// Triggered when the file cannot be opened
class FileException : public std::runtime_error {
public:
    FileException(const std::string& filename);
};

// Triggered when data inside the file is corrupt or missing
class DataFormatException : public std::runtime_error {
public:
    DataFormatException(const std::string& detail, int lineNum);
};

#endif