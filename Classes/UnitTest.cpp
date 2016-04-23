//
//  UnitTest.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/23.
//
//

#include "UnitTest.h"
#include "cocostudio/CocoStudio.h"
#include "Config.h"
using namespace CatFootPrint;

bool UnitTest::init()
{
    if (!Scene::init()) {
        return false;
    }
    return true;
}
