#include <iostream>
#include <numeric>
#include <vector>

void RestoreGravityAssistProgram(std::vector<std::size_t>& intcode)
{
    if (intcode.size() < 3)
        return;
    intcode[1] = 12;
    intcode[2] = 2;
}

void Execute(std::vector<std::size_t>& intcode)
{
    for (std::size_t pos_opcode = 0; pos_opcode < intcode.size() && intcode[pos_opcode] != 99;
         pos_opcode += 4) {
        std::size_t const first_operand = intcode[intcode[pos_opcode + 1]];
        std::size_t const second_operand = intcode[intcode[pos_opcode + 2]];

        intcode[intcode[pos_opcode + 3]] = intcode[pos_opcode] == 1
                                               ? first_operand + second_operand
                                               : first_operand * second_operand;
    }
}

int main()
{
    std::size_t element;
    char comma;
    std::cin >> element;
    if (element == 99) {
        std::cout << "99" << std::endl;
    }
    else {
        std::vector<std::size_t> intcode{element};
        while (std::cin >> comma) {
            std::cin >> element;
            intcode.push_back(element);
        }
        RestoreGravityAssistProgram(intcode);
        Execute(intcode);
        std::cout << intcode[0] << std::endl;
    }
}
