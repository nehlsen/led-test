SET(FASTLED_SRCS
        ../lib/FastLED/FastLED.cpp
        ../lib/FastLED/lib8tion.cpp
        ../lib/FastLED/colorutils.cpp
        )

set(COMPONENT_SRCS
        led_test_main.cpp
        ${FASTLED_SRCS}
        )

set(COMPONENT_ADD_INCLUDEDIRS
        ../lib/FastLED
        )

set(COMPONENT_REQUIRES
        arduino
        )

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

register_component()

component_compile_options(-DESP32)
component_compile_options(-DARDUINO)
