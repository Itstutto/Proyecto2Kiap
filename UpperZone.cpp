//
// Created by cesar on 3/6/2026.
//

#include "UpperZone.h"
UpperZone* UpperZone::instance = nullptr;

UpperZone * UpperZone::getInstance() {
    if (!instance) instance = new UpperZone();
    return instance;
}
