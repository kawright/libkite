kite_ErrorCode.h - Error Codes
==============================

This header file contains the definition of the `kite_ErrorCode` enum, which
is used for storing Kite error codes.

.. versionadded:: v0.1.0

.. c:enum:: kite_ErrorCode

    This enum defines all error codes that are supported by Kite.

    .. c:enumerator:: kite_ErrorCode_OK

        Indicates that no error has occurred.

    .. c:enumerator:: kite_ErrorCode_GENERAL

        Indicates that a general, or otherwise uncategorized error has occurred.
        
    .. c:enumerator:: kite_ErrorCode_MEMORY_ALLOCATION

        Indicates that an attempt to allocate heap memory has failed.