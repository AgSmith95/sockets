#include <arpa/inet.h>

#include <iostream>

// Book:
// Randal E. Bryant, David R. O’Hallaron - Computer Systems. A Programmer’s Perspective [3rd ed.]-Pearson (2016)

int main() {
    const char* ip_str = "192.168.0.100";
    unsigned int ip_val = 0;

    inet_pton(AF_INET, ip_str, &ip_val); // pton - presentation to network
    std::cout << "inet_pton: 0x" << std::hex << ip_val << '\n';

    char str[16] = {0};
    inet_ntop(AF_INET, &ip_val, str, sizeof(str)); // ntop - network to presentation
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

    std:: cout << "===== Practice problem 11.1 =====\n";
    {
        // PtoN
        struct in_addr inaddr;
        inet_pton(AF_INET, "107.212.122.205", &inaddr);
        std::cout << "107.212.122.205 = 0x" << std::hex << ntohl(inaddr.s_addr) << '\n';
        inet_pton(AF_INET, "64.12.149.13", &inaddr);
        std::cout << "   64.12.149.13 = 0x" << std::hex << ntohl(inaddr.s_addr) << '\n';
        inet_pton(AF_INET, "107.212.96.29", &inaddr);
        std::cout << "  107.212.96.29 = 0x" << std::hex << ntohl(inaddr.s_addr) << '\n';

        // NtoP
        char tmp[16] = {0};
        inaddr.s_addr = ntohl(0x00000080);
        std::cout << std::hex << "0x" << htonl(inaddr.s_addr) << " = "
                  << inet_ntop(AF_INET, &inaddr, tmp, sizeof(tmp)) << '\n';
        inaddr.s_addr = ntohl(0xFFFFFF00);
        std::cout << std::hex << "0x" << htonl(inaddr.s_addr) << " = "
                  << inet_ntop(AF_INET, &inaddr, tmp, sizeof(tmp)) << '\n';
        inaddr.s_addr = ntohl(0x0A010140);
        std::cout << std::hex << "0x" << htonl(inaddr.s_addr) << " = "
                  << inet_ntop(AF_INET, &inaddr, tmp, sizeof(tmp)) << '\n';
    }
    return 0;
}