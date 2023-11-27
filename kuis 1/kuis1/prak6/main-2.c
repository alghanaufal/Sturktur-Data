#include "head.h"

int main(){

	list L1, L2;		//making 2 list
	menu temp;			//and creating temp var

	createList(&L1);	//creating L1 and L2
	createList(&L2);

	int i, list1, list2;
	scanf("%d", &list1);

	for(i=0; i<list1; i++)
	{
		scanf("%s %s %d", temp.type, temp.name, &temp.price);
		addLast(temp, &L1);		//addLast the input data to the L1
	}

	scanf("%d", &list2);

	for(i=0; i<list2; i++)
	{
		scanf("%s %s %d", temp.type, temp.name, &temp.price);
		addLast(temp, &L2);		//addLast the input data to the L2
	}


    char wo[10], type[10];
	scanf("%s %s", wo, type);

	int minum1 = 0, snack1 = 0;

	if(strcmp(type, "minuman") == 0){ minum1 = 1;}
	else{snack1 = 1;}


	int jum_minuman = 0;
	int jum_snack = 0;
	if(strcmp(wo, "pertama") == 0)
	{
		if(minum1 == 1)
		{
			jum_minuman = counttype(L2, "minuman");
			jum_snack = counttype(L1, "snack");
		}
	}

    // better_swaps(&L1, &L2, wo, type);
	for(i=0; i<list1; i++)
	{
		if(minum1 == 1)
		{
			tukar(&L1, &L2, wo, "minuman");
		}
		else{
			tukar(&L1, &L2, wo, "snack");
		}
		
	}

	for(i=0; i< countElement(L2); i++)
	{
		if(minum1 == 1)
		{
			tukar(&L2, &L1, wo, "minuman");
		}
		else{
			tukar(&L2, &L1, wo, "snack");
		}
	}
	
	print(L1, L2);					//calling print function to print out the list

	return 0;
}
