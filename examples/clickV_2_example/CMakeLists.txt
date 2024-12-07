file(GLOB SOURCES src/*.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBLO REQUIRED liblo)
if(APPLE)
    # for MacOS X or iOS, watchOS, tvOS (since 3.10.3)
    set(LIBLO_INCLUDE_DIRS "/opt/homebrew/Cellar/liblo/0.32/include")
    set(LIBLO_LIBRARIES "/opt/homebrew/Cellar/liblo/0.32/lib/liblo.dylib")
endif()
include_directories(${LIBLO_INCLUDE_DIRS})

add_executable(example_click2 ${SOURCES})

target_link_libraries(example_click2 ${LIBLO_LIBRARIES} Haptic_Gestures)


# include(CTest)
# include(Catch)

# catch_discover_tests(tests)
