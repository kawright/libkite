/**
 * @file        kite_Quiz.c
 * @author      Kristoffer A. Wright (kris.al.wright@gmail.com)
 * @brief       This file implements the API described by `kite_Quiz.h`
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
#include "kite_Quiz.h"

#include <stdio.h>
#include <string.h>

/*
================================================================================
Global state
================================================================================
*/

int __testsRun__ = 0;
int __testsPassed__ = 0;
int __testsFailed__ = 0;
char* __suiteName__ = "Unnamed Test Suite";

/*
================================================================================
Init/finish functions
================================================================================
*/

void kite_Quiz_init(
        char*   name) {
    
    printf("===============================================================\n");
    printf("<<%s>> BEGIN\n", name);
    printf("===============================================================\n");
    __suiteName__ = name;
}


int kite_Quiz_finish() {
    
    printf("---------------------------------------------------------------\n");
    printf("TEST SUITE RESULTS:\n");
    printf("TESTS RUN:    %d\n", __testsRun__);
    printf("TESTS PASSED: %d\n", __testsPassed__);
    printf("TESTS FAILED: %d\n", __testsFailed__);
    printf("===============================================================\n");
    printf("<<%s>> COMPLETE\n", __suiteName__);
    printf("===============================================================\n"
        "\n");

    if (__testsFailed__ > 0) {
        return 1;
    } else {
        return 0;
    }
}

int kite_Quiz_finishWithPass() {

    printf("---------------------------------------------------------------\n");
    printf("TEST SUITE RESULTS:\n");
    printf("TESTS RUN:    %d\n", __testsRun__);
    printf("TESTS PASSED: %d\n", __testsPassed__);
    printf("TESTS FAILED: %d\n", __testsFailed__);
    printf("===============================================================\n");
    printf("<<%s>> COMPLETE\n", __suiteName__);
    printf("===============================================================\n"
        "\n");

    return 0;
}

/*
================================================================================
Error tests
================================================================================
*/

void kite_Quiz_isThrown(
        char*           name,
        kite_ErrorCode  code) {

    __testsRun__++;
    if (code == kite_ErrorState_getCode()) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isErrorState(
        char*   name) {

    __testsRun__++;
    if (kite_ErrorState_getCode() != kite_ErrorCode_OK) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isOkState(
        char*   name) {

    __testsRun__++;
    if (kite_ErrorState_getCode() == kite_ErrorCode_OK) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

/*
================================================================================
Equality tests
================================================================================
*/

void kite_Quiz_isEqualInt(
        char*   name, 
        int     real, 
        int     expected) {
    
    __testsRun__++;
    if (real == expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isEqualFloat(
        char*   name, 
        float   real, 
        float   expected) {
    
    __testsRun__++;
    if (real == expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isEqualChar(
        char*   name, 
        char    real, 
        char    expected) {
    
    __testsRun__++;
    if (real == expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isEqualString(
        char*   name, 
        char*   real, 
        char*   expected) {
    
    __testsRun__++;
    if (strcmp(expected, real) == 0) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

/*
================================================================================
Inequality tests
================================================================================
*/

void kite_Quiz_isNotEqualInt(
        char*   name, 
        int     real, 
        int     expected) {
    
    __testsRun__++;
    if (real != expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isNotEqualFloat(
        char*   name, 
        float   real, 
        float   expected) {
    
    __testsRun__++;
    if (real != expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isNotEqualChar(
        char*   name, 
        char    real, 
        char    expected) {
    
    __testsRun__++;
    if (real != expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isNotEqualString(
        char*   name, 
        char*   real, 
        char*   expected) {
    
    __testsRun__++;
    if (strcmp(expected, real) != 0) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

/*
================================================================================
Less-than tests
================================================================================
*/

void kite_Quiz_isLessThanInt(
        char*   name, 
        int     real, 
        int     expected) {
    
    __testsRun__++;
    if (real < expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isLessThanFloat(
        char*   name, 
        float   real, 
        float   expected) {
    
    __testsRun__++;
    if (real < expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isLessThanChar(
        char*   name, 
        char    real, 
        char    expected) {
    
    __testsRun__++;
    if (real < expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isLessThanString(
        char*   name, 
        char*   real, 
        char*   expected) {
    
    __testsRun__++;
    if (strcmp(real, expected) < 0) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

/*
================================================================================
Less-than-or-equal-to tests
================================================================================
*/

void kite_Quiz_isLessThanOrEqualToInt(
        char*   name, 
        int     real, 
        int     expected) {
    
    __testsRun__++;
    if (real <= expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isLessThanOrEqualToFloat(
        char*   name, 
        float   real, 
        float   expected) {
    
    __testsRun__++;
    if (real <= expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isLessThanOrEqualToChar(
        char*   name, 
        char    real, 
        char    expected) {
    
    __testsRun__++;
    if (real <= expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isLessThanOrEqualToString(
        char*   name, 
        char*   real, 
        char*   expected) {
    
    __testsRun__++;
    if (strcmp(real, expected) <= 0) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

/*
================================================================================
Greater-than tests
================================================================================
*/

void kite_Quiz_isGreaterThanInt(
        char*   name, 
        int     real, 
        int     expected) {
    
    __testsRun__++;
    if (real > expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isGreaterThanFloat(
        char*   name, 
        float   real, 
        float   expected) {
    
    __testsRun__++;
    if (real > expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isGreaterThanChar(
        char*   name, 
        char    real, 
        char    expected) {
    
    __testsRun__++;
    if (real > expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isGreaterThanString(
        char*   name, 
        char*   real, 
        char*   expected) {
    
    __testsRun__++;
    if (strcmp(real, expected) > 0) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

/*
================================================================================
Greater-than-or-equal-to tests
================================================================================
*/


void kite_Quiz_isGreaterThanOrEqualToInt(
        char*   name, 
        int     real, 
        int     expected) {
    
    __testsRun__++;
    if (real >= expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isGreaterThanOrEqualToFloat(
        char*   name, 
        float   real, 
        float   expected) {
    
    __testsRun__++;
    if (real >= expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isGreaterThanOrEqualToChar(
        char*   name, 
        char    real, 
        char    expected) {
    
    __testsRun__++;
    if (real >= expected) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isGreaterThanOrEqualToString(
        char*   name, 
        char*   real, 
        char*   expected) {
    
    __testsRun__++;
    if (strcmp(real, expected) >= 0) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

/*
================================================================================
Boolean tests
================================================================================
*/

void kite_Quiz_isTrue(
        char*   name,
        int     value) {

    __testsRun__++;
    if (value) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}

void kite_Quiz_isFalse(
        char*   name,
        int     value) {

    __testsRun__++;
    if (!value) {
        __testsPassed__++;
        printf("<<%s>> OK\n", name);
    } else {
        __testsFailed__++;
        printf("<<%s>> FAILED\n", name);
    }
}