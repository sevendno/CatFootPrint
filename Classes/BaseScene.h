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
    class BaseScene : public Scene
    {
    public:
        BaseScene() {};
        ~BaseScene() {};
    protected:
        virtual void initView() = 0;
        void loadUI(const string &filename);
        void initButton(Widget* widget, const function<void()> &cbClick);
        void replaceScene(Scene* scene);
    protected:
        Node* _mainUI = nullptr;
    };
}

#endif /* BaseScene_h */
