#include <exception>

using namespace std;


class MagazineFullException : public exception {
public:
  virtual const char* what() const throw() {
    return "Magazine is full";
  }
};