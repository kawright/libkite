/*
================================================================================
FILE:       kite_String.c
PURPOSE:    The file implements the API described by kite_String.h
AUTHOR:     Kristoffer A. Wright
SINCE:      v0.3.1
DATE:       2022-12-10
COPYRIGHT:  Copyright (c) 2022 Kristoffer A. Wright
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kite_Char.h"
#include "kite_ErrorCode.h"
#include "kite_ErrorState.h"

char* kite_String_clone(char* value) {

    char* ret = strdup(value);
    if (ret == NULL) {
        kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
        return NULL;
    }
    return ret;
}

char* kite_String_capitalize(char* value) {

    char* ret = strdup(value);
    if (ret == NULL) {
        kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
        return NULL;
    }
    for (int i = 0; i < strlen(ret); i++) {
        if (kite_Char_isWhitespace(ret[i])) {
            continue;
        }
        if (kite_Char_isLower(ret[i])) {
            ret[i] = kite_Char_toUpper(ret[i]);
        }
        break;
    }
    return ret;
}

char* kite_String_center(char* value, int width, char fill) {

    // Apply default:
    if (fill == '\0') {
        fill = ' ';
    }

    if ((width <= 0) || (strlen(value) > width)) {
        char* ret = strdup(value);
        if (ret == NULL) {
            kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
            return NULL;
        }
        return ret;
    } else {
        char* ret = malloc(width);
        if (ret == NULL) {
            kite_ErrorState_setCode(kite_ErrorCode_MEMORY_ALLOCATION);
            return NULL;
        }
        int leftLen = (width - strlen(value)) / 2;
        int rightLen = width - strlen(value) - leftLen;
        for (int i = 0; i < leftLen; i++) {
            ret[i] = fill;
        }
        for (int i = 0; i < strlen(value); i++) {
            ret[i + leftLen] = value[i];
        }
        for (int i = 0; i < rightLen; i++) {
            ret[i + leftLen + strlen(value)] = fill;
        }
        return ret;
    }
}