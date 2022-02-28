#pragma once

namespace json_conversion
{


template<class T>
struct Optional
{
	Optional(T t)
	: value(t)
	, valid_(true)
	{}

	Optional()
	: valid_(false)
	{}

	operator bool()const
	{
		return valid_;
	}

	T value;

private:
	bool valid_;
};


} //namespace json_conversion
