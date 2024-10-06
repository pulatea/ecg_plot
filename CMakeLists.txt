cmake_minimum_required(VERSION 3.16)

project(ecg_plot_project LANGUAGES CXX)


set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport)

add_executable(ecg_plot_project
    main.cpp
    widget.h
    widget.cpp
    widget.ui
    qcustomplot.cpp
    qcustomplot.h
    ecg_reader.h
    ecg_reader.cpp
)

target_link_libraries(ecg_plot_project PRIVATE Qt6::Widgets Qt6::PrintSupport)

target_include_directories(ecg_plot_project PRIVATE
    src
    src/ui
    src/qcustomplot
)

target_compile_features(ecg_plot_project PUBLIC cxx_std_11)


target_compile_options(ecg_plot_project PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-Wall>
    $<$<CXX_COMPILER_ID:MSVC>:/W3>
)
