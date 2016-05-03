//
//  SoundCtrl.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/30.
//
//

#ifndef SoundCtrl_h
#define SoundCtrl_h
#include "datas/UserModel.h"
#include "datas/ConfigVO.h"

using namespace std;
namespace CatFootPrint
{
    class SoundCtrl
    {
    public:
        SoundCtrl(const shared_ptr<UserModel> &model);
        ~SoundCtrl() {};
        void toggle();
        void playSound(ConfigVO::SOUND_ID id);
        void playBgMusic();
    private:
        shared_ptr<UserModel> _model = nullptr;
    };
}

#endif /* SoundCtrl_h */
