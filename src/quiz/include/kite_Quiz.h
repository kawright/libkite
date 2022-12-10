/*
================================================================================
FILE:       kite_Quiz.h
PURPOSE:    The file defines an API for performing small individual unit tests
            called quizzes, which exist at the level of individual assertions.
AUTHOR:     Kristoffer A. Wright
SINCE:      v0.2.0
DATE:       2022-12-01
COPYRIGHT:  Copyright (c) 2022 Kristoffer A. Wright
================================================================================
*/


/*
================================================================================
Precompiler directives
================================================================================
*/

#include "kite_ErrorCode.h"
#include "kite_ErrorState.h"

#include <stdio.h>

/*
================================================================================
Init/finish functions
================================================================================
*/

// Initialize a test suite.
void kite_Quiz_init(
    char *name);


// Complete a test suite.
//
// This will print the result of the test to STDOUT.
int kite_Quiz_finish();

// Complete a test suite with an unconditional pass.
//
// This will print the results of the suite to STDOUT.
int kite_Quiz_finishWithPass();

/*
================================================================================
Error tests
================================================================================
*/

// Test if a given error code has been thrown.
void kite_Quiz_isThrown(
    char *name,
    kite_ErrorCode code);


// Test if Kite is currently in an error state
void kite_Quiz_isErrorState(
    char *name);


// Test if Kite is currently in a normal (non-error) state.
void kite_Quiz_isOkState(
    char *name);

/*
================================================================================
Equality tests
================================================================================
*/

// Test if a given int value is equal to a test value.
void kite_Quiz_isEqualInt(
    char *name,
    int real,
    int expected);


// Test if a given float value is equal to a test value.
void kite_Quiz_isEqualFloat(
    char *name,
    float real,
    float expected);


// Test if a given char value is equal to a test value.
void kite_Quiz_isEqualChar(
    char *name,
    char real,
    char expected);


// Test if a given String value is equal to a test value.
void kite_Quiz_isEqualString(
    char *name,
    char *real,
    char *expected);

/*
================================================================================
Inequality tests
================================================================================
*/


// Test if a given int value is not equal to a test value.
void kite_Quiz_isNotEqualInt(
    char *name,
    int real,
    int expected);


// Test if a given float value is not equal to a test value.
void kite_Quiz_isNotEqualFloat(
    char *name,
    float real,
    float expected);


// Test if a given char value is not equal to a test value.
void kite_Quiz_isNotEqualChar(
    char *name,
    char real,
    char expected);


// Test if a given String value is not equal to a test value.
void kite_Quiz_isNotEqualString(
    char *name,
    char *real,
    char *expected);

/*
================================================================================
Less-than tests
================================================================================
*/


// Test if a given int value is less-than a test value.
void kite_Quiz_isLessThanInt(
    char *name,
    int real,
    int expected);


// Test if a given float value is less-than a test value.
void kite_Quiz_isLessThanFloat(
    char *name,
    float real,
    float expected);


// Test if a given char value is less-than a test value.
void kite_Quiz_isLessThanChar(
    char *name,
    char real,
    char expected);


// Test if a given String value is less-than a test value.
void kite_Quiz_isLessThanString(
    char *name,
    char *real,
    char *expected);

/*
================================================================================
Less-than-or-equal-to tests
================================================================================
*/


// Test if a given int value is less-than-or-equal-to a test value.
void kite_Quiz_isLessThanOrEqualToInt(
    char *name,
    int real,
    int expected);


// Test if a given float value is less-than-or-equal-to a test value.
void kite_Quiz_isLessThanOrEqualToFloat(
    char *name,
    float real,
    float expected);


// Test if a given char value is less-than-or-equal-to a test value.
void kite_Quiz_isLessThanOrEqualToChar(
    char *name,
    char real,
    char expected);


// Test if a given String value is less-than-or-equal-to a test value.
void kite_Quiz_isLessThanOrEqualToString(
    char *name,
    char *real,
    char *expected);

/*
================================================================================
Greater-than tests
===============================================================================
*/

// Test if a given int value is greater-than a test value.
void kite_Quiz_isGreaterThanInt(
    char *name,
    int real,
    int expected);


// Test if a given float value is greater-than a test value.
void kite_Quiz_isGreaterThanFloat(
    char *name,
    float real,
    float expected);


// Test if a given char value is greater-than a test value.
void kite_Quiz_isGreaterThanChar(
    char *name,
    char real,
    char expected);


// Test if a given String value is greater-than a test value.
void kite_Quiz_isGreaterThanString(
    char *name,
    char *real,
    char *expected);

/*
================================================================================
Greater-than-or-equal-to tests
================================================================================
*/


// Test if a given int value is greater-than-or-equal-to a test value.
void kite_Quiz_isGreaterThanOrEqualToInt(
    char *name,
    int real,
    int expected);


// Test if a given float value is greater-than-or-equal-to a test value.
void kite_Quiz_isGreaterThanOrEqualToFloat(
    char *name,
    float real,
    float expected);


// Test if a given char value is greater-than-or-equal-to a test value.
void kite_Quiz_isGreaterThanOrEqualToChar(
    char *name,
    char real,
    char expected);


// Test if a given String value is greater-than-or-equal-to a test value.
void kite_Quiz_isGreaterThanOrEqualToString(
    char *name,
    char *real,
    char *expected);

/*
================================================================================
Boolean tests
================================================================================
*/


// Test if a given value is true.
void kite_Quiz_isTrue(
    char *name,
    int value);


// Test if a given value is false.
void kite_Quiz_isFalse(
    char *name,
    int value);