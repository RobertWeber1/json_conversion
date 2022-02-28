#pragma once
#include <string>

namespace json_conversion
{


struct StringView
{
	StringView(std::string const& data)
	: begin_(data.data())
	, end_(data.data() + data.size())
	{}

	StringView(char const* data)
	: begin_(data)
	, end_(data + strlen(data))
	{}

	StringView(char const* data, size_t size)
	: begin_(data)
	, end_(data + size)
	{}

	template<size_t N>
	StringView(char const (&data)[N])
	: begin_(data)
	, end_(data + N - 1)
	{}

	char const* begin_;
	char const* end_;
};


} //namespace json_conversion
