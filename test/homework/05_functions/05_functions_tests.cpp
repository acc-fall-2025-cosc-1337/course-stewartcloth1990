#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "func.h"

TEST_CASE("Verify Test Configuration", "verification")
{
	REQUIRE(true == true);
}

TEST_CASE("get_gc_content returns correct GC content for various DNA strings")
{
	REQUIRE(get_gc_content("AGCTATAG") == Approx(0.375));
	REQUIRE(get_gc_content("CGCTATAG") == Approx(0.50));
}

TEST_CASE("get_dna_complement returns correct DNA complement for various strings")
{
	REQUIRE(get_dna_complement("AAAACCCGGT") == "ACCGGGTTTT");
	REQUIRE(get_dna_complement("CCCGGAAAAT") == "ATTTTCCGGG");
}

TEST_CASE("reverse_string returns the reversed DNA string")
{
	REQUIRE(get_reverse_string("AGCTATAG") == "GATATCGA");
	REQUIRE(get_reverse_string("CGCTATAG") == "GATATCGC");
}