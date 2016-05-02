//
//  ConfigVO.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/28.
//
//

#ifndef ConfigVO_h
#define ConfigVO_h
#include "cocos2d.h"
#include "json_cpp.h"

using namespace std;
using namespace cocos2d;
namespace CatFootPrint
{
    struct ElementsVO
    {
        string elementID = "";
        int childTag = 0;
    };
    class ConfigVO
    {
    public:
        enum class SOUND_ID { CLICK, WIN };
        ConfigVO(const Json::Value &data);
        ~ConfigVO() {};
        int getCellCount() const { return _cellCount; };
        int getTotalCellCount() const { return _cellCount*_cellCount; };
        int getLives() const { return _lives; };
        int getLevelTimes() const { return _levelTimes; };
        Color3B getDefaultColor() const { return _defaultColor; };
        string getBgMusicPath() const { return _bgMusicPath; };
        string getSoundByID(SOUND_ID id) const;
        vector<ElementsVO> getElements(int level);
        float getDelayTime() const { return _delayTime; };
        int getRandomIndex();
    private:
        void parseJson(const Json::Value &data);
    private:
        Json::Value _data;
        int _cellCount = 0;
        int _levelTimes = 0;
        int _lives = 0;
        float _delayTime = 0.0;
        string _bgMusicPath = "";
        Color3B _defaultColor;
        Json::Value _elements;
    };
}

#endif /* ConfigVO_h */