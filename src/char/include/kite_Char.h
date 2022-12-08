/*
================================================================================
FILE:       kite_Char.h
PURPOSE:    The file defines an API for performing common operations on char
            data.
AUTHOR:     Kristoffer A. Wright
SINCE:      v0.3.0
DATE:       2022-12-07
COPYRIGHT:  Copyright (c) 2022 Kristoffer A. Wright
================================================================================
*/

/*
================================================================================
Range check functions
================================================================================
*/

// Test if a given char is alphabetic.
int kite_Char_isAlpha(char value);


// Test if a given char is numeric.
int kite_Char_isNumeric(char value);


// Test if a given char is alpha-numeric.
int kite_Char_isAlphanumeric(char value);


// Test if a given char is punctuation.
int kite_Char_isPunctuation(char value);


// Test if a given char is a capital letter.
int kite_Char_isUpper(char value);


// Test if a given char is a lowercase letter.
int kite_Char_isLower(char value);


// Test if a given char is a whitespace character.
int kite_Char_isWhitespace(char value);


// Test if a given char is a printable character.
int kite_Char_isPrintable(char value);

/*
================================================================================
Conversion functions
================================================================================
*/

// Convert a char value to its uppercase equivalent.
//
// Non-lowercase characters will be returned unchanged.
int kite_Char_toUpper(char value);


// Convert a char value to its lowercase equivalent.
//
// Non-capital characters will be returned unchanged.
int kite_Char_toLower(char value);