#pragma once
#include"gameNode.h"
#include"player.h"
#include"boss.h"
#include"enemyManager.h"

class mainGame : public gameNode
{
private:
	image*			_bgImage;
	player*			_player;
	boss*			_boss;		
	enemyManager*	_enemyManager;

	//루프용 변수
	int			m_loopX;
	int			m_loopY;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

