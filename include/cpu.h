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
	CPU();
	void fetch(const std::string&);
	void execute();
	void printLabels();
private:
	Instructions instructions;
	std::unordered_map<std::string, int> fetched;
	std::unordered_map<std::string, int> labels;
	std::unordered_map<std::string, std::function<void(const std::string&, const std::string&)>> functions;
	std::unordered_map<std::string, std::function<int(int)>> functions2;
	std::string trim(const std::string&);
	int pc;
};

#endif //CPU_H