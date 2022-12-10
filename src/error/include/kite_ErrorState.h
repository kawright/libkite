/*
================================================================================
FILE:       kite_ErrorState.h
PURPOSE:    The file defines an API for setting and reading the global error

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

#include "kite_ErrorCode.h"

/*
================================================================================
Public functions
================================================================================
*/

// Get the most recently thrown error code.
kite_ErrorCode kite_ErrorState_getCode();


// Signify that an error condition has been detected by setting the global
// error state.
void kite_ErrorState_setCode(kite_ErrorCode code);


// Reset the global error state.
//
// The state will be reset to kite_ErrorCode_OK.
void kite_ErrorState_reset();


// Print a description of the most recently thrown error to STDERR.
void kite_ErrorState_print();


// Immediately terminate the process with the exit code that corresponds to the
// most recently thrown error code.
void kite_ErrorState_fatal();