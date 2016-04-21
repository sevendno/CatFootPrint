//
//  Assets.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/19.
//
//

#ifndef Assets_h
#define Assets_h
using namespace std;
using namespace cocos2d;
namespace CatFootPrint
{
    class Assets
    {
    public:
        static Assets* getIns();
        void Setup();
        Sprite* getElementsByID(const string &id);
        Sprite* getFootIcon();
    private:
        Assets() {};
        ~Assets() {};
    private:
        static Assets* _instance;
    };
}

#endif /* Assets_h */
