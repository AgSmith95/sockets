set(BASICS_EXEC basics)

add_executable(
    ${BASICS_EXEC}
    basics.cpp
)
target_compile_options(
    ${BASICS_EXEC}
    PRIVATE
    -Wall -Wextra -pedantic -Werror
)

add_executable(
    hex2dd
    hex2dd.c
)
target_compile_options(
    hex2dd
    PRIVATE
    -Wall -Wextra -pedantic -Werror
)

add_executable(
    dd2hex
    dd2hex.c
)
target_compile_options(
    dd2hex
    PRIVATE
    -Wall -Wextra -pedantic -Werror
)
