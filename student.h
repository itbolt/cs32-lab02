#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {

  public:
    // Constructor that takes name and perm
    Student(const char* name, int perm);

    // Big Three
    Student(const Student& other);
    ~Student();
    Student& operator=(const Student& rhs);

    // Accessors
    const char* getName() const;
    int getPerm() const;
    std::string toString() const;

    void setName(const char* newName);
    void setPerm(int newPerm);
  private:
    char* name;
    int perm;
};

#endif // STUDENT_H