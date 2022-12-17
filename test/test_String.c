#include "libkite.h"

#include <stdlib.h>

int main () {
    
    kite_Quiz_init("kite_String Test Suite");

    char* clone01 = kite_String_clone("Hello, world");
    
    kite_Quiz_isOkState("Test clone throws no errors");

    kite_Quiz_isEqualString("Test clone is equal to original", clone01, 
        "Hello, world");

    free(clone01);

    char* clone02 = kite_String_capitalize("california");

    kite_Quiz_isOkState("Test capitalize throws no errors 01");

    kite_Quiz_isEqualString("Test success capitalize 01", clone02, 
        "California");

    free(clone02);

    char* clone03 = kite_String_capitalize("   wyoming");

    kite_Quiz_isOkState("Test capitalize throws no errors 02");

    kite_Quiz_isEqualString("Test success capitalize 02", clone03, 
        "   Wyoming");

    free(clone03);

    char* clone04 = kite_String_capitalize("*oregon*");

    kite_Quiz_isOkState("Test capitalize throws no errors 03");

    kite_Quiz_isEqualString("Test success capitalize 03", clone04, 
        "*oregon*");

    free(clone04);

    char* clone05 = kite_String_center("Hello", 11, '*');

    kite_Quiz_isOkState("Test center throws no errors 01");

    kite_Quiz_isEqualString("Test success center 01", clone05, "***Hello***");

    free(clone05);

    char* clone06 = kite_String_center("Hello", 10, '*');

    kite_Quiz_isOkState("Test center throws no errors 02");

    kite_Quiz_isEqualString("Test success center 02", clone06, "**Hello***");

    free(clone06);

    char* clone07 = kite_String_center("Hello", -3, '*');

    kite_Quiz_isOkState("Test center throws no errors 03");

    kite_Quiz_isEqualString("Test success center 03", clone07, "Hello");

    free(clone07);

    kite_Quiz_isEqualInt("Test count 01", 
        kite_String_count("I like red shoes, red shirts, and red hats.", 
        "red", -1, -1), 3);

    kite_Quiz_isEqualInt("Test count 02", 
        kite_String_count("BoBoBoB", 
        "BoB", -1, -1), 2);

    return kite_Quiz_finish();

}