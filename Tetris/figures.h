#ifndef FIGURES_H
#define FIGURES_H

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
    int values[4][4];
};

constexpr Figure Figures[COUNT] = {
    Figure{ .values = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    }},
    Figure{ .values = {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
    }},
    Figure{ .values = {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    }},
    Figure{ .values = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
    }},
};

Figure Rotate(Figure figure);

#endif // FIGURES_H
