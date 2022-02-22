#pragma once
#include"gameNode.h"
#include"bullet.h"
#include"boss.h"

class enemyManager;
class player : public gameNode
{
private:
	image*			_player;
	RECT			player_rc;

	image*			_current_item;
	image*			_item1;
	image*			_item2;

	p_Bullet*		pBullet;
	p_Bullet2*		pBullet2; 
	p_Bullet3*		pBullet3; 
	p_Bullet4*		pBullet4; 
	p_Bullet5*		pBullet5;

	boss*			realBoss;
	enemyManager*	_enemyManager;

	bool			isItemCollision;
	bool			isGetItem;
	bool			isDie;
	
	int				currentItemType;
	int				levelOfMissile1;
//	int				levelOfMissile2;


public:
	player();
	~player();

	HRESULT		init();
	void		release();
	void		update();
	void		render();

	void		removePlayerBullet(int arrNum);
	void		collision();
	void		die();						//실험용 coll

	p_Bullet*	getBullet()			{ return pBullet; }
	p_Bullet2*	getCannon()			{ return pBullet2; }		//실험용캐논
	image*		getRocketImage()	{ return _player; }

	void		setEnemyMemoryLink(enemyManager* em) { _enemyManager = em; }
	RECT		getRect() { return player_rc; }

	int			getBossHP() { return realBoss->getBossHp(); }
};
