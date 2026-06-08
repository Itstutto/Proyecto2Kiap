//
// Created by cesar on 3/6/2026.
//

#include "LowerZone.h"
LowerZone* LowerZone::instance = nullptr;

LowerZone * LowerZone::getInstance() {
    if (!instance) instance = new LowerZone();
    return instance;
}
