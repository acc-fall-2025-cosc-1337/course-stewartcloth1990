#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "hwexpressions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify sum_numbers function") 
{
	REQUIRE(add_numbers(5, 5) == 10);
	REQUIRE(add_numbers(10, 10) == 20);
}


TEST_CASE("Test get_sales_tax_amount") {
    REQUIRE(get_sales_tax_amount(20.0) == Approx(1.35).epsilon(0.001));
    REQUIRE(get_sales_tax_amount(50.0) == Approx(3.375).epsilon(0.001));
}

TEST_CASE("Test get_tip_amount") {
    REQUIRE(get_tip_amount(20.0, 0.15) == Approx(3.0).epsilon(0.001));
    REQUIRE(get_tip_amount(50.0, 0.20) == Approx(10.0).epsilon(0.001));

}