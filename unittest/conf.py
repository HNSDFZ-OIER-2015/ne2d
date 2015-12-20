#
# Copyright 2015 riteme
#

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
