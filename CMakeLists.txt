cmake_minimum_required (VERSION 3.8)

project ("ConsoleGame" VERSION 1.0.0.2)

add_executable (ConsoleGame
				"${CMAKE_CURRENT_SOURCE_DIR}/src/board.cpp"
				"${CMAKE_CURRENT_SOURCE_DIR}/src/direction.cpp"
				"${CMAKE_CURRENT_SOURCE_DIR}/src/game.cpp"
				"${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
				"${CMAKE_CURRENT_SOURCE_DIR}/src/positioned.cpp"
				"${CMAKE_CURRENT_SOURCE_DIR}/rc/icon.rc"
				)

add_definitions(-DVERSION_MAJOR=${ConsoleGame_VERSION_MAJOR})
add_definitions(-DVERSION_MINOR=${ConsoleGame_VERSION_MINOR})
add_definitions(-DVERSION_PATCH=${ConsoleGame_VERSION_PATCH})
add_definitions(-DVERSION_TWEAK=${ConsoleGame_VERSION_TWEAK})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)