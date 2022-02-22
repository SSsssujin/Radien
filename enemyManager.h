#pragma once
#include"gameNode.h"
#include"bullet.h"
#include"enemy.h"

class enemyManager : public gameNode
{

private:
	typedef vector<enemy*> vEnemy;
	typedef vector<enemy*>::iterator viEnemy;

	player*		_player;
	enemy*		_enemy;
	RECT		_minionRC;


private:
	vEnemy		_vMinion;
	viEnemy		_viMinion;
	e_Bullet*	_eBullet;


public:

	enemyManager();
	~enemyManager();

	HRESULT init();
	void	release();
	void	update();
	void	render();

	void	setMinion();
	void	minionBulletFire();

	vEnemy	getVMinion()	{ return _vMinion; }
	viEnemy	getViMinion()	{ return _viMinion; }

	void	removeMinion(int arrNum);
	void	collision();
	void	setRocketMemoryLink(player* player) { _player = player; }

};
