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
    initButton(dynamic_cast<Widget*>(_mainUI->getChildByName("Main")), [&]() {
        replaceScene(PlayScene::create());
    });
    
    initButton(dynamic_cast<Button*>(_mainUI->getChildByName("Main")->getChildByName("rightPanel")->getChildByName("btn_help")), [&]() {
        replaceScene(HelpScene::create());
    });
}