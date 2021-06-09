cmake_minimum_required(VERSION 3.13)
cmake_policy(VERSION 3.13)

find_package(fty-cmake PATHS ${CMAKE_BINARY_DIR})

project(dlopen-test
        DESCRIPTION "Test to load a dynlib using dlopen()"
        VERSION 1.0.0
)

include(GNUInstallDirs)

#create the exe
etn_target(exe ${PROJECT_NAME}
    SOURCES
        src/dlopen-test.cpp
    USES_PRIVATE
        ${CMAKE_DL_LIBS}
)

#target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_DL_LIBS})
#target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)
#target_compile_options(${PROJECT_NAME} INTERFACE
#    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
#    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Werror>
#)
