cmake_minimum_required(VERSION 3.23)
project(BowlingGame C)

set(CMAKE_C_STANDARD 99)

add_custom_command(
        OUTPUT  ${CMAKE_CURRENT_SOURCE_DIR}/BowlingGame/BowlingTest.t.c
        COMMAND ${CMAKE_BINARY_DIR}/tddc
                      ${CMAKE_CURRENT_SOURCE_DIR}/BowlingGame/BowlingTest.c
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/BowlingGame/BowlingTest.c
                ${CMAKE_BINARY_DIR}/tddc
)

add_executable(BowlingGame main.c
        BowlingGame/BowlingTest.h
        BowlingGame/BowlingTest.c
        BowlingGame/Game.c
        BowlingGame/Game.h
            assert.h assert.c test.h)
set_source_files_properties(BowlingGame/BowlingTest.c PROPERTIES HEADER_FILE_ONLY TRUE)

add_library(Tests STATIC ${CMAKE_CURRENT_SOURCE_DIR}/BowlingGame/BowlingTest.t.c)
add_custom_command(TARGET Tests POST_BUILD
        COMMAND rm ${CMAKE_CURRENT_SOURCE_DIR}/BowlingGame/BowlingTest.t.c
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/BowlingGame
        COMMENT "Remove temp files.")

add_dependencies(BowlingGame Tests)
target_link_libraries(BowlingGame PRIVATE Tests)