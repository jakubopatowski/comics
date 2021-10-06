#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "issueInfo.hpp"

TEST_CASE( "Testing catch" ) { 
    IssueInfo issueInfo;
    issueInfo.setId( 1 );
    auto id = issueInfo.getId();
}
