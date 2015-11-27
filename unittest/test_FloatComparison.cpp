//
// Copyright 2015 riteme
//

#include "../src/FloatComparison.hpp"

#include <cassert>
#include <iostream>

using namespace std;
using namespace ne;

int main(/*int argc, char *argv[]*/) {
    assert(IsSame(1.0, 1.0));
    assert(IsSame(3.0 / 2.0, 6.0 / 4.0));
    assert(IsSame(5.0 / 4.0, 15.0 / 12.0));
    assert(IsSame(7.0 / 2.0, 0.35 * 10.0));
    assert(IsSame(233.333, 233 + 0.333));
    assert(IsSame(100000.0, 0.01 * 10000000.0));
    assert(IsSame(10.0 / 9.0, 8.0 / 7.0) == false);
    assert(IsSame(1.2 * 3.0, 1.3 * 2.0) == false);

    assert(IsGreater(2.0, 1.0));
    assert(IsGreater(1.0, 2.0) == false);
    assert(IsGreater(1.0, 1.0) == false);

    assert(IsLess(2.0, 1.0) == false);
    assert(IsLess(1.0, 2.0));
    assert(IsLess(1.0, 1.0) == false);

    assert(IsGreaterEqual(2.0, 1.0));
    assert(IsGreaterEqual(1.0, 2.0) == false);
    assert(IsGreaterEqual(1.0, 1.0) == true);

    assert(IsLessEqual(2.0, 1.0) == false);
    assert(IsLessEqual(1.0, 2.0));
    assert(IsLessEqual(1.0, 1.0) == true);

    return 0;
}  // function main
