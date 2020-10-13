/***************************************************************************************************************************************************/

#include <stdio.h>

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




/***************************************************************************************************************************************************/

List createLinkedList ( void )
{
}

/*=================================================================================================================================================*/

List createLinkedListFrom ( List other )  /* 'other' list can be implemented using arrays or other underlying data structures */
{
}

/***************************************************************************************************************************************************/




/***************************************************************************************************************************************************/

ListBoolean llAdd ( List list , ListElement element , int index )
{
}

/*=================================================================================================================================================*/

ListBoolean llAddAll ( List list , List other , int index )
{
}

/*=================================================================================================================================================*/

void llClear ( List list )
{
}

/*=================================================================================================================================================*/

ListBoolean llContains ( List list , ListElement element )
{
}

/*=================================================================================================================================================*/

ListBoolean llContainsAll ( List list , List other )
{
}

/*=================================================================================================================================================*/

ListBoolean llEquals ( List list , List other )
{
}

/*=================================================================================================================================================*/

ListElement llGet ( List list , int index )
{
}

/*=================================================================================================================================================*/

int llIndexOf ( List list , ListElement element )
{
}

/*=================================================================================================================================================*/

ListBoolean llIsEmpty ( List list )
{
}

/*=================================================================================================================================================*/

int llLastIndexOf ( List list , ListElement element )
{
}

/*=================================================================================================================================================*/

ListElement llRemove ( List list , int index )
{
}

/*=================================================================================================================================================*/

ListBoolean llRemoveElement ( List list , ListElement element )
{
}

/*=================================================================================================================================================*/

ListBoolean llRemoveAll ( List list , List other )
{
}

/*=================================================================================================================================================*/

void llReplaceAll ( List list , ListElementUnaryOperator uOperator )
{
}

/*=================================================================================================================================================*/

ListBoolean llRetainAll ( List list , List other )
{
}

/*=================================================================================================================================================*/

ListElement llSet ( List list , int index , ListElement element )
{
}

/*=================================================================================================================================================*/

int llSize ( List list )
{
}

/*=================================================================================================================================================*/

ListBoolean llSort ( List list , ListElementComparisonFunction compare )
{
}

/*=================================================================================================================================================*/

ListElement * llToArray ( List list )
{
}

/*=================================================================================================================================================*/

void llPrint ( List list , char * listName , ListElementPrintingFunction print )
{
}

/*=================================================================================================================================================*/

void llDestroy ( List list )
{
}

/***************************************************************************************************************************************************/
