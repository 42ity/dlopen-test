# dlopen-test
DL open test

Helper: shell command to test any libs in some directory
$> for item in $(ls /usr/lib/x86_64-linux-gnu/lib*.so); do ./dlopen-test $item; done
