#
# Copyright 2015 riteme
#

DEBUG_OUTPUT = True
COMPILER = 'g++ -std=c++11 -O0 -g -isystem /usr/include/ne2d/'
RUN_COMMAND = './test.out'
REGEX_PATTERN = 'test_.*\.cpp'

ATTACH_LIBRARY = ['ne2d']

ATTACH_SOURCE = {}
# ATTACH_SOURCE = {
#     'test_Vector2D.cpp': [
#         '../src/math/Vector2D.cpp'
#     ],
#     'test_Rectangle.cpp': [
#         '../src/math/Rectangle.cpp',
#         '../src/math/Vector2D.cpp'
#     ],
#     'test_Matrix3.cpp': [
#         '../src/math/Matrix3.cpp',
#         '../src/math/Vector2D.cpp'
#     ],
#     'test_Math.cpp': [
#         '../src/math/Math.cpp',
#         '../src/math/Vector2D.cpp',
#         '../src/math/Rectangle.cpp',
#         '../src/math/Matrix3.cpp'
#     ]
# }
