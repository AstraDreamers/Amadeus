# Amadeus - Binary Neural Network (BNN) AI that detects BPM in music at real time.
# Copyright (C) 2026  AstraDreamers
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 4.2)

project(simulator LANGUAGES CXX)

add_executable(${PROJECT_NAME} 
    src/main.c++
)

target_precompile_headers(${PROJECT_NAME} PRIVATE
	include/pch.h++
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
        /permissive-
        $<$<CONFIG:Debug>:/Zi>
        $<$<CONFIG:Release>:/O2>
        $<$<CONFIG:Release>:/fp:fast>
    )

    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:/DEBUG>
        $<$<CONFIG:Release>:/SUBSYSTEM:WINDOWS>
    )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -m64
        -fdiagnostics-color=always
        $<$<CONFIG:Debug>:-g>
        $<$<CONFIG:Release>:-O3>
        $<$<CONFIG:Release>:-ffast-math>
    )

    target_link_options(${PROJECT_NAME} PRIVATE
        -m64
        -static-libgcc
        -static-libstdc++
    )

    if(WIN32)
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:-mwindows>
            -static
        )
    endif()
endif()

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_26)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)