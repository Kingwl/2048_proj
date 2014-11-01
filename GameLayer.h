#pragma once
#include "cocos2d.h"
#ifndef _M_BLOCK_
#include "Block.h"
#endif
class GameLayer : public cocos2d::Layer
{
public:
	GameLayer();
	~GameLayer();
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameLayer);
};

