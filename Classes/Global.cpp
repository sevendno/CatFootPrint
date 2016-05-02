//
//  Global.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/28.
//
//

#include "Global.h"
#include "views/StartScene.h"
using namespace CatFootPrint;

Global* Global::_instance = nullptr;

Global* Global::getIns()
{
    if (_instance == nullptr) {
        _instance = new Global();
    }
    return _instance;
}

void Global::SetupGame()
{
    const std::string configStr = cocos2d::FileUtils::getInstance()->getStringFromFile("config.json");
    Json::Value json;
    Json::Reader reader;
    reader.parse(configStr, json);
    
    _configVO = make_shared<ConfigVO>(json);
    
    _userModel = make_shared<UserModel>();
    
    _soundCtrl = make_shared<SoundCtrl>(_userModel);
    
    Director::getInstance()->replaceScene(StartScene::create());
}
