#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "do_while.h"


TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("divide_bill_amount returns correct division for positive numbers") {
	REQUIRE(divide_bill_amount(100.0) == Approx(25.0));
	REQUIRE(divide_bill_amount(75.0) == Approx(18.75));
}

TEST_CASE("divide_bill_amount returns correct division for zero") {
	REQUIRE(divide_bill_amount(0.0) == Approx(0.0));
}

TEST_CASE("divide_bill_amount returns correct division for negative numbers") {
	REQUIRE(divide_bill_amount(-20.0) == Approx(-5.0));
}