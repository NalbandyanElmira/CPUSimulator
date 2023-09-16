# CPUSimulator
This is a simple CPU simulator written in C++. It allows you to execute a sequence of instructions using a custom assembly-like language.

## Features

- Instruction Set: The simulator supports a set of basic assembly-like instructions, including arithmetic operations, conditional jumps, and label definitions.

- Registers: You can work with registers (e.g., r1, r2, ..., r10) to perform arithmetic operations and comparisons.

- Labels: Define labels (e.g., label:) in your code to mark specific points in the program and use them for conditional jumps.

- Conditional Jumps: Execute conditional jumps (jl, je, jle, jz, jg, jge) based on the comparison result of cmp instruction.

- Input Programs: Load and execute programs from text files, making it easy to create and test different sequences of instructions.

- Output: The simulator provides output for each executed instruction, including register values and any detected labels.

## Usage
Clone the repository:
```bash
git clone https://github.com/NalbandyanElmira/CPUSimulator.git
```
```bash
cd cpusimulator
```

### Compile the code:
```bash
g++ src/instructions.cpp src/cpu.cpp main.cpp
```
### Run the CPU simulator:
```bash
./a.out
```

### Input Program Format
The input program should follow the format below:

- `mov r1 5`       ; Move the value 5 into register r1
- `mov r2 10`      ; Move the value 10 into register r2
- `add r1 r2`      ; Add the values in r1 and r2 and store the result in r1
- `print r1`       ; Print the value in r1
- `dec r2`         ; Decrement value of r2 register
- `print r2`       ; Print the value in r2
- `label:`         ; Label definition
- `dec r1`         ; Decrement value of r1 register
- `cmp r1 r2`      ; Compare r1 and r2
- `jg label`       ; Jump to the 'label' if r1 > r2
- `print r1`       ; Print the value in r1

The program execution proceeds sequentially from one line to the next unless specific control flow instructions, such as `jl`, are encountered. These control flow instructions can alter the program's flow by jumping to different parts of the code based on certain conditions.
