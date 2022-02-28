#pragma once
#include <json_conversion/optional.h>
#include <json_conversion/stream.h>
#include <json_conversion/string_view.h>
#include <stdint.h>


namespace json_conversion
{



Optional<InputStream> extract(InputStream stream, bool & result)
{
	if(stream.begin() == std::string("true"))
	{
		result = true;
		return InputStream(stream.begin()+4, stream.end());
	}
	else if(stream.begin() == std::string("false"))
	{
		result = false;
		return InputStream(stream.begin()+5, stream.end());
	}
    return {};
}


Optional<InputStream> extract(InputStream stream, int8_t & result)
{
	result = atoi(stream.begin());
    return {};
}


Optional<InputStream> extract(InputStream /*stream*/, int16_t &)
{
    return {};
}


Optional<InputStream> extract(InputStream /*stream*/, int32_t &)
{
    return {};
}


Optional<InputStream> extract(InputStream /*stream*/, int64_t &)
{
    return {};
}


Optional<InputStream> extract(InputStream /*stream*/, uint8_t &)
{
    return {};
}


Optional<InputStream> extract(InputStream /*stream*/, uint16_t &)
{
    return {};
}


Optional<InputStream> extract(InputStream /*stream*/, uint32_t &)
{
    return {};
}


Optional<InputStream> extract(InputStream /*stream*/, uint64_t &)
{
    return {};
}


Optional<InputStream> extract(InputStream /*stream*/, float &)
{
    return {};
}


Optional<InputStream> extract(InputStream /*stream*/, double &)
{
    return {};
}


Optional<InputStream> extract(InputStream /*stream*/, StringView &)
{
    return {};
}


} //namespace json_conversion
