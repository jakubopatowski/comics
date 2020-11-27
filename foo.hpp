#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "event.hpp"

class FooFoo {
  public:
    enum class LogType { Error, Warning, Info, Debug, Details };
    using Log = Event< void( const LogType&, const std::string& ) >;
    Log log;

    FooFoo( int no ) : _no( no ) {
        log( LogType::Debug,
             "Invoked Foo-" + to_string( _no ) + " constuctor." );
        cout << "Invoked Foo-" << _no << " constructor.\n";
    };

    virtual ~FooFoo() {
        log( LogType::Debug,
             "Invoked Foo-" + to_string( _no ) + " destructor." );
        cout << "Invoked Foo-" << _no << " desctructor.\n";
    };

    string getNo() const {
        return "Foo-" + to_string( _no );
    }; // ToDo:: how to return rvalue reference

  private:
    int _no;
};
