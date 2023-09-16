#ifndef CPU_H
#define CPU_H

#include "instructions.h"

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

class CPU
{
public:
    // Constructor for the CPU class
    CPU();
    
    // Function to fetch instructions from a file
    void fetch(const std::string&);
    
    // Function to execute the fetched instructions
    void execute();
    
    // Function to print the contents of the labels map
    void printLabels();
    
private:
    Instructions instructions;
    std::unordered_map<std::string, int> fetched; // Map to store fetched instructions with their line numbers
    std::unordered_map<std::string, int> labels;  // Map to store labels and their corresponding instruction pointers
    std::unordered_map<std::string, std::function<void(const std::string&, const std::string&)>> functions; // Map of function pointers for arithmetic and logical instructions
    std::unordered_map<std::string, std::function<int(int)>> functions2; // Map of function pointers for jump instructions
    std::string trim(const std::string&); // Function to trim leading and trailing spaces from a string
    int pc; // Program counter to keep track of the current instruction
};

#endif // CPU_H
