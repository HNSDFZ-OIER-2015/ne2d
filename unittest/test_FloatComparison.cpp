//
// Copyright 2015 riteme
//

#include "test.hpp"

#include "../src/utility/FloatComparison.hpp"

using namespace std;
using namespace ne;
using namespace ne::utility;

TESTCASE_GROUP_BEGIN

TESTCASE("Function IsSame() test") {
    CHECK(IsSame(1.0, 1.0));
    CHECK(IsSame(3.0 / 2.0, 6.0 / 4.0));
    CHECK(IsSame(5.0 / 4.0, 15.0 / 12.0));
    CHECK(IsSame(7.0 / 2.0, 0.35 * 10.0));
    CHECK(IsSame(233.333, 233 + 0.333));
    CHECK(IsSame(100000.0, 0.01 * 10000000.0));
    CHECK(IsSame(10.0 / 9.0, 8.0 / 7.0) == false);
    CHECK(IsSame(1.2 * 3.0, 1.3 * 2.0) == false);
    CHECK(IsSame(-1.0, 1.0) == false);
    CHECK(IsSame(-1.0, -1.0));
    CHECK(IsSame(-1.0, -2.0) == false);
    CHECK(IsSame(-2.0001, -2.001) == false);
    CHECK(IsSame(-2.011, -2) == false);
    CHECK(IsSame(3.45, 3.44) == false);
    CHECK(IsSame(3.001, 3.001));
    CHECK(IsSame(3.00000000000001, 3));
    CHECK(IsSame(2.0001, 2) == false);
}
TESTCASE_END

TESTCASE("Function IsGreater() test") {
    CHECK(IsGreater(2.0, 1.0));
    CHECK(IsGreater(1.0, 2.0) == false);
    CHECK(IsGreater(1.0, 1.0) == false);
}
TESTCASE_END

TESTCASE("Function IsLess() test") {
    CHECK(IsLess(2.0, 1.0) == false);
    CHECK(IsLess(1.0, 2.0));
    CHECK(IsLess(1.0, 1.0) == false);
}
TESTCASE_END

TESTCASE("Function IsGreaterEqual() test") {
    CHECK(IsGreaterEqual(2.0, 1.0));
    CHECK(IsGreaterEqual(1.0, 2.0) == false);
    CHECK(IsGreaterEqual(1.0, 1.0) == true);
}
TESTCASE_END

TESTCASE("Function IsLessEqual() test") {
    CHECK(IsLessEqual(2.0, 1.0) == false);
    CHECK(IsLessEqual(1.0, 2.0));
    CHECK(IsLessEqual(1.0, 1.0) == true);
}
TESTCASE_END

TESTCASE_GROUP_END

int main(/*int argc, char *argv[]*/) {
    RUN(true);

    return 0;
}  // function main
