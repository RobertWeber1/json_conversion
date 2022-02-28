#include <catch2/catch_test_macros.hpp>
#include <json_conversion/input.h>
#include <json_conversion/visitor.h>

TEST_CASE("bool")
{
	SECTION("true")
	{
		bool result = false;
		json_conversion::InputStream stream("true");
		json_conversion::visit(stream, [&result](bool val){ result = val; });

		REQUIRE(result == true);
		REQUIRE(stream.begin() == stream.end());
	}

	SECTION("false")
	{
		bool result = true;
		json_conversion::InputStream stream("false");
		json_conversion::visit(stream, [&result](bool val){ result = val; });

		REQUIRE(result == false);
		REQUIRE(stream.begin() == stream.end());
	}
}

TEST_CASE("int8_t")
{
	SECTION("int8_t = 0")
	{
		int8_t result = 1;
		json_conversion::InputStream stream("0");
		json_conversion::visit(stream, [&result](int8_t val){ result = val; });

		REQUIRE(result == 0);
		REQUIRE(stream.begin() == stream.end());
	}
}
