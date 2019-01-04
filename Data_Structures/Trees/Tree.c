// Checked and Completed!
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Tree{

    int value;
	struct Tree* parent_node;
    struct Tree* left_child;
    struct Tree* right_child;

} Tree;


Tree* FirstNode;

void addnewNode(int new_value,Tree* CurrNode,int loR){
/*
	Objective: add new Node to our Tree

*/

	Tree* NewNode= (Tree*)malloc(sizeof(Tree*));

	NewNode->parent_node = CurrNode;

	NewNode->value = new_value;

	if (loR == 0){
		CurrNode->left_child = NewNode;
	}else{
		CurrNode->right_child = NewNode;
	};
}

// Utils:
Tree* newNode(int nval) {
// Create new node

	Tree* NewNode = (Tree*)malloc(sizeof(Tree*));
	NewNode->value = nval;
	return NewNode;
}

Tree* TreeInsert(int new_value,Tree* CurrNode){

	if (CurrNode == NULL){
		// Create New node;
		return newNode(new_value);
	}
	else{
		if (new_value < CurrNode->value )
			CurrNode->left_child = TreeInsertBySir(new_value,CurrNode->left_child);
		else CurrNode->right_child = TreeInsertBySir(new_value,CurrNode->right_child);
	}

}


int LeftOrRight = -1;
Tree* Search_Tree(int fvalue,Tree* CurrNode,int lor){
	if(CurrNode == NULL)return NULL;

	// returing the node where this value is found
	if (CurrNode->value == fvalue){
		LeftOrRight = lor;
		return CurrNode;
	}

	if (fvalue < CurrNode->value ){
		// go left
		Search_Tree(fvalue,CurrNode->left_child,0);
	}else{
		// go right
		Search_Tree(fvalue,CurrNode->right_child,1);
	}
}


Tree* del_node_1child(Tree* Node,int delit){
/*
 Objective: delete the node with only one child

 More-info: 
			if delit == 0 then dont free the node
*/
	// connect the node's parent to this nodes's childnode
	if (Node->left_child != NULL){

		if (Node->parent_node->left_child == Node){
			Node->parent_node->left_child = Node->left_child;
		}
		else if(Node->parent_node->right_child = Node){
			Node->parent_node->right_child = Node->left_child;
		}
		if (delit)free(Node);
	}

	else if(Node->right_child != NULL){

		if (Node->parent_node->left_child == Node){
			Node->parent_node->left_child = Node->right_child;
		}
		else if(Node->parent_node->right_child = Node){
			Node->parent_node->right_child = Node->right_child;
		}

		if (delit)free(Node);
	}
}

Tree* delete_node(int fval,Tree* CurrNode){
	// delete the node and return new tree

	// case1 : no child
	// Search that node
	Tree* node2del = Search_Tree(fval,CurrNode,LeftOrRight);// search the Tree and return that node

	if (node2del->left_child == NULL && node2del->right_child == NULL){
		// then its in case 1

		if (node2del->parent_node->left_child == node2del)
			node2del->parent_node->left_child = NULL;

		if (node2del->parent_node->right_child == node2del)
			node2del->parent_node->right_child = NULL;

		free(node2del);
		return NULL;
	}

	// case 2:1child
	if (node2del->left_child == NULL || node2del->right_child == NULL){
		del_node_1child(node2del,1);

		return NULL;
	}

	// case 3: 2 child
	// Find the smallest node in the right side of the CurrNode and replace CurrNode from this smallest valued node and free this CurrNode

	// searching
	Tree* curr_node = node2del->right_child;

	restart:
	while(curr_node->left_child != NULL || curr_node->right_child != NULL){
		// go to the last nodes...
		if (curr_node -> left_child != NULL){
			// recusively visit this codeBlock and do the same process again untill you found the smallest valued node.
			curr_node = curr_node->left_child;
			goto restart;

		}else{
			// go right
			if (curr_node ->right_child != NULL){
				// if its true then, this curr_node must be the smallest node so this state is equevalent to 1 child deletion
				// but instead of deletion the child node simply do the connection with its parent and dont delete
				// curr_node... because we need to for replacing the Node which is going to be deleted.

				del_node_1child(curr_node,0);// dont delete it just make the connection
			}

			curr_node->parent_node->left_child = NULL;// detatching this node from its parent_node

				break;
			}
	}

	// so this curr_node is our smallest node

	// Copy node2del in curr_node	
	curr_node->left_child  = node2del->left_child;
	curr_node->right_child = node2del->right_child;
	curr_node->parent_node = node2del->parent_node;

	node2del->left_child->parent_node = curr_node;
	node2del->right_child->parent_node = curr_node;

	// check weather node2del is the Left to the node2del's parent_node or to its right


	if (node2del->parent_node->left_child == node2del)
		node2del->parent_node->left_child = curr_node;

	if (node2del->parent_node->right_child == node2del)
		node2del->parent_node->right_child = curr_node;


	free(node2del);// finally delete this node;

}