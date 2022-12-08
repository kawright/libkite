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