
#include "libkite.h"

int main() {

    kite_Quiz_init("kite_Quiz Test Suite (SHOULD FAIL 50\% CASE RATE)!");

    kite_Quiz_isThrown("Test isThrown pass", kite_ErrorCode_OK);
    
    kite_Quiz_isThrown("Test isThrown fail", kite_ErrorCode_GENERAL);
    
    kite_ErrorState_setCode(kite_ErrorCode_GENERAL);
    kite_Quiz_isErrorState("Test isErrorState pass");

    kite_ErrorState_setCode(kite_ErrorCode_OK);
    kite_Quiz_isErrorState("Test isErrorState fail");

    kite_Quiz_isOkState("Test isOkState pass");

    kite_ErrorState_setCode(kite_ErrorCode_GENERAL);
    kite_Quiz_isOkState("Test isOkState fail");

    kite_Quiz_isEqualInt("Test isEqualInt pass", 0, 0);

    kite_Quiz_isEqualInt("Test isEqualInt fail", 0, 1);

    kite_Quiz_isEqualFloat("Test isEqualFloat pass", 1.5, 1.5);

    kite_Quiz_isEqualFloat("Test isEqualFloat fail", 1.5, -1.5);

    kite_Quiz_isEqualChar("Test isEqualChar pass", 'a', 'a');

    kite_Quiz_isEqualChar("Test isEqualChar fail", 'a', 'A');

    kite_Quiz_isEqualString("Test isEqualString pass", "foo", "foo");

    kite_Quiz_isEqualString("Test isEqualString fail", "foo", "bar");

    kite_Quiz_isNotEqualInt("Test isNotEqualInt pass", 0, 1);

    kite_Quiz_isNotEqualInt("Test isNotEqualInt fail", 0, 0);

    kite_Quiz_isNotEqualFloat("Test isNotEqualFloat pass", 1.5, -1.5);

    kite_Quiz_isNotEqualFloat("Test isNotEqualFloat fail", 1.5, 1.5);

    kite_Quiz_isNotEqualChar("Test isNotEqualChar pass", 'a', 'A');

    kite_Quiz_isNotEqualChar("Test isNotEqualChar fail", 'a', 'a');

    kite_Quiz_isNotEqualString("Test isNotEqualString pass", "foo", "bar");

    kite_Quiz_isNotEqualString("Test isNotEqualString fail", "foo", "foo");

    kite_Quiz_isLessThanInt("Test isLessThanInt pass", 1, 10);

    kite_Quiz_isLessThanInt("Test isLessThanInt fail", 10, 1);

    kite_Quiz_isLessThanFloat("Test isLessThanFloat pass", -11.5, 11.5);

    kite_Quiz_isLessThanFloat("Test isLessThanFloat fail", 11.5, 11.5);

    kite_Quiz_isLessThanChar("Test isLessThanChar pass", 'a', 'c');

    kite_Quiz_isLessThanChar("Test isLessThanChar fail", 'c', 'a');

    kite_Quiz_isLessThanString("Test isLessThanString pass", "bar", "foo");

    kite_Quiz_isLessThanString("Test isLessThanString fail", "foo", "bar");

    kite_Quiz_isLessThanOrEqualToInt("Test isLessThanOrEqualToInt pass", 1, 10);

    kite_Quiz_isLessThanOrEqualToInt("Test isLessThanOrEqualToInt fail", 10, 1);

    kite_Quiz_isLessThanOrEqualToFloat("Test isLessThanOrEqualToFloat pass", 
        11.5, 11.5);

    kite_Quiz_isLessThanOrEqualToFloat("Test isLessThanOrEqualToFloat fail", 
        11.5, 1.5);

    kite_Quiz_isLessThanOrEqualToChar("Test isLessThanOrEqualToChar pass", 'a', 
        'c');

    kite_Quiz_isLessThanOrEqualToChar("Test isLessThanOrEqualToChar fail", 'c', 
        'a');

    kite_Quiz_isLessThanOrEqualToString("Test isLessThanOrEqualToString pass", 
        "bar", "foo");

    kite_Quiz_isLessThanOrEqualToString("Test isLessThanOrEqualToString fail", 
        "foo", "bar");

    kite_Quiz_isGreaterThanInt("Test isGreaterThanInt pass", 10, 1);

    kite_Quiz_isGreaterThanInt("Test isGreaterThanInt fail", 1, 10);

    kite_Quiz_isGreaterThanFloat("Test isGreaterThanFloat pass", 11.5, -11.5);

    kite_Quiz_isGreaterThanFloat("Test isGreaterThanFloat fail", 11.5, 11.5);

    kite_Quiz_isGreaterThanChar("Test isGreaterThanChar pass", 'c', 'a');

    kite_Quiz_isGreaterThanChar("Test isGreaterThanChar fail", 'a', 'c');

    kite_Quiz_isGreaterThanString("Test isGreaterThanString pass", "foo", 
        "bar");

    kite_Quiz_isGreaterThanString("Test isGreaterThanString fail", "bar", 
        "foo");

    kite_Quiz_isGreaterThanOrEqualToInt("Test isGreaterThanOrEqualToInt pass", 
        10, 10);

    kite_Quiz_isGreaterThanOrEqualToInt("Test isGreaterThanOrEqualToInt fail", 
        1, 10);

    kite_Quiz_isGreaterThanOrEqualToFloat("Test isGreaterThanOrEqualToFloat "
        "pass", 11.5, 11.5);

    kite_Quiz_isGreaterThanOrEqualToFloat("Test isGreaterThanOrEqualToFloat "
        "fail", -11.5, 1.5);

    kite_Quiz_isGreaterThanOrEqualToChar("Test isGreaterThanOrEqualToChar pass", 
        'c', 'a');

    kite_Quiz_isGreaterThanOrEqualToChar("Test isGreaterThanOrEqualToChar fail", 
        'c', 'z');

    kite_Quiz_isGreaterThanOrEqualToString("Test isGreaterThanOrEqualToString "
        "pass", "bar", "bar");

    kite_Quiz_isGreaterThanOrEqualToString("Test isGreaterThanOrEqualToString "
        "fail", "foo", "zap");

    kite_Quiz_isTrue("Test isTrue pass", 1);

    kite_Quiz_isTrue("Test isTrue false", 0);

    kite_Quiz_isFalse("Test isFalse pass", 0);

    kite_Quiz_isFalse("Test isFalse false", 1);

    return kite_Quiz_finish();

}