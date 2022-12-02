/**
 * @file        kite_Quiz.c
 * @author      Kristoffer A. Wright (kris.al.wright@gmail.com)
 * @brief       This file defines an API for performing small individual unit
 *              tests called quizzes, which exist at the level of individual
 *              assertions.
 * @since       v0.2.0
 * @date        2022-12-01
 * @copyright   Copyright (c) 2022 Kristoffer A. Wright
 * 
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

/**
 * @brief           Initialize a test suite.
 * 
 * @param   name    The name of the test suite.
 */
void kite_Quiz_init(
        char*   name);

/**
 * @brief   Complete a test suite. This will print the results of the test to
 *          stdout.
 * 
 */
void kite_Quiz_finish();

/*
================================================================================
Error tests
================================================================================
*/

/**
 * @brief           Test if a given error code has been thrown.
 * 
 * @param   name    The name of the test.
 * @param   code    The code being tested for.
 */
void kite_Quiz_isThrown(
        char*           name, 
        kite_ErrorCode  code);

/**
 * @brief           Test if Kite is currently in an error state.
 * 
 * @param   name    The name of the test.
 */
void kite_Quiz_isErrorState(
        char*   name);

/**
 * @brief           Test if Kite is currently in a normal (non-error) state.    
 * 
 * @param   name    The name of the test.
 */
void kite_Quiz_isOkState(
        char*   name);

/*
================================================================================
Equality tests
================================================================================
*/

/**
 * @brief               Test if a given `int` value is equal to an expected
 *                      `int` value.
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isEqualInt(
        char*   name, 
        int     expected, 
        int     real);
        
/**
 * @brief               Test if a given `float` value is equal to an expected
 *                      `float` value.    
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isEqualFloat(
        char*   name,
        float   expected,
        float   real);

/**
 * @brief               Test if a given `char` value is equal to an expected
 *                      `char` value.
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isEqualChar(
        char*   name,
        char    expected,
        char    real);

/**
 * @brief               Test if a given string value is equal to an expected
 *                      string value.
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isEqualString(
        char*   name,
        char*   expected,
        char*   real);

/*
================================================================================
Inequality tests
================================================================================
*/

/**
 * @brief               Test if a given `int` value is not equal to an expected
 *                      `int` value.
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isNotEqualInt(
        char*   name, 
        int     expected, 
        int     real);

/**
 * @brief               Test if a given `float` value is not equal to an
 *                      expected `float` value.
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isNotEqualFloat(
        char*   name,
        float   expected,
        float   real);

/**
 * @brief               Test if a given `char` value is not equal to an expected
 *                      `float` value.
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isNotEqualChar(
        char*   name,
        char    expected,
        char    real);

/**
 * @brief               Test if a given string value is not equal to an expected
 *                      string value.
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isNotEqualString(
        char*   name,
        char*   expected,
        char*   real);

/*
================================================================================
Less-than tests
================================================================================
*/

/**
 * @brief               Test if a given `int` value is less than an expected
 *                      `int` value.
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isLessThanInt(
        char*   name, 
        int     expected, 
        int     real);

/**
 * @brief               Test if a given `float` value is less than an expected
 *                      `float` value.
 * 
 * @param name          The name of the test.
 * @param expected      The expected value.
 * @param real          The given value.
 */
void kite_Quiz_isLessThanFloat(
        char*   name, 
        float   expected, 
        float   real);

/**
 * @brief               Test if a given `char` value is less than an expected
 *                      `char` value.
 * 
 * @param name          The name of the test.
 * @param expected      The expected value.
 * @param real          The given value.
 */
void kite_Quiz_isLessThanChar(
        char*   name, 
        char    expected, 
        char    real);

/**
 * @brief               Test if a given string value is less than an expected
 *                      string value.
 * 
 * @param name          The name of the test.
 * @param expected      The expected value.
 * @param real          The given value.
 */
void kite_Quiz_isLessThanString(
        char*   name,
        char*   expected,
        char*   real);

/*
================================================================================
Less-than-or-equal-to tests
================================================================================
*/  

/**
 * @brief               Test if a given `int` value is less-than-or-equal-to
 *                      an expected `int` value.
 * 
 * @param name          The name of the test.
 * @param expected      The expected value.
 * @param real          The given value.
 */
void kite_Quiz_isLessThanOrEqualToInt(
        char*   name,
        int     expected,
        int     real);

/**
 * @brief               Test if a given `float` value is less-than-or-equal-to
 *                      an expected `float` value.
 * 
 * @param name          The name of the test.
 * @param expected      The expected value.
 * @param real          The given value.
 */
void kite_Quiz_isLessThanOrEqualToFloat(
        char*   name,
        float   expected,
        float   real);

/**
 * @brief               Test if a given `char` value is less-than-or-equal-to
 *                      an expected `char` value.
 * 
 * @param name          The name of the test.
 * @param expected      The expected value.
 * @param real          The given value.
 */
void kite_Quiz_isLessThanOrEqualToChar(
        char*   name,
        char    expected,
        char    real);

/**
 * @brief               Test if a given string value is less-than-or-equal-to
 *                      an expected string value.
 * 
 * @param name          The name of the test.
 * @param expected      The expected value.
 * @param real          The given value.
 */
void kite_Quiz_isLessThanOrEqualToString(
        char*   name,
        char*   expected,
        char*   real);

/*
================================================================================
Greater-than tests
===============================================================================
*/

/**
 * @brief               Test if a given `int` value is greater than an expected
 *                      `int` value.
 * 
 * @param   name        The name of the test.         
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isGreaterThanInt(
        char*   name,
        int     expected,
        int     real);

/**
 * @brief               Test if a given `float` value is greater than an
 *                      expected `float` value.
 * 
 * @param   name        The name of the test.         
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isGreaterThanFloat(
        char*   name,
        float   expected,
        float   real);

/**
 * @brief               Test if a given `char` value is greater than an
 *                      expected `char` value.
 * 
 * @param   name        The name of the test.         
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isGreaterThanChar(
        char*   name,
        char    expected,
        char    real);


/**
 * @brief               Test if a given string value is greater than an
 *                      expected string value.
 * 
 * @param   name        The name of the test.         
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isGreaterThanString(
        char*   name,
        char*   expected,
        char*   real);

/*
================================================================================
Greater-than-or-equal-to tests
================================================================================
*/

/**
 * @brief               Test if a given `int` value 
 *                      is greater-than-or-equal-to an expected `int` value.
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isGreaterThanOrEqualToInt(
        char*   name,
        int     expected,
        int     real);


/**
 * @brief               Test if a given `float` value 
 *                      is greater-than-or-equal-to an expected `float` value.
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isGreaterThanOrEqualToFloat(
        char*   name,
        float   expected,
        float   real);

/**
 * @brief               Test if a given `char` value 
 *                      is greater-than-or-equal-to an expected `char` value.
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isGreaterThanOrEqualToChar(
        char*   name,
        char    expected,
        char    real);

/**
 * @brief               Test if a given string value 
 *                      is greater-than-or-equal-to an expected string value.
 * 
 * @param   name        The name of the test.
 * @param   expected    The expected value.
 * @param   real        The given value.
 */
void kite_Quiz_isGreaterThanOrEqualToString(
        char*   name,
        char*   expected,
        char*   real);

/*
================================================================================
Boolean tests
================================================================================
*/

/**
 * @brief           Test if a given value is true.
 * 
 * @param   name    The name of the test.
 * @param   value   The value being tested.
 */
void kite_Quiz_isTrue(
        char*   name,
        int     value);

/**
 * @brief           Test if a given value if false.
 * 
 * @param   name    The name of the test. 
 * @param   value   The value being tested.
 */
void kite_Quiz_isFalse(
        char*   name,
        int     value);