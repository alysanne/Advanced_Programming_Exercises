#include <iostream>
#include <thread>
#include "sys/socket.h"
//#include "sys/types.h"
#include <netdb.h>
#include <unistd.h>

//using namespace std;

int main(int argc, char* argv[]) {

  // Server socket creation
  int port = 5000;
  struct sockaddr_in socketAddress = {
      .sin_family = AF_INET,
      .sin_addr.s_addr = INADDR_ANY,
      .sin_port = htons(port)
  };

  int option = 1;
  // SOCK_STREAM = TCP
  // SOCK_DGRAM = UDP
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));

  if (serverSocket == -1) {
    std::cout << "Socket not found!" << std::endl;
    return 0;
  } else {
    std::cout << "Socket found!" << std::endl;
  }

  // Server socket binding
  if (bind(serverSocket, (struct sockaddr*)&socketAddress, sizeof(socketAddress)) == -1) {
    std::cout << "Socket bind failed: " << errno << std::endl;
    return 0;
  } else {
    std::cout << "Socket bind successful!" << std::endl;
  }

  // Server listen
  // SOMAXCONN is 128 connections max
  if (listen(serverSocket, SOMAXCONN) == -1) {
    std::cout << "Socket listen failed" << std::endl;
    return 0;
  } else {
    std::cout << "Listening on port " << port << std::endl;
  }

  // Server accept
  int acceptSocket = accept(serverSocket, NULL, NULL); // Will await until it receives a connection or fails
  if (acceptSocket == -1) {
    std::cout << "Socket accept failed" << std::endl;
  }

  std::cout << "Accepted connection" << std::endl;

  return 0;
}