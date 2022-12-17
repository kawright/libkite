/*
================================================================================
FILE:       kite_String.h
PURPOSE:    The file defines an API for performing common operations on
            character strings.
AUTHOR:     Kristoffer A. Wright
SINCE:      v0.3.1
DATE:       2022-12-10
COPYRIGHT:  Copyright (c) 2022 Kristoffer A. Wright
================================================================================
*/

// Return a clone of the given string.
//
// The return data is heap allocated, and must be freed after usage.
//
// Throws kite_ErrorCode_MEMORY_ALLOCATION if memory cannot be allocated for the
// return data.
char* kite_String_clone(char* value);

char* kite_String_capitalize(char* value);

char* kite_String_center(char* value, int width, char fill);

int kite_String_count(char* value, char* substring, int start, int end);