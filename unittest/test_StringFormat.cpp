//
// Copyright 2015 riteme
//

#include "../src/StringFormat.hpp"

#include <cassert>
#include <iostream>

using namespace std;
using namespace ne;

int main(/*int argc, char *argv[]*/) {
    assert(Format("Hello, world!") == "Hello, world!");
    assert(Format("{0}", "Apple") == "Apple");
    assert(Format("{}{}{}{}{}", "0", "1", 2, 3, 4.0) == "01234");
    assert(Format("{:.4f}", 2.333333333) == "2.3333");
    assert(Format("Hello, {0}! Do you like {1}?", "Yang Yue", "qiaozhanrong") ==
           "Hello, Yang Yue! Do you like qiaozhanrong?");
    assert(Format("We're {}!!!", "FFF") == "We're FFF!!!");
    assert(Format("{:>10}", "ALIGN") == "     ALIGN");
    assert(Format("{:=^20}", "CENTERED") == "======CENTERED======");

    cout << "PASSED" << endl;

    return 0;
}  // function main