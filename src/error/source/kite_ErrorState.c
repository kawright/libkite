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
            fprintf(stderr, "[000-OK]: No error has occurred.\n");
            return;
        case kite_ErrorCode_GENERAL:
            fprintf(stderr, "[001-GENERAL]: A general error has occurred.\n");
            return;
        case kite_ErrorCode_ARGV:
            fprintf(stderr, "[002-ARGV]: The argument vector is malformed.\n");
            return;
        case kite_ErrorCode_MEMORY_ALLOCATION:
            fprintf(stderr, "[003-MEMORY_ALLOCATION]: An attempt to allocate "
                "heap memory has failed.\n");
            return;
        case kite_ErrorCode_BOUNDS:
            fprintf(stderr, "[004-BOUNDS]: An out-of-bounds array access was "
                "attempted.\n");
            return;
        case kite_ErrorCode_BAD_DATA:
            fprintf(stderr, "[005-BAD_DATA]: An argument or input data is "
                "malformed or otherwise invalid.\n");
            return;
        case kite_ErrorCode_EMPTY_COLLECTION:
            fprintf(stderr, "[006-EMPTY_COLLECTION]: An illegal operation was "
                "attempted on an empty collection.\n");
        default:
            fprintf(stderr, "[UNKNOWN]: An unknown error has occurred.\n");
            return;
    }
}

void kite_ErrorState_fatal() {
    exit((int)__code);
}

void kite_ErrorState_handle(void (handler(kite_ErrorCode code))) {
    (*handler)(kite_ErrorState_getCode());
}