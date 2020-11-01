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

    List lst = createArrayList(LIST_NA);
    ArrayList element = IAL(other);
    // ArrayList *temp = &IAL(other);
    // lst->pInternalList = temp;
    for(int i =0; i<listSize(other); i++){
        alAdd(lst, element.array[i] , LIST_NA);
    }

  return lst;
}

/***************************************************************************************************************************************************/

ListBoolean alEnsureCapacity(ArrayList *lst, int minCapacity){
    if(minCapacity > lst->arraySize){
        lst->arraySize += (lst->arraySize>>1);
        if(lst->arraySize < minCapacity){
            lst->arraySize = minCapacity;
        }

        lst->array = realloc(lst->array, lst->arraySize * sizeof(lst->array));
    }
    return True;
}


/***************************************************************************************************************************************************/

//DONE
ListBoolean alAdd ( List list , ListElement element , int index )
{
    ArrayList *data = &IAL(list);

    if(index == LIST_NA){
        alEnsureCapacity(&IAL(list), data->numberOfElements+1);
        data->array[data->numberOfElements] = element;
        data->numberOfElements++;
        return True;
    } 

    if(index < 0 || index > listSize(list)){
        return False;
    }

    alEnsureCapacity(&IAL(list), data->numberOfElements+1);
   
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
    ArrayList *second = &IAL(other);
    ArrayList *first = &IAL(list);
    if(index == LIST_NA){
        index = listSize(list);
    }

    if(first->arraySize < second->arraySize + first->arraySize){
        alEnsureCapacity(first, first->numberOfElements + second->numberOfElements);
    }

    for(int i=0; i<second->numberOfElements; i++){
        first->array[index+i] = second->array[i]; 
    }

    first->numberOfElements += second->numberOfElements;

  return True;
}

/*=================================================================================================================================================*/

void alClear ( List list )
{
    ArrayList *data = &IAL(list);
    free(data->array);
    data->array = malloc(0);
    data->arraySize = 0;
    data->numberOfElements = 0;
}

/*=================================================================================================================================================*/
/* Returns True if the list contains the specified element. More formally, returns True if and only if the list contains at least one element 'e'
   such that the pointer comparison ( element == e ) is true. Otherwise, returns False. */
ListBoolean alContains ( List list , ListElement element )
{
    if(listSize(list) == 0){
        return False;
    }
    ArrayList *data = &IAL(list);

    for(int i=0; i<data->numberOfElements; i++){
        if(data->array[i] == element){
            return True;
        }
    }
    
  return False;
}

/*=================================================================================================================================================*/
/* Returns True if the list contains all of the elements of the other list. Otherwise, returns False. */
ListBoolean alContainsAll ( List list , List other )
{
    ArrayList *data = &IAL(list);
    ArrayList *ret = &IAL(other);


    for(int i=0; i<data->numberOfElements; i++){
        ListBoolean check = False;
        for(int j=0; j<ret->numberOfElements; j++){
            if(data->array[i] == ret->array[j]){
                check = True;
                continue;
            }
        }
        if(check==False){
            return False;
        }
    }

    return True;
}

/*=================================================================================================================================================*/
/* Compares the other list with the list for equality. More formally, returns True if and only if the pointer comparison ( list == other ) is true.
   Otherwise, returns False. */
ListBoolean alEquals ( List list , List other )
{
    if(listSize(list)!=listSize(other)){
        return False;
    }

    ArrayList *data = &IAL(list);
    ArrayList *oth = &IAL(other);

    for(int i=0; i<data->numberOfElements; i++){
        if(data->array[i] != oth->array[i]){
            return False;
        }
    }
  return True;
}

/*=================================================================================================================================================*/

ListElement alGet ( List list , int index )
{
    if(index < 0 || index >= listSize(list)){
        return NULL;
    }
    ArrayList *data = &IAL(list);
  return data->array[index];
}

/*=================================================================================================================================================*/

int alIndexOf ( List list , ListElement element )
{
    ArrayList *data = &IAL(list);

    for(int i=0; i<data->numberOfElements; i++){
        if(data->array[i]==element){
            return i;
        }
    }

    return 0;
}

/*=================================================================================================================================================*/

ListBoolean alIsEmpty ( List list )
{    
    return listSize(list)==0;
}

/*=================================================================================================================================================*/

int alLastIndexOf ( List list , ListElement element )
{
    ArrayList *data = &IAL(list);
    int el = 0;
    for(int i=0; i<data->numberOfElements; i++){
        if(data->array[i]==element){
            el = i;
        }
    }

    if(el == 0){
        return -1;
    }

  return el;
}

/*=================================================================================================================================================*/

ListElement alRemove ( List list , int index )
{
    if(index < 0 || index >= listSize(list)){
        return NULL;
    }

    ArrayList *data = &IAL(list);
    ListElement element = data->array[index];
    for(int i=index; i<data->numberOfElements - 1; i++){
        data->array[i] = data->array[i+1];
    }
    data->numberOfElements--;


  return element;
}

/*=================================================================================================================================================*/
//DONE
ListBoolean alRemoveElement ( List list , ListElement element )
{
    ArrayList *data = &IAL(list);
    ListBoolean check = False;
    for (int i=0; i<data->numberOfElements; i++){
        if(data->array[i]==element){
            data->array[i] = data->array[i+1];
            check = True;
            data->numberOfElements--;
        } 
        if(check == True){
            data->array[i] = data->array[i+1];
        }
    }
  return True;
}

/*=================================================================================================================================================*/

ListBoolean alRemoveAll ( List list , List other )
{
    ArrayList *data = &IAL(list);
    ArrayList *ret = &IAL(other);
    ArrayList *temp = malloc(sizeof(ArrayList));
    temp->array = malloc(sizeof(ListElement));

    int index = 0; 
    for(int i=0; i<data->numberOfElements; i++){
        ListBoolean check = False;
        for(int j=0; j<ret->numberOfElements; j++){
            if(*(int *)data->array[i] == *(int *)ret->array[j]){
                check = True;
            }
        }
        if(check == False){
            temp->array[index] = data->array[i];
            index++;
        }
    }

    data->array = temp->array;
    data->numberOfElements = index;
    return True;
}

/*=================================================================================================================================================*/

void alReplaceAll ( List list , ListElementUnaryOperator uOperator )
{

}

/*=================================================================================================================================================*/

ListBoolean alRetainAll ( List list , List other )
{
    ArrayList *data = &IAL(list);
    ArrayList *ret = &IAL(other);
    ArrayList *temp = malloc(sizeof(ArrayList));
    temp->array = malloc(sizeof(ListElement));

    int index = 0; 
    for(int i=0; i<data->numberOfElements; i++){
        for(int j=0; j<ret->numberOfElements; j++){
            if(*(int *)data->array[i] == *(int *)ret->array[j]){
                temp->array[index] = data->array[i];
                index++;
                continue;
            }
        }
    }

    data->array = temp->array;
    data->numberOfElements = index;
    return True;
}

/*=================================================================================================================================================*/
/* Replaces the element at the specified position in the list with the specified element.
   Returns the element previously at the specified position.
   Returns NULL if index < 0, or index >= listSize(list).
   Note: NULL is also a valid element value that can be stored in a list. */

ListElement alSet ( List list , int index , ListElement element )
{
    if(index <0 || index >= listSize(list)){
        return NULL;
    }

    ArrayList *data = &IAL(list);
    data->array[index] = element;

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
    ArrayList *data = &IAL(list);
    int n = data->numberOfElements;

    for(int i=0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(*(int *)data->array[j] > *(int *)data->array[j + 1]){
                ListElement swap = data->array[j];
                data->array[j] = data->array[j+1];
                data->array[j+1] = swap;
            }

        }
    }

  return True;
}

/*=================================================================================================================================================*/
/* Returns an array containing all of the elements in the list in proper sequence (from first to last element).
   The returned array will be 'safe' in that no references to it are maintained by the list (in other words, this method must allocate a new array
   even if the list is backed by an array). The caller is thus free to modify the returned array. This method acts as bridge between array-based and
   list-based APIs.
   Returns NULL if the list does not contain any elements, or if running out of memory. */

ListElement * alToArray ( List list )
{
    if(listSize(list) == 0) return NULL;

    ArrayList data = IAL(list);
    ListElement *element = malloc(sizeof(int));
    for(int i = 0; i<data.numberOfElements; i++){
        element[i] = data.array[i];
    }

  return element;
}

/*=================================================================================================================================================*/


void alPrint ( List list , char * listName , ListElementPrintingFunction print )
{
    ArrayList data = IAL(list);
    printf("ArrayList  : %s\n", listName);
    printf("Array Size : %d\n", (int)data.arraySize);
    printf("Elements   : %d\n", data.numberOfElements);
    for (int i=0; i<data.numberOfElements; i++){
       printf( "[%d] %d \n" , i ,*(int *)data.array[i]) ;
       //print(data.array[i]);
    }
}

/*=================================================================================================================================================*/

void alDestroy ( List list )
{
    ArrayList *data = &IAL(list);

    free(data->array);
    data->arraySize = 0;
    data->numberOfElements = 0;

}

/***************************************************************************************************************************************************/
