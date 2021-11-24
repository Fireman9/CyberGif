cmake_minimum_required(VERSION 3.20)
project(CyberGif)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(CyberGif main.cpp
        MainWidget.cpp MainWidget.h
        GifScene.cpp GifScene.h
        CommandsWidget.cpp CommandsWidget.h
        Commands/Resize/ResizeCommandWidget.cpp Commands/Resize/ResizeCommandWidget.h
        FileManagement.cpp FileManagement.h
        CommandsApplier.cpp CommandsApplier.h
        Commands/Speed/SpeedCommandWidget.cpp Commands/Speed/SpeedCommandWidget.hpp Commands/Speed/SpeedCommandWidget.ui
        Commands/Rotate/RotateCommandWidget.cpp Commands/Rotate/RotateCommandWidget.hpp Commands/Rotate/RotateCommandWidget.ui
        resources.qrc)
target_link_libraries(CyberGif
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
