//
//  BaseScene.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#include "Global.h"
#include "BaseScene.h"
#include "StartScene.h"
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
                GLOBAL->GetSoundCtrl()->playSound(ConfigVO::SOUND_ID::CLICK);
            }
        });
        if (dynamic_cast<Button*>(widget)) {
            dynamic_cast<Button*>(widget)->setTitleColor(GLOBAL->GetConfigVO()->getDefaultColor());
        }
    }
}

void BaseScene::loadUI(const string &filename)
{
    if (filename.empty()) {
        return;
    }
    
    _gridNode = NodeGrid::create(Rect(0, 0, Director::getInstance()->getWinSize().width, Director::getInstance()->getWinSize().height));
    addChild(_gridNode);
    
    _mainUI = CSLoader::createNodeWithVisibleSize("csb/" + filename + ".csb");
    _gridNode->addChild(_mainUI, 1);
    
    LayerColor* colorBg = LayerColor::create(Color4B(GLOBAL->GetConfigVO()->getDefaultColor()));
    colorBg->setContentSize(_mainUI->getContentSize());
    _gridNode->addChild(colorBg, 0);
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