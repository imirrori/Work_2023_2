#include "figures.h"

Figure Rotate(Figure figure)
{
    Figure result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.values[j][3 - i] = figure.values[i][j];
        }
    }
    return result;
}

int FindLeft(Figure figure)
{
    int min = 4;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (figure.values[i][j]) {
                min = std::min(min, j);
            }
        }
    }
    return min;
}

int FindRight(Figure figure)
{
    int max = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (figure.values[i][j]) {
                max = std::max(max, j);
            }
        }
    }
    return max;
}

