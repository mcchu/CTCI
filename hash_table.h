#include <iostream>

const int TABLE_SIZE = 128;

class HashEntry
{
	public:
		int key;
		int value;
		HashEntry* next;	//Pointer
		
		HashEntry(int _key, int _value){
			this->key = _key;
			this->value = _value;
			this->next = NULL;
		}
};

class HashMap
{
	HashEntry **htable;
	
	public:
		HashMap() {
			htable = new HashEntry*[TABLE_SIZE];
			for(int i = 0; i < TABLE_SIZE; i++){
				htable[i] = NULL;
			}
		}
		
		~HashMap(){
			for(int i = 0; i < TABLE_SIZE; i++){
				HashEntry* entry = htable[i];
				while(entry != NULL){
					HashEntry* prev = entry;
					entry = entry->next;
					delete prev;
				}
			}
			delete[] htable;
		}
		
		int hashFunc(int key){
			return key % TABLE_SIZE;
		}
		
		void Insert(int key, int value){
			int hash_val = hashFunc(key);
			HashEntry* prev = NULL;
			HashEntry* entry = htable[hash_val];
			
			while(entry != NULL){		//Moves through linked list to vacant spot
				prev = entry;
				entry = entry->next;
			}
			if(entry == NULL){
				entry = new HashEntry(key, value);	//Create a hash entry
				if(prev == NULL){
					htable[hash_val] = entry;		//If 1st element in linked list
					
				}
				else{
					prev->next = entry;				//Append entry to linked list
				}
			}
			else{
				entry->value = value;	//Safety. If hash table wasn't cleared well.
			}
		}
		
		void Remove(int key){
			int hash_val = hashFunc(key);
			HashEntry* prev = NULL;
			HashEntry* entry = htable[hash_val];
			
			if(entry == NULL || entry->key != key){
				std::cout << "No element found at key: " << key << std::endl;
				return;
			}
			while(entry->next != NULL){	//Find further most entry in linked list
				prev = entry;
				entry = entry->next;
			}
			if(prev != NULL){
				prev->next = entry->next;
			}
			delete entry;			
		}
		
		void Search(int key){
			int hash_val = hashFunc(key);
			HashEntry* entry = htable[hash_val];
			while(entry != NULL){
				if(entry->key == key){
					std::cout << entry->value<< " ";
				}
				entry = entry->next;
			}
		}
};