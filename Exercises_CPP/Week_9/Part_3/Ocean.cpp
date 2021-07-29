#include <mutex>
#include "Ocean.h"

using namespace std;

extern mutex mutexName;

Ocean::Ocean(){
  finished = false;
  int posX,posY;
  // Initialise players and grid cells
  players[0] = Players::unassigned;
  players[1] = Players::unassigned;
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      grids[0][x][y] = Cells::unknown_cell;
      grids[1][x][y] = Cells::unknown_cell;
    }
  }

  // Assign ship to a random cell within the first grid
  posX = rand() % 10;
  posY = rand() % 10;
  grids[0][posX][posY] = Cells::ship_cell;
  cout << "Player 0 ship x:" << posX << " y:" << posY << "\n";

  // Assign ship to a random cell within the second grid
  posX = rand() % 10;
  posY = rand() % 10;
  grids[1][posX][posY] = Cells::ship_cell;
  cout << "Player 1 ship x:" << posX << " y:" << posY << "\n";
}

bool Ocean::IsFinished() {
  lock_guard<mutex> lock(mutexName);
  return finished;
}

void Ocean::SetFinished() {
  lock_guard<mutex> lock(mutexName);
  finished = true;
}

// Turn based logic
bool Ocean::setCurrentPlayer(Players player) {
  lock_guard<mutex> lock(mutexName);
  if (currentPlayer != player) {
    currentPlayer = player;
    return true;
  } else {
    return false;
  }
}

char* Ocean::GetPlayerDescription(Players player) {
  lock_guard<mutex> lock(mutexName);
  if (player == Ocean::Players::redPlayer) {
    return "Red";
  } else {
    return "Blue";
  }
}

// Players are assigned an ID of 0 or 1 at the start of play
Ocean::Players Ocean::AssignPlayer() {
  lock_guard<mutex> lock(mutexName);
  if (players[0] == Players::unassigned) {
    players[0] = Players::redPlayer;
    cout << "Red player assigned \n";
    return Players::redPlayer;
  } else {
    players[1] = Players::bluePlayer;
    cout << "Blue player assigned \n";
    return Players::bluePlayer;
  }
}

// Return the value within a cell
Ocean::Cells Ocean::GetValue(Players player, int x, int y) {
  lock_guard<mutex> lock(mutexName);
  return grids[!player][x][y];
}

// Returns true if a ship is located within the player's grid at position x,y.
// If not flags the cell as being visited
bool Ocean::Play(Players player, int x, int y) {
  lock_guard<mutex> lock(mutexName);
  if (player == Players::redPlayer) {
    if (grids[Players::bluePlayer][x][y] == ship_cell) {
      finished = true;
    } else {
      grids[Players::bluePlayer][x][y] = visited_cell;
    }
  } else {
    if (grids[Players::redPlayer][x][y] == ship_cell) {
      finished = true;
    } else {
      grids[Players::redPlayer][x][y] = visited_cell;
    }
  }
  return finished;
}
