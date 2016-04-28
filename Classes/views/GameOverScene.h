//
//  GameOverScene.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#ifndef GameOverScene_h
#define GameOverScene_h
#include "BaseScene.h"

namespace CatFootPrint
{
    class GameOverScene : public BaseScene
    {
    public:
        static GameOverScene* create(int score);
        GameOverScene(int score) { _score = score; };
        ~GameOverScene() {};
        virtual bool init() override;
    protected:
        virtual void initView() override;
    private:
        void setTextColor(Node* text, const string &value="");
    private:
        int _score = 0;
    };
}

#endif /* GameOverScene_h */
