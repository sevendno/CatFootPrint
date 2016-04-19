//
//  Assets.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/19.
//
//

#include "Assets.h"
#include "Config.h"
using namespace CatFootPrint;
using namespace cocos2d;
Assets* Assets::_instance = nullptr;

Assets* Assets::getIns()
{
    if (_instance == nullptr) {
        _instance = new Assets();
    }
    return _instance;
}

void Assets::Setup()
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(Config::getIns()->getAssetsPath());
}

Sprite* Assets::getElementsByID(const string &id)
{
    auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName("elements/" + id + ".png");
    return Sprite::createWithSpriteFrame(spriteFrame);
}