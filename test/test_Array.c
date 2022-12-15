#include "libkite.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleter(void* element) {
    free(element);
    return;
}

int comparator(void* left, void* right) {
    return strcmp((char*)left, (char*)right);
}

int main() {
    
    kite_Quiz_init("kite_Array Test Suite");

    kite_Array array = kite_Array_new(0);

    kite_Quiz_isOkState("Test new success");

    kite_Quiz_isEqualInt("Test initial length", kite_Array_getLength(array), 0);

    kite_Array_pop(array);

    kite_Quiz_isErrorState("Test error on pop empty array");

    kite_ErrorState_reset();

    char* valueA = strdup("Citizen Kane");
    char* valueB = strdup("Psycho");
    char* valueC = strdup("Amadeus");

    kite_Array_append(array, valueA);
    kite_Array_append(array, valueB);
    kite_Array_append(array, valueC);

    kite_Quiz_isOkState("Test append success");

    kite_Quiz_isEqualInt("Test post-append length", kite_Array_getLength(array), 
        3);

    kite_Quiz_isEqualString("Test get element at index 0", 
        (char*) kite_Array_getElement(array, 0), "Citizen Kane");

    kite_Quiz_isEqualString("Test get element at index 1", 
        (char*) kite_Array_getElement(array, 1), "Psycho");

    kite_Quiz_isEqualString("Test get element at index 2", 
        (char*) kite_Array_getElement(array, 2), "Amadeus");

    kite_Array_sort(array, &comparator, -1, -1);

    kite_Quiz_isOkState("Test sort success");

    kite_Quiz_isEqualString("Test get sorted element at index 0", 
        (char*) kite_Array_getElement(array, 0), "Amadeus");

    kite_Quiz_isEqualString("Test get sorted element at index 1", 
        (char*) kite_Array_getElement(array, 1), "Citizen Kane");

    kite_Quiz_isEqualString("Test get sort element at index 2", 
        (char*) kite_Array_getElement(array, 2), "Psycho");

    char* valueD = strdup("Shining, The");
    char* valueE = strdup("Ben Hur");

    kite_Array_insert(array, 1, valueD);
    kite_Array_insert(array, 3, valueE);

    kite_Quiz_isOkState("Test insert success");

    kite_Quiz_isEqualString("Test get post-insert element at index 0", 
        (char*) kite_Array_getElement(array, 0), "Amadeus");

    kite_Quiz_isEqualString("Test get post-insert element at index 1", 
        (char*) kite_Array_getElement(array, 1), "Shining, The");

    kite_Quiz_isEqualString("Test get post-insert element at index 2", 
        (char*) kite_Array_getElement(array, 2), "Citizen Kane");

    kite_Quiz_isEqualString("Test get post-insert element at index 3", 
        (char*) kite_Array_getElement(array, 3), "Ben Hur");
    
    kite_Quiz_isEqualString("Test get post-insert element at index 4", 
        (char*) kite_Array_getElement(array, 4), "Psycho");

    kite_Array_sort(array, &comparator, -1, -1);

    kite_Quiz_isOkState("Test 2nd sort success");

    kite_Quiz_isEqualString("Test get post-2nd-sort element at index 0", 
        (char*) kite_Array_getElement(array, 0), "Amadeus");

    kite_Quiz_isEqualString("Test get post-2nd-sort element at index 1", 
        (char*) kite_Array_getElement(array, 1), "Ben Hur");

    kite_Quiz_isEqualString("Test get post-2nd-sort element at index 2", 
        (char*) kite_Array_getElement(array, 2), "Citizen Kane");

    kite_Quiz_isEqualString("Test get post-2nd-sort element at index 3", 
        (char*) kite_Array_getElement(array, 3), "Psycho");
    
    kite_Quiz_isEqualString("Test get post-2nd-sort element at index 4", 
        (char*) kite_Array_getElement(array, 4), "Shining, The");

    char* valueF = strdup("Gone With The Wind");
    char* valueG = strdup("North by Northwest");

    kite_Array_insert(array, -1, valueF);

    kite_Quiz_isErrorState("Test error on insert at negative position");

    kite_ErrorState_reset();
    
    kite_Array_insert(array, 5, valueG);

    kite_Quiz_isErrorState("Test error on insert past end of array");

    kite_ErrorState_reset();

    kite_Array_remove(array, 3, &deleter);

    kite_Quiz_isOkState("Test remove index 3 success");

    kite_Quiz_isEqualString("Test get post-remove element at index 3",
        (char*) kite_Array_getElement(array, 3), "Shining, The");

    kite_Quiz_isEqualInt("Test post remove length", kite_Array_getLength(array),
        4);

    kite_Array_remove(array, -1, &deleter);

    kite_Quiz_isErrorState("Test error on remove at negative position");

    kite_ErrorState_reset();

    kite_Array_remove(array, 5, &deleter);

    kite_Quiz_isErrorState("Test error on remove past end of array");

    kite_ErrorState_reset();

    kite_Quiz_isEqualString("Test pop element value",
        (char*) kite_Array_pop(array), "Shining, The");

    kite_Quiz_isEqualInt("Test post-pop length", kite_Array_getLength(array), 
        3);

    kite_Quiz_isEqualString("Test get post-pop element at index 0", 
        (char*) kite_Array_getElement(array, 0), "Amadeus");

    kite_Quiz_isEqualString("Test get post-pop element at index 1", 
        (char*) kite_Array_getElement(array, 1), "Ben Hur");

    kite_Quiz_isEqualString("Test get post-pop element at index 2", 
        (char*) kite_Array_getElement(array, 2), "Citizen Kane");

    kite_Array_reverse(array);

    kite_Quiz_isOkState("Test reverse success");

    kite_Quiz_isEqualString("Test get post-reverse element at index 0", 
        (char*) kite_Array_getElement(array, 0), "Citizen Kane");

    kite_Quiz_isEqualString("Test get post-reverse element at index 1", 
        (char*) kite_Array_getElement(array, 1), "Ben Hur");

    kite_Quiz_isEqualString("Test get post-reverse element at index 2", 
        (char*) kite_Array_getElement(array, 2), "Amadeus");

    kite_Array_del(array, &deleter);

    kite_Quiz_isOkState("Test del success");

    return kite_Quiz_finish();
}