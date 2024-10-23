cmake_minimum_required(VERSION 3.10)
# 设置项目名称和版本
project(MyProject)  

# 设置 C++ 标准set(CMAKE_CXX_STANDARD11)  
set(CMAKE_CXX_STANDARD_REQUIRED True)  

# 包含目录
include_directories(${PROJECT_SOURCE_DIR}/include)  

# 添加库add_library(MyLibrary src/MyLibrary.cpp)  

# 添加可执行文件
add_executable(MyExecutable main.cpp)  

# 链接库到可执行文件target_link_libraries(MyExecutable PRIVATE MyLibrary)  

# 设置编译选项target_compile_options(MyExecutable PRIVATE -Wall -Wextra)  

# 安装规则install(TARGETS MyExecutable MyLibrary RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)  
