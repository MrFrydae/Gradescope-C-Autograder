//
// Created by merlin on 12/30/2024.
//

#ifndef FRAMEWORK_TEST_DETAILS_H
#define FRAMEWORK_TEST_DETAILS_H
#include "practice.h"


checkOneThing("first just_multiply test",just_multiply(-2) == -84,5,"Should work for negatives");
checkOneThing("failing_test",just_multiply(100)== 4200,10,"Don't make this so hard - just multiply!!!");

#endif //FRAMEWORK_TEST_DETAILS_H
