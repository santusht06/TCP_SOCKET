


#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int createTCPIpv4Socket();
struct sockaddr_in createIPv4Address(char *ip, int port);

struct sockaddr_in createIPv4Address(char *ip, int port) {
    struct sockaddr_in address;
    address.sin_port = htons(port);
    address.sin_family = AF_INET;
    
    if (ip == NULL) {
        address.sin_addr.s_addr = INADDR_ANY;
    } else {
        inet_pton(AF_INET, ip, &address.sin_addr.s_addr);
    }
    
    return address;
}

int createTCPIpv4Socket() {
    return socket(AF_INET, SOCK_STREAM, 0);
}