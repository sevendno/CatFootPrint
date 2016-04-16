//
//  BaseScene.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#include "BaseScene.h"
#include "cocostudio/CocoStudio.h"
using namespace CatFootPrint;

void BaseScene::initButton(cocos2d::ui::Widget *widget, const function<void()> &cbClick)
{
    if (widget) {
        widget->addTouchEventListener([cbClick](Ref* sender, Widget::TouchEventType type) {
            if (type == Widget::TouchEventType::ENDED) {
                if(cbClick) cbClick();
            }
        });
    }
}

void BaseScene::loadUI(const string &filename)
{
    if (filename.empty()) {
        return;
    }
    _mainUI = CSLoader::createNodeWithVisibleSize(filename + ".csb");
    addChild(_mainUI);
    initView();
}

void BaseScene::replaceScene(cocos2d::Scene *scene)
{
    if (!scene) {
        return;
    }
    Director::getInstance()->replaceScene(scene);
}