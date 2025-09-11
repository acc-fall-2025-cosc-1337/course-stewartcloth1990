#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "data_types.h"
TEST_CASE("Test multiply_numbers function") {
	REQUIRE(multiply_numbers(2, 3) == 6);
	REQUIRE(multiply_numbers(-1, 5) == -5);
	REQUIRE(multiply_numbers(0, 10) == 0);
	REQUIRE(multiply_numbers(-2, -4) == 8);
}