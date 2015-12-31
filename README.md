# ne2d
A 2D render engine.

# Status
| Linux     | Windows   | OSX       |
|:---------:|:---------:|:---------:|
| PASS      | Unknown   | Unknown   |

Version: 0.2.2 beta (unstable)

# Build (beta/linux)
You should have g++(>= 4.8, support for C++11) and SDL2.  
On Ubuntu(14.04 or above), just use ```apt-get``` to get them.
```shell
# May require root
apt-get install build-essential libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

Clone this repo.
```shell
git clone https://github.com/riteme/ne2d.git
cd [PATH TO REPO]
```

Then, run build.py at the root folder of ne2d.
```shell
./build.py
```

Finally, install it.
```shell
# May require root
mkdir /usr/include/ne2d/
./install.sh
```

# TODO-list
1. Prepare to write raw interfaces.
2. Complete docs.
