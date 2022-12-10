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