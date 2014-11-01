#include "GameLayer.h"
using namespace cocos2d;

GameLayer::GameLayer()
{
}


GameLayer::~GameLayer()
{
}
Scene* GameLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = GameLayer::create();
	scene->addChild(layer);
	return scene;
}
bool GameLayer::init()
{
	auto sp = Block::createBlock();
	this->addChild(sp);
	sp->setNumber(256);
	sp->setPosition(100, 100);
	return true;
}