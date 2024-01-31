# 递归将本文件夹下所有的cpp放到SOURCE中
file(GLOB_RECURSE SOURCE ./ *.cpp)

# 将SOURCE中所有的cpp编译成source 这个source库
add_library(source ${SOURCE})