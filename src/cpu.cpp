#include "../include/cpu.h"

CPU::CPU()
	: pc{0}
{
	functions["add"] = [this](const std::string& a, const std::string& b) {instructions.add(a, b);};
	functions["sub"] = [this](const std::string& a, const std::string& b) {instructions.subtract(a, b);};
	functions["mul"] = [this](const std::string& a, const std::string& b) {instructions.multiply(a, b);};
	functions["div"] = [this](const std::string& a, const std::string& b) {instructions.divide(a, b);};
	functions["shr"] = [this](const std::string& a, const std::string& b) {instructions.shiftRight(a, b);};
	functions["shl"] = [this](const std::string& a, const std::string& b) {instructions.shiftLeft(a, b);};
	functions["and"] = [this](const std::string& a, const std::string& b) {instructions.logicalAnd(a, b);};
	functions["or"] = [this](const std::string& a, const std::string& b) {instructions.logicalOr(a, b);};
	functions["xor"] = [this](const std::string& a, const std::string& b) {instructions.logicalXor(a, b);};
	functions["mov"] = [this](const std::string& a, const std::string& b) {instructions.mov(a, b);};
	functions["print"] = [this](const std::string& a, const std::string& b) {instructions.printRegister(a);};
	functions["cmp"] = [this](const std::string& a, const std::string& b) {instructions.cmp(a, b);};
	functions2["jmp"] = [this](int a) {return instructions.jmp(a);};
	functions2["jl"] = [this](int a) {return instructions.jl(a);};
	functions2["je"] = [this](int a) {return instructions.je(a);};
	functions2["jle"] = [this](int a) {return instructions.jle(a);};
	functions2["jz"] = [this](int a) {return instructions.jz(a);};
	functions2["jg"] = [this](int a) {return instructions.jg(a);};
	functions2["jge"] = [this](int a) {return instructions.jge(a);};
}

std::string CPU::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    if (first == std::string::npos) {
        return "";
    }
    return str.substr(first, (last - first + 1));
}

void CPU::printLabels()
{
    std::cout << "Labels Map Contents:\n";
    for (const auto& label : labels)
    {
        std::cout << "Label: " << label.first << " - Instruction Pointer: " << label.second << std::endl;
    }
}

void CPU::fetch(const std::string& fileName)
{
    std::ifstream file(fileName);
    std::string line;
    int line_number = 0;

    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') {
            continue;
        }
        fetched[line] = line_number;
        line_number++;
    }
}

void CPU::execute()
{
    int pc = 0; 
    while (pc < fetched.size()) {
        auto it = std::find_if(fetched.begin(), fetched.end(),
            [this, pc](const auto& entry) { return entry.second == pc; });

        if (it != fetched.end()) {
            std::string instruction = it->first;
            std::istringstream iss(instruction);
            std::string op;
            iss >> op;
            if (op.back() == ':') {
                labels[op.substr(0, op.size() - 1)] = pc;
                pc++;
                continue;
            }
            std::unordered_set<std::string> jumpOps = {"jmp", "jl", "je", "jle", "jz", "jg", "jge"};
            if (jumpOps.find(op) != jumpOps.end()) {
                std::string labelName;
                iss >> labelName;
                if (labels.find(labelName) != labels.end()) {
                    pc = functions2[op](labels[labelName]);
                    continue;
                }
                else {
                    std::cout << "Label '" << labelName << "' not found." << std::endl;
                    break;
                }
            }
            else {
                std::string src1, src2;
                iss >> src1 >> src2;
                if (functions.find(op) != functions.end()) {
                    functions[op](src1, src2);
                }
                else {
                    break;
                }
            }
        }
        else {
            break;
        }
        pc++; 
    }
}