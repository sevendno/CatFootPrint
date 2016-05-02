//
//  ConfigVO.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/28.
//
//

#include "ConfigVO.h"
using namespace CatFootPrint;

ConfigVO::ConfigVO(const Json::Value &data)
{
    parseJson(data);
}

void ConfigVO::parseJson(const Json::Value &data)
{
    _data = data;
    if (!data.empty()) {
        if (data.isMember("cellCount")) {
            _cellCount = data["cellCount"].asInt();
        }
        if (data.isMember("bgMusicID")) {
            _bgMusicPath = data["bgMusicID"].asString();
        }
        if (data.isMember("elements")) {
            _elements = data["elements"];
        }
        if (data.isMember("delayTime")) {
            _delayTime = data["delayTime"].asFloat();
        }
        if (data.isMember("lives")) {
            _lives = data["lives"].asInt();
        }
        if (data.isMember("levelTimes")) {
            _levelTimes = data["levelTimes"].asInt();
        }
        if (data.isMember("colors")) {
            const Json::Value &colors = data["colors"];
            const int count = (int)colors.size();
            const int randIndex = rand() % count + 1;
            
            if (colors.isMember(to_string(randIndex))) {
                _defaultColor = Color3B(colors[to_string(randIndex)][0].asInt(),
                                   colors[to_string(randIndex)][1].asInt(),
                                   colors[to_string(randIndex)][2].asInt());
            }
        } else {
            _defaultColor = Color3B(rand() % 256, rand() % 256, rand() % 256);
        }
    }
}

string ConfigVO::getSoundByID(CatFootPrint::ConfigVO::SOUND_ID id) const
{
    string url = "";
    switch (id) {
        case SOUND_ID::CLICK:
            url = _data["soundClickID"].asString();
            break;
            
        default:
            break;
    }
    return url;
}


vector<ElementsVO> ConfigVO::getElements(int level)
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

int ConfigVO::getRandomIndex()
{
    return 1 + rand() % getTotalCellCount();
}
