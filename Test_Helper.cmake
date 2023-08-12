# https://eb2.co/blog/2015/06/driving-boost.test-with-cmake/

function(add_boost_test SOURCE_FILE_NAME DEPENDENCY_LIB)

    file(READ "${SOURCE_FILE_NAME}" SOURCE_FILE_CONTENTS)
    string(REGEX MATCHALL "BOOST_AUTO_TEST_CASE\\( *([A-Za-z_0-9]+) *\\)" 
           FOUND_TESTS ${SOURCE_FILE_CONTENTS})

    foreach(HIT ${FOUND_TESTS})
        string(REGEX REPLACE ".*\\( *([A-Za-z_0-9]+) *\\).*" "\\1" TEST_NAME ${HIT})

        add_test(NAME "${DEPENDENCY_LIB}.${TEST_NAME}" 
                 COMMAND ${DEPENDENCY_LIB}
                 --run_test=${TEST_NAME} --catch_system_error=yes)
    endforeach()
endfunction()