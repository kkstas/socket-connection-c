#include <stdio.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main(void) {
    // -- create a socket --
    int network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // -- specify an address for the socket --
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002); // port you want to connect to
    server_address.sin_addr.s_addr = INADDR_ANY;  // to samo, co 0.0.0.0, czyli obecny komputer

    int connection_status = connect(
        network_socket,
        (struct sockaddr *) &server_address,
        sizeof(server_address)
    );

    // -- check for error within the connection --
    if (connection_status == -1) {
        printf("There was an error making a connectio nto the remote socket\n\n");
    }

    // -- receive data from the server --
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    // -- print out the server's response --
    printf("Received data from the server: %s", server_response);

    // -- and then close the socket --
    close(network_socket);

    return 0;
}
