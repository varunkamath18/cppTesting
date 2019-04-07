
add_library(cppsrc
    my_new_dummy_class.cpp
    my_class_1.cpp
    my_class_2.cpp)

target_link_libraries(cppsrc)


add_executable(cpptsk
    cpptesting.m.cpp)

target_link_libraries(cpptsk PUBLIC
    cppsrc)


INSTALL(TARGETS cpptsk DESTINATION output/bin/)
