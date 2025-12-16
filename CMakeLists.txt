# 1. 指定CMake最低版本（根据本地版本调整，如3.10）
cmake_minimum_required(VERSION 3.10)

# 2. 定义项目名称（自定义，如LedgerProject）
project(LedgerProject LANGUAGES CXX)

# 3. 设置C++标准（与代码匹配，如C++11）
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. 【关键1：编译业务代码为静态库】（让测试程序能复用业务代码）
# 4.1 收集src目录下的业务源码文件（注意路径是src/xxx.cpp）
set(BUSINESS_SOURCES
    src/ui.cpp
    src/manager.cpp
)

# 4.2 编译为静态库（库名：ledger_lib，可自定义）
add_library(ledger_lib STATIC ${BUSINESS_SOURCES})

# 4.3 指定头文件目录（让业务库和测试程序能找到include下的头文件）
# PUBLIC：表示依赖这个库的目标（如Ledger、LedgerTest）会继承这个头文件目录
target_include_directories(ledger_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include  # 项目根目录的include文件夹
)

# 5. 【关键2：编译业务可执行程序（Ledger）】（原有业务程序）
# 5.1 业务入口文件是src/main.cpp
add_executable(Ledger src/main.cpp)

# 5.2 链接业务库（让Ledger能调用ui/manager的函数）
target_link_libraries(Ledger
    PRIVATE
        ledger_lib
)

# 6. 【关键3：配置Gtest并编译测试程序】
# 6.1 查找vcpkg安装的Gtest（适配vcpkg的CONFIG模式，必须保留）
find_package(GTest REQUIRED CONFIG)

# 6.2 收集test目录下的测试源码文件（路径是test/xxx.cpp）
set(TEST_SOURCES
    test/test.cpp
    test/test2.cpp
)

# 6.3 编译测试可执行程序（程序名：LedgerTest，可自定义）
add_executable(LedgerTest ${TEST_SOURCES})

# 6.4 链接依赖：业务库 + Gtest库 + MinGW的线程库（避免链接错误）
target_link_libraries(LedgerTest
    PRIVATE
        ledger_lib          # 链接业务库（核心：测试程序要调用业务代码）
        GTest::gtest        # Gtest核心库
        GTest::gtest_main   # Gtest自带的main函数（无需自己写main）
)

# 6.5 MinGW环境下必须链接pthread库（解决Gtest的线程相关链接错误）
if(MINGW)
    target_link_libraries(LedgerTest PRIVATE pthread)
endif()

# 7. 【可选：配置CTest（用cmake的ctest命令运行测试）】
enable_testing()
# 添加测试目标：运行LedgerTest
add_test(NAME AllTests COMMAND LedgerTest)

