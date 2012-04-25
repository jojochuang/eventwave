# CMake generated Testfile for 
# Source directory: /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/appmacedon_test
# Build directory: /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/appmacedon_test
# 
# This file includes the relevent testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(appm-RandTree "/appmacedon_test" "-data_packet_size" "1000" "-num_clients" "5" "-run_length" "30" "-streaming_rate" "100" "-streaming_time" "10" "-mode" "RandTree")
ADD_TEST(appm-ScribeMS-Pastry "/appmacedon_test" "-data_packet_size" "1000" "-num_clients" "5" "-run_length" "30" "-streaming_rate" "100" "-streaming_time" "20" "-join_time" "10" "-mode" "ScribeMS")
ADD_TEST(appm-ScribeMS-Bamboo "/appmacedon_test" "-data_packet_size" "1000" "-num_clients" "5" "-run_length" "30" "-streaming_rate" "100" "-streaming_time" "20" "-join_time" "10" "-mode" "ScribeMS-Bamboo")
ADD_TEST(appm-ScribeMS-Chord "/appmacedon_test" "-data_packet_size" "1000" "-num_clients" "5" "-run_length" "30" "-streaming_rate" "100" "-streaming_time" "20" "-join_time" "10" "-mode" "ScribeMS-Chord")
ADD_TEST(appm-SplitStreamMS-Pastry "/appmacedon_test" "-data_packet_size" "1000" "-num_clients" "5" "-run_length" "30" "-streaming_rate" "100" "-streaming_time" "20" "-join_time" "10" "-mode" "SplitStreamMS")
ADD_TEST(appm-SplitStreamMS-Bamboo "/appmacedon_test" "-data_packet_size" "1000" "-num_clients" "5" "-run_length" "30" "-streaming_rate" "100" "-streaming_time" "20" "-join_time" "10" "-mode" "SplitStreamMS-Bamboo")
ADD_TEST(appm-SplitStreamMS-Chord "/appmacedon_test" "-data_packet_size" "1000" "-num_clients" "5" "-run_length" "30" "-streaming_rate" "100" "-streaming_time" "20" "-join_time" "10" "-mode" "SplitStreamMS-Chord")
