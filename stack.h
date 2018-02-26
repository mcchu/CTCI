#ifndef STACK_H
#define STACK_H

#include <iostream>

//------ Stack Implementation ------
//Implemented using a linked list
//Appends and removes only on the top in O(1) time
//Accessing values in the middle of the linked list take O(n) time
//----------------------------------------

//struct Node{
//	int val;
//	Node* next;
//};

class Stack
{
	Node* top;

	public:
		Stack()
		{
			top = NULL;
		}
		
		~Stack()
		{
			while(!is_empty()){
				pop();
			}
		}
		
		//Function: Returns True if empty, False if not.
		bool is_empty()
		{
			if(top == NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		int size()
		{
			int size = 0;
			Node* index = top;
			while(index != NULL){
				size++;
				index = index->next;
			}
			return size;			
		}
		
		//Function: Returns top value of LinkedList	
		int peek()
		{
			if(top == NULL){
				return -1;
			}
			else{
				return top->val;
			}
		}
		
		//Function: Append item to top of stack					
		void push_top(int val)
		{
			Node* new_node = new Node();
			new_node->val = val;
			new_node->next = top;
			if(top == NULL){ //If Empty Stack
				top = new_node;
				new_node->next = NULL;
			}
			else{
				top = new_node;
			}
		}

		
		//Function: Removes item from the top of the stack								
		void pop()
		{
			Node* temp = top;	//Save top node pointer
			if(temp != NULL){
				top = top->next;
				delete temp;
			}			
		}
};

#endif