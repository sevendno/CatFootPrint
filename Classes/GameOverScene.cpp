//
//  GameOverScene.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#include "GameOverScene.h"
using namespace CatFootPrint;

bool GameOverScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    loadUI("GameOverScene");
    return true;
}

void GameOverScene::initView()
{
    
}