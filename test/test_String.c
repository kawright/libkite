#include "libkite.h"

#include <stdlib.h>

int main () {
    
    kite_Quiz_init("kite_String Test Suite");

    char* clone = kite_String_clone("Hello, world");
    
    kite_Quiz_isOkState("Test clone throws no errors");

    kite_Quiz_isEqualString("Test clone is equal to original", clone, 
        "Hello, world");

    free(clone);

    return kite_Quiz_finish();

}