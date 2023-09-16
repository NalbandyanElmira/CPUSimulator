#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <unordered_map>
#include <stdexcept>
#include <iostream>
#include <string>

// Struct to represent CPU flags
struct Flags
{
    bool zeroFlag;   // Flag indicating if the result is zero
    bool greatFlag;  // Flag indicating if the result is greater
    bool lowFlag;    // Flag indicating if the result is lower
    bool equalFlag;  // Flag indicating if the result is equal
};

class Instructions
{
public:
    // Constructor for the Instructions class
    Instructions();
    
    // Arithmetic and logical operations
    void add(const std::string&, const std::string&);
    void subtract(const std::string&, const std::string&);
    void multiply(const std::string&, const std::string&);
    void divide(const std::string&, const std::string&);
    void logicalAnd(const std::string&, const std::string&);
    void logicalOr(const std::string&, const std::string&);
    void logicalXor(const std::string&, const std::string&);
    void shiftRight(const std::string&, const std::string&);
    void shiftLeft(const std::string&, const std::string&);
    
    // Move and compare operations
    void mov(const std::string&, const std::string&);
    void cmp(const std::string&, const std::string&);
    
    // Jump instructions
    int jmp(int);
    int jz(int);
    int jl(int);
    int jle(int);
    int je(int);
    int jg(int);
    int jge(int);
    
    // Function to print the value of a register
    void printRegister(const std::string&);
    
    // Functions to increment and decrement a register
    void increment(const std::string&);
    void decrement(const std::string&);
    
    // Function to get the current value of the program counter
    int getPC() const;
    
    // Function to get the value of an operand (either a register or a constant)
    int getValue(const std::string&);
    
private:
    std::unordered_map<std::string, int> registers; // Map to store register values
    Flags flags; // Flags representing the status of the CPU
    int pc; // Program counter to keep track of the current instruction
};

#endif // INSTRUCTIONS_H
