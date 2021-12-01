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
        GifWidget.cpp GifWidget.h
        Commands/CommandsWidget.cpp Commands/CommandsWidget.h
        FileManagement.cpp FileManagement.h
        CommandsApplier.cpp CommandsApplier.h
        Commands/Speed/SpeedCommandWidget.cpp Commands/Speed/SpeedCommandWidget.hpp Commands/Speed/SpeedCommandWidget.ui
        Commands/Rotate/RotateCommandWidget.cpp Commands/Rotate/RotateCommandWidget.hpp Commands/Rotate/RotateCommandWidget.ui
        Commands/Optimize/OptimizeCommandWidget.cpp Commands/Optimize/OptimizeCommandWidget.hpp Commands/Optimize/OptimizeCommandWidget.ui
        Commands/Resize/ResizeCommandWidget.cpp Commands/Resize/ResizeCommandWidget.hpp Commands/Resize/ResizeCommandWidget.ui
        Commands/Crop/CropCommandWidget.cpp Commands/Crop/CropCommandWidget.hpp Commands/Crop/CropCommandWidget.ui
        resources.qrc)
target_link_libraries(CyberGif
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
