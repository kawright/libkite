/*
================================================================================
FILE:       kite_Char.c
PURPOSE:    The file implements the API described by kite_Char.h
AUTHOR:     Kristoffer A. Wright
SINCE:      v0.3.0
DATE:       2022-12-07
COPYRIGHT:  Copyright (c) 2022 Kristoffer A. Wright
================================================================================
*/

/*
================================================================================
Precompiler directives
================================================================================
*/

#include "kite_Char.h"

#define TRUE 1
#define FALSE 0

/*
================================================================================
Range check functions
================================================================================
*/

int kite_Char_isLower(char value) {
    if ((value >= 97) && (value <= 122)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int kite_Char_isUpper(char value) {
    if ((value >= 65) && (value <= 90)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int kite_Char_isAlpha(char value) {
    return (kite_Char_isLower(value) || kite_Char_isUpper(value));
}

int kite_Char_isNumeric(char value) {
    if((value >= 48) && (value <= 57)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int kite_Char_isAlphanumeric(char value) {
    return (kite_Char_isAlpha(value) || kite_Char_isNumeric(value));
}

int kite_Char_isPunctuation(char value) {
    if (
            ((value >= 33) && (value <= 47))
            || ((value >= 58) && (value <= 64))
            || ((value >= 91) && (value <= 96))
            || ((value >= 123) && (value <= 126))) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int kite_Char_isWhitespace(char value) {
    if (
            (value == ' ')
            || (value == '\t')
            || (value == '\r')
            || (value == '\n')
            || (value == '\v')
            || (value == '\f')) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int kite_Char_isPrintable(char value) {
    if((value >= 32) && (value <= 126)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

char kite_Char_toUpper(char value) {
    if (kite_Char_isLower(value)) {
        return value - ('a' - 'A');
    } else {
        return value;
    }
}

char kite_Char_toLower(char value) {
    if (kite_Char_isUpper(value)) {
        return value + ('a' - 'A');
    } else {
        return value;
    }
}