//
//  GameOverScene.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#include <string>
#include <vector>

#include "GameOverScene.h"
#include "Global.h"
#include "flatbuffers/util.h"

using namespace std;
using namespace cocos2d;
using namespace CatFootPrint;
using namespace flatbuffers;

GameOverScene* GameOverScene::create(int score)
{
    auto ret = new GameOverScene(score);
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

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
    initButton(dynamic_cast<Button*>(_mainUI->getChildByName("Main")->getChildByName("btn_retry")), [&]() {
        BaseScene::gotoScene(SCENE_TYPE::START);
    });
    _mainUI->getChildByName("Main")->getChildByName("btn_shared")->setVisible(false);
    initButton(dynamic_cast<Button*>(_mainUI->getChildByName("Main")->getChildByName("btn_shared")), [&]() {
        
    });
    auto panel = _mainUI->getChildByName("Main")->getChildByName("panelscore")->getChildByName("bg");
    setTextColor(panel->getChildByName("tScoreTitle"));
    setTextColor(panel->getChildByName("tScore"), NumToString(_score));
    setTextColor(panel->getChildByName("tBestTitle"));
    
    auto tPastBest = _mainUI->getChildByName("Main")->getChildByName("tPastBest");
    tPastBest->setVisible(false);
    const string key = "CatBestScore";
    if (UserDefault::getInstance()->getIntegerForKey(key.c_str()) < _score) {
        UserDefault::getInstance()->setIntegerForKey(key.c_str(), _score);
        tPastBest->setVisible(true);
    } else {
        GLOBAL->GetSoundCtrl()->playSound(ConfigVO::SOUND_ID::OVER);
    }
    setTextColor(panel->getChildByName("tBest"), NumToString(UserDefault::getInstance()->getIntegerForKey(key.c_str())));
}

void GameOverScene::setTextColor(cocos2d::Node *text, const string &value)
{
    if (!text) return;
    dynamic_cast<Text*>(text)->setTextColor(Color4B(GLOBAL->GetConfigVO()->getDefaultColor()));
    if (!value.empty()) {
        dynamic_cast<Text*>(text)->setString(value);
    }
}