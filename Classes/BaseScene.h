//
//  BaseScene.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#ifndef BaseScene_h
#define BaseScene_h
#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace ui;
using namespace std;

namespace CatFootPrint
{
    enum class SCENE_TYPE {START, PLAY, HELP, GAMEOVER};
    class BaseScene : public Scene
    {
    public:
        BaseScene() {};
        ~BaseScene() {};
        static void gotoScene(SCENE_TYPE type);
        virtual void onEnter() override;
    protected:
        virtual void initView() = 0;
        void loadUI(const string &filename);
        void initButton(Widget* widget, const function<void()> &cbClick);
    protected:
        Node* _mainUI = nullptr;
    };
}

#endif /* BaseScene_h */
