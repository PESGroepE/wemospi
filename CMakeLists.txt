cmake_minimum_required(VERSION 3.25)
project(wemospi)

set(CMAKE_CXX_STANDARD 11)

add_executable(wemospi main.cpp Webserver.cpp Webserver.h Handler.cpp Handler.h RFIDHandler.cpp RFIDHandler.h MotionHandler.cpp MotionHandler.h MatrixHandler.cpp MatrixHandler.h LEDHandler.cpp LEDHandler.h TCPSocket.cpp TCPSocket.h Event.cpp Event.h Deuren.cpp Deuren.h)
