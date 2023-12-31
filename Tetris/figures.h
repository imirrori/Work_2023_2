#ifndef FIGURES_H
#define FIGURES_H

#include <array>

enum FIGURE_TYPE
{
    NONE = -1,
    SQUERE,
    LINE,
    Z,
    F,
    //--------
    COUNT
};

struct Figure
{
    std::array<std::array<int, 4>, 4> values;
};

constexpr Figure Figures[COUNT] = {
    Figure{ .values = {
        std::array<int, 4>{0, 0, 0, 0},
        std::array<int, 4>{0, 1, 1, 0},
        std::array<int, 4>{0, 1, 1, 0},
        std::array<int, 4>{0, 0, 0, 0},
    }},
    Figure{ .values = {
        std::array<int, 4>{0, 1, 0, 0},
        std::array<int, 4>{0, 1, 0, 0},
        std::array<int, 4>{0, 1, 0, 0},
        std::array<int, 4>{0, 1, 0, 0},
    }},
    Figure{ .values = {
        std::array<int, 4>{0, 0, 0, 0},
        std::array<int, 4>{1, 1, 0, 0},
        std::array<int, 4>{0, 1, 1, 0},
        std::array<int, 4>{0, 0, 0, 0},
    }},
    Figure{ .values = {
        std::array<int, 4>{0, 0, 0, 0},
        std::array<int, 4>{0, 1, 1, 0},
        std::array<int, 4>{0, 1, 0, 0},
        std::array<int, 4>{0, 1, 0, 0},
    }},
};

struct CurrentFigure
{
    int x = 0;
    int y = 0;
    int type = NONE;
    Figure data;
};

Figure Rotate(Figure figure);

int FindLeft(Figure figure);
int FindRight(Figure figure);

#endif // FIGURES_H
