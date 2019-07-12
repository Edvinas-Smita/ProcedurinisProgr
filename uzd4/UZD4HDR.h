/*
Edvinas Smita - VU MIF PS 1k. 2gr.
*/

typedef struct quoteListUnquote
{
	int listValue;
	struct quoteListUnquote *nextItem;
	struct quoteListUnquote *prevItem;
}listName;

#ifndef createNItemStructINCLUDED
#define createNItemStructINCLUDED
int createNItemStruct(listName **startItem, unsigned int N);
#endif

#ifndef setValueXToStructItemIINCLUDED
#define setValueXToStructItemIINCLUDED
int setValueXToStructItemI(listName *structPointer, int X, unsigned int I);
#endif

#ifndef appendNItemsToStructINCLUDED
#define appendNItemsToStructINCLUDED
int appendNItemsToStruct(listName *structPointer, unsigned int N);
#endif

#ifndef insertNItemsAtIPosINCLUDED
#define insertNItemsAtIPosINCLUDED
int insertNItemsAtIPos(listName **structPointer, unsigned int N, unsigned int I);
#endif

#ifndef deleteNItemsFromStructEndINCLUDED
#define deleteNItemsFromStructEndINCLUDED
int deleteNItemsFromStructEnd(listName **structPointer, unsigned int N);
#endif

#ifndef deleteNItemsFromIPosINCLUDED
#define deleteNItemsFromIPosINCLUDED
int deleteNItemsFromIPos(listName **structPointer, unsigned int N, unsigned int I);
#endif

#ifndef swapStructItemsByIndexINCLUDED
#define swapStructItemsByIndexINCLUDED
int swapStructItemsByIndex(listName **structPointer, unsigned int I, unsigned int J);
#endif

#ifndef swapMultipleStructItemsByIndexINCLUDED
#define swapMultipleStructItemsByIndexINCLUDED
int swapMultipleStructItemsByIndex(listName **structPointer, unsigned int N, unsigned int I, unsigned int M, unsigned int J);
#endif

#ifndef printStructChainINCLUDED
#define printStructChainINCLUDED
void printStructChain(listName *structPointer);
#endif

#ifndef fillValuesINCLUDED
#define fillValuesINCLUDED
void fillValues(listName *structPointer);
#endif

#ifndef reverseOrderIToJINCLUDED
#define reverseOrderIToJINCLUDED
int reverseOrderIToJ(listName **structPointer, unsigned int I, unsigned int J);
#endif

#ifndef freeAllINCLUDED
#define freeAllINCLUDED
int freeAll(listName **structPointer);
#endif





#ifndef appendOneItemToEndWithValXINCLUDED
#define appendOneItemToEndWithValXINCLUDED
int appendOneItemToEndWithValX(listName **structPointer, int X);
#endif

#ifndef insertOneItemAtIPosWithValXINCLUDED
#define insertOneItemAtIPosWithValXINCLUDED
int insertOneItemAtIPosWithValX(listName **structPointer, unsigned int I, int X);
#endif
