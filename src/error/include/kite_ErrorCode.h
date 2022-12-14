/*
================================================================================
FILE:       kite_ErrorCode.h
PURPOSE:    The file contains the definition of the kite_ErrorCode enum, which
            contains all error codes that can be thrown.
AUTHOR:     Kristoffer A. Wright
SINCE:      v0.1.0
DATE:       2022-11-30
COPYRIGHT:  Copyright (c) 2022 Kristoffer A. Wright
================================================================================
*/

/*
================================================================================
Precompiler directives
================================================================================
*/

#pragma once

/*
================================================================================
Enums
================================================================================
*/

// Stores all error codes which may be thrown.
typedef enum __ErrorCode {

    // No error has occurred.
    kite_ErrorCode_OK,

    // A general error has occurred.
    kite_ErrorCode_GENERAL,

    // An attempt to allocate heap memory failed.
    kite_ErrorCode_MEMORY_ALLOCATION

} kite_ErrorCode;