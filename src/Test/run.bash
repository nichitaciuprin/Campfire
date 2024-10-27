# TODO skip confirmation
# echo y | gdb -q -ex=run -ex=backtrace -ex=quit --args ./build/main
gdb -q -ex=run -ex=backtrace -ex=quit --args ./build/CampfireClient.exe
# ./build/main