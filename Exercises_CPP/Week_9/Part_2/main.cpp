#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;


class GameObject {
public:
  int health;
  GameObject() {
    health = 100;
  }
};

mutex acctLock;

void SyncThread(int id, GameObject *param) {
  // Protect against multiple access to same resource, releases when execution ends, can handle exceptions
  lock_guard<mutex> lock(acctLock);

  // Can also block this way, but if there's an exception it won't release
  // acctLock.lock();

  cout << "Game Object Health : " << param->health << endl;

  // acctLock.unlock();
}

int main() {
  cout << "------ Exercise 2 ------" << endl;
  cout << "------ GameObject Thread ------" << endl;
  thread threadPool[2];
  GameObject *obj = new GameObject();

  threadPool[0] = thread(SyncThread, 1, obj);
  threadPool[1] = thread(SyncThread, 2, obj);

  this_thread::sleep_for(chrono::seconds(15));
  return 0;
}
