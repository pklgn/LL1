#include "pch.h"
#include "../src/TaskTable.h"
#include "../src/LLParser.h"

TEST_CASE("SUCCESS testies")
{
	std::string expected;
	std::string actual;

	std::istringstream iss;

	TaskTable table;
	LLParser parser(iss, table);

	SECTION("Check terminal a")
	{
		iss.str("a");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal b")
	{
		iss.str("b");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal 8")
	{
		iss.str("8");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal 3")
	{
		iss.str("3");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal 3 with minus")
	{
		iss.str("-3");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal b with minus")
	{
		iss.str("-b");

		REQUIRE(parser.Parse());
	}

	SECTION("Check brackets")
	{
		iss.str("()");

		REQUIRE(parser.Parse());
	}

	SECTION("Check nested pair of brackets")
	{
		iss.str("(())");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal in brackets")
	{
		iss.str("(a)");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal with minus in brackets")
	{
		iss.str("(-a)");

		REQUIRE(parser.Parse());
	}

	SECTION("Check sum in brackets")
	{
		iss.str("(-a)+(a)");

		REQUIRE(parser.Parse());
	}

	SECTION("Check sum inside brackets")
	{
		iss.str("(-a+b)+(a)");

		REQUIRE(parser.Parse());
	}

	SECTION("Check multiplication inside brackets")
	{
		iss.str("(-a+b)+(a*b)");

		REQUIRE(parser.Parse());
	}

	SECTION("Check sum of brackets and non-brackets")
	{
		iss.str("(-a+b)+a");

		REQUIRE(parser.Parse());
	}

	SECTION("Check multiplication of brackets and non-brackets")
	{
		iss.str("a*(-a+b)");

		REQUIRE(parser.Parse());
	}

	SECTION("Check sequence of non-brackets operations")
	{
		iss.str("a*b+3*8+a");

		REQUIRE(parser.Parse());
	}

	SECTION("Check minus in a sequence of non-brackets operations")
	{
		iss.str("a*-8+a");

		REQUIRE(parser.Parse());
	}

	SECTION("Check minus before brackets")
	{
		iss.str("-(a*b+3)*-8+a");

		REQUIRE(parser.Parse());
	}

	SECTION("Check nested brackets in binary operation")
	{
		iss.str("-((((a))))*-8+a");

		REQUIRE(parser.Parse());
	}
}