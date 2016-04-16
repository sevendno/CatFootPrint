//
//  StartScene.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#include "StartScene.h"
#include "PlayScene.h"
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
}