
cmake_minimum_required(VERSION 3.0.0)

project(BrickLover VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "C:/Users/1/CLionProjects/libs/SFML-2.5.1/lib/cmake/SFML")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML 2.5 REQUIRED graphics network audio window system)

include(CTest)
enable_testing()

add_executable(
    ${PROJECT_NAME}    main.cpp

    
    button/button.cpp           button/button.hpp
    menu/menu.cpp               menu/menu.hpp
    level_menu/level_menu.cpp   level_menu/level_menu.hpp                    

    player/player.cpp           player/player.hpp
    player_controller/player_controller.cpp           player_controller/player_controller.hpp

    ball/ball.cpp ball/ball.hpp

    font/sansation.hpp
                       

)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${PROJECT_NAME} sfml-graphics)

