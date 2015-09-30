#include <stdio.h>
#include <winsock2.h>   
#include <windows.h>

#define SERVER_ADDR "127.0.0.1"
#define PORT 9999

int main() {
    char buff[1024];
    
    puts("wsa start up");
    if (WSAStartup(0x0202,(WSADATA *)&buff[0]))
    {
      printf("WSAStart error %d\n",WSAGetLastError());
      return -1;
    }
    
    SOCKET my_sock;
    my_sock=socket(AF_INET,SOCK_STREAM,0);
    
    if (my_sock < 0)
    {
      printf("Socket() error %d\n",WSAGetLastError());
      return -1;
    }
    
    struct sockaddr_in dest_addr;
    dest_addr.sin_family=AF_INET;
    dest_addr.sin_port=htons(PORT);
    
    HOSTENT *hst;
    if (inet_addr(SERVER_ADDR)!=INADDR_NONE) {
      dest_addr.sin_addr.s_addr=inet_addr(SERVER_ADDR);
    } else {
      if ((hst=gethostbyname(SERVER_ADDR)))
      ((unsigned long *)&dest_addr.sin_addr)[0]=((unsigned long **)hst->h_addr_list)[0][0];
      else 
      {
        printf("Invalid address %s\n",SERVER_ADDR);
        closesocket(my_sock);
        WSACleanup();
        return -1;
      }
    }
    
    if (connect(my_sock,(struct sockaddr *)&dest_addr,sizeof(dest_addr))) {
        printf("Connect error %d\n",WSAGetLastError());
        return -1;
    }
    
    
    puts("enter message");
    scanf("%s", buff);
    
    send(my_sock, &buff[0], sizeof(buff), 0);
    recv(my_sock, &buff[0], sizeof(buff), 0);
    
    printf("recv: %s\n", buff);
        
    printf("Recv error %d\n",WSAGetLastError());
    closesocket(my_sock);
    WSACleanup();
    
    getchar();
    
    return 0;
}

/*
int remain = sizeof(RecvData);
    while(remain)
    {
      remain -= recv(s, (char*)(&RecvData+sizeof(RecvData)-remain), remain, 0);
    }*/
