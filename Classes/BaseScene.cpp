//
//  BaseScene.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#include "BaseScene.h"
#include "StartScene.h"
#include "Sounds.h"
#include "PlayScene.h"
#include "HelpScene.h"
#include "GameOverScene.h"
#include "cocostudio/CocoStudio.h"
#include "Config.h"
using namespace CatFootPrint;

void BaseScene::initButton(cocos2d::ui::Widget *widget, const function<void()> &cbClick)
{
    if (widget) {
        widget->addTouchEventListener([cbClick](Ref* sender, Widget::TouchEventType type) {
            if (type == Widget::TouchEventType::ENDED) {
                if(cbClick) cbClick();
                Sounds::click();
            }
        });
        if (dynamic_cast<Button*>(widget)) {
            const Color4B configColor = Config::getIns()->getColor();
            dynamic_cast<Button*>(widget)->setTitleColor(Color3B(configColor.r, configColor.g, configColor.b));
        }
    }
}

void BaseScene::loadUI(const string &filename)
{
    if (filename.empty()) {
        return;
    }
    _mainUI = CSLoader::createNodeWithVisibleSize(filename + ".csb");
    addChild(_mainUI, 1);
    
    LayerColor* colorBg = LayerColor::create(Config::getIns()->getColor());
    colorBg->setContentSize(_mainUI->getContentSize());
    addChild(colorBg, 0);
}

void BaseScene::onEnter()
{
    Scene::onEnter();
    initView();
}

void BaseScene::gotoScene(CatFootPrint::SCENE_TYPE type, int score)
{
    const float delayTime = 0.5f;
    Scene* scene = nullptr;
    switch (type) {
        case SCENE_TYPE::START:
            scene = TransitionFade::create(delayTime, StartScene::create());//TransitionFadeDown
            break;
        case SCENE_TYPE::PLAY:
            scene = TransitionFade::create(delayTime, PlayScene::create());
            break;
        case SCENE_TYPE::HELP:
            scene = TransitionFade::create(delayTime, HelpScene::create());
            break;
        case SCENE_TYPE::GAMEOVER:
            scene = TransitionFade::create(delayTime, GameOverScene::create(score));
            break;
        default:
            break;
    }
    if (!scene) return;
    Director::getInstance()->replaceScene(scene);
}