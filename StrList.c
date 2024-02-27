#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct _Node{
	struct _Node* next;
	char* data;
 }
 _Node;
 
typedef struct StrList
{
	_Node* head;
	size_t length;
}
StrList;

/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_alloc(){
	StrList* p= (StrList*)malloc(sizeof(StrList));
	if (p == NULL)
	{
		printf("error shrodi");
		exit(1);
	}
	return p;
	
}

/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */
void StrList_free(StrList* StrList){
	_Node* curr= StrList->head;
	_Node* next;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr=next;
	}
	free(curr);
	free(StrList);
}
/*
 * Returns the number of elements in the StrList.
 */
size_t StrList_size(const StrList* StrList){
	
	return StrList->length;
}
/*
 * Inserts an element in the end of the StrList.
 */
void StrList_insertLast(StrList* StrList,  const char* data1){
	_Node* newnode = (_Node*)malloc(sizeof(_Node));
    if (newnode == NULL)
    {
        exit(1);
    }
    newnode->data = strdup(data1);
    _Node* last = StrList->head;
    if(StrList->head == NULL)
    {
        StrList->head = newnode;
        StrList->length++;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newnode;
    StrList->length++;

}
	
/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList* StrList,
	const char* data,int index){
	_Node *p=StrList->head;
	
	if (index>StrList->length){
		return;
	}
	if (index==0){
		_Node* newnode = (_Node*)malloc(sizeof(_Node));
		newnode->next=StrList->head;
		newnode->data = strdup(data);
		StrList->head=newnode;
		StrList->length++;

		return;
	}
	while (index>1)
	{
		p=p->next;
		index--;
	}
	_Node *sharonk12=(_Node *)malloc(sizeof(_Node));
	sharonk12->next=p->next;
	sharonk12->data=strdup(data);
	p->next=sharonk12;	
	StrList->length++;
	}
	
/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList* StrList){
	return StrList->head->data;}
/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* StrList){
	_Node *p=StrList->head;
	while (p !=NULL)
	{	
		if((p->next)==NULL){
			printf("%s",p->data);
			printf("\n");
			return;
		}
		else{
		printf("%s ",p->data);
		p=p->next;
	}}
	printf("\n");
	
}
/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* Strlist,int index){
	_Node *p=Strlist->head;
	if(index>Strlist->length){
		return;
	}
	for(int i=0;i<index;i++)
	{
		p=p->next;
	}
	printf("%s\n",p->data);
}

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* Strlist){
		_Node *p =Strlist->head;
		int count=0;
		while (p !=NULL)
		{
		count= count +strlen(p->data);
		p=p->next;
		}
		return count;	
		}
/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
	_Node *p =StrList1->head;
	_Node *s =StrList2->head;
	int i=1;
	while ((p!=NULL)&&(s!=NULL)){
		i=strcmp(p->data,s->data);
		if (i==0) return i;
		s=s->next;
		p=p->next;
		}
	return i;
}
/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* StrList1){
	StrList* clone = StrList_alloc();
    if (StrList1 == NULL) {
        return NULL;
	
    }

    
    if (clone == NULL) {
        
        return NULL;
    }
  
    clone->length = StrList1->length;
    clone->head = NULL;

    _Node* current = StrList1->head;
    _Node* clone_prev = NULL;

    while (current != NULL) {
        
        _Node* new__node = (_Node*)malloc(sizeof(_Node));
        if (new__node == NULL) {
            StrList_free(clone);
            return NULL;
        }

        new__node->data = strdup(current->data);
        if (new__node->data == NULL) {
            StrList_free(clone);
            free(new__node);
            return NULL;
        }

        new__node->next = NULL;
        if (clone_prev == NULL) {
            clone->head = new__node;
        } else {
            clone_prev->next = new__node;
        }
        clone_prev = new__node;
        current = current->next;
    }
    return clone;
}


/*
 * Reverces the given StrList. 
 */
void StrList_reverse( StrList* StrList){
	_Node *p =StrList->head;
	_Node *h=NULL;
	_Node *temp=NULL;
	while (p->next !=NULL){
		temp=p;
		p=p->next;
		temp->next=h;
		h=temp;
		
	}
	p->next=h;
	StrList->head=p;

}

/*
 * Sort the given list in lexicographical order 
 */
void StrList_sort( StrList* StrList){
	if (StrList == NULL||StrList->head == NULL|| StrList->head->next == NULL)
	{
		return;
	}
	int swapped;
	_Node* end = NULL;
	for (size_t i = 0; i < StrList->length; i++)
	{
		swapped=0;
		_Node* current = StrList->head;
		while (current->next!=end)
		{
			if (strcmp(current->data,current->next->data)>0)
			{
				char* tempData = current->data;
				current->data = current->next->data;
				current->next->data= tempData;
				swapped= 1;
			}
			current=current->next;
		}
		if (swapped ==0)
		{
			break;
		}
		end=current;
	}
}

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList){
	if (StrList == NULL||StrList->head == NULL|| StrList->head->next == NULL)
	{
		return 1;
	}
	_Node* current = StrList->head;
	while (current->next!=NULL)
	{
		if (strcmp(current->data,current->next->data)>0)
		{
			return 0;
		}
		current = current->next;
	}
	return 1;
}
int StrList_count(StrList* StrList, const char* data){
    int count =0;
    _Node* p = StrList->head;
    if (StrList == NULL || data == NULL)
    {
        return count;
    }
    for (size_t i = 0; i < StrList->length; i++)
    {
        if (strcmp(p->data,data)==0)
        {
            count++;
        }
        p = p->next;
    }
    return count;
}
void StrList_remove(StrList* StrList, const char* data){
    _Node* p = StrList->head;
    _Node* nextNode = p->next;
    while (p!= NULL)
    {
        if (strcmp(nextNode->data,data)==0)
        {
			
            free(nextNode->data);
            p->next = nextNode->next;
            free(nextNode);
			StrList->length--;
			nextNode=p->next;
        }
        else nextNode = nextNode->next;
        p=p->next;
    }
}

/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* StrList, int index){
	_Node* p = StrList->head;
	_Node* z;
	if(index>StrList->length){
		printf("index is too big");
		return;
	}
	while(index>1)
	{
		 p= p->next;
		 index--;
	}
	z=p->next;
	p->next = z->next;
	StrList->length--;
}


