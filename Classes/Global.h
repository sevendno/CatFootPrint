//
//  Global.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/28.
//
//

#ifndef Global_h
#define Global_h

#include <memory>

#include "datas/ConfigVO.h"
#include "datas/UserModel.h"
#include "SoundCtrl.h"

using namespace std;

namespace CatFootPrint
{
    class Global
    {
    public:
        static Global* getIns();
        
        void SetupGame();
        shared_ptr<UserModel> GetUserModel() const { return _userModel; };
        shared_ptr<ConfigVO> GetConfigVO() const { return _configVO; };
        shared_ptr<SoundCtrl> GetSoundCtrl() const { return _soundCtrl; };
    private:
        Global() {};
        ~Global() {};
    private:
        static Global* _instance;
        shared_ptr<UserModel> _userModel = nullptr;
        shared_ptr<ConfigVO> _configVO = nullptr;
        shared_ptr<SoundCtrl> _soundCtrl = nullptr;
    };
}

#define GLOBAL CatFootPrint::Global::getIns()

#endif /* Global_h */
