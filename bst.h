#ifndef BST_H
#define BST_H

//------ BST Implementation ------
//
//----------------------------------------

struct leaf
{
    int val;
    struct leaf *left;
    struct leaf *right;
};

class BST
{
	leaf* root;
	
	public:
		BST(){
			root = NULL;
		}
				
		void insert(leaf* node, leaf* newnode){
			if(root == NULL){
				root = new leaf;
				root->val = newnode->val;
				root->left = NULL;
				root->right = NULL;
				std::cout << "Root Node is Added" << std::endl;
				return;
			}	
			if(node->val > newnode->val){	//Newnode goes to the left
				if(node->left == NULL){
					newnode->left = NULL;
					newnode->right = NULL;
					node->left = newnode;
					std::cout << "Node added to left." << std::endl;
					return;
				}
				else{
					insert(node->left, newnode);
				}
			}
			else if(node->val < newnode->val){	//Newnode goes to the right
				if(node->right == NULL){
					newnode->left = NULL;
					newnode->right = NULL;
					node->right = newnode;
					std::cout << "Node added to right." << std::endl;
					return;
				}
				else{
					insert(node->right,newnode);
				}
			}
			else{
				std::cout << "Node value already in tree." << std::endl;
				return;
			}			
		}
		
		void del(int val);
		void print(leaf* node);
		void preorder(leaf* node);
		void inorder(leaf* node);
		void postorder(leaf* node);	
};

#endif