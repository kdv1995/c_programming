#include "server.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Server server_Constructor(int domain, int port, int service,
                                 int protocol, int backlog, u_long interface,
                                 void (*launch)(struct Server *server)) {
  struct Server server;

  server.domain = domain;
  server.port = port;
  server.service = service;
  server.protocol = protocol;
  server.backlog = backlog;
  server.interface = interface;

  server.address.sin_family = domain;
  server.address.sin_port = htons(port);
  server.address.sin_addr.s_addr = htonl(interface);
  // Use the service (socket type) when creating the socket, not the port
  server.socket = socket(domain, service, protocol);

  if (server.socket < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  if (bind(server.socket, (struct sockaddr *)&server.address,
           sizeof(server.address)) < 0) {
    perror("Failed to bind socket...\n");
    exit(EXIT_FAILURE);
  }

  if (listen(server.socket, server.backlog) < 0) {
    perror("Failed to listen on socket...\n");
    exit(EXIT_FAILURE);
  }
  server.launch = launch;
  return server;
}

void launch(struct Server *server) {
  char buffer[BUFFER_SIZE];
  while (1) {
    printf("===== Waiting for new connection... =====\n");
    int addrlen = sizeof(server->address);
    int new_socket = accept(server->socket, (struct sockaddr *)&server->address,
                            (socklen_t *)&addrlen);
    ssize_t bytesRead = read(new_socket, buffer, BUFFER_SIZE);

    if (bytesRead >= 0) {
      buffer[bytesRead] = '\0';
      puts(buffer);
    } else {
      perror("Read failed\n");
    }
    int isFamous = true;

    char *response = "HTTP/1.1 200 OK\r\n"
                     "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                     "<!DOCTYPE html>\r\n"
                     "<html>\r\n"
                     "<head>\r\n"
                     "<title>Testing Basic HTTP-SERVER</title>\r\n"
                     "</head>\r\n"
                     "<body>\r\n"
                     "Hello, Ahmed!\r\n"
                     "</body>\r\n"
                     "</html>\r\n";
    if (isFamous) {
      write(new_socket, response, strlen(response));
      close(new_socket);
    }
  }
}
