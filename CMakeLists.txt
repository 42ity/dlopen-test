cmake_minimum_required(VERSION 3.0)

project(dlopen-test
        VERSION 1.0.0 )

set(PROJECT_DESCRIPTION "Try to load lib")

include(GNUInstallDirs)

#create the header only library
add_executable(${PROJECT_NAME}
    src/dlopen-test.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_DL_LIBS})
 
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)

target_compile_options(${PROJECT_NAME} INTERFACE 
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Werror>
)