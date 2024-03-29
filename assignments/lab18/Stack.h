
#ifndef STACK_H
#define STACK_H
#include <deque>

template<typename T>
class Stack {
public:
   // return the top element of the Stack
   const T& top() {
      return stack.front();
   } 

   // push an element onto the Stack
   void push(const T& pushValue) {
      stack.push_front(pushValue);
   } 

   // pop an element from the stack
   void pop() {
      stack.pop_front();
   } 

   // determine whether Stack is empty
   bool isEmpty() const {
      return stack.empty(); 
   } 

   // return size of Stack
   size_t size() const {
      return stack.size();
   } 

private:
   std::deque<T> stack; // internal representation of the Stack
}; 

#endif
