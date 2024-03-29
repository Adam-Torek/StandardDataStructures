add_test( TestArray.TestEmptyArray /home/adam-torek/StandardDataStructures/build/Tester [==[--gtest_filter=TestArray.TestEmptyArray]==] --gtest_also_run_disabled_tests)
set_tests_properties( TestArray.TestEmptyArray PROPERTIES WORKING_DIRECTORY /home/adam-torek/StandardDataStructures/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( TestArray.TestEmptyArrayInitialized /home/adam-torek/StandardDataStructures/build/Tester [==[--gtest_filter=TestArray.TestEmptyArrayInitialized]==] --gtest_also_run_disabled_tests)
set_tests_properties( TestArray.TestEmptyArrayInitialized PROPERTIES WORKING_DIRECTORY /home/adam-torek/StandardDataStructures/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( TestArray.TestEmptyArrayInitializedAnotherArray /home/adam-torek/StandardDataStructures/build/Tester [==[--gtest_filter=TestArray.TestEmptyArrayInitializedAnotherArray]==] --gtest_also_run_disabled_tests)
set_tests_properties( TestArray.TestEmptyArrayInitializedAnotherArray PROPERTIES WORKING_DIRECTORY /home/adam-torek/StandardDataStructures/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( TestArray.TestOneElementListInitialized /home/adam-torek/StandardDataStructures/build/Tester [==[--gtest_filter=TestArray.TestOneElementListInitialized]==] --gtest_also_run_disabled_tests)
set_tests_properties( TestArray.TestOneElementListInitialized PROPERTIES WORKING_DIRECTORY /home/adam-torek/StandardDataStructures/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( Tester_TESTS TestArray.TestEmptyArray TestArray.TestEmptyArrayInitialized TestArray.TestEmptyArrayInitializedAnotherArray TestArray.TestOneElementListInitialized)
