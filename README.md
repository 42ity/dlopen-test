# dlopen-test

dlopen() runtime test

# How to build

To build, run:

```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=usr ..
make
sudo make install
```

# How to run

To run:

* from within the build/ tree, run:

```bash
./dlopen-test
```

# Helpers

## shell command to test one lib

```bash
$> dlopen-test /path/to/one/lib
```

## shell command to test any libs in some directory

```bash
$> for solib in $(ls /path/to/any/libs/lib*.so); do dlopen-test $solib; done
```
