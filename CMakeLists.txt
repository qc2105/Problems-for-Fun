project("Problems for Fun")

add_executable(single_linked_list single_linked_list.cpp)
target_link_libraries(single_linked_list)

add_executable(test_list test_list.cpp List.cpp)