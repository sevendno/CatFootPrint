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
using namespace cocos2d;
using namespace std;
namespace CatFootPrint
{
    struct ElementsVO
    {
        string elementID = "";
        int childTag = 0;
    };
    class Config
    {
    public:
        static Config* getIns();
        void Setup();
        int getCellCount() const { return _cellCount; };
        int getTotalCellCount() const { return _cellCount*_cellCount; };
        int getLevelTimes() const { return _levelTimes; };
        int getLives() const { return _lives; };
        float getDelayTime() const { return _delayTime; };
        string getMusicPath() const { return _musciPath; };
        string getLanguage(const string &key) const;
        string getAssetsPath() const { return _assetsPath; };
        Color4B getColor() const { return _color4b; };
        vector<ElementsVO> getElements(int level);
        string getSoundClickID() const { return _soundClickID; };
    private:
        Config() {};
        ~Config() {};
        int getRandomIndex();
    private:
        static Config* _instance;
        int _cellCount = 0;
        int _levelTimes = 0;
        float _delayTime = 0.0;
        int _lives = 0;
        string _musciPath = "";
        string _assetsPath = "";
        string _soundClickID = "";
        Color4B _color4b;
        Json::Value _language;
        Json::Value _elements;
    };
}

#endif /* Config_h */
