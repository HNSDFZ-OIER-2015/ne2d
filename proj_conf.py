#  ==========设置部分==========
DEBUG_OUTPUT = True 
 
# 源代码和版本
SOURCES = [
    './src/*.cpp',
    './src/math/*.cpp',
    './src/raw/*.cpp'
    # './src/utility/*.cpp'
]

VERSION = '0.2.2-beta'

# 指定编译器
COMPILER = 'g++'

# 编译器设置
COMPILER_WARNINGS = [
    'everything'
]
COMPILER_IGNORE_WARNINGS = [
    # 'c++98-compat',
    # 'c++98-compat-pedantic',
    'padded',
    # 'gnu-zero-variadic-macro-arguments',
    'undef',
    'switch-enum',
    # 'global-constructors',
    # 'exit-time-destructors',
    'sign-conversion',
    'conversion',
    'deprecated'
    # 'weak-vtables'
]

COMPILER_LIBRARYS = [
    'pthread',
    'SDL2', 'SDL2_image', 'SDL2_ttf',
    'GL', 'GLEW'
]
COMPILER_LIBRARYS_DIRECTORY = [

]

COMPILER_INCLUDES_DIRECTORY = [
    './src/'
]
COMPILER_SYSTEM_INCLUDES_DIRECTORY = [

]

COMPILER_OTHER_PARAMETERS = [
    '-D __LINUX__',
    '-D __UNIX__'
    # '-D __WINDOWS__'
]

# 输出设置
# shared: 编译成动态库
# executable: 编译成可执行文件
# OUTPUT_MODE = 'shared'
OUTPUT_MODE = 'shared'
OUTPUT_LOCATION = './release/libne2d.so'
OUTPUT_WITH_VERSION = True
OUTPUT_LINK_TO_LATEST = True

# 其他设置
DEBUG_MODE = True
# 注意：
# 0 - 无优化
# 1 - O1级优化
# 2 - O2级优化
# 2.5 - Os级优化
# 3 - 最高级优化
# 其他值均视为0
# 若DEBUG_MODE为True，则也为0
OPTIMIZE_LEVEL = '2'
PREPARE_SHELL = ''
CLEANUP_SHELL = ''

# 语言设置
CXX_VERSION = 'c++11'
CXX_STDLIB = 'libstdc++'

# check.py的设置
CHECK_USE_CLANG_SYNTAX = True
CHECK_USE_CLANG_ANALYZE = True
CHECK_USE_CPPCHECK = True

CHECK_WARNINGS = [
    'everything'
]
CHECK_IGNORE_WARNINGS = [
    'c++98-compat',
    'c++98-compat-pedantic',
    'padded',
    'gnu-zero-variadic-macro-arguments',
    'undef',
    'switch-enum',
    'global-constructors',
    'exit-time-destructors',
    'sign-conversion',
    'conversion',
    'deprecated'
    # 'weak-vtables'
]

# Cppcheck设置
# --std可供设置（来自cppcheck --help）：
# The available options are:
#  * posix
#         POSIX compatible code
#  * c89
#         C code is C89 compatible
#  * c99
#         C code is C99 compatible
#  * c11
#         C code is C11 compatible (default)
#  * c++03
#         C++ code is C++03 compatible
#  * c++11
#         C++ code is C++11 compatible (default)
# 可以使用多标准
CPPCHECK_STD = ['c++11']
CPPCHECK_ENABLE = ['warning', 'performance', 'portability']
# 指定cppcheck使用多少个线程并行
CPPCHECK_JOBS = 4
# ============================
