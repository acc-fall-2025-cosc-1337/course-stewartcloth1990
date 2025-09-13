#include <catch2/catch.hpp>
#include "data_types.h"

TEST_CASE("multiply_numbers returns correct product for positive integers") {
	REQUIRE(multiply_numbers(2, 3) == 6);
	REQUIRE(multiply_numbers(7, 8) == 56);
}

TEST_CASE("multiply_numbers returns correct product for negative and positive integers") {
	REQUIRE(multiply_numbers(-1, 5) == -5);
	REQUIRE(multiply_numbers(4, -3) == -12);
}

TEST_CASE("multiply_numbers returns correct product for zero") {
	REQUIRE(multiply_numbers(0, 10) == 0);
	REQUIRE(multiply_numbers(0, 0) == 0);
	REQUIRE(multiply_numbers(5, 0) == 0);
}

TEST_CASE("multiply_numbers returns correct product for two negative integers") {
	REQUIRE(multiply_numbers(-2, -4) == 8);
	REQUIRE(multiply_numbers(-7, -3) == 21);
}