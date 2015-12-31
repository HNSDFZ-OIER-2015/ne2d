#!/usr/bin/env python3

#
# Copyright 2015 riteme
#

import re
import os
import os.path
import shutil

# Copy header files
INSTALL_TO = '/usr/include/ne2d/'
IGNORED_FILES = ['.+\.cpp']

shutil.rmtree(INSTALL_TO, ignore_errors=True)
shutil.copytree('./ne2d', INSTALL_TO)

for i in range(0, len(IGNORED_FILES)):
    IGNORED_FILES[i] = re.compile(IGNORED_FILES[i])

for parent, dirnames, filenames in os.walk(INSTALL_TO):
    for filename in filenames:
        for pattern in IGNORED_FILES:
            if pattern.match(filename) != None:
                os.remove(os.path.join(parent, filename))

# Copy dynamic library
shutil.copy2('./release/libne2d.so', '/usr/lib/libne2d.so')
