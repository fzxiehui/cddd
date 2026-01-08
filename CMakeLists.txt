cmake_minimum_required(VERSION 3.15)
project(ddd C)

set(CMAKE_C_STANDARD 11)

# compile_commands.json 文件
# ln -sf build/compile_commands.json .
# 让nvim coc 可以找到 这个依赖包
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 添加cjson 依赖
add_subdirectory(third_party/cjson)
add_subdirectory(src)
