/*  =========================================================================
    dlopen-test

    Copyright (C) 2017 - 2020 Eaton.

    This software is confidential and licensed under Eaton Proprietary License
    (EPL or EULA).
    This software is not authorized to be used, duplicated or disclosed to
    anyone without the prior written permission of Eaton.
    Limitations, restrictions and exclusions of the Eaton applicable standard
    terms and conditions, such as its EPL and EULA, apply.
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
