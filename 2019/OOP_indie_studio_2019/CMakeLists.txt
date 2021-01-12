cmake_minimum_required(VERSION 3.11)

project(IndieStudio)

# Append cmake directory to module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# Set Irrlicht_DIR variable to Irrlicht directory
set(Irrlicht_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/Irrlicht")

# Call FindIrrlicht.cmake module and check if irrlicht exists
find_package(Irrlicht REQUIRED)

# Include Irrlicht
include_directories("${CMAKE_CURRENT_LIST_DIR}/lib/Irrlicht/include")

# Link project with Irrlicht
link_libraries(${Irrlicht_LIBRARIES})

include_directories("${CMAKE_CURRENT_LIST_DIR}/lib/SFML-2.5.1/include")
set(FIND_SFML_PATHS ${CMAKE_CURRENT_LIST_DIR}/lib/SFML-2.5.1)
set(SFML_DIR ${CMAKE_CURRENT_LIST_DIR}/lib/SFML-2.5.1/lib/cmake/SFML)

# setup dll files on Windows
if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/lib/Irrlicht/Irrlicht.dll ${CMAKE_CURRENT_BINARY_DIR}/Irrlicht.dll COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML-2.5.1/bin/sfml-audio-d-2.dll ${CMAKE_CURRENT_BINARY_DIR}/sfml-audio-d-2.dll COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML-2.5.1/bin/sfml-system-d-2.dll ${CMAKE_CURRENT_BINARY_DIR}/sfml-system-d-2.dll COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML-2.5.1/bin/openal32.dll ${CMAKE_CURRENT_BINARY_DIR}/openal32.dll COPYONLY)
endif()

# Set sources
set(SRCS
    src/Menus/TitleScreen/TitleScreen.cpp
    src/Menus/MainMenu/QuitButton.cpp
    src/Menus/MainMenu/PlayButton.cpp
    src/Menus/MainMenu/StartMenu.cpp
    src/Menus/MainMenu/LoadButton.cpp
    src/Menus/MainMenu/SettingsButton.cpp
    src/Menus/MainMenu/CreditsButton.cpp
    src/Menus/PlayerSelection/UIPlayerSelection.cpp
    src/Menus/PlayerSelection/LaunchButton.cpp
    src/Menus/CreditsScreen.cpp
    src/Menus/ControlsScreen.cpp
    src/Menus/SettingsMenu/SettingsMenu.cpp
    src/Menus/SettingsMenu/MusicUpButton.cpp
    src/Menus/SettingsMenu/MusicDownButton.cpp
    src/Menus/SettingsMenu/SFXUpButton.cpp
    src/Menus/SettingsMenu/SFXDownButton.cpp
    src/Entities/Player.cpp
    src/Entities/Bomb.cpp
    src/Entities/AI.cpp
    src/Entities/Block.cpp
    src/Entities/BlastCube.cpp
    src/Entities/Powers/Power.cpp
    src/Entities/Powers/Intensity.cpp
    src/Entities/Powers/Speed.cpp
    src/Entities/Powers/MagSize.cpp
    src/UI/UIManager.cpp
    src/UI/UIEnd.cpp
    src/UI/UIPauseMenu.cpp
    src/UI/SaveButton.cpp
    src/UI/BackMenuButton.cpp
    src/UI/ResumeButton.cpp
    src/EventReceiver.cpp
    src/Game.cpp
    src/main.cpp
    src/Map.cpp
    src/Sound.cpp
    src/Utils.cpp
)

set(HEADERS
    include/Menus/TitleScreen/TitleScreen.hpp
    include/Menus/MainMenu/LoadButton.hpp
    include/Menus/MainMenu/StartMenu.hpp
    include/Menus/MainMenu/QuitButton.hpp
    include/Menus/MainMenu/PlayButton.hpp
    include/Menus/MainMenu/SettingsButton.hpp
    include/Menus/MainMenu/CreditsButton.hpp
    include/Menus/PlayerSelection/UIPlayerSelection.hpp
    include/Menus/PlayerSelection/LaunchButton.hpp
    include/Menus/CreditsScreen.hpp
    include/Menus/ControlsScreen.hpp
    include/Menus/SettingsMenu/SettingsMenu.hpp
    include/Menus/SettingsMenu/MusicUpButton.hpp
    include/Menus/SettingsMenu/MusicDownButton.hpp
    include/Menus/SettingsMenu/SFXUpButton.hpp
    include/Menus/SettingsMenu/SFXDownButton.hpp
    include/Entities/Player.hpp
    include/Entities/IEntity.hpp
    include/Entities/EntityEnumeration.hpp
    include/Entities/Bomb.hpp
    include/Entities/AI.hpp
    include/Entities/Block.hpp
    include/Entities/BlastCube.hpp
    include/Entities/Powers/Power.hpp
    include/Entities/Powers/Intensity.hpp
    include/Entities/Powers/Speed.hpp
    include/Entities/Powers/MagSize.hpp
    include/UI/UIEnumeration.hpp
    include/UI/IButton.hpp
    include/UI/UIManager.hpp
    include/UI/IUI.hpp
    include/UI/UIEnd.hpp
    include/UI/UIPauseMenu.hpp
    include/UI/SaveButton.hpp
    include/UI/BackMenuButton.hpp
    include/UI/ResumeButton.hpp
    include/EventReceiver.hpp
    include/Game.hpp
    include/Map.hpp
    include/Timer.hpp
    include/Sound.hpp
    include/Utils.hpp
    include/RNGenerator.hpp
)

find_package(SFML 2.5.1 REQUIRED audio)
add_executable(bomberman ${SRCS} ${HEADERS})
target_link_libraries(bomberman sfml-audio)
target_link_libraries(bomberman -g)