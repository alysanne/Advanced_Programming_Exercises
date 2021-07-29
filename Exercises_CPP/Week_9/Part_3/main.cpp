#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include "Ocean.h"

using namespace std;

mutex mutexName;

int SyncThread2(int id, Ocean *ocean) {
  Ocean::Cells target;
  int x,y;
  char playerDescription[5];

  // Get a unique player for this thread - either red or blue
  Ocean::Players player = ocean->AssignPlayer();

  if (player == Ocean::Players::redPlayer) {
    strcpy(playerDescription,"Red");
  } else {
    strcpy(playerDescription,"Blue");
  }

  srand(player);

  do {
    if (!ocean->IsFinished() && ocean->setCurrentPlayer(player)) {
      do {
        // Select a random cell
        x = rand() % 10;
        y = rand() % 10;
        // Get the cells value
        target = ocean->GetValue(player, x, y);
        // If the cell has not been visited before
        if (target == Ocean::Cells::unknown_cell) {
          ocean->Play(player, x, y);
          cout << ocean->GetPlayerDescription(player) << " x: " << x << " y: " << y << "\n";
          break;
        } else {
          // Opponent's ship found!
          if (target == Ocean::Cells::ship_cell) {
            ocean->SetFinished();
            cout << ocean->GetPlayerDescription(player) << " x: " << x << " y: " << y << "\n";
            cout << "Player " << ocean->GetPlayerDescription(player) << " Wins\n";
            break;
          }
        }
      }
        // If the random cell has been visited before then try another one
      while (target == Ocean::Cells::visited_cell);
    }
  }
  // Until a ship has been found
  while(!ocean->IsFinished());
  return 0;
}

int main() {
  cout << "------ Exercise 3 ------" << endl;
  cout << "------ Ocean Thread ------" << endl;

  srand(time(0));
  thread threadPool[2];
  Ocean *ocean = new Ocean();
  threadPool[0] = thread(SyncThread2, 1, ocean);
  threadPool[1] = thread(SyncThread2, 2, ocean);

  this_thread::sleep_for(chrono::seconds(15));
  delete ocean;
  return 0;
}
