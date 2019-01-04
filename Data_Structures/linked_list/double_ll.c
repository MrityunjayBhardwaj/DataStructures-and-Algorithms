#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
    Linked List
*/

typedef struct list{

    struct list *pre;  // pointer to previous node
    int value;         // value of this node
    struct list *next; // pointer to next node

} list;


// initializing pointers of the first and last elements of the list
list *firstMember;
list *lastMember;


void insert(list *firstNode,list *lastNode,int new_value,int insert_index){
/* 
    Objective: Inserting new element to the list

    Input:
            firstNode,lastNode = Pointer to the firstnode and last node of the list
            new_value          = value of this new node that we are inserting inside the list
            insert_index       = where do we want to insert the new node

    Output:
            void (all the changes we want are done directly to the list so we don't have to return anything)

    More-Info: 
            if insert_index == 0            -> then, make new node the "*firstNode" in the list
            if insert_index == 0-list_len-1 -> then, insert this new node inbetween the list
            if insert_index >= list_len-1   -> then, make this new node,the "*lastNode" of the list
*/

    list* new_node  = (list*)malloc(sizeof(list)); 
    new_node->value = new_value;

    list* curr_node = firstNode;

    int c_index = 0;
    while(curr_node != NULL){
        if(c_index == insert_index){// then insert new node into that index 

            new_node->pre  = curr_node->pre;
            new_node->next = curr_node;

            curr_node->pre = new_node;

            
            if(c_index == 0)firstNode = curr_node;// if its the first index, that means we need to add the new_node at the firstindex of the list

        }
        
        if(curr_node->next == NULL){ // then its the last node, so we need to add the new_node at the last of the list
            new_node->pre   = curr_node;
            curr_node->next = new_node;

            lastNode = new_node; 

            break;// becuz its the last node, we can safely, stop the loop here.
        }

        c_index++;
        curr_node = curr_node->next;
    }
};

void delete(list* firstNode,list* lastNode,int del_index){
/*
    Objective : delete the node @del_index in the list

    Input:
            firstNode,lastNode :  same as insert function inputs
            del_index : index of node to delete
    Output: 
            void;

    *:
*/
    int c_index = 0;
    list* curr_node   = firstNode;

    while(curr_node != NULL){

        if(c_index == del_index){

            if(curr_node->pre == NULL){ // which means we hav to delete the firstNode
                firstNode = curr_node->next;
            }
            else{
                curr_node->pre->next = curr_node->next;
            }

            if(curr_node->next == NULL){ // which means we have to delete the lastNode
               lastNode = curr_node->pre; 
            }
            else{
                curr_node->next->pre = curr_node->pre;
            }

            free(curr_node);

            return;
        }
        curr_node = curr_node->next;
        c_index++;
    }

}

list* search(list* firstNode,int search_value){
/*
    Objective: Search and reture the node which contain search_value

    Input : 
            firstNode : same as insert() inputs
            search_value: what value are we looking for

    Output: 
            Node reference that contain that search_value


*/

    list *curr_node = firstNode;

    while(curr_node->next != NULL){
        if (curr_node->value == search_value)return curr_node;
        curr_node = curr_node->next;
    }
};

// UTILs:-
int calc_len(list* firstNode){
/*
    Objective:  calculate the length of the list

    Input : 
            firstNode : same as insert() inputs
    Output :
            length of the list

*/

    int length = 0;
    list* curr_node = firstNode;

    while(curr_node != NULL){
        length++;
        curr_node = curr_node->next; 
    }

    return length;
}
