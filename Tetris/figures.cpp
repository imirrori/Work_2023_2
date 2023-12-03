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
