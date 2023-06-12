#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //strlen
#include <winsock2.h> //socket functions
#include <windows.h> //thread functions
#include <iostream>
#include <vector>
#include <string>

#include "crc.h"

#define PORT 8800
//the thread function
DWORD WINAPI connection_handler(void *);
DWORD WINAPI ui_handler(void *);
DWORD WINAPI database_handler(void *);
DWORD WINAPI errin_handler(void *);

int srvDataAnalysis(uint8_t * nums,msgReq * msg)
{
    if(nums==NULL)
    {
        std::cout<<"param error"<<std::endl;
        return -1;
    }
    msg->msgHead.devId=*nums;
    nums++;
    msg->msgHead.seq=*nums;
    nums++;
    msg->msgHead.datalen=*nums;
    nums++;
    msg->msgHead.datalen=msg->msgHead.datalen>>8+*nums;
    nums++;
    msg->msgHead.crc8=*nums;
    nums++;
    msg->idReq=*nums;
    nums++;
    msg->crc16=*nums;
    nums++;
    msg->crc16=msg->crc16>>8+*nums;
    for(int i=0;i<(msg->msgHead.datalen-4);i++)
    {
        msg->nums.push_back(*nums);
        nums++;
    }
    return 0;
}

 typedef struct _head{
     uint8_t  devId;
     uint8_t  seq;
     uint8_t  crc8;
     uint16_t datalen;
 }head;
 
 // 请求报文
 typedef struct _msgReq{
     head msgHead;
     uint8_t   idReq;
     uint16_t   crc16;
     std::vector<uint8_t>  nums;
 }msgReq;
 
 // 响应报文
 typedef struct _msgRsp{
     head msgHead;
     uint8_t   idRsp;
     std::vector<uint8_t>  nums;
     uint16_t   crc16;
 }msgRsp;

enum obj{
    UI,
    DATABASE,
    ERRIN
};

int main(int argc , char *argv[])
{
    WSADATA wsa;
    int socket_desc , client_sock , c;
    struct sockaddr_in server , client;
    
    //Initialize Winsock
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("WSAStartup failed: %d\n", WSAGetLastError());
        return 1;
    }
    
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == INVALID_SOCKET)
    {
        printf("Could not create socket: %d\n" , WSAGetLastError());
        return 1;
    }
    
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed: %d\n" , WSAGetLastError());
        return 1;
    }
    
    //Listen
    listen(socket_desc , 3);
    
    //Accept and incoming connection
    printf("Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);
    
    while( (client_sock = accept(socket_desc , (struct sockaddr *)&client, &c)) != INVALID_SOCKET )
    {
        printf("Connection accepted\n");
        
        HANDLE sniffer_thread;
        DWORD thread_id;
        
        sniffer_thread = CreateThread(NULL, 0, connection_handler, (void*)client_sock, 0, &thread_id);
        
        if(sniffer_thread == NULL)
        {
            printf("Could not create thread: %d\n", GetLastError());
            return 1;
        }
        printf("Handler assigned\n");
        Sleep(10);
    }
    
    if (client_sock == INVALID_SOCKET)
    {
        printf("Accept failed: %d\n" , WSAGetLastError());
        return 1;
    }
    
    WSACleanup();
    
    return 0;
}

/*
This will handle connection for each client
*/
DWORD WINAPI connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    
    char client_message[2000];
    
    while(recv(sock, client_message, 2000, 0) > 0)
    {
        uint8_t id = client_message[0];
        uint16_t len = client_message[2]>>8+client_message[3];
        uint8_t crc = client_message[4];

        if(crc!=crc8((uint8_t *)client_message,len,crc_8_MAXIM))
        {
            std::cout<<"crc8 error"<<std::endl;
            break;
        }else{
            switch (id)
            {
            case  UI:
                HANDLE uiTheard;
                DWORD uiTheardId;
                
                uiTheard = CreateThread(NULL, 0, ui_handler, (void*)client_message, 0, &uiTheardId);
                
                if(uiTheard == NULL)
                {
                    printf("Could not create thread: %d\n", GetLastError());
                    return 1;
                }
                printf("Handler assigned\n");
                break;
            case  DATABASE:
                HANDLE databaseTheard;
                DWORD databaseTheardId;
                
                databaseTheard = CreateThread(NULL, 0, database_handler, (void*)client_message, 0, &databaseTheardId);
                
                if(databaseTheard == NULL)
                {
                    printf("Could not create thread: %d\n", GetLastError());
                    return 1;
                }
                printf("Handler assigned\n");
                break;
                break;
            case  ERRIN:
                HANDLE errinTheard;
                DWORD errinTheardId;
                
                errinTheard = CreateThread(NULL, 0, errin_handler, (void*)client_message, 0, &errinTheardId);
                
                if(errinTheard == NULL)
                {
                    printf("Could not create thread: %d\n", GetLastError());
                    return 1;
                }
                printf("Handler assigned\n");
                break;
                break;
            default:
                std::cout<<"never run here"<<std::endl;
                break;
            }
        }        
        Sleep(100); //wait for a while
    }
    
    closesocket(sock);
    
    printf("Client disconnected\n");
    
    return 0;
}

DWORD WINAPI ui_handler(void *msg)
{
    uint8_t * data =(uint8_t *)msg;
    msgReq uiReq;
    msgReq * uiReqPointer =NULL;
    uiReqPointer =&uiReq;
    if(srvDataAnalysis(data,uiReqPointer)!=0)
    {
        std::cout<<"ui data analysis error"<<std::endl;
    }
    //ui hander func
    return 0;
}

DWORD WINAPI database_handler(void *msg)
{
    uint8_t * data =(uint8_t *)msg;
    msgReq databaseReq;
    msgReq * databaseReqPointer =NULL;
    databaseReqPointer =&databaseReq;
    if(srvDataAnalysis(data,databaseReqPointer)!=0)
    {
        std::cout<<"database data analysis error"<<std::endl;
    }
    return 0;
}

DWORD WINAPI errin_handler(void *msg)
{
    uint8_t * data =(uint8_t *)msg;
    msgReq errinReq;
    msgReq * errinReqPointer =NULL;
    errinReqPointer =&errinReq;
    if(srvDataAnalysis(data,errinReqPointer)!=0)
    {
        std::cout<<"errin data analysis error"<<std::endl;
    }
    //errin func
    return 0;
}

