#include "include/cpu.h"

int main()
{
	CPU cpu;
	cpu.fetch("data/code.txt");
	cpu.execute();

	return 0;
}