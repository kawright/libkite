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

    Complete a test suite run.

    If *any* individual tests fail, this function will return `1`, otherwise `0`
    will be returned. The reason for this so that the return value may be used
    as the exit code for the entire test suite process.

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

    Test that two given `int` values are equal.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isEqualFloat(char* name, float real, float expected)

    Test that two given `float` values are equal.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isEqualChar(char* name, char real, char expected)

    Test that two given `char` values are equal.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.

.. c:function:: void kite_Quiz_isEqualString(char* name, char* real, char* expected)

    Test that two given string values are equal.

    :param name:        The name of the test.
    :param real:        The given value which is being tested.
    :param expected:    The expected value which is being tested against.