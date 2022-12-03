kite_ErrorState.h - Global Error State
======================================

This header file defines an API in which to interact with the global error 
state, allowing the user to set and read the current error code, among other 
things.

.. versionadded:: v0.1.0

.. c:function:: kite_ErrorCode kite_ErrorState_getCode()

    Get the most recently thrown error code.

    :returns:   The last error code to have been set with 
                `kite_ErrorState_setCode`. If `kite_ErrorState_setCode` has not 
                been called, `kite_ErrorCode_OK` is returned.

.. c:function:: void kite_ErrorState_setCode(kite_ErrorCode code)

    Indicate that an error has been thrown by setting the global error code.

    :param code:    The error code being set.

.. c:function:: void kite_ErrorState_reset()

    Reset the global error state so that the current error code is 
    `kite_ErrorCode_OK`.

.. c:function:: void kite_ErrorState_print()

    Print a description of the most recently thrown error code to `stderr`.

.. c:function:: void kite_ErrorState_fatal()

    Immediately terminate the current process using an exit code which 
    corresponds to the most recently thrown error code.