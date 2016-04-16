//
//  GameOverScene.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#ifndef GameOverScene_h
#define GameOverScene_h
#include "BaseScene.h"

namespace CatFootPrint
{
    class GameOverScene : public BaseScene
    {
    public:
        CREATE_FUNC(GameOverScene);
        GameOverScene() {};
        ~GameOverScene() {};
        virtual bool init() override;
    protected:
        virtual void initView() override;
    };
}

#endif /* GameOverScene_h */
