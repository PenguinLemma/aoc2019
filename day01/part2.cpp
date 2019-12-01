#include <iostream>
#include <iterator>
#include <numeric>

int ComputeFuelForUnit(int mass)
{
    if (mass < 7)
        return 0;
    int fuel = mass / 3 - 2;
    return fuel + ComputeFuelForUnit(fuel);
}

int main()
{
    std::cout << std::accumulate(
                     std::istream_iterator<int>(std::cin),
                     std::istream_iterator<int>(),
                     0,
                     [](int fuel, int mass) { return fuel += ComputeFuelForUnit(mass); })
              << std::endl;
}
