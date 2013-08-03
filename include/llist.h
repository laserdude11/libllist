/*
 * llist.h is part of libllist.
 * 
 * libllist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * libllist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with libllist.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * llist.h 
 *
 * AUTHOR: Noah Harvey
 *
 * VERSION: v0.0.1
 *
 * DESCRIPTION: main header file for libllist
 */

/*
 * MACRO: VALIDPNTR
 * 
 * PARAMETERS: x
 * 
 * DESCRIPTION: checks if given value isn't NULL or 0 and forces an exit of containing function if
 * it is.
 */
#ifndef VALIDPNTR
#define VALIDPNTR(x,returnval) if(!x) return returnval
#endif 

#ifndef __LLIST
#define __LLIST

struct node_st
{
	void* data;
	struct node_st* next;
	struct node_st* prev;
};

typedef struct node_st Node;

typedef struct llist
{
	Node* head;
	Node* tail;
	int length;	
} LList;

/*
 * FUNCTION: nodenew
 * 
 * PARAMETERS: 
 *
 * RETURNS: Node* - new node
 * 
 * DESCRIPTION: creates a newly created node with all initial values = NULL;
 *
 * NOTE: returns a NULL pointer on error
 */
Node* nodenew();

/*
 * FUNCTION: nodedestroy
 * 
 * PARAMETERS: Node* node
 *
 * RETURNS: int - error code 
 * 
 * DESCRIPTION: frees memory used by given node (including the Node* itself)
 *
 * NOTE: this does not free the next and prev variables in the structure as this will destroy the
 * list the node is found in
 */
int nodedestroy(Node* node);

/*
 * FUNCTION: llnew
 * 
 * PARAMETERS: 
 *
 * RETURNS: LList* - pointer to new llist
 * 
 * DESCRIPTION: creates a newlist
 *
 * NOTE: returns NULL pointer if error occurs
 *
 * RETURN DETAILS: upon a successful creation the newly created LList contains: 
 *   head = NULL;
 *   tail = NULL;
 *   length = 0;
 * 				
 */
LList* llnew();

/*
 * FUNCTION: lldestroy
 * 
 * PARAMETERS: LList* list
 *
 * RETURNS: int - error code
 * 
 * DESCRIPTION: frees the memory used by the linked list
 *
 * NOTES: error codes: 0 - no error; 1 - something bad happened
 */
int lldestroy(LList* list);

/*
 * FUNCTION: llappend
 * 
 * PARAMETERS: LList* list, void* data
 *
 * RETURNS: LList* - linked list with appended node
 * 
 * DESCRIPTION: appends the data to the end of the given LList
 *
 * NOTE: returns NULL pointer if error occurs
 */
LList* llappend(LList* list, void* value);

/*
 * FUNCTION: llget
 * 
 * PARAMETERS: LList* list, int index
 *
 * RETURNS: Node* - node pointer 
 * 
 * DESCRIPTION: pointer to node found at the given index. 
 *
 * NOTE: if occurs NULL pointer is returned
 */
Node* llget(LList* list, int index);

/*
 * FUNCTION: llgetvalue
 * 
 * PARAMETERS: LList* list, int index
 *
 * RETURNS: void* - void poiner
 * 
 * DESCRIPTION: returns the data found for the node at index
 */
void* llgetvalue(LList* list, int index);

/*
 * FUNCTION: llinsert
 * 
 * PARAMETERS: LList* list, void* data, int index
 *
 * RETURNS: LList* - list with inserted node
 * 
 * DESCRIPTION: inserts the given data at the given index
 *
 * NOTE: NULL pointer returned if error occurs
 *
 * INDEX NOTE: index values must be >= 0 or <= list->length
 */
LList* llinsert(LList* list, void* value, int index);

/*
 * FUNCTION: llset
 * 
 * PARAMETERS: LList* list, void* value, int index
 *
 * RETURNS: LList*  - list with inserted value
 * 
 * DESCRIPTION: inserts the given value for the node located at index
 */
LList*  llset(LList* list, void* value, int index);

/*
 * FUNCTION: llapply
 * 
 * PARAMETERS: LList* list, void (func*)(void* data) 
 *
 * RETURNS: LList* - given LList* with applied values
 * 
 * DESCRIPTION: applys a function to ALL the data nodes in a given LList
 *
 * NOTE: returns NULL if error occurs
 * NOTE: second argument should be a function that performs operations on the data of a node
 */
LList* llapply(LList* list, void (*func)(void* data));

/*
 * FUNCTION: llfilter
 * 
 * PARAMETERS: LList* list, char (func*)(void* data)
 *
 * RETURNS: LList* - newly created LList*
 * 
 * DESCRIPTION: traverses the entire llist and creates a new LList containing the nodes 
 * for which (func*) returns a value greater than 0
 *
 * NOTE: returns NULL if error occurs
 */
LList* llfilter(LList* list, char (*func)(void* data));

/*
 * FUNCTION: llmap
 * 
 * PARAMETERS: LList* list, void* (func*)(void* data)
 *
 * RETURNS: LList* - newly created LList*
 * 
 * DESCRIPTION: exactly the same as llapply but store the results in a new 
 * list instead of back into the given list.
 *
 * NOTE: returns NULL if error occurs
 * NOTE: second argument should be a function that creates a new value to be contained by a new node
 */
LList* llmap(LList* list, void* (*func)(void* data));

#endif 
