root=./../..
deps=$root/deps
build=./build

flags=
flags="$flags -g3 -Og -std=c++17 -pthread -m64"
flags="$flags -Werror -Wno-missing-braces"

include=
include="$include -I$deps/Base/include"
include="$include -I$deps/Sys/include"
include="$include -I./src"

src=
src="$src $deps/Sys/src/SysHelper.c"
src="$src $deps/Sys/src/SysWindow.c"
src="$src $deps/Sys/src/SysNet.c"

rm -rf build
mkdir build

g++ main.cpp $src -o build/main.exe $flags $include -lX11
