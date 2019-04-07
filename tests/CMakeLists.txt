include (CTest)

include_directories ("${PROJECT_SOURCE_DIR}/src")

add_executable(test_cpptsk
    my_class_1_unit.t.cpp
    my_class_2_unit.t.cpp)

target_link_libraries(test_cpptsk PUBLIC
    gtest
    gtest_main
    pthread
    cppsrc)

install(TARGETS test_cpptsk
    DESTINATION output/tests)

add_test(unit_test_cpptsk test_cpptsk)

add_executable(test_cppmock
    my_new_dummy_class_mock.t.cpp)

target_link_libraries(test_cppmock PUBLIC
    gtest
    gmock
    gmock_main
    pthread
    cppsrc)

add_test(unit_test_cppmock test_cppmock)