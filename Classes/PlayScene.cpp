//
//  PlayScene.cpp
//  CatFootPrint
//
//  Created by sevendno on 16/4/14.
//
//

#include "PlayScene.h"
#include "Config.h"
#include "Assets.h"
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
        auto itemView = CellView::create(index, cellWidth, cellWidth, CC_CALLBACK_1(PlayScene::handleCellClick, this));
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
    for (auto cell : _cellMaps) {
        cell.second.value = "";
    }
    for (auto child : _container->getChildren()) {
        if (dynamic_cast<CellView*>(child)) {
            dynamic_cast<CellView*>(child)->clear();
        }
    }
    _actionShow.clear();
    
    const int totalCellCount = Config::getIns()->getTotalCellCount();
    for (const string element : _curLevelElements) {
        int index = getRandomIndex();
        while (index <= totalCellCount && !_cellMaps[index].value.empty()) {
            index = getRandomIndex();
        }
        _cellMaps[index].value = element;
        _actionShow.push_back(index);
    }
    actionShowValue();
}

void PlayScene::actionShowValue()
{
    if (!_actionShow.empty()) {
        const int index = _actionShow.front();
        if (_container->getChildByTag(index)) {
            dynamic_cast<CellView*>(_container->getChildByTag(index))->showValue(_cellMaps[index].value, [&]() {
                _actionShow.erase(_actionShow.begin());
                actionShowValue();
            });
        }
    } else {
        for (auto child : _container->getChildren()) {
            if (dynamic_cast<CellView*>(child)) {
                dynamic_cast<CellView*>(child)->showFootFrint();
            }
        }
        _isInitChessing = false;
    }
}

int PlayScene::getRandomIndex()
{
    const int totalCellCount = Config::getIns()->getTotalCellCount();
    const int randomIndex = rand()%(totalCellCount + 1);
    return randomIndex;
}

void PlayScene::handleCellClick(const string &value)
{
    if (_isInitChessing) return;
    auto findResult = find(_curLevelElements.begin(), _curLevelElements.end(), value);
    if (findResult == _curLevelElements.end()) {
        return;
    }
    _curLevelElements.erase(findResult);
    if (_curLevelElements.empty()) {
        initChessBoard();
    }
}

//================== CellView ==================
static const string FOOT_ICON = "footIconKey";
CellView* CellView::create(int index, float w, float h, const function<void(const string &value)> &cbResult)
{
    auto pRet = new CellView(index, w, h, cbResult);
    if (pRet && pRet->init()) {
        pRet->autorelease();
    } else {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

CellView::CellView(int index, float w, float h, const function<void(const string &value)> &cbResult)
:_index(index),
_w(w),
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
            if (_cbResult && !_value.empty()) {
                hideFootPrint();
                _cbResult(_value);
            }
        }
    });
    return true;
}

void CellView::showValue(const string &key, const function<void()> &cbDelayComplete)
{
    _value = key;
    auto spr = Assets::getIns()->getElementsByID(key);
    addChild(spr, 0);
    spr->setName(_value);
    spr->setScale(3);
    spr->setPosition(Vec2(spr->getContentSize().width/2, spr->getContentSize().height/2));
    this->runAction(Sequence::create(DelayTime::create(Config::getIns()->getDelayTime()), CallFunc::create(cbDelayComplete), NULL));
}

void CellView::showFootFrint()
{
    if (_value.empty()) {
        return;
    }
    hideFootPrint();
    auto footIcon = Assets::getIns()->getFootIcon();
    addChild(footIcon);
    footIcon->setScale(5);
    footIcon->setPosition(Vec2(footIcon->getContentSize().width/2, footIcon->getContentSize().height/2));
    footIcon->setName(FOOT_ICON);
}

void CellView::hideFootPrint()
{
    if (this->getChildByName(FOOT_ICON)) {
        this->removeChildByName(FOOT_ICON);
    }
}

void CellView::clear()
{
    if (_value.empty()) {
        return;
    }
    hideFootPrint();
    if (this->getChildByName(_value)) {
        this->removeChildByName(_value);
    }
    _value = "";
}
