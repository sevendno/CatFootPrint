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
    
    Json::Value json;
    Json::Reader reader;
    reader.parse(configStr, json);
    
    if (json.isMember("cellCount")) {
        _cellCount = json["cellCount"].asInt();
    }
    if (json.isMember("levelTimes")) {
        _levelTimes = json["levelTimes"].asInt();
    }
    if (json.isMember("musicID")) {
        _musciPath = json["musicID"].asString();
    }
    if (json.isMember("language")) {
        _language = json["language"];
    }
    if (json.isMember("elements")) {
        _elements = json["elements"];
    }
    if (json.isMember("assetsID")) {
        _assetsPath = json["assetsID"].asString();
    }
    if (json.isMember("delayTime")) {
        _delayTime = json["delayTime"].asFloat();
    }
    if (json.isMember("lives")) {
        _lives = json["lives"].asInt();
    }
    const int r = rand() % 256;
    const int g = rand() % 256;
    const int b = rand() % 256;
    _color4b = Color4B(r, g, b, 255);
}

string Config::getLanguage(const string &key) const
{
    if (_language.isMember(key)) {
        return _language[key].asString();
    }
    return "";
}

vector<ElementsVO> Config::getElements(int level)
{
    const int elementsID = std::ceil(level*1.0f / _levelTimes);
    vector<ElementsVO> eles;
    if (!_elements.isMember(to_string(elementsID))) {
        return eles;
    }
    const Json::Value &elements = _elements[to_string(elementsID)];
    map<int,int> childTagMap;
    for (const auto& element : elements) {
        int childTag = getRandomIndex();
        while (childTagMap[childTag]) {
            childTag = getRandomIndex();
        }
        childTagMap[childTag] = childTag;
        
        ElementsVO vo;
        vo.elementID = element.asString();
        vo.childTag = childTag;
        eles.push_back(vo);
    }
    return eles;
}

int Config::getRandomIndex()
{
    return 1 + rand() % getTotalCellCount();
}