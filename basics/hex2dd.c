#include <stdio.h>
#include <stdint.h>

#include <arpa/inet.h>

int main(int argc, char** argv) {
    uint16_t val;

    if (argc < 2) {
        printf("usage: hex2dd param\n");
        printf("    param  - 16 bit hexadecimal value\n");
        printf("             e.g: 0x400, 0XF0F0, 1234\n");
        printf("    output - param converted to network order\n");
        return 0;
    }

    sscanf(argv[1], "%hx", &val);
    printf("0x%04x\n", htons(val));
    return 0;
}
