//
//  HelpScene.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#include "HelpScene.h"
#include "StartScene.h"
#include "Global.h"
using namespace CatFootPrint;

bool HelpScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    loadUI("HelpScene");
    return true;
}

void HelpScene::initView()
{
    initButton(dynamic_cast<Button*>(_mainUI->getChildByName("Main")->getChildByName("btn_back")), [&]() {
        BaseScene::gotoScene(SCENE_TYPE::START);
    });
    
    initButton(dynamic_cast<Button*>(_mainUI->getChildByName("Main")->getChildByName("btn_sound")), [&]() {
        GLOBAL->GetSoundCtrl()->toggle();
    });
}