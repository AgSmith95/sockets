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
