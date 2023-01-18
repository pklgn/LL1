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

	SECTION("Check termianl a")
	{
		iss.str("-(8)");

		REQUIRE(parser.Parse());
	}
}