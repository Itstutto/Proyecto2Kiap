//
// Created by cesar on 4/6/2026.
//

#include "LowerMovList.h"
LowerMovList* LowerMovList::instance = nullptr;

LowerMovList * LowerMovList::getInstance() {
    if (!instance) instance = new LowerMovList();
    return instance;
}
