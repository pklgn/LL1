#include "pch.h"
#include "../src/TaskTable.h"
#include "../src/LLParser.h"

TEST_CASE("SUCCESS testies")
{
	std::istringstream iss;

	TaskTable table;
	LLParser parser(iss, table);

	SECTION("Check terminal a")
	{
		iss.str("a\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal b")
	{
		iss.str("b\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal 8")
	{
		iss.str("8\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal 3")
	{
		iss.str("3\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal 3 with minus")
	{
		iss.str("-3\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal b with minus")
	{
		iss.str("-b\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check brackets")
	{
		iss.str("()\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check nested pair of brackets")
	{
		iss.str("(())\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal in brackets")
	{
		iss.str("(a)\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check terminal with minus in brackets")
	{
		iss.str("(-a)\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check sum in brackets")
	{
		iss.str("(-a)+(a)\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check sum inside brackets")
	{
		iss.str("(-a+b)+(a)\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check multiplication inside brackets")
	{
		iss.str("(-a+b)+(a*b)\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check sum of brackets and non-brackets")
	{
		iss.str("(-a+b)+a\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check multiplication of brackets and non-brackets")
	{
		iss.str("a*(-a+b)\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check sequence of non-brackets operations")
	{
		iss.str("a*b+3*8+a\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check minus in a sequence of non-brackets operations")
	{
		iss.str("a*-8+a\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check minus before brackets")
	{
		iss.str("-(a*b+3)*-8+a\n");

		REQUIRE(parser.Parse());
	}

	SECTION("Check nested brackets in binary operation")
	{
		iss.str("-((((a))))*-8+a\n");

		REQUIRE(parser.Parse());
	}
}

TEST_CASE("Error tests")
{
	std::istringstream iss;

	TaskTable table;
	LLParser parser(iss, table);

	SECTION("Unbalanced brackets sequences")
	{
		std::vector<std::string> unbalancedSequences = {
			"(\n",
			")\n",
			"(()\n",
			"())\n",
			"(b\n",
			"b)\n",
		};
		
		for (auto&& sequence : unbalancedSequences)
		{
			iss.str(std::string());
			DYNAMIC_SECTION("Concrete sequence: " << sequence)
			{
				iss.str(sequence);

				REQUIRE_FALSE(parser.Parse());
			}
		}
	}

	SECTION("Incorrect combination of params")
	{
		std::unordered_map<std::string, size_t> combinations = {
			{ "b*bb\n", 3 },
			{ "()()\n", 2 },
			{ "((a*))8\n", 4 }, // FIXED: ошибка в позиции 6, хотя вроде логичнее сразу после * ее получать?
			{ "88*3\n", 1 },
			{ "*b\n", 0 },
			{ "8*\n", 2 }, // FIXED: тест не должен падать
		};

		for (auto&& [combination, errorPos] : combinations)
		{
			iss.str(std::string());
			DYNAMIC_SECTION("Concrete combination: " << combination)
			{
				iss.str(combination);

				REQUIRE_FALSE(parser.Parse());
				REQUIRE(parser.GetTapePosition() == errorPos);
			}
		}
	}
}