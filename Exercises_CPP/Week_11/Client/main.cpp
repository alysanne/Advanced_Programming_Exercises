#include <iostream>
#include <thread>
#include "sys/socket.h"
//#include "sys/types.h"
#include <netdb.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

  // Client socket creation
  int port = 5000;
  struct sockaddr_in socketAddress = {
      .sin_family = AF_INET,
      .sin_addr.s_addr = INADDR_ANY,
      .sin_port = htons(port)
  };
  int option = 1;
  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  setsockopt(clientSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));

  if (clientSocket == -1) {
    std::cout << "Socket not found!" << std::endl;
    return 0;
  } else {
    std::cout << "Socket found!" << std::endl;
  }

  if (connect(clientSocket, (struct sockaddr*)&socketAddress, sizeof(socketAddress)) == -1) {
    std::cout << "Socket failed to connect. Error: " << errno << std::endl;
    close(clientSocket);
    return 0;
  } else {
    std::cout << "Client connected successfully" << std::endl;
    std::cout << "Client can start sending and receiving data..." << std::endl;
  }

  close(clientSocket);

  return 0;
}