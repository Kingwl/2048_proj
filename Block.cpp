#include "Block.h"
using namespace cocos2d;

Block::Block()
:m_color(nullptr), m_num(0)
{
	M_WIDTH = Director::sharedDirector()->getWinSize().width / 4.0;
	M_HEIGHT = Director::sharedDirector()->getWinSize().height / 4.0;
	srand((unsigned)time(nullptr));
}

Block::~Block()
{
}

Block* Block::createBlock()
{
	auto b = new Block();
	if (b && b->init())
	{
		b->autorelease();
		return b;
	}
	CC_SAFE_DELETE(b);
	return nullptr;
}
bool Block::init()
{
	this->setContentSize(Size(M_WIDTH, M_HEIGHT));

	m_color = LayerColor::create(ccc4(0x00,0x00,0x00,255),M_WIDTH,M_HEIGHT);
	this->addChild(m_color);
	int font_size = std::min(M_WIDTH / 2.0, M_HEIGHT / 2.0);
	m_label = Label::create("0", "Î¢ÈíÑÅºÚ",font_size);
	Size b_size = this->getContentSize();
	m_label->setPosition(b_size.width / 2.0, b_size.height / 2.0);
	this->addChild(m_label);
 	if (m_color == nullptr)
	{
		return false;
	}
	int n = rand() % 10;
	n = (n == 0) + 2;
	this->setNumber(n);
	return true;
}
void Block::setNumber(int n)
{
	m_num = n;
	this->setColor(n);
	this->setText(n);
}
void Block::setColor(int n)
{
	assert(m_color != nullptr);
	Color3B color;
	switch (n)
	{
	case 0:
		break;
		color = ccc3(0xff, 0xff, 0xff);
	case 2:
		color = ccc3(0x1f, 0x00, 0x68);
		break;
	case 4:
		color = ccc3(0x46, 0x17, 0xb4);
		break;
	case 8:
		color = ccc3(0x2d, 0x00, 0x4e);
		break;
	case 16:
		color = ccc3(0x72, 0x00, 0xac);
		break;
	case 32:
		color = ccc3(0xc1, 0x00, 0x4f);
		break;
	case 64:
		color = ccc3(0x4e, 0x00, 0x38);
		break;
	case 128:
		color = ccc3(0x4e, 0x00, 0x00);
		break;
	case 256:
		color = ccc3(0xb0, 0x1e, 0x00);
		break;
	case 512:
		color = ccc3(0x2e, 0x17, 0x00);
		break;
	case 1024:
		color = ccc3(0x63, 0x2f, 0x00);
		break;
	case 2048:
		color = ccc3(0xae, 0x11, 0x3d);
		break;
	default:
		break;
	}
	m_color->setColor(color);
}
void Block::setText(int n)
{
	char c[10];
	sprintf_s(c, "%d", n);
	m_label->setString(c);
}