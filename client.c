#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "socketutils.h"
#include <stdbool.h>



int main() {
    int socketFD = createTCPIpv4Socket();
    if (socketFD < 0) {
        printf("Socket creation failed\n");
        return 1;
    }

    struct sockaddr_in address = createIPv4Address("127.0.0.1", 8080);

    int result = connect(socketFD, (const struct sockaddr *)&address, sizeof(address));
    if (result < 0) {
        printf("RESULT VALIDATION FAILED\n");
        return 1;
    }

    printf("CONNECTION VALIDATED SUCCESS\n");

    char *line = NULL;
    size_t lineSize = 0;

    printf("type `exit` to terminate \n write your message\n  ");

    while (true){

        ssize_t charCount =  getline(&line,&lineSize,stdin);

        if(charCount>0){
            if(strcmp(line,"exit\n")==0){
                break;
            }
            else{

                ssize_t amountWasSend =   send(socketFD, line, charCount, 0);
            }
        }

    }



    // char *message = "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n";
    

    // char buffer[1024];
    // int bytesReceived = recv(socketFD, buffer, sizeof(buffer) - 1, 0);
    
    // if (bytesReceived > 0) {
    //     buffer[bytesReceived] = '\0';  // Null-terminate
    //     printf("RESPONSE WAS:\n%s\n", buffer);
    // } else {
    //     printf("No response received\n");
    // }
    
    close(socketFD);

    
    return 0;
}