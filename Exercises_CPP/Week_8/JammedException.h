#include <exception>

using namespace std;


class JammedException : public exception {
private:
  int rounds;
public:
  JammedException() {}
  JammedException(int rounds) : rounds(rounds) {}
  virtual const char* what() const throw() {
    return "The weapon is jammed";
  }
  int GetRounds() {
    return rounds;
  }
};