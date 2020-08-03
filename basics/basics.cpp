#include <arpa/inet.h>

#include <iostream>

int main() {
    const char* ip_str = "192.168.0.100";
    unsigned int ip_val = 0;

    inet_pton(AF_INET, ip_str, &ip_val); // pton - presentation to network
    std::cout << "inet_pton: 0x" << std::hex << ip_val << '\n';

    char str[16] = {0};
    inet_ntop(AF_INET, &ip_val, str, 16); // ntop - network to presentation
    std::cout << "inet_ntop: " << str << '\n';

    in_addr ip{ip_val};
    /* Internet address.
    typedef uint32_t in_addr_t;
    struct in_addr
    {
        in_addr_t s_addr;
    };
    */
    std::cout << "in_addr  : 0x" << std::hex << ip.s_addr << '\n';

    // h - host; n - network
    // network = big endian
    // l - long 32 bits; s - short 16 bits
    std::cout << "htonl    : 0x" << htonl(0xabcdef12) << '\n';
    std::cout << "htons    : 0x" << htons(0xabcd) << '\n';
    std::cout << "ntohl    : 0x" << ntohl(0x12efcdab) << '\n';
    std::cout << "ntohs    : 0x" << ntohs(0xcdab) << '\n';
    return 0;
}