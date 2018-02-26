#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

//------ Queue Implementation ------
//Implemented using a linked list
//Appends and removes in order in O(1) time
//Accessing values in the middle of the linked list take O(n) time
//----------------------------------------

//struct Node{
//	int val;
//	Node* next;
//};

class Queue
{
	Node* head;
	Node* tail;

	public:
		Queue()
		{
			head = NULL;
			tail = NULL;
		}
		
		~Queue()
		{
			while(!is_empty()){
				pop();
			}
		}
		
		//Function: Returns True if empty, False if not.
		bool is_empty()
		{
			if(head == NULL || tail == NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		int size()
		{
			int size = 0;
			Node* index = head;
			while(index != NULL){
				size++;
				index = index->next;
			}
			return size;			
		}
		
		//Function: Returns top value of LinkedList	
		int peek()
		{
			if(head == NULL){
				return -1;
			}
			else{
				return head->val;
			}
		}
		
		//Function: Append item to end of Queue					
		void push_back(int val)
		{
			Node* new_node = new Node();
			new_node->val = val;
			new_node->next = NULL;
			if(head == NULL || tail == NULL){ //If Empty Queue
				head = new_node;
				tail = new_node;
				new_node->next = NULL;
			}
			else{
				tail->next = new_node;
				tail = new_node;		
			}
		}

		//Function: Removes item from the queue								
		void pop()
		{
			Node* temp = head;	//Save head node pointer
			if(temp != NULL){
				head = head->next;
				delete temp;
			}			
		}
};

#endif