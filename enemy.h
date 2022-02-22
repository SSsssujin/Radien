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

	float	x;						//x��ǥ
	float	y;						//y��ǥ
	float	speed;

	int		_fireCount;
	int		_rndfireCount;			//�������� �Ѿ� �߽�


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
	//���߿� ��� init ���� �����ϰ�
	//�߰������� ���� init �ϰ�
	//mainGame���� #include"enemy.h" �ذ�����
	// _enemy()->init() ���ִ°� ������?�ƴѰ�?
};



