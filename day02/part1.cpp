#include <iostream>
#include <numeric>
#include <vector>

void RestoreGravityAssistProgram(std::vector<uint16_t>& intcode)
{
    if (intcode.size() < 3)
        return;
    intcode[1] = 12;
    intcode[2] = 2;
}

constexpr uint16_t PositionFirstOperand(uint16_t opcode_pos)
{
    return opcode_pos + 1;
}

constexpr uint16_t PositionSecondOperand(uint16_t opcode_pos)
{
    return opcode_pos + 2;
}

constexpr uint16_t PositionOutput(uint16_t opcode_pos)
{
    return opcode_pos + 3;
}

constexpr uint16_t PositionNextOpcode(uint16_t opcode_pos)
{
    return opcode_pos + 4;
}

void Execute(std::vector<uint16_t>& intcode)
{
    uint16_t pos_opcode = 0;
    while (pos_opcode < intcode.size() && intcode[pos_opcode] != 99) {
        uint16_t const first_operand = intcode[PositionFirstOperand(pos_opcode)];
        uint16_t const second_operand = intcode[PositionSecondOperand(pos_opcode)];

        intcode[PositionOutput(pos_opcode)] = intcode[pos_opcode] == 1
                                                  ? first_operand + second_operand
                                                  : first_operand * second_operand;
        pos_opcode = PositionNextOpcode(pos_opcode);
    }
}

int main()
{
    uint16_t element;
    char comma;
    std::cin >> element;
    if (element == 99) {
        std::cout << "99" << std::endl;
    }
    else {
        std::vector<uint16_t> intcode{element};
        while (std::cin >> comma) {
            std::cin >> element;
            intcode.push_back(element);
        }
        RestoreGravityAssistProgram(intcode);
        Execute(intcode);
        std::cout << intcode[0] << std::endl;
    }
}
