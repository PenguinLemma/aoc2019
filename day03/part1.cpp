#include <iostream>
#include <numeric>
#include <tuple>
#include <unordered_map>
#include <vector>

struct Point
{
    int x;
    int y;
};

static std::unordered_map<char, int> const move_x = {{'R', 1}, {'U', 0}, {'L', -1}, {'D', 0}};
static std::unordered_map<char, int> const move_y = {{'R', 0}, {'U', 1}, {'L', 0}, {'D', -1}};

Point Move(Point start, char direction, int distance)
{
    return {start.x + move_x.at(direction) * distance, start.y + move_y.at(direction) * distance};
}

struct Segment
{
    Segment(Point o, int distance, char direction)
        : origin(o), destination(Move(o, distance, direction))
    {}

    Point origin;
    Point destination;
};

bool IsHorizontal(char direction)
{
    return direction == 'R' || direction == 'L';
}

bool IsVertical(char direction)
{
    return direction == 'U' || direction == 'D';
}

struct Wire
{
    Point AddSegmentAndGiveDestination(Point o, int distance, char direction)
    {
        if (IsHorizontal(direction)) {
            horizontal_segments.push_back(Segment(o, distance, direction));
        }
        else {
            vertical_segments.push_back(Segment(o, distance, direction));
        }
    }
    std::vector<Segment> horizontal_segments{};
    std::vector<Segment> vertical_segments{};
};

std::pair<Wire, Wire> ReadWires()
{
    char separator;
    char direction;
    int distance;
    std::cin >> direction;
    std::cin >> distance;
    std::vector<Wire> wires(2, Wire{});
    int wire_pos = 0;
    Point dest_previous_segment = wires[wire_pos].AddSegmentAndGiveDestination(Point{0, 0}, distance, direction);
    while (std::cin >> separator) {
        if (separator != ',') {
            ++wire_pos;
            direction = separator;
        }
        else
            std::cin >> direction;
        std::cin >> distance;
        dest_previous_segment = wires[wire_pos].AddSegmentAndGiveDestination(dest_previous_segment, distance, direction);
    }
    return {wires[0], wires[1]};
}

int main()
{
    Wire w1, w2;
    std::tie(w1, w2) = ReadWires();
}
