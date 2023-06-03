enable_language(ASM)

list(APPEND srcs 
    "startup_CH583.S"
    )

add_library(common STATIC ${srcs})
target_include_directories(common PUBLIC include)
set_target_properties(common PROPERTIES C_STANDARD 11)
target_link_libraries(common INTERFACE -nostartfiles)


