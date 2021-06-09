/*  =========================================================================
    Copyright (C) 2014 - 2020 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
*/

/*
@header
@discuss
@end
*/

#include <dirent.h>
#include <dlfcn.h>
#include <iostream>
#include <memory>

int main (int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " libpath" << std::endl;
        return 2;
    }

    //try to load the lib
    std::shared_ptr<void> m_spLib = std::shared_ptr<void>(dlopen(argv[1], RTLD_NOW), [] (void * ptr) { if(ptr) dlclose(ptr);});
    if (!m_spLib) {
        std::cerr << "ERROR: Failed to load " << argv[1] << ": " << dlerror() << std::endl;
        return 1;
    }

    std::cout << "SUCCESS: " << argv[1] << " loaded" << std::endl;
    return 0;
}
