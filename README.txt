---version 1
本项目可以使用compile.bat编译和运行，之后在本目录下生成Ledger，也可以直接运行
现在不支持了
---version 2
现在本项目支持cmake，先进入build目录，依次执行
cmake .. -G "MinGW Makefiles"
cmake --build .
在build下生成Ledger
cmake .. -G "MinGW Makefiles"  -DCMAKE_TOOLCHAIN_FILE=D:/CSTool/vcpkg/scripts/buildsystems/vcpkg.cmake  -DVCPKG_TARGET_TRIPLET=x64-mingw-static  


测试环境配置说明：
- 操作系统：Windows 10/11（64位）
- 终端工具：Windows PowerShell 7.x
- 编译工具：g++ (MinGW-w64 12.2.0)
- 其他依赖：（如有需要，补充如数据库、中间件版本等）