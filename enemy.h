#pragma once
#include"gameNode.h"

class player;
class enemy : public gameNode
{
private:
	image*	_enemy;
	RECT	enemy_rc;

	int		_currentFrameX;
	int		_currentFrameY;
	int		_count;

	float	x;						//x좌표
	float	y;						//y좌표
	float	speed;

	int		_fireCount;
	int		_rndfireCount;			//랜덤으로 총알 발싸


public:
	enemy();
	~enemy();

	HRESULT init();
	HRESULT init(const char* imageName, POINT position);

	void	release();
	void	update();
	void	render();

	virtual void animation();
	virtual void draw();

	bool	bulletCountFire();

	RECT	getRect() { return enemy_rc; }
	float	getX(){ return x; }
	float	getY() { return y; }
};


class minion : public enemy
{
	//나중에 요거 init 따로 생성하고
	//중간보스도 따로 init 하고
	//mainGame에서 #include"enemy.h" 해가지고
	// _enemy()->init() 해주는게 나을듯?아닌가?
};



