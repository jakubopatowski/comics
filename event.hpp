#pragma once

#include <functional>
#include <list>

template < typename T >
class Event {
  public:
    using Handler = std::function< T >;

    template < typename... Arg >
    void operator()( Arg... arg ) {
        for ( auto& item : _handlers ) {
            item( arg... );
        }
    }

    Event< T >& operator+=( const Handler& handler ) {
        _handlers.emplace_back( handler );
        return *this;
    }

    Event< T >& operator+=( Handler&& handler ){
	_handlers.emplace_back( handler );
	return *this;
    }

  private:
    std::list< Handler > _handlers;
};
