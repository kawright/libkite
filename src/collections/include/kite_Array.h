typedef struct __kite_Array * kite_Array;

kite_Array kite_Array_new(int size);

void kite_Array_del(kite_Array self, void (deleter(void* element)));

void kite_Array_clear(kite_Array self, void (deleter(void* element)));

void kite_Array_append(kite_Array self, void* element);

void* kite_Array_pop(kite_Array self);

void* kite_Array_getElement(kite_Array self, int index);

int kite_Array_getLength(kite_Array self);

void kite_Array_sort(kite_Array self, int (comparator(void* left, void* right)),
        int start, int end);

void kite_Array_insert(kite_Array self, int position, void* element);

void kite_Array_remove(kite_Array self, int position, 
        void (deleter(void* element)));

void kite_Array_reverse(kite_Array self);

void kite_Array_extend(kite_Array self, kite_Array extension);