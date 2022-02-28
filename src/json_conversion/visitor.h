#pragma once
#include <json_conversion/optional.h>
#include <utility>
#include <tuple>

namespace json_conversion
{


template<class... Args>
auto make_forwarding_reference_tuple( void( * )( Args... ) )
-> std::tuple<Args...>;


template<class C, class... Args>
auto make_forwarding_reference_tuple( void( C::* )( Args... ) )
-> std::tuple<Args...>;


template<class C, class... Args>
auto make_forwarding_reference_tuple( void( C::* )( Args... ) const )
-> std::tuple<Args...>;


template<class C, class... Args>
auto make_forwarding_reference_tuple( void( C::* )( Args... ) volatile )
-> std::tuple<Args...>;


template<class C, class... Args>
auto make_forwarding_reference_tuple( void( C::* )( Args... ) const volatile )
-> std::tuple<Args...>;


template<class R>
auto make_forwarding_reference_tuple( R )
-> decltype( make_forwarding_reference_tuple(
	&std::remove_pointer_t<R>::operator() ) );


template<class Func, class ... Args>
void call_with_tuple(Func f, std::tuple<Args...> const& args)
{
	f(std::get<Args>(args)...);
}


template<class, class, class>
struct CallWrapper;


template<class Input, class Func, class ... Args>
struct CallWrapper<Input, Func, std::tuple<Args ...>>
{
	void operator()(bool & run, Input & input, Func func)
	{
		if(not run)
		{
			return;
		}

		std::tuple<Args...> args;
		auto result = extract(input, std::get<Args...>(args));
		if(result)
		{
			call_with_tuple(func, args);
			input = result.value;
			run = false;
		}
	}
};


template<class Input, class ...Funcs>
void visit(Input & input, Funcs ... funcs)
{
	bool run = true;
	(CallWrapper<
		Input,
		Funcs,
		decltype( make_forwarding_reference_tuple( funcs ))>{}(
			run, input, funcs), ... );
}


} //namespace json_conversion
