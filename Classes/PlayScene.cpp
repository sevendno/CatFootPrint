//
//  PlayScene.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#include "PlayScene.h"
#include "Config.h"
using namespace CatFootPrint;

bool PlayScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    loadUI("PlayScene");
    return true;
}

void PlayScene::initView()
{
    _container = _mainUI->getChildByName("Main")->getChildByName("container");
    _rightPanel = _mainUI->getChildByName("Main")->getChildByName("rightPanel");
    
    const auto &winSize = Director::getInstance()->getWinSize();
    _container->setContentSize(Size(winSize.width, winSize.width));
    
    const int rowCellCount = Config::getIns()->getCellCount();
    const int totalCellCount = Config::getIns()->getTotalCellCount();
    const int cellWidth = int(winSize.width*1.0f / rowCellCount);
    
    int index = 1;
    while (index <= totalCellCount) {
        auto itemView = CellView::create(cellWidth, cellWidth, CC_CALLBACK_1(PlayScene::handleCellClick, this));
        _container->addChild(itemView);
        const float xpos = index <= 6 ? (index - 1) * cellWidth : (index - 1) % rowCellCount * cellWidth;
        const float ypos = _container->getContentSize().height - ceil(index*1.0/rowCellCount) * cellWidth;
        itemView->setPosition(Vec2(xpos, ypos));
        itemView->setTag(index);
        
        CellVO vo;
        vo.index = index;
        _cellMaps[index] = vo;
        index++;
    }
    
    initChessBoard();
}

void PlayScene::initChessBoard()
{
    _isInitChessing = true;
    _level++;
    _curLevelElements = Config::getIns()->getElements(_level);
    
    const int totalCellCount = Config::getIns()->getTotalCellCount();
    
    vector<int> actionShow;
    for (const string element : _curLevelElements) {
        int index = getRandomIndex();
        while (index <= totalCellCount && !_cellMaps[index].value.empty()) {
            index = getRandomIndex();
        }
        _cellMaps[index].value = element;
        actionShow.push_back(index);
    }
    if (!actionShow.empty()) {
        
    }
    
    _isInitChessing = false;
}

int PlayScene::getRandomIndex()
{
    const int totalCellCount = Config::getIns()->getTotalCellCount();
    const int randomIndex = rand()%(totalCellCount + 1);
    return randomIndex;
}

void PlayScene::handleCellClick(bool result)
{
    if (_isInitChessing) return;
    _curLevelElements.erase(_curLevelElements.begin());
    if (_curLevelElements.empty()) {
        initChessBoard();
    }
}

//================== CellView ==================
CellView* CellView::create(float w, float h, const function<void(bool result)> &cbResult)
{
    auto pRet = new CellView(w, h, cbResult);
    if (pRet && pRet->init()) {
        pRet->autorelease();
    } else {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

CellView::CellView(float w, float h, const function<void(bool result)> &cbResult)
:_w(w),
_h(h),
_cbResult(cbResult)
{
}

bool CellView::init()
{
    if (!Layout::init()) {
        return false;
    }
    setContentSize(Size(_w, _h));
    setTouchEnabled(true);
    addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::ENDED) {
            if (_cbResult) {
                _cbResult(false);
            }
        }
    });
    setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    setBackGroundColor(Color3B::WHITE);
    return true;
}

void CellView::showValue(const string &key)
{
    
}

void CellView::showFootPrint()
{
    
}

void CellView::clear()
{
    
}
