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
//DONE
List createArrayList ( int initialCapacity )
{
    if (initialCapacity == LIST_NA) {
        initialCapacity = 10;
    }

    if(initialCapacity <= 0){
        return NULL;
    }

    ArrayList *newArrayList = malloc(sizeof(ArrayList));
    if(newArrayList == NULL) {  
        return NULL;  
    }

    //Create the internal data container
    newArrayList->arraySize = initialCapacity;
    newArrayList->numberOfElements = 0;
    newArrayList->array = malloc(initialCapacity * sizeof(int));

    if(newArrayList->array == NULL){
        return NULL;
    }
    

    //Allocate the List and connect it to the newArrayList

    List lst = malloc(sizeof(struct list));
  
    lst->pInternalList = newArrayList;
    setFunctionPointers(lst);
  
    return lst;
}

/*=================================================================================================================================================*/

List createArrayListFrom ( List other )  /* 'other' list can be implemented using linked lists or other underlying data structures */
{
    // ArrayList data = IAL(other);
    // List lst = malloc(sizeof(List));
    // lst->pInternalList = &data;

  return 0;
}

/***************************************************************************************************************************************************/

ListBoolean alEnsureCapacity(struct arrayList lst, int minCapacity){
    if(minCapacity > lst.arraySize){
        lst.arraySize += (lst.arraySize>>1);
        if(lst.arraySize < minCapacity){
            lst.arraySize = minCapacity;
        }

        lst.array = realloc(lst.array, lst.arraySize * sizeof(lst.array));
    }
    return True;
}


/***************************************************************************************************************************************************/
/* Inserts the specified element at the specified position in the list. Shifts the element currently at that position (if any) and any subsequent
   elements to the right (adds one to their indices). If index is LIST_NA, then appends the specified element to the end of the list.
   Returns True if the operation is successful.
   Returns False if the operation is unsuccessful; for example if index < 0, or index > listSize(list), or running out of memory. */
//DONE
ListBoolean alAdd ( List list , ListElement element , int index )
{
    ArrayList *data = &IAL(list);

    if(index == LIST_NA){
        alEnsureCapacity(IAL(list), data->numberOfElements+1);
        data->array[data->numberOfElements] = element;
        data->numberOfElements++;
        return True;
    } 

    if(index < 0 || index > listSize(list)){
        return False;
    }

     alEnsureCapacity(IAL(list), data->numberOfElements+1);
   
    for(int i = data->numberOfElements; i> index; i--){
       data->array[i] = data->array[i-1];
    }

   data->array[index] = element;
   data->numberOfElements++;

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
    ArrayList *data = &IAL(list);

    int size = data->numberOfElements;
    
    return size;
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
/* Prints the list (a short header, and then all of the list elements, one element per line, with index of each element printed at the beginning of
   its line) to the standard output stream (stdout).
   
   
ArrayList  : list1
Array size : 10
Elements   : 3
[0] 4
[1] 8
[2] 3
 */


void alPrint ( List list , char * listName , ListElementPrintingFunction print )
{
    ArrayList data = IAL(list);
    printf("ArrayList  : %s\n", listName);
    printf("Array Size : %d\n", (int)data.arraySize);
    printf("Elements   : %d\n", data.numberOfElements);
    for (int i=0; i<data.numberOfElements; i++){
       printf( "[%d] %d \n" , i ,*(int *)data.array[i]) ;
    }
}

/*=================================================================================================================================================*/

void alDestroy ( List list )
{
}

/***************************************************************************************************************************************************/
