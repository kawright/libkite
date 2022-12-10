#include "libkite.h"

int main() {

    kite_Quiz_init("kite_Char Test Suite");

    kite_Quiz_isTrue("Test isUpper with A", kite_Char_isUpper('A'));

    kite_Quiz_isTrue("Test isUpper with Z", kite_Char_isUpper('Z'));

    kite_Quiz_isFalse("Test isUpper with a", kite_Char_isUpper('a'));

    kite_Quiz_isFalse("Test isUpper with a dollar sign", 
        kite_Char_isUpper('$'));

    kite_Quiz_isFalse("Test isLower with A", kite_Char_isLower('A'));

    kite_Quiz_isFalse("Test isLower with Z", kite_Char_isLower('Z'));

    kite_Quiz_isTrue("Test isLower with a", kite_Char_isLower('a'));

    kite_Quiz_isFalse("Test isLower with a dollar sign", 
        kite_Char_isLower('$'));

    kite_Quiz_isTrue("Test isAlpha with A", kite_Char_isAlpha('A'));

    kite_Quiz_isTrue("Test isAlpha with Z", kite_Char_isAlpha('Z'));

    kite_Quiz_isTrue("Test isAlpha with a", kite_Char_isAlpha('a'));

    kite_Quiz_isFalse("Test isAlpha with a dollar sign", 
        kite_Char_isAlpha('$'));

    kite_Quiz_isTrue("Test isNumeric with 0", kite_Char_isNumeric('0'));

    kite_Quiz_isTrue("Test isNumeric with 4", kite_Char_isNumeric('4'));

    kite_Quiz_isTrue("Test isNumeric with 9", kite_Char_isNumeric('9'));

    kite_Quiz_isFalse("Test isNumeric with a", kite_Char_isNumeric('a'));

    kite_Quiz_isFalse("Test isNumeric with a dollar sign", 
        kite_Char_isNumeric('$'));

    kite_Quiz_isTrue("Test isAlphanumeric with 0", 
        kite_Char_isAlphanumeric('0'));

    kite_Quiz_isTrue("Test isAlphanumeric with 4", 
        kite_Char_isAlphanumeric('4'));

    kite_Quiz_isTrue("Test isAlphanumeric with 9", 
        kite_Char_isAlphanumeric('9'));

    kite_Quiz_isTrue("Test isAlphanumeric with a", 
        kite_Char_isAlphanumeric('a'));

    kite_Quiz_isFalse("Test isAlphanumeric with a dollar sign", 
        kite_Char_isAlphanumeric('$'));

    kite_Quiz_isTrue("Test isPunctuation with !", kite_Char_isPunctuation('!'));

    kite_Quiz_isTrue("Test isPunctuation with *", kite_Char_isPunctuation('*'));

    kite_Quiz_isTrue("Test isPunctuation with `", kite_Char_isPunctuation('`'));

    kite_Quiz_isTrue("Test isPunctuation with &", kite_Char_isPunctuation('&'));

    kite_Quiz_isFalse("Test isPunctuation with p",
        kite_Char_isPunctuation('p'));

    kite_Quiz_isFalse("Test isPunctuation with space",
        kite_Char_isPunctuation(' '));

    kite_Quiz_isTrue("Test isWhitespace with space", 
        kite_Char_isWhitespace(' '));

    kite_Quiz_isTrue("Test isWhitespace with new-line", 
        kite_Char_isWhitespace('\n'));

    kite_Quiz_isTrue("Test isWhitespace with tab", 
        kite_Char_isWhitespace('\t'));

    kite_Quiz_isFalse("Test isWhitespace with 7", kite_Char_isWhitespace('7'));

    kite_Quiz_isTrue("Test isPrintable with 0", kite_Char_isPrintable('0'));

    kite_Quiz_isTrue("Test isPrintable with 4", kite_Char_isPrintable('4'));

    kite_Quiz_isTrue("Test isPrintable with 9", kite_Char_isPrintable('9'));

    kite_Quiz_isTrue("Test isPrintable with a", kite_Char_isPrintable('a'));

    kite_Quiz_isTrue("Test isPrintable with $", kite_Char_isPrintable('$'));

    kite_Quiz_isFalse("Test isPrintable with tab", kite_Char_isPrintable('\t'));

    kite_Quiz_isEqualChar("Test toLower with F", kite_Char_toLower('F'), 'f');

    kite_Quiz_isEqualChar("Test toLower with Z", kite_Char_toLower('Z'), 'z');

    kite_Quiz_isEqualChar("Test toLower with d", kite_Char_toLower('d'), 'd');

    kite_Quiz_isEqualChar("Test toLower with 9", kite_Char_toLower('9'), '9');

    kite_Quiz_isEqualChar("Test toUpper with F", kite_Char_toUpper('F'), 'F');

    kite_Quiz_isEqualChar("Test toUpper with Z", kite_Char_toUpper('Z'), 'Z');

    kite_Quiz_isEqualChar("Test toUpper with d", kite_Char_toUpper('d'), 'D');

    kite_Quiz_isEqualChar("Test toUpper with 9", kite_Char_toUpper('9'), '9');

    return kite_Quiz_finish();
}