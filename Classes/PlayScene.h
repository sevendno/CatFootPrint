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
        void handleCellClick(const string &value);
        void initChessBoard();
        void actionShowValue();
        int getRandomIndex();
        void reset();
    private:
        Layout* _container = nullptr;
        Node* _rightPanel = nullptr;
        map<int, CellVO> _cellMaps;
        int _level = 0;
        vector<int> _actionShow;
        vector<string> _curLevelElements;
    };
    
    class CellView : public Layer
    {
    public:
        static CellView* create(int index, float w, float h, const function<void(const string &value)> &cbResult);
        CellView(int index, float w, float h, const function<void(const string &value)> &cbResult);
        ~CellView() {};
        virtual bool init() override;
        void showValue(const string& key, const function<void()> &cbDelayComplete);
        void showFootFrint();
        void clear();
    private:
        float _w = 0.0;
        float _h = 0.0;
        int _index = 0;
        string _value = "";
        Text* _tValue = nullptr;
        Node* _footIcon = nullptr;
        function<void(const string &value)> _cbResult = nullptr;
    };
}

#endif /* PlayScene_h */
