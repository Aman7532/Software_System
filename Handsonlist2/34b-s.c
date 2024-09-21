// Aman Agarwal
// MT2024017
//  Question : Write a program to communicate between two machines using socket.

// This is the server program

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void communicate(int *fd)
{
    ssize_t readBytes, writeBytes;
    char dataFromClient[100];

    // ========================= Server - Client communication =================
    writeBytes = write(*fd, "I'm the server!", 15);
    if (writeBytes == -1)
        perror("Error while writing to network via socket!");
    else
        printf("Data sent to client!\n");

    readBytes = read(*fd, dataFromClient, 100);
    if (readBytes == -1)
        perror("Error while reading from network via socket!");
    else
        printf("Data from client: %s\n", dataFromClient);

    // =======================================================================
    close(*fd);
}

void main()
{
    int socketFileDescriptor, connectionFileDescriptor;
    int bindStatus;
    int listenStatus;
    int clientSize;

    struct sockaddr_in address, client;
    pthread_t threadID;

    // Create a socket
    socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        perror("Error while creating socket!");
        _exit(0);
    }
    printf("Server side socket successfully created!\n");

    // Configure server address
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    // Bind the socket
    bindStatus = bind(socketFileDescriptor, (struct sockaddr *)&address, sizeof(address));
    if (bindStatus == -1)
    {
        perror("Error while binding name to socket!");
        _exit(0);
    }
    printf("Binding to socket was successful!\n");

    // Listen for connections
    listenStatus = listen(socketFileDescriptor, 2);
    if (listenStatus == -1)
    {
        perror("Error while trying to listen for connections!");
        _exit(0);
    }
    printf("Now listening for connections on a socket!\n");

    // Accept connections in a loop
    while (1)
    {
        clientSize = (int)sizeof(client);
        connectionFileDescriptor = accept(socketFileDescriptor, (struct sockaddr *)&client, &clientSize);
        if (connectionFileDescriptor == -1)
            perror("Error while accepting a connection!");
        else
        {
            // Create a new thread for each connection
            if (pthread_create(&threadID, NULL, (void *)communicate, &connectionFileDescriptor))
                perror("Error while creating thread");
        }
    }

    close(socketFileDescriptor);
}

// Output:
// Server side socket successfully created!
// Binding to socket was successful!
// Now listening for connections on a socket!
