#include <iostream>
#include <numeric>
#include <vector>

struct Point
{
    Point(int a, int b) : x{a}, y{b} {}
    int x;
    int y;
};

Point Move(Point start, char direction, int distance)
{
    switch (direction) {
        case 'R':
            return Point(start.x + distance, start.y);
        case 'L':
            return Point(start.x - distance, start.y);
        case 'U':
            return Point(start.x, start.y + distance);
        case 'D':
            return Point(start.x, start.y - distance);
        default:
            return start;
    }
}

struct Segment
{
    Segment(int dist, char dir) : distance{dist}, direction{dir} {}

    int distance;
    char direction;
};

int main()
{
    char separator;
    char direction;
    int distance;
    std::cin >> direction;
    std::cin >> distance;
    std::vector<std::vector<Segment> > wires(2, std::vector<Segment>());
    int wire_pos = 0;
    wires[wire_pos].push_back(Segment(distance,direction));
    while (std::cin >> separator) {
        if (separator != ' ') {
            ++wire_pos;
            direction = separator;
        }
        else std::cin >> direction;
        std::cin >> distance;
        wires[wire_pos].push_back(Segment(distance, direction));
    }
}
