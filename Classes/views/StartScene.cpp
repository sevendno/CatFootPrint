//
//  StartScene.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#include "StartScene.h"
#include "PlayScene.h"
#include "HelpScene.h"
using namespace CatFootPrint;

bool StartScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    loadUI("StartScene");
    return true;
}

void StartScene::initView()
{
    
}

void StartScene::onEnter()
{
    Scene::onEnter();
    const auto &size = Director::getInstance()->getWinSize();
    _gridNode->runAction(RepeatForever::create(Ripple3D::create(4.0f, Size(32,24), Vec2(size.width/2,size.height/2), size.height, 10, 18)));
    
    initButton(dynamic_cast<Widget*>(_mainUI->getChildByName("Main")), [&]() {
        BaseScene::gotoScene(SCENE_TYPE::PLAY);
    });
    
    initButton(dynamic_cast<Button*>(_mainUI->getChildByName("Main")->getChildByName("rightPanel")->getChildByName("btn_help")), [&]() {
        BaseScene::gotoScene(SCENE_TYPE::HELP);
    });
}

