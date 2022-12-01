/**
 * @file        kite_ErrorState.c
 * @author      Kristoffer A. Wright (kris.al.wright@gmail.com)
 * @brief       This file implements the API defined in `kite_ErrorState.h`
 * @since       v0.1.0
 * @date        2022-11-30
 * @copyright   Copyright (c) 2022 Kristoffer A. Wright
 * 
 */

/*
================================================================================
Precompile directives
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#include "kite_ErrorCode.h"
#include "kite_ErrorState.h"

/*
================================================================================
Private globals
================================================================================
*/

kite_ErrorCode __code = kite_ErrorCode_OK;

/*
================================================================================
Public functions
================================================================================
*/

kite_ErrorCode kite_ErrorState_getCode() {
    return __code;
}

void kite_ErrorState_setCode(
        kite_ErrorCode code) {
    __code = code;
}

void kite_ErrorState_reset() {
    __code = kite_ErrorCode_OK;
}

void kite_ErrorState_print() {
    switch (__code) {
        case kite_ErrorCode_OK:
            fprintf(stderr, "[OK]: No error has occurred.\n");
            return;
        case kite_ErrorCode_GENERAL:
            fprintf(stderr, "[GENERAL]: A general error has occurred.\n");
            return;
        case kite_ErrorCode_MEMORY_ALLOCATION:
            fprintf(stderr, "[MEMORY_ALLOCATION]: An attempt to allocate heap "
                "memory has failed.\n");
            return;
        default:
            fprintf(stderr, "[UNKNOWN]: An unknown error has occurred.\n");
            return;
    }
}

void kite_ErrorState_fatal() {
    switch (__code) {
        case kite_ErrorCode_OK:
            exit(0);
        case kite_ErrorCode_GENERAL:
            exit(1);
        case kite_ErrorCode_MEMORY_ALLOCATION:
            exit(3);
        default:
            exit(1);
    }
}