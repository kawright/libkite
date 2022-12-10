kite_Quiz.h - Simple Unit Tests
===============================

This header file defines an API for performing simplified unit tests called
quizzes. A quiz is a small test which exists at the level of a single assertion,
and is run on a single line. These smaller tests make it easier for the
developer to write individual tests, hopefully leading to more comprehensively
tested projects.

.. note::

    Please be aware that, unlike the assertion statements used by most unit
    testing frameworks, quizzes do *not* alter the flow of execution, regardless
    of the result of the test. That is, if a given quiz fails, execution 
    continues with the next line just as if the quiz had passed.

.. versionadded:: v0.2.0

Initialization and Teardown Functions
-------------------------------------

These functions are used to initialize and conclude a single test suite run.

.. c:function:: void kite_Quiz_init(char* name)

    Initialize a test suite.

    Failing to call this function before a test suite run will not cause an
    error, but the test suite will be given the default name "Unnamed Suite".

    :param name:    The name of the new test suite.

.. c:function:: int kite_Quiz_finish()

    Complete a test suite run and print the results to `STDOUT`.

    :returns:   Returns a value that indicates the success or failure of this
                test suite run. A value of `0` indicates that all tests passed.
                A value of `1` indicates at least one test failed. This value
                can conveniently be used as the exit code for an entire test
                suite executable so that a test harness can run the suite and
                report the result of it to the user.

.. c:function:: int kite_Quiz_finishWithPass()

    Complete a test suite run with an unconditional pass, and print the results
    to `STDOUT`.

    .. versionadded:: v0.2.1

    :returns:   Returns `0` unconditionally, regardless of whether or not any
                tests failed.

Error State Tests
-----------------

These tests are used for validating the global error state.

.. c:function:: void kite_Quiz_isThrown(char* name, kite_ErrorCode code)

    Test if the most recently thrown error code is equivalent to a given error
    code.

    :param name:    The name of the test.
    :param code:    The error code being tested.

.. c:function:: void kite_Quiz_isErrorState(char* name)

    Test if the program is currently in an error state. The program is
    considered to be in an error state if the most recently thrown error is
    *anything* except for `kite_ErrorCode_OK`.

    :param name:    The name of the test.

.. c:function:: void kite_Quiz_isOkState(char* name)

    Test if the program is currently in an OK state. The program is considered
    to be in an OK state if the most recently thrown error is 
    `kite_ErrorCode_OK`.

    :param name:    The name of the test.

Equality Tests
--------------

These tests are used for validating equality between two values.

.. c:function:: void kite_Quiz_isEqualInt(char* name, int real, int expected)

    Test that a given `int` value is equal to an expected `int` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isEqualFloat(char* name, float real, float expected)

    Test that a given `float` value is equal to an expected `float` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isEqualChar(char* name, char real, char expected)

    Test that a given `char` value is equal to an expected `char` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isEqualString(char* name, char* real, char* expected)

    Test that a given string value is equal to an expected string value.

    Two strings are considered equivalent if all characters

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

Inequality Tests
----------------

These tests are used for validating inequality between two values.

.. c:function:: void kite_Quiz_isNotEqualInt(char* name, int real, int expected)

    Test that two given `int` values are not equal.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isNotEqualFloat(char* name, float real, float expected)

    Test that two given `float` values are not equal.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isNotEqualChar(char* name, char real, char expected)

    Test that two given `char` values not are equal.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isNotEqualString(char* name, char* real, char* expected)

    Test that two given string values not are equal.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

Less-than Tests
---------------

These tests are used for validating that a given test value is less-than an 
expected control value.

.. c:function:: void kite_Quiz_isLessThanInt(char* name, int real, int expected)

    Test that a given `int` is less than an expected `int` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isLessThanFloat(char* name, float real, float expected)

    Test that a given `float` is less than an expected `float` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isLessThanChar(char* name, char real, char expected)

    Test that a given `char` is less than an expected `char` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isLessThanString(char* name, char* real, char* expected)

    Test that a given String is less than an expected String value. A given test
    string is considered less-than a control string if its first non-matching
    character's ASCII code is less than the control's at the same position.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

Less-than-or-equal-to Tests
---------------------------

These tests are used for validating that a given test value is less-than-or-
equal-to an expected control value.

.. c:function:: void kite_Quiz_isLessThanOrEqualToInt(char* name, int real, int expected)

    Test that a given `int` is less-than-or-equal-to an expected `int` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isLessThanOrEqualToFloat(char* name, float real, float expected)

    Test that a given `float` is less-than-or-equal-to an expected `float` 
    value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isLessThanOrEqualToChar(char* name, char real, char expected)

    Test that a given `char` is less-than-or-equal-to an expected `char` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isLessThanOrEqualToString(char* name, char* real, char* expected)

    Test that a given String is less-than-or-equal-to an expected String value. 
    A given test string is considered less-than-or-equal-to a control string if 
    its first non-matching character's ASCII code is less-than-or-equal-to the 
    control's at the same position.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

Greater-than Tests
------------------

These tests are used for validating that a given test value is greater-than an 
expected control value.

.. c:function:: void kite_Quiz_isGreaterThanInt(char* name, int real, int expected)

    Test that a given `int` is greater-than an expected `int` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isGreaterThanFloat(char* name, float real, float expected)

    Test that a given `float` is greater-than an expected `float` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isGreaterThanChar(char* name, char real, char expected)

    Test that a given `char` is greater-than an expected `char` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isGreaterThanString(char* name, char* real, char* expected)

    Test that a given String is greater-than an expected String value. A given 
    test string is considered greater-than a control string if its first non-
    matching character's ASCII code is greater-than the control's at the same 
    position.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

Greater-than-or-equal-to Tests
------------------------------

These tests are used for validating that a given test value is greater-than-or-
equal-to an expected control value.

.. c:function:: void kite_Quiz_isGreaterThanOrEqualToInt(char* name, int real, int expected)

    Test that a given `int` is greater-than-or-equal-to an expected `int` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isGreaterThanOrEqualToFloat(char* name, float real, float expected)

    Test that a given `float` is greater-than-or-equal-to an expected `float` 
    value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isGreaterThanOrEqualToChar(char* name, char real, char expected)

    Test that a given `char` is greater-than-or-equal-to an expected `char` value.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isGreaterThanOrEqualToString(char* name, char* real, char* expected)

    Test that a given String is greater-than-or-equal-to an expected String value. 
    A given test string is considered greater-than-or-equal-to a control string if 
    its first non-matching character's ASCII code is greater-than-or-equal-to the control's at 
    the same position.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

Boolean Tests
-------------

These tests are used for validating boolean values.

.. c:function:: void kite_Quiz_isTrue(char* name, int value)

    Test that a given `int` value is true. An `int` value is considered true if
    it is non-zero.

    :param name:        The name of the test.
    :param value:       The given value which is being tested.

.. c:function:: void kite_Quiz_isFalse(char* name, int value)

    Test that a given `int` value is false. An `int` value is considered false 
    if it is exactly zero.

    :param name:        The name of the test.
    :param value:       The given value which is being tested.