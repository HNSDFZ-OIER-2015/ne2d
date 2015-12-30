# ne2d
A 2D render engine.

# Status
| Linux     | Windows   | OSX       |
|:---------:|:---------:|:---------:|
| PASS      | Unknown   | Unknown   |

Version: 0.0.2.2 beta (unstable)

# Build (beta/linux)
You should have clang(>= 3.5), libc++(>= 1.0) and libsdl2.
```shell
apt-get install clang++ libc++1 libsdl2-*
```

Then, run build.py at the root folder of ne2d.
```shell
./build.py
```

Finally, copy the .so file to /usr/lib.
```shell
# May require root
mkdir /usr/include/ne2d/
./copy.sh
```

# TODO-list
1. Prepare to write raw interfaces.
2. Complete docs.
