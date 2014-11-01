#pragma once
#ifndef _M_BLOCK_
#define _M_BLOCK_
#endif
#include "cocos2d.h"
class Block : public cocos2d::Node
{
public:
	Block();
	~Block();
	virtual bool init();
	static Block* createBlock();
	void setNumber(int n);
private:
	void setColor(int n);
	void setText(int n);
	cocos2d::LayerColor *m_color;
	cocos2d::Label *m_label;
	int m_num;
	int M_WIDTH;
	int M_HEIGHT;

};

