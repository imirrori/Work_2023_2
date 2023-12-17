#include "gtest/gtest.h"

#include "../figures.h"

TEST(RotateTests, Test1)
{
    Figure fig = {
        .values = {
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 0, 0}
        }
    };

    Figure result = Rotate(fig);

    EXPECT_EQ(fig.values, result.values);
}

TEST(RotateTests, Test2)
{
    Figure fig1 = {
        .values = {
            std::array<int, 4>{0, 1, 0, 0},
            std::array<int, 4>{0, 1, 0, 0},
            std::array<int, 4>{0, 1, 0, 0},
            std::array<int, 4>{0, 1, 0, 0}
        }
    };

    Figure fig2 = {
        .values = {
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{1, 1, 1, 1},
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 0, 0}
        }
    };

    Figure fig3 = {
        .values = {
            std::array<int, 4>{0, 0, 1, 0},
            std::array<int, 4>{0, 0, 1, 0},
            std::array<int, 4>{0, 0, 1, 0},
            std::array<int, 4>{0, 0, 1, 0}
        }
    };

    Figure fig4 = {
        .values = {
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{1, 1, 1, 1},
            std::array<int, 4>{0, 0, 0, 0}
        }
    };

    Figure result = fig1;

    result = Rotate(result);
    EXPECT_EQ(fig2.values, result.values);

    result = Rotate(result);
    EXPECT_EQ(fig3.values, result.values);

    result = Rotate(result);
    EXPECT_EQ(fig4.values, result.values);

    result = Rotate(result);
    EXPECT_EQ(fig1.values, result.values);
}

TEST(RotateTests, Test3)
{
    Figure fig1 = {
        .values = {
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 1, 1, 0},
            std::array<int, 4>{0, 1, 0, 0},
            std::array<int, 4>{0, 1, 0, 0}
        }
    };

    Figure fig2 = {
        .values = {
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{1, 1, 1, 0},
            std::array<int, 4>{0, 0, 1, 0},
            std::array<int, 4>{0, 0, 0, 0}
        }
    };

    Figure fig3 = {
        .values = {
            std::array<int, 4>{0, 0, 1, 0},
            std::array<int, 4>{0, 0, 1, 0},
            std::array<int, 4>{0, 1, 1, 0},
            std::array<int, 4>{0, 0, 0, 0}
        }
    };

    Figure fig4 = {
        .values = {
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 1, 0, 0},
            std::array<int, 4>{0, 1, 1, 1},
            std::array<int, 4>{0, 0, 0, 0}
        }
    };

    Figure result = fig1;

    result = Rotate(result);
    EXPECT_EQ(fig2.values, result.values);

    result = Rotate(result);
    EXPECT_EQ(fig3.values, result.values);

    result = Rotate(result);
    EXPECT_EQ(fig4.values, result.values);

    result = Rotate(result);
    EXPECT_EQ(fig1.values, result.values);
}

TEST(LeftTests, Test1)
{
    Figure fig1 = {
        .values = {
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{1, 1, 1, 1},
            std::array<int, 4>{0, 0, 0, 0}
        }
    };
    EXPECT_EQ(FindLeft(fig1), 0);

    Figure fig2 = {
        .values = {
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 1, 1, 0},
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 0, 0}
        }
    };
    EXPECT_EQ(FindLeft(fig2), 1);

    Figure fig3 = {
        .values = {
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 1, 0},
            std::array<int, 4>{0, 0, 1, 0},
            std::array<int, 4>{0, 0, 0, 0}
        }
    };
    EXPECT_EQ(FindLeft(fig3), 2);

    Figure fig4 = {
        .values = {
            std::array<int, 4>{0, 0, 0, 1},
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 0, 1}
        }
    };
    EXPECT_EQ(FindLeft(fig4), 3);
}

TEST(RightTests, Test1)
{
    Figure fig1 = {
        .values = {
            std::array<int, 4>{1, 0, 0, 0},
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{1, 0, 0, 0}
        }
    };
    EXPECT_EQ(FindRight(fig1), 0);

    Figure fig2 = {
        .values = {
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{1, 1, 0, 0},
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 0, 0}
        }
    };
    EXPECT_EQ(FindRight(fig2), 1);

    Figure fig3 = {
        .values = {
            std::array<int, 4>{0, 0, 0, 0},
            std::array<int, 4>{0, 0, 1, 0},
            std::array<int, 4>{0, 0, 1, 0},
            std::array<int, 4>{0, 0, 0, 0}
        }
    };
    EXPECT_EQ(FindRight(fig3), 2);

    Figure fig4 = {
        .values = {
            std::array<int, 4>{1, 1, 1, 1},
            std::array<int, 4>{0, 1, 0, 0},
            std::array<int, 4>{0, 1, 0, 0},
            std::array<int, 4>{0, 0, 0, 1}
        }
    };
    EXPECT_EQ(FindRight(fig4), 3);
}
