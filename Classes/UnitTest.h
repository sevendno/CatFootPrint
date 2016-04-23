//
//  UnitTest.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/23.
//
//

#ifndef UnitTest_h
#define UnitTest_h

#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace ui;
using namespace std;

namespace CatFootPrint
{
    class UnitTest : public Scene
    {
    public:
        UnitTest() {};
        ~UnitTest() {};
        
        virtual bool init() override;
    };
}

#endif /* UnitTest_h */
