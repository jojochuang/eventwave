SET(APPS appmacedon_test)
#SET(LIBNAME AppMacedonTest)
SET(SERVICES ReplayTree RandTree GenericTreeMulticast Pastry ScribeMS SplitStreamMS CacheRecursiveOverlayRoute)
#SET(EXTRALIBS)

INCLUDE(${CMAKE_CURRENT_BINARY_DIR}/../application.cmake)

ADD_TEST("appmacedon-RandTree" ${EXECUTABLE_OUTPUT_PATH}/appmacedon_test -data_packet_size 1000 -num_clients 5 -run_length 30 -streaming_rate 100 -streaming_time 10 -tree RandTree)
ADD_TEST("appmacedon-ScribeMS" ${EXECUTABLE_OUTPUT_PATH}/appmacedon_test -data_packet_size 1000 -num_clients 5 -run_length 30 -streaming_rate 100 -streaming_time 20 -join_time 10 -tree ScribeMS)
ADD_TEST("appmacedon-SplitStreamMS" ${EXECUTABLE_OUTPUT_PATH}/appmacedon_test -data_packet_size 1000 -num_clients 5 -run_length 30 -streaming_rate 100 -streaming_time 20 -join_time 10 -multicast SplitStreamMS)
