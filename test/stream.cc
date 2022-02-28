#include <catch2/catch_test_macros.hpp>
#include <json_conversion/stream.h>

TEST_CASE("input stream")
{
	SECTION("const char[]")
	{
		char data[] = "false";
		json_conversion::InputStream s(data);
		REQUIRE(*s.begin() == 'f');
		REQUIRE(s.size() == 5);
	}

	SECTION("const char*")
	{
		char data[] = "false";
		char * data_p = data;
		json_conversion::InputStream s(data_p);

		REQUIRE(*s.begin() == 'f');
		REQUIRE(s.size() == 5);
	}

	SECTION("const char* and size")
	{
		char data[] = "false";
		char * data_p = data;
		json_conversion::InputStream s(data_p, 5);

		REQUIRE(*s.begin() == 'f');
		REQUIRE(s.size() == 5);
	}

	SECTION("std::string")
	{
		std::string data("false");
		json_conversion::InputStream s(data);

		REQUIRE(*s.begin() == 'f');
		REQUIRE(s.size() == 5);
	}

	SECTION("std::array")
	{
		std::array<char, 5> data({'f','a','l','s','e'});
		json_conversion::InputStream s(data);

		REQUIRE(*s.begin() == 'f');
		REQUIRE(s.size() == 5);
	}

	SECTION("std::vector")
	{
		std::vector<char> data{'f','a','l','s','e'};
		json_conversion::InputStream s(data);

		REQUIRE(s.size() == 5);
		REQUIRE(*s.begin() == 'f');
	}

	SECTION("copy ctor")
	{
		json_conversion::InputStream s0("false");
		json_conversion::InputStream s1(s0);

		REQUIRE(s1.size() == 5);
		REQUIRE(*s1.begin() == 'f');
	}
}
