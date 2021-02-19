cmake_minimum_required (VERSION 3.13)

project (ConsoleGame VERSION 1.1)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_BUILD_TYPE RelWithDebInfo)

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

if(WIN32 OR MSVC)
	add_compile_definitions(PDCURSES_AVAILABLE)

	include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/pdcurses/")
	link_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/pdcurses/")
	
	add_library(curses UNKNOWN IMPORTED)
	set_target_properties(curses PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/pdcurses/windows/pdcurses.lib")

	target_link_libraries(ConsoleGame curses)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS Release
        RUNTIME DESTINATION Release/bin)