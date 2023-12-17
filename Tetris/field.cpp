#include "field.h"

bool CheckField(const Field* field, CurrentFigure figure)
{
    for(int i = 0; i < 4; ++i) {
        int max = -1;
        for(int j = 0; j < 4; ++j) {
            if(figure.data.values[i][j]) {
                max = std::max(max, j);
            }
        }
        if (field->data[figure.y + max + 1][figure.x + i] ||
            figure.y + max >= field->Height - 1)
        {
            return true;
        }
    }
    return false;
}

void AddField(Field* , CurrentFigure )
{

}

int CleanField(Field* , CurrentFigure )
{
    return 0;
}
