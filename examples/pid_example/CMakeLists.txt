file(GLOB SOURCES src/*.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBLO REQUIRED liblo)
if(APPLE)
    # for MacOS X or iOS, watchOS, tvOS (since 3.10.3)
    set(LIBLO_INCLUDE_DIRS "/opt/homebrew/Cellar/liblo/0.32/include")
    set(LIBLO_LIBRARIES "/opt/homebrew/Cellar/liblo/0.32/lib/liblo.dylib")
endif()
# set(LIBLO_INCLUDE_DIRS "/opt/homebrew/Cellar/liblo/0.32/include")
# set(LIBLO_LIBRARIES "/opt/homebrew/Cellar/liblo/0.32/lib/liblo.dylib")
include_directories(${LIBLO_INCLUDE_DIRS})

add_executable(example_PID ${SOURCES})

target_link_libraries(example_PID ${LIBLO_LIBRARIES} Haptic_Gestures)


# include(CTest)
# include(Catch)

# catch_discover_tests(tests)
