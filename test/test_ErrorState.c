#include "libkite.h"

int main() {

    kite_Quiz_init("kite_ErrorState Test Suite");

    kite_Quiz_isOkState("Test initial error state");

    kite_ErrorState_setCode(kite_ErrorCode_GENERAL);

    kite_Quiz_isThrown("Test error state updated successfully", 
        kite_ErrorCode_GENERAL);

    kite_ErrorState_reset();

    kite_Quiz_isOkState("Test successful reset");

    return kite_Quiz_finish();
}