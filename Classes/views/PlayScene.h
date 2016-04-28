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
#include "Config.h"

namespace CatFootPrint
{
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
        void handleCellClick(const string &value);
        void initChessBoard();
        void actionShowValue();
        void reset();
        void updateLivePanel();
    private:
        Layout* _container = nullptr;
        Node* _rightPanel = nullptr;
        int _level = 0;
        int _curLives = 0;
        int _score = 0;
        vector<ElementsVO> _actionShow;
        vector<ElementsVO> _curLevelElements;
        map<int, string> _orderMaps;
        int _order = 0;
    };
    
    class CellView : public Layer
    {
    public:
        static CellView* create(float w, float h, const function<void(const string &value)> &cbResult);
        CellView(float w, float h, const function<void(const string &value)> &cbResult);
        ~CellView() {};
        virtual bool init() override;
        void showValue(const string& key, const function<void()> &cbDelayComplete);
        void showFootFrint();
        void clear();
    private:
        float _w = 0.0;
        float _h = 0.0;
        string _value = "";
        Text* _tValue = nullptr;
        Node* _footIcon = nullptr;
        function<void(const string &value)> _cbResult = nullptr;
    };
}

#endif /* PlayScene_h */
