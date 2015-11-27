#!/usr/bin/env python3

#
# Copyright 2015 riteme
#

import os
import os.path
import re

COMPILER = 'clang++ -std=c++11 -stdlib=libc++ -O2 -g'
RUN_COMMAND = './test.out'
REGEX_PATTERN = 'test_'

def match_test(filename):
    result = re.match(REGEX_PATTERN, filename)
    return result != None

def compile_test(filename):
    print('(info) Compiling {}...'.format(filename))

    result = os.system('{0} {1} -o {2}'.format(COMPILER, filename,RUN_COMMAND))

    if result == 0:
        # print('(info) Compilation succeeded.')
        return True
    else:
        print('(error) Compilation failed! Compiler returned {}', result)
        return False

def run_test(filename):
    print('(info) Running {}...'.format(filename))

    if not compile_test(filename):
        print('(error) Cannot run the test.')
        return False
    else:
        result = os.system(RUN_COMMAND)

        if result == 0:
            print('(info) {}: **PASSED**!'.format(filename))
            return True
        else:
            print('(error) {}: **FAILED**.'.format(filename))
            return False

if __name__ != '__main__':
    print('(warn) This program may run in a uncorrect situation.')

print('(info) Running all the tests...')

for filename in os.listdir():
    if not match_test(filename):
        continue  # Not a unittest.

    if not run_test(filename):
        print('(fatal) Test of {} has not passed.'.format(filename))
            

print('(info) Program exited.')
