#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include "socketutils.h"
#include <stdbool.h>

int main(){

   int serverSocketFD = createTCPIpv4Socket();
   if(serverSocketFD < 0){
      printf("SERVER SOCKET CONNECTION FAILED");
      return -1;
   }

   struct sockaddr_in serverAddress = createIPv4Address(NULL, 8080);

   int bindresult = bind(serverSocketFD,(const struct sockaddr *)&serverAddress,sizeof(serverAddress));

   if(bindresult < 0){
      printf("BIND RESULT FAILED\n");
      return -1;
   }
   printf("BIND RESULT SUCCESS\n");
   int listenResult = listen(serverSocketFD, 3);
   if(listenResult < 0){
      printf("LISTEN RESULT FAILED\n");
      return -1;     }
   printf("LISTEN RESULT SUCCESS\n");

   
   
   struct sockaddr_in clientAddress;
   socklen_t clientAddresslen = sizeof(clientAddress);


   int clientSocketFD = accept(serverSocketFD,(struct sockaddr *)&clientAddress,&clientAddresslen);
   if(clientSocketFD < 0){
      printf("CLIENT SOCKET BUILDING FAILED \n");
   }

 char buffer[1024];

 while (true){


    int bytes = recv(clientSocketFD, buffer, sizeof(buffer) - 1, 0);
    if (bytes > 0) {
        buffer[bytes] = '\0';  
        printf("SERVER RECEIVED:\n%s\n", buffer);
    }
    else if (bytes == 0) {

      printf("SESSION TERMINATED BY CLIENT");
      break;
    
    }else{
      printf("INTERNAL SERVER ERROR");
    }

 }


close(clientSocketFD);
shutdown(serverSocketFD,SHUT_RDWR);
   
return 0;


   


    
   
}