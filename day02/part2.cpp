#include <iostream>
#include <numeric>
#include <vector>

std::size_t Execute(std::vector<std::size_t> intcode, std::size_t noun, std::size_t verb)
{
    intcode[1] = noun;
    intcode[2] = verb;
    for (std::size_t pos_opcode = 0; pos_opcode < intcode.size() && intcode[pos_opcode] != 99;
         pos_opcode += 4) {
        std::size_t const first_operand = intcode[intcode[pos_opcode + 1]];
        std::size_t const second_operand = intcode[intcode[pos_opcode + 2]];

        intcode[intcode[pos_opcode + 3]] = intcode[pos_opcode] == 1
                                               ? first_operand + second_operand
                                               : first_operand * second_operand;
    }
    return intcode[0];
}

void Write(std::vector<std::size_t>& intcode)
{
    for (std::size_t i = 0; i < intcode.size(); ++i) {
        std::cout << intcode[i] << " ";
    }
    std::cout << std::endl;
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
        for (std::size_t noun = 0; noun < 100; ++noun) {
            for (std::size_t verb = 0; verb < 100; ++verb) {
                std::size_t result = Execute(intcode, noun, verb);
                if (result == 19690720) {
                    std::cout << 100 * noun + verb << std::endl;
                    break;
                }
            }
        }
    }
}
