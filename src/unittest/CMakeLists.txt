################################################################################
#                                                                              #
# Copyright (C) 2023 Luca Tricerri                                                                           
                                        #
# All Rights Reserved.                                                         #
#                                                                              #
################################################################################

# @author Luca Tricerri <triccyx@gmail.com> 

project(unittest)

set(SOURCES gtest_main.cc
            testMultiplier.cpp
            testMultiplierInternal.cpp
            testMultiplierFromFile.cpp
            testPwm.cpp
            testMediaScanner.cpp
            testDivision.cpp
            testMultiplierParamAndFixture.cpp
            testMultiplier-c.cpp
            testcapplication.cpp
            fff.h
            )

set(CMAKE_EXE_LINKER_FLAGS  "-rdynamic")
set(CMAKE_INSTALL_RPATH ./)

add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME}  udev gtest gmock multiplier multiplierfromfile pwm mediascanner division capplication)

# install
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})