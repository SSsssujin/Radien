#pragma once
#include"gameNode.h"
#define PI 3.141592
#define DEGREE(p) (PI/180*(p))

struct tagBoss
{
	image*	_bossImage;
//	image*	_explosion;
	RECT	_rc;

	float	width;
	float	height;
	float	x;
	float	y;
	float	speed;

	int		_maxHp;
	int		_currentHp;

	int		time;
	float	angle;
	float	angle2;
	int		_count;
	int		_index;

	bool	isActive;
	bool	isDie;
	bool	isBlocked;

};

class boss : public gameNode
{
private:
	
	tagBoss _boss;
	bool	respone;


public:
	boss() {}
	~boss() {}

	HRESULT init();
	void	release();
	void	update();
	void	render();

	void	create();
	void	bossMove();
	void	bossFire();

	void	hitDamage(int damage);
	void	bossDie();

	RECT	getBossRC() { return _boss._rc; }

	void	setBossHp(int n) { _boss._currentHp = n; }
	int		getBossHp()const { return _boss._currentHp; }
};



