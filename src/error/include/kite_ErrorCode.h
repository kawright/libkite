/**
 * @file        kite_ErrorCode.h
 * @author      Kristoffer A. Wright (kris.al.wright@gmail.com)
 * @brief       This file contains the definition of the kite_ErrorCode enum,
 *              which contains all error codes that can be thrown.
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

/*
================================================================================
Enums
================================================================================
*/

/**
 * @brief       Stores all error codes that can be thrown.
 * @since       v0.1.0
 * 
 */
typedef enum __ErrorCode {

    /// @brief No error.
    kite_ErrorCode_OK,

    /// @brief A general error has occurred.
    kite_ErrorCode_GENERAL,

    /// @brief An attempt to allocate heap memory failed.
    kite_ErrorCode_MEMORY_ALLOCATION

} kite_ErrorCode;