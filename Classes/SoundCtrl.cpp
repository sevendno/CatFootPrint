//
//  SoundCtrl.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/30.
//
//

#include "SoundCtrl.h"
#include "Global.h"
#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
using namespace CatFootPrint;
using namespace cocos2d;
using namespace CocosDenshion;

const string SoundCtrl::SOUNDID_CLICK = "clickWavShort.wav";
SoundCtrl::SoundCtrl(const shared_ptr<UserModel> &model)
:_model(model)
{
}

void SoundCtrl::toggle()
{
    _model->toggleSoundState();
    if (_model->isSoundOpend()) {
        SimpleAudioEngine::getInstance()->playBackgroundMusic(GLOBAL->GetConfigVO()->getBgMusicPath().c_str());
    } else {
        SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    }
}

void SoundCtrl::playSound(const string &key)
{
    if (_model->isSoundOpend()) {
        SimpleAudioEngine::getInstance()->playEffect(key.c_str());
    }
}