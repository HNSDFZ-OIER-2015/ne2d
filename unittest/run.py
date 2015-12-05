#!/usr/bin/env python3

#
# Copyright 2015 riteme
#

import os
import os.path
import re

COMPILER = 'clang++ -std=c++11 -O2'
RUN_COMMAND = './test.out'
REGEX_PATTERN = 'test_.*\.cpp'

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
        print('(error) Compilation failed! Compiler returned {}'.format(result))
        return False

def run_test(filename):
    if not compile_test(filename):
        print('(error) Cannot run the test.')
        return False
    else:
        print('(info) Running {}...'.format(filename))

        result = os.system(RUN_COMMAND)

        if result == 0:
            print('(info) [PASS] {}'.format(filename))
            return True
        else:
            print('(error) [FAIL] {}'.format(filename))
            return False

# Main
if __name__ != '__main__':
    print('(warn) This program may run in a uncorrect situation.')

print('(info) Running all the tests...')

status = 0
count = 0
passed_count = 0
failed_count = 0
unpassed = []

for filename in os.listdir():
    if not match_test(filename):
        continue  # Not a unittest.

    count += 1

    if not run_test(filename):
        print('(error) Test of {} has not passed.'.format(filename))
        status = -1
        failed_count += 1
        unpassed.append(filename)
    else:
        passed_count += 1
            
print('(info) Unittest Report:')
print('\tTested {} unittests.'.format(count))
print('\t{} passed, {} failed.'.format(passed_count, failed_count))
print('\tPassed Ratio: {}%'.format((float(passed_count) / float(count)) * 100.0))

if len(unpassed) != 0:
    print('\tUnpassed: \n\t\t{}'.format(',\n\t\t'.join(unpassed)))

print('(info) Program exited.')
exit(status)
