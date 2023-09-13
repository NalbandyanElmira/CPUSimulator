#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <unordered_map>
#include <stdexcept>
#include <iostream>
#include <string>

struct Flags
{
	bool zeroFlag;
	bool greatFlag;
	bool lowFlag;
	bool equalFlag;
};

class Instructions
{
public:
	Instructions();
	void add(const std::string&, const std::string&);
	void subtract(const std::string&, const std::string&);
	void multiply(const std::string&, const std::string&);
	void divide(const std::string&, const std::string&);
	void logicalAnd(const std::string&, const std::string&);
	void logicalOr(const std::string&, const std::string&);
	void logicalXor(const std::string&, const std::string&);
	void shiftRight(const std::string&, const std::string&);
	void shiftLeft(const std::string&, const std::string&);
	void mov(const std::string&, const std::string&);
	void cmp(const std::string&, const std::string&);
	int jmp(int);
	int jz(int);
	int jl(int);
	int jle(int);
	int je(int);
	int jg(int);
	int jge(int);
	void printRegister(const std::string&);
	int getPC() const;
	int getValue(const std::string&);
private:
	std::unordered_map<std::string, int> registers;
	Flags flags;
	int pc;
};

#endif // INSTRUCTIONS_H