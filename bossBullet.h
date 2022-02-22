#pragma once
#include"singleton.h"
#include"image.h"
//#include"player.h"
#define MAXBULLET_BOSS 300

enum PATTRN
{
	PATTRN1,
	PATTRN2,
};

struct tagBossBullet
{
	image*	img;
	RECT	_rc;

	float	x, y;
	float	angle;
	float	radius;
	float	speed;
	int		width;
	int		height;
	int		_count;
	int		_index;
	
	bool	isFire;

	PATTRN	pt;
};

class bossBullet : public Singleton<bossBullet>
{
private:
	//player* _player;

public:
	bossBullet() {}
	~bossBullet() {}

	HRESULT init();

	void	release();
	void	update();
	void	render(HDC hdc);

	void	fire(float p_x, float p_y, float angle, PATTRN pt);
	void	bulletMove();
	void	bulletOut();
	bool	collision(RECT p_rc);

protected:
	PATTERN _pt;
	vector<tagBossBullet> v_BossBullet;
	vector<tagBossBullet> v_BossBullet2;
};
