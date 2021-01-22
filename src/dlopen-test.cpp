#include <dirent.h> 
#include <dlfcn.h>

#include <iostream>
#include <memory>

int main (int argc, char *argv[]) {

    if(argc != 2) {
        std::cerr << "Usage: " << argv[0] << " libpath" << std::endl;
        return 2;
    }
    //try to load the lib
    std::shared_ptr<void> m_spLib = std::shared_ptr<void>(dlopen(argv[1], RTLD_NOW), [] (void * ptr) { if(ptr) dlclose(ptr);});
    if (!m_spLib) {
        std::cerr << "Cannot load lib " << argv[1] << ": " << dlerror() << std::endl;
        return 1;
    }

    return 0;
}
