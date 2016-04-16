//
//  HelpScene.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#include "HelpScene.h"
#include "StartScene.h"
#include "Sounds.h"
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
    initButton(dynamic_cast<Button*>(_mainUI->getChildByName("btn_back")), [&]() {
        replaceScene(StartScene::create());
    });
    
    initButton(dynamic_cast<Button*>(_mainUI->getChildByName("btn_sound")), [&]() {
        Sounds::toggle();
    });
}