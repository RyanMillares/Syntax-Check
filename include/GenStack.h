#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

template <typename T>
class GenStack{
public:
  GenStack();
  //overload
  GenStack(int maxSize);
  ~GenStack();

  int getSize();
  bool isEmpty();
  bool isFull();
  void push(T data);
  void resize();
  T pop();
  T peek();
  int max;
  int top;
  T *myArray;

private:

};
/**
template <typename T>
GenStack<T>::GenStack(int max){

}
template <typename T>
GenStack<T>::~GenStack(){
  delete myArray;
}
**/
template <class T>
GenStack<T>::GenStack(){ //default size to 100
  myArray = new T[100];
  top = -1;
  max = 100;
}
//overloaded constructor, will make array maxSize size
template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize];
  top = -1;
  max = maxSize;
}
//deconstructor, deletes array to free memory
template <class T>
GenStack<T>::~GenStack(){
  delete[] myArray;
}
//returns the size of the stack
template <class T>
int GenStack<T>::getSize(){
  return top + 1;
}
//returns if the stack is empty or not
template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}
//returns if the stack is full or not
template <class T>
bool GenStack<T>::isFull(){
  return (top == (max - 1));
}
//https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
//used to avoid isEmpty and isFull calls

template <class T>
void GenStack<T>::push(T data){
  if(top >= max - 1){
    resize();//if stack is full, resize the stack then push
  }

  myArray[++top] = data; //pushes data then increments the top


}

template <class T>
T GenStack<T>::pop(){
  if(top < 0){
    throw;//throw empty stack is the stack is empty
    cout << "Stack is empty!" << endl;

  }
  else{
    return myArray[top--]; // returns top value and decrements top
  }

}

template <class T>
T GenStack<T>::peek(){
  if(top < 0){
    throw; //throw is stack is empty
    cout << "Stack is empty!" << endl;
  }
  else{
    return myArray[top]; //returns the top value but doesnt decrement top
  }
}
template <class T>
void GenStack<T>::resize(){
  T* newArray = new T[max*2]; //makes new array twice as big
  for(int i = 0; i < max; ++i){
    newArray[i] = myArray[i]; //copies all elements into new array
  }
  delete[] myArray; //deletes memory of old array
  myArray = newArray; //reassigns the pointer to the new, bigger array

  max *= 2;


}
