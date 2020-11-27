#include <iostream>
#include <memory>
#include <string>
using namespace std;

#include "event.hpp"
#include "foo.hpp"

int main() {
    std::unique_ptr< FooFoo > foo( new FooFoo( 1 ) );
    cout << foo->getNo() << '\n';
    foo = std::make_unique< FooFoo >( 2 );
    cout << ( *foo ).getNo() << '\n';
    // cout << *foo.getNo() << '\n'; // error, cheeck operator precedence

    if ( foo ) {
        cout << "Foo object exists, it holds no. " << ( *foo ).getNo() << '\n';
    }
    foo.reset();
    
    if ( !foo ) {
        cout << "There is no Foo object." << '\n';
    }

    cout << "Main function ends here." << '\n';
    return 0;
}
