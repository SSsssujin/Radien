#pragma once
#include"gameNode.h"

class player;
class item : public gameNode
{
private:
	image*	_item;
	player* _player;
	RECT	item_rc;


public:
	item();
	~item();


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	RECT getRect() { return item_rc; }

	bool isGet();
};

