#include "student.h"
#include <string>
#include <cstring>
#include <sstream>

Student::Student(const char * const name, int perm) {
  this->perm = perm;
  this->name = new char[strlen(name) + 1];
  strncpy(this->name, name, strlen(name) + 1);
}

Student::Student(const Student& orig) {
  perm = orig.perm;
  name = new char[strlen(orig.name) + 1];
  strncpy(name, orig.name, strlen(orig.name) + 1);
}


Student::~Student() {
  delete[] name;
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return name;
}

void Student::setPerm(int newPerm) {
  perm = newPerm;
}

void Student::setName(const char * const name) {
  delete[] this->name;
  this->name = new char[strlen(name) + 1];
  strncpy(this->name, name  , strlen(name) + 1);
}


Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...


  // KEEP THE CODE BELOW THIS LINE

  delete[] name;
  perm = right.perm;
  name = new char[strlen(right.name) + 1];
  strncpy(name, right.name, strlen(right.name) + 1);

  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  std::ostringstream oss;
  oss << "[" << name << "," << perm << "]";
  return oss.str();
}
