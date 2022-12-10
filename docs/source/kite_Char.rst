kite_Char.h - Common Character Operations
=========================================

This header file defines an API for performing common character operations.

.. versionadded:: v0.3.0

Range Test Functions
--------------------

These functions are used to test whether a given character is in a range (class)
of characters.

.. c:function:: int kite_Char_isAlpha(char value)

    Test if a given character is alphabetic.

    :param value:   The value being tested.
    :returns:       A boolean `int` which indicates whether or not the test
                    passed.

.. c:function:: int kite_Char_isLower(char value)

    Test if a given character is lowercase.

    :param value:   The value being tested.
    :returns:       A boolean `int` which indicates whether or not the test
                    passed.

.. c:function:: int kite_Char_isUpper(char value)

    Test if a given character is uppercase.

    :param value:   The value being tested.
    :returns:       A boolean `int` which indicates whether or not the test
                    passed.

.. c:function:: int kite_Char_isNumeric(char value)

    Test if a given character is numeric.

    :param value:   The value being tested.
    :returns:       A boolean `int` which indicates whether or not the test
                    passed.

.. c:function:: int kite_Char_isAlphanumeric(char value)

    Test if a given character is alphanumeric.

    :param value:   The value being tested.
    :returns:       A boolean `int` which indicates whether or not the test
                    passed.

.. c:function:: int kite_Char_isPunctuation(char value)

    Test if a given character is punctuation.

    :param value:   The value being tested.
    :returns:       A boolean `int` which indicates whether or not the test
                    passed.

.. c:function:: int kite_Char_isWhitespace(char value)

    Test if a given character is whitespace.

    :param value:   The value being tested.
    :returns:       A boolean `int` which indicates whether or not the test
                    passed.

.. c:function:: int kite_Char_isPrintable(char value)

    Test if a given character is printable.

    :param value:   The value being tested.
    :returns:       A boolean `int` which indicates whether or not the test
                    passed.

Conversion Functions
--------------------

These functions are used to perform character conversions.

.. c:function:: char kite_Char_isLower(char value)

    Convert a character to its lowercase equivalent.

    If the given character is not an uppercase letter, it will be returned
    unconverted.

    :param value:   The value being converted.
    :returns:       The converted character.

.. c:function:: char kite_Char_isUpper(char value)

    Convert a character to its uppercase equivalent.

    If the given character is not a lowercase letter, it will be returned
    unconverted.

    :param value:   The value being converted.
    :returns:       The converted character.