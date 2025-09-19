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


//test case for get_sales_tax_amount
TEST_CASE("get_sales_tax_amount returns correct tax for positive amounts") {
	REQUIRE(get_sales_tax_amount(100.0) == Approx(6.75).epsilon(0.01));
	REQUIRE(get_sales_tax_amount(50.0) == Approx(3.375).epsilon(0.01));
}

TEST_CASE("get_sales_tax_amount returns zero for zero amount") {
	REQUIRE(get_sales_tax_amount(0.0) == Approx(0.0));
}

TEST_CASE("get_sales_tax_amount returns correct tax for decimal amounts") {
	REQUIRE(get_sales_tax_amount(12.34) == Approx(0.83295).epsilon(0.01));
}

TEST_CASE("get_sales_tax_amount returns negative tax for negative amounts") {
	REQUIRE(get_sales_tax_amount(-20.0) == Approx(-1.35).epsilon(0.01));
}

//test case for get_tip_amount
TEST_CASE("get_tip_amount returns correct tip for positive amounts and rates") {
	REQUIRE(get_tip_amount(100.0, 0.15) == Approx(15.0).epsilon(0.01));
	REQUIRE(get_tip_amount(50.0, 0.20) == Approx(10.0).epsilon(0.01));
	REQUIRE(get_tip_amount(80.0, 0.10) == Approx(8.0).epsilon(0.01));
}

TEST_CASE("get_tip_amount returns zero for zero amount or zero rate") {
	REQUIRE(get_tip_amount(0.0, 0.15) == Approx(0.0));
	REQUIRE(get_tip_amount(100.0, 0.0) == Approx(0.0));
	REQUIRE(get_tip_amount(0.0, 0.0) == Approx(0.0));
}

TEST_CASE("get_tip_amount returns correct tip for decimal amounts and rates") {
	REQUIRE(get_tip_amount(12.34, 0.18) == Approx(2.2212).epsilon(0.01));
	REQUIRE(get_tip_amount(45.67, 0.22) == Approx(10.0474).epsilon(0.01));
}

TEST_CASE("get_tip_amount returns negative tip for negative amounts or rates") {
	REQUIRE(get_tip_amount(-50.0, 0.15) == Approx(-7.5).epsilon(0.01));
	REQUIRE(get_tip_amount(50.0, -0.15) == Approx(-7.5).epsilon(0.01));
	REQUIRE(get_tip_amount(-50.0, -0.15) == Approx(7.5).epsilon(0.01));
}