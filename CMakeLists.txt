cmake_minimum_required(VERSION 3.17)
project(l2)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(l2
        ConsoleUI/Menu.cpp
        ConsoleUI/Menu.h
        ConsoleUI/Navigation.cpp
        ConsoleUI/Navigation.h
        ConsoleUI/Options.cpp
        ConsoleUI/Options.h
        ConsoleUI/State.h
        Options/Main/mainCBs.h
        Options/Main/mainItems.h
        Options/Main/mainOptions.h
        Options/Settings/settingsCBs.h
        Options/Settings/settingsItems.h
        Options/Settings/settingsOptions.h
        Options/allOptions.h
        Options/menuSectionCodes.h
        "Test/Cases.h"
        Test/Test.h
        Util/ConsoleState.h
        Util/UserFile.h
        main.cpp
        Algorithm/Array.h
        Algorithm/Dict.h
        Util/Input.h "Algorithm/Algorithm.h")
