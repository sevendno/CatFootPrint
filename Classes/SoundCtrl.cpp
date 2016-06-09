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
#include "datas/UserModel.h"
#include "datas/ConfigVO.h"

using namespace CatFootPrint;
using namespace cocos2d;
using namespace CocosDenshion;

SoundCtrl::SoundCtrl(const shared_ptr<UserModel> &model)
:_model(model)
{
}


void SoundCtrl::toggle()
{
    _model->toggleSoundState();
    playBgMusic();
}

void SoundCtrl::playBgMusic()
{
    if (_model->isSoundOpend()) {
        SimpleAudioEngine::getInstance()->playBackgroundMusic(GLOBAL->GetConfigVO()->getBgMusicPath().c_str(), true);
    } else {
        SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    }
}

void SoundCtrl::playSound(ConfigVO::SOUND_ID id)
{
    if (_model->isSoundOpend()) {
        SimpleAudioEngine::getInstance()->playEffect(GLOBAL->GetConfigVO()->getSoundByID(id).c_str());
    }
}