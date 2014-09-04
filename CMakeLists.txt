cmake_minimum_required(VERSION 2.8)

PROJECT(ccTraining)

set(Qt5_DIR $ENV{Qt5_ROOT})

file(GLOB sources "src/*.cpp")
file(GLOB headers "include/*.h")
file(GLOB forms "UIs/*.ui")

set(CMAKE_AUTO_MOC ON)
set(CMAKE_AUTOMOC_MOC_OPTIONS "-bstdafx.h" "-fstdafx.h")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
FIND_PACKAGE(Qt5 COMPONENTS Gui Widgets Core)

QT5_WRAP_UI(UIS ${forms})
QT5_WRAP_CPP(MOC ${sources} ${headers})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${Qt5Gui_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${Qt5Core_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIR})

message(${forms})

add_executable(ccTraining
	${sources}
	${MOC}
	${headers}
        ${UIS}
)

TARGET_LINK_LIBRARIES(ccTraining 
	Qt5::Gui
	Qt5::Widgets
	Qt5::Core
)
