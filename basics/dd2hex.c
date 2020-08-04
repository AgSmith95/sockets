#include <stdio.h>
#include <stdint.h>

#include <arpa/inet.h>

int main(int argc, char** argv) {
    uint16_t val = 0;

    if (argc < 2) {
        printf("usage: dd2hex param\n");
        printf("    param  - 16 bit value in network byte order\n");
        printf("             e.g: 1024, 25, 65535\n");
        printf("    output - param converted to host order\n");
        return 0;
    }

    sscanf(argv[1], "%hu", &val);
    printf("0x%04x\n", ntohs(val));
    return 0;
}
