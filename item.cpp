#include"framework.h"
#include"item.h"
#include"player.h"

item::item()
{
}

item::~item()
{
}

HRESULT item::init()
{
	_item = new image;
	_item = IMAGE->addImage("item", "images/sigong.bmp", 40, 40, true, RGB(255, 0, 255));

	item_rc = RectMakeCenter(_item->getFrameX(), _item->getFrameY(), _item->getWidth(), _item->getFrameHeight());

	return S_OK;
}

void item::release()
{
}

void item::update()
{
}

void item::render()
{
	//_item->render(getMemDC(), WINSIZEX / 2, 500);		//ÁÂÇ¥¼öÁ¤ÇØ¾ßµÊ
}

bool item::isGet()
{
	RECT rc;
	if (IntersectRect(&rc, &_player->getRect(), &item_rc))
	return false;
}



