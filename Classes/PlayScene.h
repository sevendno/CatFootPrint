//
//  PlayScene.h
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#ifndef PlayScene_h
#define PlayScene_h
#include "BaseScene.h"

namespace CatFootPrint
{
    struct CellVO
    {
        int index = 0;
        string value = "";
    };
    class PlayScene : public BaseScene
    {
    public:
        CREATE_FUNC(PlayScene);
        PlayScene() {};
        ~PlayScene() {};
        virtual bool init() override;
    protected:
        virtual void initView() override;
    private:
        void handleCellClick(bool result);
        void initChessBoard();
        int getRandomIndex();
    private:
        Node* _container = nullptr;
        Node* _rightPanel = nullptr;
        map<int, CellVO> _cellMaps;
        int _level = 0;
        bool _isInitChessing = false;
        vector<string> _curLevelElements;
    };
    
    class CellView : public Layout
    {
    public:
        static CellView* create(float w, float h, const function<void(bool result)> &cbResult);
        CellView(float w, float h, const function<void(bool result)> &cbResult);
        ~CellView() {};
        virtual bool init() override;
    private:
        float _w = 0.0;
        float _h = 0.0;
        function<void(bool result)> _cbResult = nullptr;
    };
}

#endif /* PlayScene_h */
