#include <stdio.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main(void) {

    // string to hold the data that we're going to send to all the clients.
    char server_message[256] = "You have reached the server!";

    // -- create the server socket --
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // -- define the server address --
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY; // any IP address on the local machine

    // -- bind the socket to our specified IP and port --
    int bind_result = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_result == -1) {
        printf("There was an error binding the socket\n\n");
    }

    // -- listen for up to 5 connections at once --
    listen(server_socket, 5);

    int client_socket = accept(server_socket, NULL, NULL);

    // -- send the message --
    send(client_socket, server_message, sizeof(server_message), 0);

    // -- close the socket --
    close(server_socket);

    return 0;
}
