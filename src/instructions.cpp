#include "../include/instructions.h"

Instructions::Instructions()
	: pc{0}
{
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

void Instructions::add(const std::string& src1, const std::string& src2)
{
	registers[src1] += getValue(src2);
}

void Instructions::subtract(const std::string& src1, const std::string& src2)
{
	registers[src1] -= getValue(src2);
}

void Instructions::multiply(const std::string& src1, const std::string& src2)
{
	registers[src1] *= getValue(src2);
}

void Instructions::divide(const std::string& src1, const std::string& src2)
{
	if (registers[src2] == 0) {
		throw std::logic_error{"Zero dividion error."};
	}
	registers[src1] /= getValue(src2);
}

void Instructions::logicalAnd(const std::string& src1, const std::string& src2)
{
	registers[src1] &= getValue(src2);
}

void Instructions::logicalOr(const std::string& src1, const std::string& src2)
{
	registers[src1] |= getValue(src2);
}

void Instructions::logicalXor(const std::string& src1, const std::string& src2)
{
	registers[src1] ^= getValue(src2);
}

void Instructions::shiftRight(const std::string& src1, const std::string& src2)
{
	registers[src1] >>= getValue(src2);
}

void Instructions::shiftLeft(const std::string& src1, const std::string& src2)
{
	registers[src1] <<= getValue(src2);
}

void Instructions::mov(const std::string& src1, const std::string& src2)
{
	if (registers.find(src2) != registers.end()) {
        registers[src1] = registers[src2];
    } else {
        registers[src1] = std::stoi(src2);
    }
}

void Instructions::cmp(const std::string& src1, const std::string& src2)
{
	int val1 = getValue(src1);
	int val2 = getValue(src2);
	flags.zeroFlag = (val1 == 0);
	flags.equalFlag = (val1 == val2);
	flags.lowFlag = (val1 < val2);
	flags.greatFlag = (val1 > val2);
}

int Instructions::jmp(int targetLine)
{
	return targetLine;
}

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

int Instructions::getPC() const
{
	return pc;
}

void Instructions::printRegister(const std::string& reg)
{
	if (registers.find(reg) != registers.end()) {
        std::cout << "Value of register " << reg << ": " << registers[reg] << "\n";
    } else {
        throw std::runtime_error{"Register not found."};
    }
}

int Instructions::getValue(const std::string& operand) {
    if (registers.find(operand) != registers.end()) {
        return registers[operand];
    } else {
        return std::stoi(operand);
    }
}