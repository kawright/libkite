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

        // Calculate the length of the padding. Since we will use int division,
        // and int division trucates towards zero, the left will always be
        // shorter if the total padding character count is odd:
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

int kite_String_count(char* value, char* substring, int start, int end) {
    
    // Apply defaults:
    if (start < 0) {
        start = 0;
    }
    if (end < 0) {
        end = strlen(value);
    }

    // Reject if substring is empty:
    if (strlen(substring) == 0) {
        kite_ErrorState_setCode(kite_ErrorCode_BAD_DATA);
        return 0;
    }

    // Reject if end is less than or equal to start:
    if (end <= start) {
        kite_ErrorState_setCode(kite_ErrorCode_BAD_DATA);
        return 0;
    }

    // Reject if start or end is out-of-bounds:
    if (start >= strlen(value)) {
        kite_ErrorState_setCode(kite_ErrorCode_BOUNDS);
        return 0;
    }

    if (end > strlen(value)) {
        kite_ErrorState_setCode(kite_ErrorCode_BOUNDS);
        return 0;
    }    

    // If the search length is smaller than the substring length, the substring
    // can't possibly fit in once. We can assume zero instances:
    if ((end - start) < strlen(substring)) {
        return 0;
    }

    // For each character in the search spacce, see if that character is the
    // start of a sub string:
    int ret = 0;
    for (int i = start; i <= (end - strlen(substring)); i++) {
        int matched = 1;
        for (int j = 0; j < strlen(substring); j++) {
            if (substring[j] != value[i+j]) {
                matched = 0;
                break;
            }
        }
        if (matched) {
            ret++;

            // Since we want non-overlapping matches, advance the position
            // in the loop to the end of the match so that the next iteration
            // begins on the first non-matched characted:
            i += (strlen(substring) - 1);
        }
    }
    return ret;
}