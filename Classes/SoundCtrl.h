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

using namespace std;
namespace CatFootPrint
{
    class SoundCtrl
    {
    public:
        static const string SOUNDID_CLICK;
        SoundCtrl(const shared_ptr<UserModel> &model);
        ~SoundCtrl() {};
        void toggle();
        void playSound(const string &key);
    private:
        shared_ptr<UserModel> _model = nullptr;
    };
}

#endif /* SoundCtrl_h */
