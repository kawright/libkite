#include <stdlib.h>

#include "kite_Array.h"
#include "kite_ErrorCode.h"
#include "kite_ErrorState.h"

typedef struct __kite_Array {
    void**  contents;
    int     length;
} * kite_Array;

int __partition(kite_Array array, int (comparator(void* left, void* right)),
        int start, int end) {
    void* pivot = array->contents[end];
    int partIndex = start - 1;
    for (int i = start; i <= end; i++) {
        if ((*comparator)(array->contents[i], pivot) < 0) {
            partIndex++;
            void* temp = array->contents[partIndex];
            array->contents[partIndex] = array->contents[i];
            array->contents[i] = temp;
        }
    }
    void* temp = array->contents[partIndex + 1];
    array->contents[partIndex + 1] = array->contents[end];
    array->contents[end] = temp;
    return (partIndex + 1);
}

kite_Array kite_Array_new() {
    kite_Array ret;
    ret = malloc(sizeof ret);
    if (ret == NULL) {
        kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
        return NULL;
    }
    ret->contents = NULL;
    ret->length = 0;
    return ret;
}

void kite_Array_del(kite_Array self, void (deleter(void* element))) {

    // Use the given deleter function to free each element:
    for (int i = 0; i < self->length; i++) {
        (*deleter)(self->contents[i]);
    }
    free(self);
    return;
}

void kite_Array_append(kite_Array self, void* element) {

    // If this is the first element, do a malloc:
    if (self->length == 0) {
        self->contents = malloc(sizeof (void*));
    } else {
        self->contents = realloc(self->contents, self->length+1);
    }
    if (self->contents == NULL) {
        kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
        return;
    }
    self->contents[self->length] = element;
    self->length++;
    return;
}

void* kite_Array_getElement(kite_Array self, int index) {
    if ((index < 0 ) || (index >= self->length)) {
        kite_ErrorState_setCode(kite_ErrorCode_BOUNDS);
        return NULL;
    }
    return self->contents[index];
}

int kite_Array_getLength(kite_Array self) {
    return self->length;
}

void kite_Array_sort(kite_Array self, int (comparator(void* left, void* right)),
        int start, int end) {

    // Apply defaults:
    int realStart;
    if (start < 0) {
        realStart = 0;
    } else {
        realStart = start;
    }
    int realEnd;
    if (end < 0) {
        realEnd = self->length - 1;
    } else {
        realEnd = end;
    }
    if (realStart >= realEnd) {
        return;
    }
    int partIndex = __partition(self, comparator, realStart, realEnd);
    kite_Array_sort(self, comparator, realStart, partIndex-1);
    kite_Array_sort(self, comparator, partIndex+1, realEnd);
}