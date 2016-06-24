//
//  StartScene.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#ifndef StartScene_h
#define StartScene_h
#include "BaseScene.h"

//namespace CatFootPrint
//{
class StartScene : public CatFootPrint::BaseScene
    {
    public:
        CREATE_FUNC(StartScene);
        StartScene() {};
        ~StartScene() {};
        virtual bool init() override;
        virtual void onEnter() override;
    protected:
        virtual void initView() override;
    private:
        void onKeyReleased(EventKeyboard::KeyCode keycode, cocos2d::Event *event);
    };
//}

#endif /* StartScene_h */
