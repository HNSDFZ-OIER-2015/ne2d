//
// Copyright 2015 riteme
//

#include "test.hpp"

#include "../src/utility/StringFormat.hpp"

using namespace std;
using namespace ne;
using namespace ne::utility;

TESTCASE_GROUP_BEGIN

TESTCASE("StringFormat test") {
    CHECK(Format("Hello, world!") == "Hello, world!");
    CHECK(Format("{0}", "Apple") == "Apple");
    CHECK(Format("{}{}{}{}{}", "0", "1", 2, 3, 4.0) == "01234");
    CHECK(Format("{:.4f}", 2.333333333) == "2.3333");
    CHECK(Format("Hello, {0}! Do you like {1}?", "Yang Yue", "qiaozhanrong") ==
          "Hello, Yang Yue! Do you like qiaozhanrong?");
    CHECK(Format("We're {}!!!", "FFF") == "We're FFF!!!");
    CHECK(Format("{:>10}", "ALIGN") == "     ALIGN");
    CHECK(Format("{:=^20}", "CENTERED") == "======CENTERED======");
}
TESTCASE_END

TESTCASE_GROUP_END

int main(/*int argc, char *argv[]*/) {
    RUN(true);

    return 0;
}  // function main
