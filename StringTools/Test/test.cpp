#define CATCH_CONFIG_MAIN
#include "Catch2.h"

int Add(int a, int b)
{
    return a+b;
}

TEST_CASE("Add works with zeroes", "[add]")
{
    REQUIRE(Add(0, 0) == 0);
    REQUIRE(Add(5, 0) == 5);
    REQUIRE(Add(0, 5) == 5);
}

TEST_CASE("Add works with negatives", "[add]")
{
    REQUIRE(Add(-5, 0) == -5);
    REQUIRE(Add(0, -5) == -5);
    REQUIRE(Add(-5, -5) == -10);
}
