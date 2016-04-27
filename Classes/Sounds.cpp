//
//  Sounds.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#include "Config.h"
#include "Sounds.h"
#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
using namespace CatFootPrint;
using namespace cocos2d;
using namespace CocosDenshion;

static const std::string SOUND_KEY = "sound";
void Sounds::toggle()
{
    bool openState = UserDefault::getInstance()->getBoolForKey(SOUND_KEY.c_str());
    openState = !openState;
    UserDefault::getInstance()->setBoolForKey(SOUND_KEY.c_str(), openState);
    
    playMusic();
}

void Sounds::playMusic()
{
    if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY.c_str())) {
        SimpleAudioEngine::getInstance()->playBackgroundMusic(Config::getIns()->getMusicPath().c_str());
    } else {
        SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    }
}

void Sounds::click()
{
    if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY.c_str())) {
        SimpleAudioEngine::getInstance()->playEffect(Config::getIns()->getSoundClickID().c_str());
    }
}

