#pragma once
#include <string>
#include <array>
#include <cstring>

namespace json_conversion
{

struct InputStream
{
	InputStream() = default;

	InputStream(InputStream const& other)
	: begin_(other.begin_)
	, end_(other.end_)
	{}

	InputStream(std::string const& data)
	: begin_(data.data())
	, end_(data.data() + data.size())
	{}

	InputStream(char const* data)
	: begin_(data)
	, end_(data + strlen(data))
	{}

	InputStream(char const* data, size_t size)
	: begin_(data)
	, end_(data + size)
	{}

	template<size_t N>
	InputStream(char const (&data)[N])
	: begin_(data)
	, end_(data + N - 1)
	{}

	template<size_t N>
	InputStream(std::array<char, N> const& data)
	: begin_(&data[0])
	, end_(&data[0]+N)
	{}

	InputStream(std::vector<char> const& data)
	: begin_(&data[0])
	, end_(&data[0] + data.size())
	{}

	InputStream(char const* begin, char const* end)
	: begin_(begin)
	, end_(end)
	{}

	InputStream & operator=(InputStream const& other)
	{
		begin_ = other.begin_;
		end_ = other.end_;
		return *this;
	}

	char const* begin() const
	{
		return begin_;
	}

	char const* end() const
	{
		return end_;
	}

	size_t size() const
	{
		return end_ - begin_;
	}

private:
	char const* begin_;
	char const* end_;
};


} //json_conversion
