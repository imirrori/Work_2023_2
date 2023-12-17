#ifndef FIELD_H
#define FIELD_H

#include "figures.h"

struct Field
{
    static constexpr int Width = 18;
    static constexpr int Height = 22;

    bool data[Height][Width] = {};
};

bool CheckField(const Field* field, CurrentFigure figure);
void AddField(Field* field, CurrentFigure figure);
int CleanField(Field* field, CurrentFigure figure);

#endif // FIELD_H
