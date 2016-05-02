//
//  UserModel.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/28.
//
//

#include "UserModel.h"

using namespace CatFootPrint;
using namespace std;
using namespace cocos2d;

static const string GAME_NAME = "CatFootPrint";
static const string BEST_SCORE = "base_score";
static const string SOUND_STATE = "soundState";

void UserModel::toggleSoundState()
{
    const bool soundState = UserDefault::getInstance()->getBoolForKey(SOUND_STATE.c_str());
    UserDefault::getInstance()->setBoolForKey(SOUND_STATE.c_str(), !soundState);
}

bool UserModel::isSoundOpend()
{
    if (isBeginner()) {
        UserDefault::getInstance()->setBoolForKey(SOUND_STATE.c_str(), true);
    }
    const bool soundState = UserDefault::getInstance()->getBoolForKey(SOUND_STATE.c_str());
    return soundState;
}

bool UserModel::isBeginner()
{
    const bool isBegin = UserDefault::getInstance()->getBoolForKey(GAME_NAME.c_str());
    if (isBegin) {
        UserDefault::getInstance()->setBoolForKey(GAME_NAME.c_str(), true);
    }
    return isBegin;
}

int UserModel::getBestScore()
{
    return UserDefault::getInstance()->getIntegerForKey(BEST_SCORE.c_str());
}

void UserModel::setCurrentScore(int score)
{
    if (_score != score) {
        _score = score;
        const int bestScore = UserDefault::getInstance()->getIntegerForKey(BEST_SCORE.c_str());
        if (_score > bestScore) {
            UserDefault::getInstance()->setIntegerForKey(BEST_SCORE.c_str(), _score);
        }
    }
}