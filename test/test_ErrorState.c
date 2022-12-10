#include "libkite.h"

void errorHandler(kite_ErrorCode code) {
    kite_ErrorState_reset();
}

int main() {

    kite_Quiz_init("kite_ErrorState Test Suite");

    kite_Quiz_isOkState("Test initial error state");

    kite_ErrorState_setCode(kite_ErrorCode_GENERAL);

    kite_Quiz_isThrown("Test error state updated successfully", 
        kite_ErrorCode_GENERAL);

    kite_ErrorState_reset();

    kite_Quiz_isOkState("Test successful reset");

    kite_ErrorState_setCode(kite_ErrorCode_GENERAL);

    // The error handler resets the state...
    kite_ErrorState_handle(&errorHandler);

    kite_Quiz_isOkState("Test error handler");

    return kite_Quiz_finish();
}