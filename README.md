# ne2d
A 2D render engine.

# Status
| Linux     | Windows   | OSX       |
|:---------:|:---------:|:---------:|
| PASS      | Unknown   | Unknown   |

Version: 0.2.2 beta (unstable)

# Build (beta/linux)
## Requirements
* G++ (>= 4.8)
* SDL2
* Necessary OpenGL library such as libGLEW
* Python3 for build scripts

If you're on Ubuntu, run this command to get G++ and SDL2.
```shell
# May require root
apt-get install build-essential libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

## Build ne2d
1. Clone this repo.
```shell
git clone https://github.com/riteme/ne2d.git
cd [PATH TO REPO]
```

2. Then, run ```build.py``` in the root folder of ne2d.
```shell
./build.py
```
It will generate ```libne2d.so``` in ```./release```.

3. To install ne2d, run:
```shell
# May require root
./install.py
```
It will copy all header files to ```/usr/include/ne2d/``` and copy dynamic library to ```/usr/lib/```.

## Rebuild
If you want to build a newer version of ne2d, follow these instructions below:
```shell
cd [PATH TO REPO]

# Update repo
git pull origin master

# Clean-up
./clean.py

# Build it
./build.py

# Install it
./install.py
```

# TODO-list
1. Prepare to write raw interfaces.
2. Complete docs.

# Feedback
This project is in beta, there would be dozens of bugs need to be fixed.  
If you have any problems while using ne2d, open an issue or contract me in e-mail.
