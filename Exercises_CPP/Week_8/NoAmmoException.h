#include <exception>

using namespace std;


class NoAmmoException : public exception {
public:
  virtual const char* what() const throw() {
    return "Insufficient ammunition";
  }
};