#include <string>
#include "studentRoll.h"
#include <sstream>


StudentRoll::StudentRoll() {
  head = tail = nullptr;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  // STUB
  head = tail = nullptr;
  Node *current = orig.head;
  while (current != nullptr){
    insertAtTail(*(current->s));
    current = current->next;
  }
}

StudentRoll::~StudentRoll() {
  Node *current = head;
  while (current != nullptr){
    Node *temp = current;
    current = current->next;
    delete temp->s;
    delete temp;
  }
}

void StudentRoll::insertAtTail(const Student &s) {
  Student *newStudent = new Student(s);
  Node *newNode = new Node;
  newNode -> s = newStudent;
  newNode ->next = nullptr;

  if (tail == nullptr){
    head = tail = newNode;
  } else{
    tail->next = newNode;
    tail = newNode;
  }

}

std::string StudentRoll::toString() const {
  std::ostringstream oss;
  Node * current = head;
  while (current != nullptr){
    oss <<current -> s -> toString();
    if (current -> next != nullptr){
      oss << "\n";
    }
    current = current->next;
  }
  return oss.str();
}



StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
 

  // KEEP THE CODE BELOW THIS LINE

  Node *current = head;
  while (current != nullptr){
    Node*temp = current;
    current = current->next;
    delete temp->s;
    delete temp;
  }
  head = tail = nullptr;

  Node*copy = right.head;
  while (copy != nullptr){
    insertAtTail(*(copy->s));
    copy = copy->next;
  }
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





