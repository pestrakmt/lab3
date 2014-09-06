#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

/*
 * This method creates a struct arrayList, initializes it to default values, and
 * returns a pointer to the struct arrayList created.
 *
 * @param type the primitive type of the struct arrayList
 * @return a pointer to the created struct arrayList
 */
arrayList * initialize(primitiveType type)
{
    arrayList * listPtr;
    listPtr = (arrayList*) malloc(sizeof(arrayList));
    listPtr->arraySize = 4;
    listPtr->numElements = 0;
    listPtr->type = type;
    listPtr->elementSize = getSize(type);
    listPtr->array = (void*) malloc(getSize(type) * 4);
    return listPtr;
}

/*
 * This method returns the size in bytes of a struct arrayList.
 *
 * @param type the primitive type of the struct arrayList
 * @return the type of the struct arrayList
 */
int getSize(primitiveType type)
{
    if (type == charType)
    {
        return sizeof(char);
    }
    else if (type == shortType)
    {
        return sizeof(short);
    }
    else
    {
        return sizeof(int);
    }
}

/*
 * This method adds the indicated element to the indicated arrayList using
 * pointers.  It needs to determine type of arrayList before the proper method
 * is chosen to add the element to the arrayList. If the numElements is equal to
 * the size of the array the allocated array space is doubled.
 *
 * @param arylstP is the pointer to the struct arrayList
 * @param element is the pointer to the element to add to the arrayList
 */
void addElement(arrayList * arylstP, void * element)
{
    if ((arylstP->arraySize) == (arylstP->numElements))
    {
        int arrSize = (arylstP->elementSize) * (arylstP->numElements);
        void * newArrayPtr = (void*) malloc(arrSize * 2);
        int i;
        for (i = 0; i < arrSize; i++)
        {
            ((char*) (newArrayPtr))[i] =  ((char*) (arylstP->array))[i];
        }
        free(arylstP->array);
        (arylstP->array) = newArrayPtr;
        arylstP->arraySize = (arylstP->arraySize) * 2;
    }
    
    if ((arylstP->type) == charType)
    {
        ((char*) (arylstP->array))[arylstP->numElements] = *((char*) element);
    }
    else if ((arylstP->type) == shortType)
    {
        ((short*) (arylstP->array))[arylstP->numElements] = *((short*) element);
    }
    else
    {
        ((int*) (arylstP->array))[arylstP->numElements] = *((int*) element);
    }
    (arylstP->numElements)++;
}

/*
 * This method removes the indicated element and moves all elements after
 * the removed element down one index.
 *
 * @param arylstP is the pointer to the struct arrayList
 * @param index the index of the element to remove
 */
void removeElement(arrayList * arylstP, int index)
{
    int i;
    if ((arylstP->type) == charType)
    {
        for (i = index; i < (arylstP->numElements) - 1; i++)
        {
            ((char*) (arylstP->array))[i] = ((char*) (arylstP->array))[i + 1];
        }
    }
    else if ((arylstP->type) == shortType)
    {
        for (i = index; i < (arylstP->numElements) - 1; i++)
        {
            ((short*) (arylstP->array))[i] = ((short*) (arylstP->array))[i + 1];
        }
    }
    else
    {
        for (i = index; i < (arylstP->numElements) - 1; i++)
        {
            ((int*) (arylstP->array))[i] = ((int*) (arylstP->array))[i + 1];
        }
    }
    (arylstP->numElements)--;
}
      
/*
 * This method prints out the elements of the struct arrayList.
 *
 * @param arylstP the pointer to the struct arrayList
 */
void printArray(arrayList * arylstP)
{
    int i;
    printf("array size: %d, num elements: %d contents: ", 
           arylstP->arraySize, arylstP->numElements);
    for (i = 0; i < arylstP->numElements; i++)
    {
        if (arylstP->type == charType)
        {
            //fill in the missing code that gets the element and &s it with 0xff
            if ((((char*) (arylstP->array))[i] & 0x80) != 0
                && (((int*) (arylstP->array))[i] & 0x80000000) == 0)
            {
                unsigned char element = ((char*) (arylstP->array))[i] & 0xff;
                printf("%02x ", element);
            }
            else
            {
                char element = ((char*) (arylstP->array))[i] & 0xff;
                printf("%02x ", element);
            }
        }
        else if (arylstP->type == shortType)
        {
            //fill in the missing code that gets the element and &s it with 0xffff
            if ((((short*) (arylstP->array))[i] & 0x8000) != 0
                && (((int*) (arylstP->array))[i] & 0x80000000) == 0)
            {
                unsigned short element = ((short*) (arylstP->array))[i] & 0xffff;
                printf("%04x ", element);
            }
            else
            {
                short element = ((short*) (arylstP->array))[i] & 0xffff;
                printf("%04x ", element);
            }
        }
        else if (arylstP->type == intType)
        {
            //fill in the missing code that gets the element and &s it with 0xffffffff
            int element = ((int*) (arylstP->array))[i] & 0xffffffff;
            printf("%08x ", element);
        }
    }
    printf("\n");
}

