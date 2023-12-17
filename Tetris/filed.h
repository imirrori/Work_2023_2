#ifndef FILED_H
#define FILED_H

struct Field
{
    static constexpr int Width = 18;
    static constexpr int Height = 22;

    bool data[Width][Height] = {};
};

#endif // FILED_H
