message(STATUS "Configuring unit tests")

include(CMakeParseArguments)
include_directories(include)
include_directories(../include)

add_library(testlib STATIC test_main.cpp)

set(ALL_TESTS "")

# Otherwise GCC throws a lot of warnings for REQUIRE(...) from Catch v.1.2.1
if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wno-parentheses)
endif()

add_executable(test_geos_factory t/test_geos_factory.cpp)
target_link_libraries(test_geos_factory testlib ${GEOS_LIBRARY})
add_test(NAME test_geos_factory
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND test_geos_factory)

add_executable(test_geos_factory_projection t/test_geos_factory_projection.cpp)
target_link_libraries(test_geos_factory_projection testlib ${GEOS_LIBRARY} ${PROJ_LIBRARY})
add_test(NAME test_geos_factory_projection
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND test_geos_factory_projection)

add_executable(test_geos_factory_mercator t/test_geos_factory_mercator.cpp)
target_link_libraries(test_geos_factory_mercator testlib ${GEOS_LIBRARY})
add_test(NAME test_geos_factory_mercator
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND test_geos_factory_mercator)
