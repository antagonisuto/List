/***************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#include "ArrayList.h"
#include "ListImplementation.h"

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

#define IAL(list)  ( * ( (ArrayList *) ((list)->pInternalList) ) )  /* Internal ArrayList */

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

static ListBoolean   alAdd           ( List list , ListElement element , int index                     ) ;
static ListBoolean   alAddAll        ( List list , List other , int index                              ) ;
static void          alClear         ( List list                                                       ) ;
static ListBoolean   alContains      ( List list , ListElement element                                 ) ;
static ListBoolean   alContainsAll   ( List list , List other                                          ) ;
static ListBoolean   alEquals        ( List list , List other                                          ) ;
static ListElement   alGet           ( List list , int index                                           ) ;
static int           alIndexOf       ( List list , ListElement element                                 ) ;
static ListBoolean   alIsEmpty       ( List list                                                       ) ;
static int           alLastIndexOf   ( List list , ListElement element                                 ) ;
static ListElement   alRemove        ( List list , int index                                           ) ;
static ListBoolean   alRemoveElement ( List list , ListElement element                                 ) ;
static ListBoolean   alRemoveAll     ( List list , List other                                          ) ;
static void          alReplaceAll    ( List list , ListElementUnaryOperator uOperator                  ) ;
static ListBoolean   alRetainAll     ( List list , List other                                          ) ;
static ListElement   alSet           ( List list , int index , ListElement element                     ) ;
static int           alSize          ( List list                                                       ) ;
static ListBoolean   alSort          ( List list , ListElementComparisonFunction compare               ) ;
static ListElement * alToArray       ( List list                                                       ) ;
static void          alPrint         ( List list , char * listName , ListElementPrintingFunction print ) ;
static void          alDestroy       ( List list                                                       ) ;

/***************************************************************************************************************************************************/




/* This is a suggested data structure (you may change it if you wish) ******************************************************************************/

typedef struct arrayList
{
  int           numberOfElements ;
  size_t        arraySize        ;
  ListElement * array            ;
}
ArrayList ;


/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

static void setFunctionPointers ( List list )
{
  list->add           = alAdd           ;
  list->addAll        = alAddAll        ;
  list->clear         = alClear         ;
  list->contains      = alContains      ;
  list->containsAll   = alContainsAll   ;
  list->equals        = alEquals        ;
  list->get           = alGet           ;
  list->indexOf       = alIndexOf       ;
  list->isEmpty       = alIsEmpty       ;
  list->lastIndexOf   = alLastIndexOf   ;
  list->remove        = alRemove        ;
  list->removeElement = alRemoveElement ;
  list->removeAll     = alRemoveAll     ;
  list->replaceAll    = alReplaceAll    ;
  list->retainAll     = alRetainAll     ;
  list->set           = alSet           ;
  list->size          = alSize          ;
  list->sort          = alSort          ;
  list->toArray       = alToArray       ;
  list->print         = alPrint         ;
  list->destroy       = alDestroy       ;
}

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

List createArrayList ( int initialCapacity )
{
  if (initialCapacity == LIST_NA) {
    printf("OK2 ");
    initialCapacity = 10;
  }

  if(initialCapacity <= 0){
    printf("OK1 ");
    return NULL;
  }

  ArrayList* newArrayList = malloc(sizeof(ArrayList));
  if(newArrayList == NULL) {  return NULL;  }

  //Create the internal data container
  newArrayList->arraySize = initialCapacity;
  newArrayList->numberOfElements = 0;
  newArrayList->array = malloc(initialCapacity * sizeof(int));

  printf("OK3 ");


  //Allocate the List and connect it to the newArrayList

  List lst = malloc(sizeof(List));
  lst->pInternalList = newArrayList;
  free(newArrayList);

  printf("%d \n", initialCapacity);

  return lst;

}

/*=================================================================================================================================================*/

List createArrayListFrom ( List other )  /* 'other' list can be implemented using linked lists or other underlying data structures */
{
  ArrayList* newArrayList = malloc((int) other->size *sizeof(ArrayList));

  newArrayList->numberOfElements = (int) other->size;
  newArrayList->array = other->pInternalList;
  newArrayList->arraySize = (int) other->size;

  return (List) newArrayList;
}

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/
/* Inserts the specified element at the specified position in the list. Shifts the element currently at that position (if any) and any subsequent
   elements to the right (adds one to their indices). If index is LIST_NA, then appends the specified element to the end of the list.
   Returns True if the operation is successful.
   Returns False if the operation is unsuccessful; for example if index < 0, or index > listSize(list), or running out of memory. */

ListBoolean alAdd ( List list , ListElement element , int index )
{
  printf("alADD");

  if(list == NULL){ 
    printf("alAdd2 ");
    return False; 
  }

  if(index < 0 || index > listSize(list)){
    printf("alAdd3 ");
    return False;
  }
  
  //ArrayList *data = (ArrayList*)(list->pInternalList);


  if(index == LIST_NA){
    printf("alAdd0 ");
    list->add(list, element, listSize(list)+1);
  }

  list->add(list, element, index);

  printf("alAdd1 ");

  //list->add(list, element, index);

  return True;
}

/*=================================================================================================================================================*/

ListBoolean alAddAll ( List list , List other , int index )
{
  return False;
}

/*=================================================================================================================================================*/

void alClear ( List list )
{

}

/*=================================================================================================================================================*/

ListBoolean alContains ( List list , ListElement element )
{
  return False;
}

/*=================================================================================================================================================*/

ListBoolean alContainsAll ( List list , List other )
{
  return False;
}

/*=================================================================================================================================================*/

ListBoolean alEquals ( List list , List other )
{
  return False;
}

/*=================================================================================================================================================*/

ListElement alGet ( List list , int index )
{
  return 0;
}

/*=================================================================================================================================================*/

int alIndexOf ( List list , ListElement element )
{
  return 0;
}

/*=================================================================================================================================================*/

ListBoolean alIsEmpty ( List list )
{
  return False;
}

/*=================================================================================================================================================*/

int alLastIndexOf ( List list , ListElement element )
{
  return False;
}

/*=================================================================================================================================================*/

ListElement alRemove ( List list , int index )
{
  return 0;
}

/*=================================================================================================================================================*/

ListBoolean alRemoveElement ( List list , ListElement element )
{
  return False;
}

/*=================================================================================================================================================*/

ListBoolean alRemoveAll ( List list , List other )
{
  return False;
}

/*=================================================================================================================================================*/

void alReplaceAll ( List list , ListElementUnaryOperator uOperator )
{

}

/*=================================================================================================================================================*/

ListBoolean alRetainAll ( List list , List other )
{
  return False;
}

/*=================================================================================================================================================*/

ListElement alSet ( List list , int index , ListElement element )
{
  return 0;
}

/*=================================================================================================================================================*/

int alSize ( List list )
{
  return False;
}

/*=================================================================================================================================================*/

ListBoolean alSort ( List list , ListElementComparisonFunction compare )
{
  return False;
}

/*=================================================================================================================================================*/

ListElement * alToArray ( List list )
{
  return 0;
}

/*=================================================================================================================================================*/

void alPrint ( List list , char * listName , ListElementPrintingFunction print )
{
}

/*=================================================================================================================================================*/

void alDestroy ( List list )
{
}

/***************************************************************************************************************************************************/
