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
  Node * pHead            ;
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



/* Constructs an empty list.
   Returns the created list, or NULL if running out of memory. 
   
   
typedef struct node
{
  ListElement   element ;
  struct node * next    ;
}
Node ;

typedef struct linkedList
{
  int    numberOfElements ;
  Node * pHead            ;
  Node * pTail            ;
}
LinkedList ;*/

/***************************************************************************************************************************************************/

List createLinkedList ( void )
{
    LinkedList *newLinkedList = malloc(sizeof(LinkedList));
    if(newLinkedList == NULL){
        return NULL;
    }

    newLinkedList->numberOfElements = 0;
    newLinkedList->pHead = malloc(sizeof(struct node));
    newLinkedList->pTail = malloc(sizeof(struct node));

    if(newLinkedList->pTail || newLinkedList->pHead){
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

    List data = createLinkedList();
    data = other;

  return data;
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
    if(data == NULL){
        return False;
    }
    
    struct node *newNode = malloc(sizeof(struct node));
    //newNode->next = malloc(sizeof(struct node));
    newNode->element = element;
    printf("%d", *(int *)newNode->element);

    struct node *curr = malloc(sizeof(struct node));

    if(index == LIST_NA){
        curr = data->pTail;

        while(curr->next!=NULL){
            curr = curr->next;
        }

        struct node *temp = curr->next;
        curr->next = newNode;
        newNode->next = temp;
        
        data->pTail = curr;
        data->numberOfElements++;
        free(temp);
        free(curr);
        return True;
    }

    if(index < 0 || index > listSize(list)){
        return False;
    }

    curr = data->pTail;

    for(int i = 0; i<index; i++){
        curr = curr->next;
    }

    struct node *temp = curr->next;
    curr->next = newNode;
    newNode->next = temp;

    data->pTail = curr;
    data->numberOfElements++;
    free(temp);
    free(curr);

    return True;
}

/*=================================================================================================================================================*/

ListBoolean llAddAll ( List list , List other , int index )
{
  return False;
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

    int size = data->numberOfElements;

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
    LinkedList data = ILL(list);

    printf("LinkedList  : %s\n", listName);
    printf("Elements    : %d\n", data.numberOfElements);
    for(int i = 0; i<data.numberOfElements; i++){
        printf("[%d] %d \n", i, *(int *) data.pTail->element);
    }
}

/*=================================================================================================================================================*/

void llDestroy ( List list )
{
}

/***************************************************************************************************************************************************/
