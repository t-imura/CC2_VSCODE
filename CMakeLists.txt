# CMakeの最低バージョンを指定
cmake_minimum_required(VERSION 3.29.0)

# CMakeにテストを有効にするように指示
enable_testing()

# プロジェクト名の設定
project(MyTestProject)

# C++の標準を指定（例：C++23）
set(CMAKE_CXX_STANDARD 23)

# ビルドタイプの設定
set(CMAKE_BUILD_TYPE Debug)

# To use the googletest
#find_package(GTest REQUIRED)

# GoogleTestをサブモジュールとして追加
add_subdirectory(extern/googletest)

# ヘッダファイルのインクルードパスを指定
include_directories(include)

# メインのソースコードを指定（実行ファイル名 ソースファイル名）
add_library(SampleApp Src/CC.cpp Src/MyClass.cpp Src/MyClass2.cpp)

# GoogleTestライブラリをリンク
target_link_libraries(SampleApp gtest gtest_main)

# テスト用のソースファイルを指定
add_executable(test_my_class ../Sample-Test1/test.cpp)

# GoogleTestライブラリをリンク
target_link_libraries(test_my_class gtest gtest_main SampleApp)

# CMakeでgtest_discover_testsを使えるようにするためのインクルード
include(GoogleTest)

# CtestでGoogleTestを実行できるようにする
gtest_discover_tests(test_my_class)