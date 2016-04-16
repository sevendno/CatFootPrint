//
//  HelpScene.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#ifndef HelpScene_h
#define HelpScene_h
#include "BaseScene.h"

namespace CatFootPrint
{
    class HelpScene : public BaseScene
    {
    public:
        CREATE_FUNC(HelpScene);
        HelpScene() {};
        ~HelpScene() {};
        virtual bool init() override;
    protected:
        virtual void initView() override;
    };
}

#endif /* HelpScene_h */
