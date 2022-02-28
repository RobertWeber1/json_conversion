#include <catch2/catch_test_macros.hpp>
#include <json_conversion/visitor.h>



struct Stream
{
	int modified = 0;
};

json_conversion::Optional<Stream> extract(Stream /*stream*/, int &)
{
	return {};
}

json_conversion::Optional<Stream> extract(Stream /*stream*/, float &)
{
	return Stream{2};
}

json_conversion::Optional<Stream> extract(Stream /*stream*/, bool &)
{
	return {};
}

TEST_CASE("visut")
{
	Stream stream;
	json_conversion::visit(
		stream,
		[](int){/*puts("int");*/},
		[](float){/*puts("float");*/},
		[](bool){/*puts("bool");*/});

	REQUIRE(stream.modified == 2);
}

