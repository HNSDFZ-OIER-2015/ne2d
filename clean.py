#!/usr/bin/env python3

#
# Copyright 2015 riteme
#

import os
import shutil

CLEAN_FOLDERS = ['/usr/include/ne2d']
CLEAN_FILES = ['/usr/lib/libne2d.so']

for folder in CLEAN_FOLDERS:
    try:
        shutil.rmtree(folder)
    except OSError:
        pass

for filename in CLEAN_FILES:
    try:
        os.remove(filename)
    except OSError:
        pass
