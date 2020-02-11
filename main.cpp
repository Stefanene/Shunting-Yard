/*
  Shunting Yard Algorithm by Stefan Ene, finished 2/13/2020
    Works Cited: Stack reference form geeksforgeeks.org/stack-in-cpp-stl/
 */

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stack>

#include "Node.h"

using namespace std;

//function prototypes
void push(Node* &stack, Node* add);  //thanks Andew T
void pop(Node* &stack);
void enqueue(Node* &queue);
void dequeue(Node* &queue);
Node* getEnd(Node* head);  //also a peek function
void toPost();
void toPre();
int precedence(char op);

int main() {
  //variables
  int countSigns = 0;
  int countNum = 0;
  Node* stack = NULL;
  
  //program
  cout << "==========Welcome=========" << endl;
  cout << "This is a Shunting Yard Algorithm." << endl;
  bool run = true;
  char in[10];
  char input[100];
  char* modif[100];
  while (run) {
    cout << endl << "Input an operation: calc, quit." << endl;
    cin.get(in, 10);
    cin.clear();
    cin.ignore(10000, '\n');
    if (strcmp(in, "calc") == 0) {
      for (int i = 0; i < sizeof(input); i++) {  //clear input
	input[i] = 0;
      }
      cout << "=========Calculate========" << endl;
      cout << "Input equation with infix notation:" << endl;
      cin.get(input, 100);
      cin.clear();
      cin.ignore(10000, '\n');
      //break input by spaces
      int l = 0;  //keeps track of # of chars before space
      int count = 0; //number of chars
      for (int i = 0; i < strlen(input); i++) {
	if (input[i] == ' ') {
	  if (l == 1) {
	    char *temp = new char[10];
	    for (int z = 0; z < sizeof(temp); z++) {  //clear temp memory
	      temp[z] = 0;
	    }
	    temp[0] = input[i-1];
	    modif[count] = temp;
	    //cout << temp << endl;
	    count++;
	    l = 0;
	  } else {
	    char *temp = new char[10];
	    for (int z = 0; z < sizeof(temp); z++) {  //clear temp memory
	      temp[z] = 0;
	    }
	    for (int a = 0; a < l; a++) {
	      temp[a] = input[i-l+a]; 
	    }
	    modif[count] = temp;
	    count++;
	    l = 0;
	    //cout << temp << endl;
	  }
	} else {
	  char *temp = new char[10];
	  for (int z = 0; z < sizeof(temp); z++) {  //clear temp memory
	    temp[z] = 0;
	  }
	  l++;
	  if (i == strlen(input) - 1) {  //last possible pair of chars
	    for (int a = 0; a < l; a++) {
	      temp[a] = input[i+a+1-l];
	    }
	    modif[count] = temp;
	    count++;
	    //cout << temp << endl;
	  }
	}
      }
      for (int i = 0; i < count; i++) {
	cout << modif[i] << endl;
      }
      cout << "==========================" << endl;
    }
    else if (strcmp(in, "quit") == 0) {
      cout << endl << "Thanks for using the program." << endl;
      cout << endl << "==========Exitted=========" << endl;
      run = false;
    }
    else {
      cout << endl << "Unknown command. Try again." << endl;
    }
  }
}

//precedence funtion to get the importance of charactert 
int precedence(char op) {
  if (op == '^') {
    return 3;  //highest precedence
  } else if (op == '*' || op == '/') {
    return 2; //second highest precedence
  } else if (op == '+' || op == '-') {
    return 1;  //second lowest precedence
  }
  return 0; //number has lowest precedence
}

//push function to add new element at end of stack
void push (Node* &stack, Node* add) {
  getEnd(stack)->setNext(add);
}

//get last node in stack -- also acts as a PEEK function
Node* getEnd(Node* head) {
  if (head->getNext() != NULL) {
    getEnd(head->getNext());  //recursion lmao
  } else {
    return head;
  }
}

//pop function to remove newst added element
void pop(Node* &stack) {
  Node* end = getEnd(stack);
  Node* current = NULL;
  while (current != end) {  //get the second to last element
    current = current->getNext();
  }
  current->setNext(NULL);  //set pointer to last null
  delete end;  //delete last(newest) node
}

//convert to postfix function
void doPost() {

}

//convert to prefix
void doPre() {

}
