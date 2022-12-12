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

    kite_Array array = kite_Array_new();

    kite_Quiz_isOkState("Test new success");

    kite_Quiz_isEqualInt("Test initial length", kite_Array_getLength(array), 0);

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

    kite_Array_del(array, &deleter);

    kite_Quiz_isOkState("Test del success");

    kite_Array_sort(array, comparator, -1, -1);

    kite_Quiz_isOkState("Test sort success");

    kite_Quiz_isEqualString("Test get sorted element at index 0", 
        (char*) kite_Array_getElement(array, 0), "Amadeus");

    kite_Quiz_isEqualString("Test get sorted element at index 1", 
        (char*) kite_Array_getElement(array, 1), "Citizen Cane");

    kite_Quiz_isEqualString("Test get sort element at index 2", 
        (char*) kite_Array_getElement(array, 2), "Psycho");

    return kite_Quiz_finish();
}