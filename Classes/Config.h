//
//  Config.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/15.
//
//

#ifndef Config_h
#define Config_h
#include "json_cpp.h"

namespace CatFootPrint
{
    class Config
    {
    public:
        static Config* getIns();
        void Setup();
        int getCellCount() const { return _cellCount; };
        int getLevelTimes() const { return _levelTimes; };
    private:
        Config() {};
        ~Config() {};
    private:
        static Config* _instance;
        int _cellCount = 0;
        int _levelTimes = 0;
        Json::Value _data;
    };
}

#endif /* Config_h */
