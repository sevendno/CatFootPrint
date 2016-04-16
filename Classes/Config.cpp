//
//  Config.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/15.
//
//

#include "Config.h"
using namespace CatFootPrint;

Config* Config::_instance = nullptr;
Config* Config::getIns()
{
    if (_instance == nullptr) {
        _instance = new Config();
    }
    return _instance;
}

void Config::Setup()
{
    const std::string configStr = cocos2d::FileUtils::getInstance()->getStringFromFile("config.json");
    
    Json::Value root;
    Json::Reader reader;
    reader.parse(configStr, root);
    
    if (root.isMember("cellCount")) {
        _cellCount = root["cellCount"].asInt();
    }
    if (root.isMember("levelTimes")) {
        _levelTimes = root["levelTimes"].asInt();
    }
}