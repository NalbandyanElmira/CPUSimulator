#include "../include/instructions.h"

// Constructor for the Instructions class
Instructions::Instructions()
	: pc{0}
{
	// Initialize registers r1 to r10 with default values of 0
	registers["r1"] = 0;
	registers["r2"] = 0;
	registers["r3"] = 0;
	registers["r4"] = 0;
	registers["r5"] = 0;
	registers["r6"] = 0;
	registers["r7"] = 0;
	registers["r8"] = 0;
	registers["r9"] = 0;
	registers["r10"] = 0;
}

// Function to add two operands and store the result in the first operand
void Instructions::add(const std::string& src1, const std::string& src2)
{
	registers[src1] += getValue(src2);
}

// Function to subtract the second operand from the first operand
void Instructions::subtract(const std::string& src1, const std::string& src2)
{
	registers[src1] -= getValue(src2);
}

// Function to multiply two operands and store the result in the first operand
void Instructions::multiply(const std::string& src1, const std::string& src2)
{
	registers[src1] *= getValue(src2);
}

// Function to divide the first operand by the second operand
void Instructions::divide(const std::string& src1, const std::string& src2)
{
	// Check for division by zero
	if (registers[src2] == 0) {
		throw std::logic_error{"Zero division error."};
	}
	registers[src1] /= getValue(src2);
}

// Function to perform a bitwise AND operation between two operands
void Instructions::logicalAnd(const std::string& src1, const std::string& src2)
{
	registers[src1] &= getValue(src2);
}

// Function to perform a bitwise OR operation between two operands
void Instructions::logicalOr(const std::string& src1, const std::string& src2)
{
	registers[src1] |= getValue(src2);
}

// Function to perform a bitwise XOR operation between two operands
void Instructions::logicalXor(const std::string& src1, const std::string& src2)
{
	registers[src1] ^= getValue(src2);
}

// Function to shift the first operand right by the number of bits specified in the second operand
void Instructions::shiftRight(const std::string& src1, const std::string& src2)
{
	registers[src1] >>= getValue(src2);
}

// Function to shift the first operand left by the number of bits specified in the second operand
void Instructions::shiftLeft(const std::string& src1, const std::string& src2)
{
	registers[src1] <<= getValue(src2);
}

// Function to move a value from src2 to src1 (can be either a register or a constant)
void Instructions::mov(const std::string& src1, const std::string& src2)
{
	// Check if src2 is a register or a constant and copy the value accordingly
	if (registers.find(src2) != registers.end()) {
        registers[src1] = registers[src2];
    } else {
        registers[src1] = std::stoi(src2);
    }
}

// Function to compare two values and set flags accordingly
void Instructions::cmp(const std::string& src1, const std::string& src2)
{
	int val1 = getValue(src1);
	int val2 = getValue(src2);
	flags.zeroFlag = (val1 == 0);
	flags.equalFlag = (val1 == val2);
	flags.lowFlag = (val1 < val2);
	flags.greatFlag = (val1 > val2);
}

// Function to perform an unconditional jump to the specified target line
int Instructions::jmp(int targetLine)
{
	return targetLine;
}

// Function to jump to the specified target line if the zero flag is set
int Instructions::jz(int targetLine)
{
	if (flags.zeroFlag) {
		pc = targetLine;
	}
	else {
		pc++;
	}
	return pc;
}

// Function to jump to the specified target line if the low flag is set
int Instructions::jl(int targetLine)
{
	if (flags.lowFlag) {
		pc = targetLine + 1;
	}
	else {
		pc++;
	}
	return pc;
}

// Function to jump to the specified target line if the low flag or equal flag is set
int Instructions::jle(int targetLine)
{
	if (flags.lowFlag || flags.equalFlag) {
		pc = targetLine;
	}
	else {
		pc++;
	}
	return pc;
}

// Function to jump to the specified target line if the equal flag is set
int Instructions::je(int targetLine)
{
	if (flags.equalFlag) {
		pc = targetLine;
	}
	else {
		pc++;
	}
	return pc;
}

// Function to jump to the specified target line if the great flag is set
int Instructions::jg(int targetLine)
{
	if (flags.greatFlag) {
		pc = targetLine;
	}
	else {
		pc++;
	}
	return pc;
}

// Function to jump to the specified target line if the great flag or equal flag is set
int Instructions::jge(int targetLine)
{
	if (flags.greatFlag || flags.equalFlag) {
		pc = targetLine;
	}
	else {
		pc++;
	}
	return pc;
}

// Function to get the current value of the program counter
int Instructions::getPC() const
{
	return pc;
}

// Function to print the value of a specified register
void Instructions::printRegister(const std::string& reg)
{
	if (registers.find(reg) != registers.end()) {
        std::cout << "Value of register " << reg << ": " << registers[reg] << "\n";
    } else {
        throw std::runtime_error{"Register not found."};
    }
}

// Function to increment the value of a specified register
void Instructions::increment(const std::string& reg)
{
	if (registers.find(reg) != registers.end()) {
        registers[reg] += 1;
    } else {
        throw std::runtime_error{"Register not found."};
    }
}

// Function to decrement the value of a specified register
void Instructions::decrement(const std::string& reg)
{
	if (registers.find(reg) != registers.end()) {
        registers[reg] -= 1;
    } else {
        throw std::runtime_error{"Register not found."};
    }
}

// Function to get the integer value of an operand (either a register or a constant)
int Instructions::getValue(const std::string& operand) {
    if (registers.find(operand) != registers.end()) {
        return registers[operand];
    } else {
        return std::stoi(operand);
    }
}
