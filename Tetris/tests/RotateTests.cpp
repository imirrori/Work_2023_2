#include "gtest/gtest.h"

#include "../figures.h"

TEST(RotateTests, Test1)
{
    Figure fig = {
        .values = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        }
    };

    Figure result = Rotate(fig);

    EXPECT_EQ(memcmp(fig.values, result.values, sizeof(result.values)), 0);
}

TEST(RotateTests, Test2)
{
    Figure fig1 = {
        .values = {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0}
        }
    };

    Figure fig2 = {
        .values = {
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        }
    };

    Figure fig3 = {
        .values = {
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0}
        }
    };

    Figure fig4 = {
        .values = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0}
        }
    };

    Figure result = fig1;

    result = Rotate(result);
    EXPECT_EQ(memcmp(fig2.values, result.values, sizeof(result.values)), 0);

    result = Rotate(result);
    EXPECT_EQ(memcmp(fig3.values, result.values, sizeof(result.values)), 0);

    result = Rotate(result);
    EXPECT_EQ(memcmp(fig4.values, result.values, sizeof(result.values)), 0);

    result = Rotate(result);
    EXPECT_EQ(memcmp(fig1.values, result.values, sizeof(result.values)), 0);
}

TEST(RotateTests, Test3)
{
    Figure fig1 = {
        .values = {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 1, 0, 0}
        }
    };

    Figure fig2 = {
        .values = {
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        }
    };

    Figure fig3 = {
        .values = {
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        }
    };

    Figure fig4 = {
        .values = {
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 1, 1},
            {0, 0, 0, 0}
        }
    };

    Figure result = fig1;

    result = Rotate(result);
    EXPECT_EQ(memcmp(fig2.values, result.values, sizeof(result.values)), 0);

    result = Rotate(result);
    EXPECT_EQ(memcmp(fig3.values, result.values, sizeof(result.values)), 0);

    result = Rotate(result);
    EXPECT_EQ(memcmp(fig4.values, result.values, sizeof(result.values)), 0);

    result = Rotate(result);
    EXPECT_EQ(memcmp(fig1.values, result.values, sizeof(result.values)), 0);
}
