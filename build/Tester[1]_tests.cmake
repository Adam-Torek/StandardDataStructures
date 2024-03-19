add_test( TestArray.TestEmptyArray /home/adam-torek/StandardDataStructures/build/Tester [==[--gtest_filter=TestArray.TestEmptyArray]==] --gtest_also_run_disabled_tests)
set_tests_properties( TestArray.TestEmptyArray PROPERTIES WORKING_DIRECTORY /home/adam-torek/StandardDataStructures/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( Tester_TESTS TestArray.TestEmptyArray)
