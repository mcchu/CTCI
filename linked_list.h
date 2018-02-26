#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

//------ Linked List Implementation ------
//Double-ended linked list. Each node in the linked list points to it's neighbors
//Can append to the front and back in O(1) time.
//Accessing values in the middle of the linked list take O(n) time
//----------------------------------------

struct Node{
	int val;
	Node* prev;
	Node* next;
};

class LinkedList
{
	Node* head;
	Node* tail;

	public:
		LinkedList()
		{
			head = NULL;
			tail = NULL;
		}
		
		~LinkedList()
		{
			while(!empty()){
				pop_front();
			}
		}
		
		//Function: Returns True if empty, False if not.
		bool empty()
		{
			if(head == NULL || tail == NULL){
				return true;
			}
			else{
				return false;
			}
		}
		
		//Function: Returns size of LinkedList
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
		
		//Function: Returns first value of LinkedList	
		int front()
		{
			if(head == NULL){
				return -1;
			}
			else{
				return head->val;
			}
		}

		//Function: Returns last value of LinkedList			
		int back()
		{
			if(tail == NULL){
				return -1;
			}
			else{
				return tail->val;
			}			
		}
		
		//Function: Append item to front of list					
		void push_front(int val)
		{
			Node* new_node = new Node();
			new_node->val = val;
			new_node->prev = NULL;
			new_node->next = head;
			if(head == NULL || tail == NULL){ //If Empty List
				head = new_node;
				tail = new_node;
				new_node->next = NULL;
			}
			else{
				head->prev = new_node;
				head = new_node;
			}
		}

		//Function: Append item to back of list							
		void push_back(int val)
		{
			Node* new_node = new Node();
			new_node->val = val;
			new_node->prev = tail;
			new_node->next = NULL;			
			if(head == NULL || tail == NULL){ //If Empty List
				head = new_node;
				tail = new_node;
				new_node->prev = NULL;
			}
			else{
				tail->next = new_node;
				tail = new_node;
			}			
		}

		//Function: Removes item from the front of the list								
		void pop_front()
		{
			Node* temp = head;	//Save front node pointer
		//	head->next->prev = NULL;
			if(temp != NULL){
				head = head->next;
				delete temp;
			}
		}
		
		//Function: Removes item from the back of the list								
		void pop_back()
		{
			Node* temp = tail;	//Save front node pointer
			if(temp != NULL){
				tail = tail->prev;
				delete temp;
			}			
		}
};

#endif