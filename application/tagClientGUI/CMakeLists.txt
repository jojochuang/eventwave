SET(APPS tagClientGUI)
SET(SERVICES TagClient TcpTransport)

FIND_LIBRARY( LIB_NCURSES ncurses ) 

INCLUDE(${CMAKE_CURRENT_BINARY_DIR}/../application.cmake)
