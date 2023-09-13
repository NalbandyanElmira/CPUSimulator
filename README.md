# CPUSimulator
This is a simple CPU simulator written in C++. It allows you to execute a sequence of instructions using a custom assembly-like language.

## Features

###Instruction Set: The simulator supports a set of basic assembly-like instructions, including arithmetic operations, conditional jumps, and label definitions.

### Registers: You can work with registers (e.g., r1, r2, ..., r10) to perform arithmetic operations and comparisons.

### Labels: Define labels (e.g., label:) in your code to mark specific points in the program and use them for conditional jumps.

### Conditional Jumps: Execute conditional jumps (jl, je, jle, jz, jg, jge) based on the comparison result of cmp instruction.

### Input Programs: Load and execute programs from text files, making it easy to create and test different sequences of instructions.

### Output: The simulator provides output for each executed instruction, including register values and any detected labels.

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

`mov r1 5`       ; Move the value 5 into register r1
`mov r2 10`      ; Move the value 10 into register r2
`add r1 r2`      ; Add the values in r1 and r2 and store the result in r1
`label:`         ; Label definition
`sub r1 2`       ; Subtract 2 from r1
`cmp r1 r2`      ; Compare r1 and r2
`jl label`       ; Jump to the 'label' if r1 < r2
`print r1`       ; Print the value in r1
