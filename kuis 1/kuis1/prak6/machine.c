#include "head.h"

void createList(list *L)
//function to create list
{
	(*L).first = NULL;
	//set the first pointer as null
}

int countElement(list L)
//function to count how many data are in the list
{
	int result = 0;
	if(L.first != NULL)
	{								//counting process will only happenning						
		elements* point;			//if the list aren't empty, then count list
		point = L.first;			//while point->next is not Null
		while(point != NULL)		
		{
			result++;
			point = point->next;
		}
	}
	return result;
}

int counttype(list L, char type[])
//function to count how many data are in the list
{
	int result = 0;
	if(L.first != NULL)
	{								//counting process will only happenning						
		elements* point;			//if the list aren't empty, then count list
		point = L.first;			//while point->next is not Null
		while(point != NULL)		
		{
			if(strcmp(point->container.type, type)==0)
			{
				result++;
			}
			
			point = point->next;
		}
	}
	return result;
}


void addFirst(menu input, list *L)
//function to add data to the head of the list
{
	elements* new;

	new = (elements*) malloc (sizeof(elements));	//locate a memory for pointer "new"
	new->container = input;						//copy the input data

	if((*L).first == NULL)
	{
		new->next = NULL;		//if the first is null, then current next will be null 
	}							//i.e. the only data on the list
	else{
		new->next = (*L).first;	//else, set the first data on the list to be the next on the list 
	}

	(*L).first = new;			//first one is now the "new"

	new = NULL;					//set the "new" as null, for it is no longer used
}

void addAfter(elements* prev, menu input, list *L)
//function to add new data to a certain position on the list
{
	elements* new;
	new = (elements*) malloc (sizeof(elements));	//locate a memory for pointer "new"
	new->container = input;						//copy the input data

	if(prev->next == NULL)
	{							//if the previous's next is null
		new->next = NULL;		//then the current next will be null
	}							//i.e. the last data on the list
	else{
		new->next = prev->next;	//else, current next is the previous one
	}

	prev->next = new;			//previous's next is now the "new"

	new = NULL;					//set the "new" as null, for it is no longer used
}

void addLast(menu input, list *L)
//function to add new data to the last position on the list
{
	if((*L).first == NULL)
	{											//if the list are empty, the addFirst
		addFirst(input, L);
	}
	else{										
		elements* prev = (*L).first;
		while(prev->next != NULL)				//search the last data on the list
		{
			prev = prev->next;
		}
		addAfter(prev, input, L);				//then, addAfter
	}

}

void print(list L1, list L2)
//function to print all the data on the list (after swapping)
{
	printf("\nmenu warung pertama:\n");
	if(L1.first != NULL)								//there are no unique code that needs to be explain here..
	{													//basically, we're just gonna print the data on the current pointer
		elements* point = L1.first;						//and move the pointer forward till we reach the last data
		// int i = 1;
		while(point != NULL)
		{
			printf("%s %s %d\n",point->container.type , point->container.name, point->container.price);
			point = point->next;
			// i++;
		}
	}

	printf("\nmenu warung kedua:\n");
	if(L2.first != NULL)
	{
		elements* point = L2.first;
		// int i = 1;
		while(point != NULL)
		{
			printf("%s %s %d\n",point->container.type , point->container.name, point->container.price);;
			point = point->next;
			// i++;
		}
	}
}

void swaps(list *L1, list *L2, swap s1, swap s2)
//function to swap the data between list number 1 and number 2
{
	elements *p1=L1->first,				//i'm using 6 pointer here... this function could run with only 4
			 *p2=L2->first,				//but i'm just gonna play safe here, so 6 it is :)
			 *b1,						//p pointer will point the current data, b for the prev data, and temp for the next data
			 *b2;
			 
	int i, head1 = -1, head2 = -1;		//and we're gonna need 2 head var (to mark the data that's gonna be swapped)

	if((strcmp(p1->container.name, s2.name) == 0) || (strcmp(p1->container.name, s1.name) == 0))
	{
		//if the data that's gonna be swapped is the head, then head is 1
		head1 = 1;
	}
	else{
		//if not, then head is 0

		while((p1 != NULL) && (head1 == -1))	//here we're gonna search the data from pointer to pointer
		{
			if((strcmp(p1->next->container.name, s2.name) == 0) || (strcmp(p1->next->container.name, s1.name) == 0))
			{
				//we search it using p->next pointer so that we got to point the prev data
				b1 = p1;	//b1 is pointing the prev data
				head1 = 0;	//and head is 0
			}
			p1 = p1->next;	//while p1 is moving forward until the loop's break
		}
	}

	if((strcmp(p2->container.name, s1.name) == 0) || (strcmp(p2->container.name, s2.name) == 0))
	{										
		head2 = 1;									//this is just the same as before, but this one is for list number 2
	}
	else{
		while((p2 != NULL) && (head2 == -1))
		{
			if((strcmp(p2->next->container.name, s1.name) == 0) || (strcmp(p2->next->container.name, s2.name) == 0))
			{
				b2 = p2;
				head2 = 0;
			}
			p2 = p2->next;
		}
	}
	
	
	if((head1 == 1) && (head2 == 1))	//if both data are the head of each list
	{
		L1->first = p1->next;			//then move the head forward
		L2->first = p2->next;
		
		addLast(p1->container, L2);		//and addLast the data from list 1 to the list 2
		addLast(p2->container, L1);		//same goes for the list number 2

		free(p1);						//then, free the swapped data 
		free(p2);
	}
	else if(head1 == 1)					//if the data on list number 1 is the head
	{
		L1->first = p1->next;			//move the head of list number 1 forward
		
		b2->next = p2->next;			//and skip the current data on the list number 2
										//this was done by pointing the b->next(previous next) to the p->next(current next)
		addLast(p1->container, L2);
		addLast(p2->container, L1);

		free(p1);						//and then free the swapped data
		free(p2);
	}
	else if(head2 == 1)
	{
		L2->first = p2->next;			//this is the same as before (this is if the data is the head of list number 2)

		b1->next = p1->next;

		addLast(p1->container, L2);
		addLast(p2->container, L1);

		free(p1);
		free(p2);
	}
	else{								//and if both data aren't the head of each list
		b1->next = p1->next;			//then skip the current data
		b2->next = p2->next;

		addLast(p1->container, L2);		//addLast data on pointer1 to the last of list 2
		addLast(p2->container, L1);		//and vice versa

		free(p1);						//then free the swapped data
		free(p2);
	}

}

void tukar(list *L1, list *L2, char wo[], char type[])
{
	elements *current,
			 *prev;

	
		prev = current;
		current = L2->first;
		if(strcmp(type, current->container.type) == 0)
		{
			if(current == L2->first)
			{
				L2->first = current->next;
				current->next = L1->first;
				L1->first = current;
			}
		}
		else{
				while(strcmp(current->container.type, type) != 0)
				{
					prev = current;
					current = current->next;
				}
				prev->next = current->next;
				current->next = L1->first;
				L1->first = current;
			}
}