#include "libkite.h"

int main() {

    kite_Quiz_init("kite_Char Test Suite");

    kite_Quiz_isTrue("Test isUpper with A", kite_Char_isUpper('A'));

    kite_Quiz_isTrue("Test isUpper with Z", kite_Char_isUpper('Z'));

    kite_Quiz_isFalse("Test isUpper with a", kite_Char_isUpper('a'));

    kite_Quiz_isFalse("Test isUpper with a dollar sign", 
        kite_Char_isUpper('$'));

    return kite_Quiz_finish();
}