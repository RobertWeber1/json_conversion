#pragma once
#include <string>

namespace json_conversion
{


struct ParseError
{
	enum Type{
		UnexpectedType,
		UnexpectedEndOfInput
	} type;
	size_t error_position;
};

template<class T>
struct Result
{
	Result(T const& value)
	: value_(value)
	, valid_(true)
	{}

	Result(ParseError::Type error, size_t pos)
	: value_({error, pos})
	, valid_(false)
	{}

	operator bool() const
	{
		return valid_;
	}

	T const& get_value() const
	{
		return value_.good;
	}

	ParseError const& get_error() const
	{
		return value_.bad;
	}

private:
	union Value
    {
		T good;
		ParseError bad;

        Value(T const& t)
        : good(t)
        {}

        Value(ParseError const& e)
        : bad(e)
        {}
	}value_;
	bool valid_;
};


} //namespace json_conversion
