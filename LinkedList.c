/***************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include "LinkedList.h"
#include "ListImplementation.h"

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

#define ILL(list)  ( * ( (LinkedList *) ((list)->pInternalList) ) )  /* Internal LinkedList */

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

static ListBoolean   llAdd           ( List list , ListElement element , int index                     ) ;
static ListBoolean   llAddAll        ( List list , List other , int index                              ) ;
static void          llClear         ( List list                                                       ) ;
static ListBoolean   llContains      ( List list , ListElement element                                 ) ;
static ListBoolean   llContainsAll   ( List list , List other                                          ) ;
static ListBoolean   llEquals        ( List list , List other                                          ) ;
static ListElement   llGet           ( List list , int index                                           ) ;
static int           llIndexOf       ( List list , ListElement element                                 ) ;
static ListBoolean   llIsEmpty       ( List list                                                       ) ;
static int           llLastIndexOf   ( List list , ListElement element                                 ) ;
static ListElement   llRemove        ( List list , int index                                           ) ;
static ListBoolean   llRemoveElement ( List list , ListElement element                                 ) ;
static ListBoolean   llRemoveAll     ( List list , List other                                          ) ;
static void          llReplaceAll    ( List list , ListElementUnaryOperator uOperator                  ) ;
static ListBoolean   llRetainAll     ( List list , List other                                          ) ;
static ListElement   llSet           ( List list , int index , ListElement element                     ) ;
static int           llSize          ( List list                                                       ) ;
static ListBoolean   llSort          ( List list , ListElementComparisonFunction compare               ) ;
static ListElement * llToArray       ( List list                                                       ) ;
static void          llPrint         ( List list , char * listName , ListElementPrintingFunction print ) ;
static void          llDestroy       ( List list                                                       ) ;

/***************************************************************************************************************************************************/




/* This is a suggested data structure (you may change it if you wish) ******************************************************************************/

typedef struct node
{
  ListElement   element ;
  struct node * next    ;
}
Node ;

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

typedef struct linkedList
{
  int    numberOfElements ;
  //Node * pHead            ;
  Node * pTail            ;
}
LinkedList ;

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

static void setFunctionPointers ( List list )
{
  list->add           = llAdd           ;
  list->addAll        = llAddAll        ;
  list->clear         = llClear         ;
  list->contains      = llContains      ;
  list->containsAll   = llContainsAll   ;
  list->equals        = llEquals        ;
  list->get           = llGet           ;
  list->indexOf       = llIndexOf       ;
  list->isEmpty       = llIsEmpty       ;
  list->lastIndexOf   = llLastIndexOf   ;
  list->remove        = llRemove        ;
  list->removeElement = llRemoveElement ;
  list->removeAll     = llRemoveAll     ;
  list->replaceAll    = llReplaceAll    ;
  list->retainAll     = llRetainAll     ;
  list->set           = llSet           ;
  list->size          = llSize          ;
  list->sort          = llSort          ;
  list->toArray       = llToArray       ;
  list->print         = llPrint         ;
  list->destroy       = llDestroy       ;
}

/***************************************************************************************************************************************************/



/***************************************************************************************************************************************************/

List createLinkedList ( void )
{
    LinkedList *newLinkedList = malloc(sizeof(LinkedList));

    newLinkedList->pTail = malloc(sizeof(struct node));
    newLinkedList->numberOfElements = 0;
    newLinkedList->pTail->next = malloc(sizeof(struct node));
    newLinkedList->pTail->element = NULL;

    if(newLinkedList->pTail == NULL || newLinkedList->pTail->next == NULL){
        return NULL;
    }
    
    
    List lst = malloc(sizeof(struct list));
    lst->pInternalList = newLinkedList;
    setFunctionPointers(lst);

    return lst;
}

/*=================================================================================================================================================*/

List createLinkedListFrom ( List other )  /* 'other' list can be implemented using arrays or other underlying data structures */
{
    int digits [] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 } ;
    
    List newLinkedList = createLinkedList();
    ListElement *n =  ((other)->pInternalList);

    printf("%d \n", listSize(other));
    
    for(int i = 0; i<listSize(other); i++){
        llAdd(newLinkedList, n, LIST_NA);
    }
    
    


  return newLinkedList;
}

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/
/* Inserts the specified element at the specified position in the list. Shifts the element currently at that position (if any) and any subsequent
   elements to the right (adds one to their indices). If index is LIST_NA, then appends the specified element to the end of the list.
   Returns True if the operation is successful.
   Returns False if the operation is unsuccessful; for example if index < 0, or index > listSize(list), or running out of memory. */

ListBoolean llAdd ( List list , ListElement element , int index )
{
    LinkedList *data = &ILL(list);
    //Node *nn = malloc(sizeof(struct node));


    while(data->pTail->next!= NULL){
        data->pTail = data->pTail->next;
    }

    Node *newNode = malloc(sizeof(struct node));
    newNode->element = element;
    newNode->next = NULL;

    data->pTail = newNode;

    data->numberOfElements++;

    
    return True;
}

/*=================================================================================================================================================*/
/* Inserts all of the elements in the other list into the list at the specified position. Shifts the element currently at that position (if any) and
   any subsequent elements to the right (increases their indices). If index is LIST_NA, then appends all of the elements in the other list to the end
   of the list. The new elements will appear in the list in the order that they are stored in the other list. The behavior of this operation is
   undefined if the other list is modified while the operation is in progress (note that this will occur if the other list is the same as the list,
   and it is nonempty).
   Returns True if the list is changed as a result of the call.
   Returns False if the list is unchanged and/or if the operation is unsuccessful. */

ListBoolean llAddAll ( List list , List other , int index )
{
    LinkedList *first = &ILL(list);
    LinkedList *second = &ILL(createLinkedListFrom(other));

    struct node * nn = first->pTail;
    for(int i = 0; i<first->numberOfElements; i++){
        nn = nn->next;
    }

    nn = second->pTail;
    first->pTail = nn;
    first->numberOfElements += second->numberOfElements;

    //printf("%d, %d", first->numberOfElements,*(int *)nn->element);

    //free(nn);

    // for(int i=0; i<listSize(other); i++){
    //     llAdd(list, second->pTail->element, LIST_NA);
    //     second->pTail = second->pTail->next;
    // }

  return True;
}

/*=================================================================================================================================================*/

void llClear ( List list )
{
}

/*=================================================================================================================================================*/

ListBoolean llContains ( List list , ListElement element )
{
  return False;
}

/*=================================================================================================================================================*/

ListBoolean llContainsAll ( List list , List other )
{
  return False;
}

/*=================================================================================================================================================*/

ListBoolean llEquals ( List list , List other )
{
  return False;
}

/*=================================================================================================================================================*/

ListElement llGet ( List list , int index )
{
  return 0;
}

/*=================================================================================================================================================*/

int llIndexOf ( List list , ListElement element )
{
  return False;
}

/*=================================================================================================================================================*/

ListBoolean llIsEmpty ( List list )
{
  return False;
}

/*=================================================================================================================================================*/

int llLastIndexOf ( List list , ListElement element )
{
  return False;
}

/*=================================================================================================================================================*/

ListElement llRemove ( List list , int index )
{
  return 0;
}

/*=================================================================================================================================================*/

ListBoolean llRemoveElement ( List list , ListElement element )
{
  return False;
}

/*=================================================================================================================================================*/

ListBoolean llRemoveAll ( List list , List other )
{
  return False;
}

/*=================================================================================================================================================*/

void llReplaceAll ( List list , ListElementUnaryOperator uOperator )
{
  
}

/*=================================================================================================================================================*/

ListBoolean llRetainAll ( List list , List other )
{
  return False;
}

/*=================================================================================================================================================*/

ListElement llSet ( List list , int index , ListElement element )
{
  return 0;
}

/*=================================================================================================================================================*/

int llSize ( List list )
{
    LinkedList *data = &ILL(list);

    int size = 0;
    while(data->pTail!= NULL){
        size++;
    }

    return size;
}

/*=================================================================================================================================================*/

ListBoolean llSort ( List list , ListElementComparisonFunction compare )
{
  return False;
}

/*=================================================================================================================================================*/

ListElement * llToArray ( List list )
{
  return 0;
}

/*=================================================================================================================================================*/

void llPrint ( List list , char * listName , ListElementPrintingFunction print )
{
    LinkedList *data = &ILL(list);

    printf("LinkedList  : %s\n", listName);
    printf("Elements    : %d\n", data->numberOfElements);
    for(int i = 0; i<data->numberOfElements; i++){
        printf("[%d] %d \n", i, *(int *) data->pTail->element);
        data->pTail = data->pTail->next;
    }
    // while(data->pTail != NULL){
    //     printf("[%d] \n", *(int *) data->pTail->element);
    //     data->pTail = data->pTail->next;
    // }
}

/*=================================================================================================================================================*/

void llDestroy ( List list )
{
}

/***************************************************************************************************************************************************/
