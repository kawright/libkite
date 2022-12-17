#include <stdlib.h>

#include "kite_Array.h"
#include "kite_ErrorCode.h"
#include "kite_ErrorState.h"

#define TRUE 1;
#define FALSE 0;

typedef struct __kite_Array {
    void**  contents;
    int     length;
} * kite_Array;

// Is the given position within the bounds of the given array?
int __checkBounds(kite_Array array, int position) {
    if ((position < 0) || (position >= array->length)) {
        return FALSE;
    }
        return TRUE;
}

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

kite_Array kite_Array_new(int size) {

    // Set default:
    if (size < 0) {
        size = 0;
    }

    if (size == 0) {
        kite_Array ret = malloc(sizeof(struct __kite_Array));
        if (ret == NULL) {
            kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
            return NULL;
        }
        ret->contents = NULL;
        ret->length = 0;
        return ret;
    } else {
        kite_Array ret = malloc(sizeof(struct __kite_Array));
        if (ret == NULL) {
            kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
            return NULL;
        }
        ret->contents = malloc((sizeof (void*)) * size);
        if (ret->contents == NULL) {
            free(ret);
            kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
            return NULL;
        }
        for (int i = 0; i < size; i++) {
            ret->contents[i] = NULL;
        }
        ret->length = size;
        return ret;
    }
}

void kite_Array_del(kite_Array self, void (deleter(void* element))) {

    // Use the given deleter function to free each element:
    for (int i = 0; i < self->length; i++) {
        (*deleter)(self->contents[i]);
    }
    free(self->contents);
    free(self);
    return;
}

void kite_Array_clear(kite_Array self, void (deleter(void* element))) {

    // Use the given deleter function to free each element:
    for (int i = 0; i < self->length; i++) {
        (*deleter)(self->contents[i]);
    }
    free(self->contents);
    self->contents = NULL;
    self->length = 0;
    return;
}

void kite_Array_append(kite_Array self, void* element) {

    // Resize:
    if (self->length == 0) {
        self->contents = malloc(sizeof (void*));
    } else {
        void** temp = realloc(self->contents, 
            (sizeof (void*)) * (self->length+1));
        if (temp == NULL) {
            kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
            return;
        }
        self->contents = temp;
    }
    
    self->contents[self->length] = element;
    self->length++;
    return;
}

void* kite_Array_pop(kite_Array self) {

    // Reject if self is empty.
    if (self->length == 0) {
        kite_ErrorState_setCode(kite_ErrorCode_EMPTY_COLLECTION);
        return NULL;
    }
    
    // Save a reference to the return data before we remove it:
    void* ret = self->contents[self->length-1];

    // Resize:
    if (self->length == 1) {
        free(self->contents);
        self->contents = NULL;
    } else {
        void** temp = realloc(self->contents, 
            (sizeof (void*)) * (self->length-1));
        if (temp == NULL) {
            kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
            return NULL;
        }
        self->contents = temp;
    }

    self->length--;
    return ret;
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

void kite_Array_insert(kite_Array self, int position, void* element) {

    // Inserting at the last position is equivalent to appending:
    if (position == self->length) {
        kite_Array_append(self, element);
        return;
    }

    // Check bounds:
    if (!__checkBounds(self, position)) {
        kite_ErrorState_setCode(kite_ErrorCode_BOUNDS);
        return;
    }

    // Resize:
    if (self->length == 0) {
        self->contents = malloc(sizeof (void*));
    } else {
        void** temp = realloc(self->contents, 
            (sizeof (void*)) * (self->length+1));
        if (temp == NULL) {
            kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
            return;
        }
        self->contents = temp;
    }
    

    // Shift all elements at and to the right of the given position one
    // position further to the right in order to make space for the new
    // element.
    for (int i = self->length-1; i >= position; i--) {
        self->contents[i+1] = self->contents[i];
    }

    // Insert:
    self->contents[position] = element;

    self->length++;
}

void kite_Array_remove(kite_Array self, int position, 
        void (deleter(void* element))) {

    // Check bounds:
    if (!__checkBounds(self, position)) {
        kite_ErrorState_setCode(kite_ErrorCode_BOUNDS);
        return;
    }

    // Delete the element:
    (*deleter)(self->contents[position]);

    // Shift elements left:
    for (int i = position + 1; i < self->length; i++) {
        self->contents[i-1] = self->contents[i];
    }

    // Resize:
    if (self->length == 1) {
        free(self->contents);
        self->contents = NULL;
    } else {
        void** temp = realloc(self->contents, 
            (sizeof (void*)) * self->length-1);
        if (temp == NULL) {
            kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
            return;
        }
        self->contents = temp;
    }

    self->length--;
}

void kite_Array_reverse(kite_Array self) {
    int i = 0;
    int j = self->length-1;
    while (i <= j) {
        void* temp = self->contents[i];
        self->contents[i] = self->contents[j];
        self->contents[j] = temp;
        i++;
        j--;
    }
    return;
}

void kite_Array_extend(kite_Array self, kite_Array extension) {
    
    // Check if `extension` is empty. If it is, we can just return right away:
    if (kite_Array_getLength(extension) == 0) {
        return;
    }

    // Resize:
    void** temp = realloc(
        self->contents, 
        ((sizeof (void*)) * self->length) + 
        ((sizeof (void*)) * kite_Array_getLength(extension)));
    if (temp == NULL) {
        kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
        return;
    }

    self->contents = temp;

    // Copy the contents to the newly allocated space:
    for (int i = 0; i < kite_Array_getLength(extension); i++) {
        self->contents[self->length + i] = kite_Array_getElement(extension, i);
    }

    self->length += kite_Array_getLength(extension);

    return;

}