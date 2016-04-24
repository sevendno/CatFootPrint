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
#include "cocostudio/CocoStudio.h"
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
    _container = dynamic_cast<Layout*>(_mainUI->getChildByName("Main")->getChildByName("container"));
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
        index++;
    }
    
    initChessBoard();
}

void PlayScene::initChessBoard()
{
    reset();
    _level++;
    _curLevelElements = Config::getIns()->getElements(_level);
    _actionShow = _curLevelElements;
    actionShowValue();
}

void PlayScene::actionShowValue()
{
    if (!_actionShow.empty()) {
        ElementsVO vo = _actionShow.front();
        if (_container->getChildByTag(vo.childTag)) {
            dynamic_cast<CellView*>(_container->getChildByTag(vo.childTag))->showValue(vo.elementID, [&]() {
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
        _container->setEnabled(true);
    }
}

void PlayScene::handleCellClick(const string &value)
{
    for(auto it=_curLevelElements.begin(); it!=_curLevelElements.end(); ) {
        if((* it).elementID == value) {
            it = _curLevelElements.erase(it);
        } else {
            ++it;
        }
    }
    if (_curLevelElements.empty()) {
        initChessBoard();
    }
}

void PlayScene::reset()
{
    for (auto child : _container->getChildren()) {
        if (dynamic_cast<CellView*>(child)) {
            dynamic_cast<CellView*>(child)->clear();
        }
    }
    _actionShow.clear();
    _container->setEnabled(false);
}

//================== CellView ==================
CellView* CellView::create(float w, float h, const function<void(const string &value)> &cbResult)
{
    auto pRet = new CellView(w, h, cbResult);
    if (pRet && pRet->init()) {
        pRet->autorelease();
    } else {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

CellView::CellView(float w, float h, const function<void(const string &value)> &cbResult)
:_w(w),
_h(h),
_cbResult(cbResult)
{
}

bool CellView::init()
{
    if (!Layer::init()) {
        return false;
    }
    setContentSize(Size(_w, _h));
    auto node = CSLoader::createNode("CellViewComp.csb");
    node->setContentSize(getContentSize());
    Helper::doLayout(node);
    addChild(node);
    
    auto main = dynamic_cast<Layout*>(node->getChildByName("Main"));
    main->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::ENDED) {
            if (_cbResult && !_value.empty()) {
                _cbResult(_value);
                clear();
            }
        }
    });
    _tValue = dynamic_cast<Text*>(main->getChildByName("tValue"));
    _footIcon = main->getChildByName("footIcon");
    return true;
}

void CellView::showValue(const string &key, const function<void()> &cbDelayComplete)
{
    _value = key;
    _tValue->setString(key);
    this->runAction(Sequence::create(DelayTime::create(Config::getIns()->getDelayTime()), CallFunc::create(cbDelayComplete), NULL));
}

void CellView::showFootFrint()
{
    if (_value.empty()) return;
    _footIcon->setVisible(true);
}

void CellView::clear()
{
    _tValue->setString("");
    _footIcon->setVisible(false);
    _value = "";
}
