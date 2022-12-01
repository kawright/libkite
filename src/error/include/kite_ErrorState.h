/**
 * @file        kite_ErrorState.h
 * @author      Kristoffer A. Wright (kris.al.wright@gmail.com)
 * @brief       This file contains the definition of the kite_ErrorState type
 *              and all of the method functions which act directly on it.
 * @since       v0.1.0
 * @date        2022-11-30
 * @copyright   Copyright (c) 2022 Kristoffer A. Wright
 * 
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

/**
 * @brief                   Get the most recently thrown error code.
 * @since                   v0.1.0
 * @return  kite_ErrorCode  Returns the most recently thrown error code. The
 *                          default `kite_ErrorCode_OK` is returned if no error
 *                          has been thrown since initialization or since the
 *                          last time `kite_ErrorState_reset` was called.  
 */
kite_ErrorCode kite_ErrorState_getCode();


/**
 * @brief           Signify that an error has been thrown by setting the error 
 *                  code.
 * @since           v0.1.0
 * @param   code    The code being set.
 */
void kite_ErrorState_setCode(
        kite_ErrorCode code);


/**
 * @brief   Reset the error state. This will set the current error code to
 *          `kite_ErrorCode_OK`.
 * @since   v0.1.0
 * 
 */
void kite_ErrorState_reset();


/**
 * @brief   Print a description of the most recently thrown error to `stderr`.
 * @since   v0.1.0
 * 
 */
void kite_ErrorState_print();


/**
 * @brief   Immediately terminate the process with the exit code that
 *          corresponds to the most recently thrown error code.
 * @since   v0.1.0
 * 
 */
void kite_ErrorState_fatal();