/*
 * Compiling 
 * gcc -Wall -o "%e" "%f" -mwindows  -lwsock32
 * 
 */

#include <stdio.h>
#include <winsock2.h>   
#include <windows.h>

#define PORT 9999

int main()
{
    char buff[1024];  
    char sendbuff[1024];  
    
    puts("wsastartup");
    if (WSAStartup(0x0202,(WSADATA *) &buff[0])) 
    {
          printf("Error WSAStartup %d\n",
             WSAGetLastError());
      return -1;
    }
    
    puts("create server socket");
    SOCKET mysocket;
    if ((mysocket=socket(AF_INET,SOCK_STREAM,0))<0)
    {
      printf("Error socket %d\n",WSAGetLastError());
      WSACleanup();
      return -1;
    }
    
    struct sockaddr_in local_addr;
    local_addr.sin_family=AF_INET;
    local_addr.sin_port=htons(PORT);
    local_addr.sin_addr.s_addr=0;
    
    puts("bind");
    if (bind(mysocket,(struct sockaddr *) &local_addr,sizeof(local_addr)))
    {
      
      printf("Error bind %d\n",WSAGetLastError());
      closesocket(mysocket);  
      WSACleanup();
      return -1;
    }
    
    puts("listen");
    if (listen(mysocket, 4))
    {
      printf("Error listen %d\n",WSAGetLastError());
      closesocket(mysocket);
      WSACleanup();
      return -1;
    }
    
    puts("accept");
    
    SOCKET client_socket;    
    struct sockaddr_in client_addr;    
    int client_addr_size=sizeof(client_addr);
    
    while((client_socket=accept(mysocket, (struct sockaddr *)&client_addr, &client_addr_size))) {
        //nclients++;    
        HOSTENT *hst;
        hst=gethostbyaddr((char *)&client_addr.sin_addr.s_addr,4, AF_INET);
        printf("+%s [%s] new connect!\n", (hst)?hst->h_name:"", inet_ntoa(client_addr.sin_addr));
         
          
        recv(client_socket, &buff[0], sizeof(buff), 0);
        sprintf(sendbuff,"server said: %s", buff);
        send(client_socket, &sendbuff[0], sizeof(sendbuff), 0);
        printf("recv: %s\n", buff);
      // clietn
      //DWORD thID;
      //CreateThread(NULL,NULL,function,&client_socket,NULL,&thID);
    }
    
    return 0;
}
