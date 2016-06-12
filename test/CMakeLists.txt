add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (test_constructor constructor.cc)

target_link_libraries(test_constructor ${Boost_LIBRARIES})

add_test (test_constructor test_constructor)
