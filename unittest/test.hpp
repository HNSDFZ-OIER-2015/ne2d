//
// Copyright 2015 riteme
//

#ifndef NE2D_TEST_HPP_
#define NE2D_TEST_HPP_

#include <cassert>

#include <vector>
#include <iostream>
#include <functional>

typedef std::function<void(void)> FunctionType;

struct Testcase {
    Testcase(const std::string &_name, const FunctionType &_func)
            : name(_name), function(_func) {}

    std::string name;
    FunctionType function;
};  // struct Test

extern std::vector<Testcase> tests;
std::vector<Testcase> tests;

void initialize();

#define COLOR_NONE "\033[0m"
#define COLOR_GREEN "\033[34m"

#define TESTCASE_GROUP_BEGIN void initialize() {
#define TESTCASE_GROUP_END }

#define TESTCASE(name) tests.push_back({ (name), []() -> void {
#define TESTCASE_END \
    }                \
    });

#define RUN(output)                                                      \
    initialize();                                                        \
    for (auto &t : tests) {                                              \
        if ((output))                                                    \
            cout << COLOR_GREEN << "(unittest) " << COLOR_NONE << t.name \
                 << endl;                                                \
        t.function();                                                    \
    }

#endif  // NE2D_TEST_HPP_
