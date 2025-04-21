#include "student.h"
#include <cstring>
#include <sstream>

Student::Student(const char* name, int perm) {
  this->perm = perm;
  this->name = new char[strlen(name) + 1];
  strncpy(this->name, name, strlen(name) + 1);
}

Student::Student(const Student& other) {
  perm = other.perm;
  name = new char[strlen(other.name) + 1];
  strncpy(name, other.name, strlen(other.name) + 1);
}

Student::~Student() {
  delete[] name;
}

Student& Student::operator=(const Student& rhs) {
  if (this == &rhs) return *this;

  delete[] name;
  perm = rhs.perm;
  name = new char[strlen(rhs.name) + 1];
  strncpy(name, rhs.name, strlen(rhs.name) + 1);

  return *this;
}

const char* Student::getName() const {
  return name;
}

int Student::getPerm() const {
  return perm;
}

void Student::setName(const char* newName) {
  delete[] name;
  name = new char[strlen(newName) + 1];
  strncpy(name, newName, strlen(newName) + 1);
}

void Student::setPerm(int newPerm) {
  perm = newPerm;
}


std::string Student::toString() const {
  std::ostringstream oss;
  oss << "[" << name << "," << perm << "]";
  return oss.str();
}
