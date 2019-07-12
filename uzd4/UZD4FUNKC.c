/*
Edvinas Smita - VU MIF PS 1k. 2gr.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct quoteListUnquote
{
	int listValue;
	struct quoteListUnquote *nextItem;
	struct quoteListUnquote *prevItem;
}listName;

int createNItemStruct(listName **structPointer, unsigned int N)
{
	if(*structPointer!=NULL)
		freeAll(structPointer);
	
	int i;
	listName *listItem=malloc(sizeof(listName));
	if(listItem==NULL)
		return N;
	*structPointer=listItem;
	
	listItem->prevItem=NULL;
	for(i=1; i<N; i++)
	{
		listItem->nextItem=malloc(sizeof(listName));
		if(listItem->nextItem==NULL)
			return N-i;				/*Kiek elementu nepavyko sukurti*/
		listItem->nextItem->prevItem=listItem;
		listItem=listItem->nextItem;
	}
	listItem->nextItem=NULL;
	return 0;
}

int setValueXToStructItemI(listName *structPointer, int X, unsigned int I)
{
	listName *listItem=structPointer;
	int i;
	for(i=0; i<I; i++)
	{
		if(listItem->nextItem==NULL)
			return 1;
		listItem=listItem->nextItem;
	}
	listItem->listValue=X;
	return 0;
}

int appendNItemsToStruct(listName *structPointer, unsigned int N)
{
	listName *listItem=structPointer, *extraList=NULL;
	while(listItem->nextItem!=NULL)
		listItem=listItem->nextItem;
	
	int failed=createNItemStruct(&extraList, N);
	if(failed==0)
	{
		listItem->nextItem=extraList;
		extraList->prevItem=listItem;
	}
	
	return failed;
}

int insertNItemsAtIPos(listName **structPointer, unsigned int N, unsigned int I)
{
	listName *listItem=*structPointer, *extraList=NULL, *extraListItem=NULL;
	int i;
	for(i=0; i<I; i++)
	{
		if(listItem->nextItem==NULL)
			return N;
		listItem=listItem->nextItem;
	}
	int failed=createNItemStruct(&extraList, N);
	if(failed==N)
		return N;
	extraListItem=extraList;
	while(extraListItem->nextItem!=NULL)
		extraListItem=extraListItem->nextItem;
	
	if(I)
	{
		extraList->prevItem=listItem;
		extraListItem->nextItem=listItem->nextItem;
		if(listItem->nextItem!=NULL)
			listItem->nextItem->prevItem=extraListItem;
		listItem->nextItem=extraList;
	}
	else
	{
		*structPointer=extraList;
		extraListItem->nextItem=listItem;
		listItem->prevItem=extraListItem;
	}
	return 0;
}

int deleteNItemsFromStructEnd(listName **structPointer, unsigned int N)
{
	listName *listItem=*structPointer, *listPrevItem=NULL;
	while(listItem->nextItem!=NULL)
		listItem=listItem->nextItem;
		
	int i;
	for(i=0; i<N; i++)
	{
		if(listItem->prevItem==NULL)
		{
			*structPointer=NULL;
			return 1;
		}
		listPrevItem=listItem->prevItem;
		free(listItem);
		listItem=listPrevItem;
	}
	listItem->nextItem=NULL;
	return 0;
}

int deleteNItemsFromIPos(listName **structPointer, unsigned int N, unsigned int I)
{
	listName *listItem=*structPointer, *listLastPart=NULL;
	int i;
	for(i=0; i<I; i++)
	{
		if(listItem->nextItem==NULL)
			return 1;
		listItem=listItem->nextItem;
	}
	
	listLastPart=listItem;
	if(I)
		listItem=listItem->prevItem;
	
	for(i=0; i<N; i++)
	{
		listLastPart=listLastPart->nextItem;
		if(listLastPart==NULL)
		{
			break;
		}
		else
		{
			free(listLastPart->prevItem);
		}
	}
	
	if(I)
	{
		listItem->nextItem=listLastPart;
		if(listLastPart!=NULL)
			listLastPart->prevItem=listItem;
	}
	else
	{
		*structPointer=listLastPart;
		if(listLastPart!=NULL)
		{
			return 0;	/*returnint kad viska istryne*/
		}
		else
		{
			listLastPart->prevItem=NULL;
		}
	}
	
	return 0;
}

int swapStructItemsByIndex(listName **structPointer, unsigned int I, unsigned int J)
{
	if(I==J)
		return 0;
	
	int i;
	if(I>J)
	{
		i=I;
		I=J;
		J=i;
	}
	
	listName *listItemI=*structPointer, *listItemJ=*structPointer, *temp=NULL;
	for(i=0; i<I; i++)
	{
		if(listItemI->nextItem==NULL)
			return 1;
		listItemI=listItemI->nextItem;
	}
	for(i=0; i<J; i++)
	{
		if(listItemJ->nextItem==NULL)
			return 2;
		listItemJ=listItemJ->nextItem;
	}
	
	if(listItemI->nextItem==listItemJ)
	{
		listItemJ->prevItem=listItemI->prevItem;
		listItemI->nextItem=listItemJ->nextItem;
		if(I)
		{
			listItemI->prevItem->nextItem=listItemJ;
		}
		else
		{
			*structPointer=listItemJ;
			listItemJ->prevItem=NULL;
		}
		listItemI->prevItem=listItemJ;
		if(listItemJ->nextItem!=NULL)
			listItemJ->nextItem->prevItem=listItemI;
		listItemJ->nextItem=listItemI;
		return 0;
	}
	else
	{
		temp=listItemI->prevItem;
		listItemI->prevItem=listItemJ->prevItem;
		listItemJ->prevItem->nextItem=listItemI;
		if(I)
		{
			temp->nextItem=listItemJ;
			listItemJ->prevItem=temp;
		}
		else
		{
			*structPointer=listItemJ;
			listItemJ->prevItem=NULL;
		}
		listItemI->nextItem->prevItem=listItemJ;
		
		if(listItemJ->nextItem!=NULL)
			listItemJ->nextItem->prevItem=listItemI;
		
		temp=listItemI->nextItem;
		listItemI->nextItem=listItemJ->nextItem;
		listItemJ->nextItem=temp;
	}
	return 0;
}

int swapMultipleStructItemsByIndex(listName **structPointer, unsigned int N, unsigned int I, unsigned int M, unsigned int J)
{
	int i;
	if(I>J)
	{
		i=I;
		I=J;
		J=i;
		
		i=N;
		N=M;
		M=i;
	}
	if(N>(J-I))
		return 3;
	
	listName *listItemIStart=*structPointer, *listItemJStart=*structPointer, *listItemIEnd=NULL, *listItemJEnd=NULL, *temp=NULL;
	
	for(i=0; i<I; i++)
	{
		if(listItemIStart->nextItem==NULL)
			return 1;
		listItemIStart=listItemIStart->nextItem;
	}
	listItemIEnd=listItemIStart;
	for(i=1; i<N; i++)
	{
		if(listItemIEnd->nextItem==NULL)
			break;
		listItemIEnd=listItemIEnd->nextItem;
	}
	
	
	for(i=0; i<J; i++)
	{
		if(listItemJStart->nextItem==NULL)
			return 2;
		listItemJStart=listItemJStart->nextItem;
	}
	listItemJEnd=listItemJStart;
	for(i=1; i<M; i++)
	{
		if(listItemJEnd->nextItem==NULL)
			break;
		listItemJEnd=listItemJEnd->nextItem;
	}
	
	if(I)
		listItemIStart->prevItem->nextItem=listItemJStart;
	if(listItemJEnd->nextItem!=NULL)
		listItemJEnd->nextItem->prevItem=listItemIEnd;
	if(listItemIEnd->nextItem==listItemJStart)
	{
		listItemJStart->prevItem=listItemIStart->prevItem;
		listItemIStart->prevItem=listItemJEnd;
		
		listItemIEnd->nextItem=listItemJEnd->nextItem;
		listItemJEnd->nextItem=listItemIStart;
	}
	else
	{
		listItemJStart->prevItem->nextItem=listItemIStart;
		listItemIEnd->nextItem->prevItem=listItemJEnd;
	
		temp=listItemIStart->prevItem;
		listItemIStart->prevItem=listItemJStart->prevItem;
		listItemJStart->prevItem=temp;
	
		temp=listItemIEnd->nextItem;
		listItemIEnd->nextItem=listItemJEnd->nextItem;
		listItemJEnd->nextItem=temp;
	}
	if(I==0)
		*structPointer=listItemJStart;
	return 0;
}

void printStructChain(listName *structPointer)
{
	listName *listItem=structPointer;
	while(listItem!=NULL)
	{
		printf("praeitas %p |dabartinis %p |kitas %p |reiksme %d\n", listItem->prevItem, listItem, listItem->nextItem, listItem->listValue);
		listItem=listItem->nextItem;
	}
}

void fillValues(listName *structPointer)
{
	listName *listItem=structPointer;
	int i=0;
	while((listItem) != NULL)
	{
		listItem->listValue=i++;
		listItem=listItem->nextItem;
	}
}

int reverseOrderIToJ(listName **structPointer, unsigned int I, unsigned int J)
{
	int i;
	if(I>J)
	{
		i=I;
		I=J;
		J=i;
	}
	for(i=0; i<(J-I)/2; i++)
		if(swapStructItemsByIndex(structPointer, I+i, J-i))
			return 1;
	
	return 0;
}

int freeAll(listName **structPointer)
{
	if(*structPointer==NULL)
		return 1;
	listName *listItem=*structPointer;
	
	while(listItem->nextItem!=NULL)
	{
		listItem=listItem->nextItem;
		free(listItem->prevItem);
	}
	free(listItem);
	*structPointer=NULL;
	return 0;
}

int appendOneItemToEndWithValX(listName **structPointer, int X)
{
	listName *listItem=*structPointer;
	if(listItem==NULL)
	{
		*structPointer=malloc(sizeof(listName));
		if(*structPointer==NULL)
			return 1;
		listItem=*structPointer;
		listItem->prevItem=NULL;
		listItem->nextItem=NULL;
		listItem->listValue=X;
	}
	else
	{
		while(listItem->nextItem!=NULL)
			listItem=listItem->nextItem;
		listItem->nextItem=malloc(sizeof(listName));
		if(listItem==NULL)
			return 1;
		listItem->nextItem->prevItem=listItem;
		listItem->nextItem->nextItem=NULL;
		listItem->nextItem->listValue=X;
	}
	return 0;
}
int insertOneItemAtIPosWithValX(listName **structPointer, unsigned int I, int X)
{
	int failed=insertNItemsAtIPos(structPointer, 1, I);
	if(failed)
		return failed;
	
	int i;
	listName *listItem=*structPointer;
	
	for(i=0; i<I; i++)
	{
		if(listItem->nextItem==NULL)
			return 1;
		listItem=listItem->nextItem;
	}
	listItem->listValue=X;
	return 0;
}
