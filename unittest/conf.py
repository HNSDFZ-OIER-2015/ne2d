#
# Copyright 2015 riteme
#

DEBUG_OUTPUT = False
COMPILER = 'clang++ -std=c++1z -stdlib=libc++ -O0 -g -I../src/'
RUN_COMMAND = './test.out'
REGEX_PATTERN = 'test_.*\.cpp'

ATTACH_SOURCE = {
    'test_Vector2D.cpp': [
        '../src/math/Vector2D.cpp'
    ],
    'test_Rectangle.cpp': [
        '../src/math/Rectangle.cpp',
        '../src/math/Vector2D.cpp'
    ],
    'test_Matrix3.cpp': [
        '../src/math/Matrix3.cpp',
        '../src/math/Vector2D.cpp'
    ],
    'test_Math.cpp': [
        '../src/math/Math.cpp',
        '../src/math/Vector2D.cpp',
        '../src/math/Rectangle.cpp',
        '../src/math/Matrix3.cpp'
    ]
}
