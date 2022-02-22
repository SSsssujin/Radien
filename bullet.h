#pragma once
#include"gameNode.h"

struct tagBullet
{
	image*	bulletImage;
	RECT	rc;
	float	x, y;					//¡Ú
	float	fireX, fireY;
	float	radius;					//¡Ú
	float	angle;					//¡Ú
	float	speed;					//¡Ú
	bool	fire;					//¡Ú
	int		count;
};

//player ºÒ¸´
class p_Bullet : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	int			_missileMax;
	float		_range;

public:
	p_Bullet();
	~p_Bullet();

	HRESULT	init(int bulletMax, float range);
	virtual void	release();
	void	update();
	void	render();
	
	void	fire(float x, float y);
	void	move();

	void	removeNuclear(int arrNum);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};


class p_Bullet2 : public gameNode
{
	private:
		vector<tagBullet> _vBullet;
		vector<tagBullet>::iterator _viBullet;

		int			_missileMax;
		float		_range;

	public:
		p_Bullet2();
		~p_Bullet2();

		HRESULT	init(int bulletMax, float range);
		virtual void release();
		void	update();
		void	render();

		void	fire(float x, float y);
		void	move();

		void	removeNuclear(int arrNum);

		vector<tagBullet> getVBullet() { return _vBullet; }
		vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};


class p_Bullet3 : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	int			_missileMax;
	float		_range;

public:
	p_Bullet3();
	~p_Bullet3();

	HRESULT	init(int bulletMax, float range);
	virtual void release();
	void	update();
	void	render();

	void	fire(float x, float y);
	void	move();

	void	removeNuclear(int arrNum);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};


class p_Bullet4 : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	int			_missileMax;
	float		_range;

public:
	p_Bullet4();
	~p_Bullet4();

	HRESULT	init(int bulletMax, float range);
	virtual void release();
	void	update();
	void	render();

	void	fire(float x, float y);
	void	move();

	void	removeNuclear(int arrNum);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};



class p_Bullet5 : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	int			_missileMax;
	float		_range;

public:
	p_Bullet5();
	~p_Bullet5();

	HRESULT	init(int bulletMax, float range);
	virtual void release();
	void	update();
	void	render();

	void	fire(float x, float y);
	void	move();

	void	removeNuclear(int arrNum);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};



//enemy ºÒ¸´
class e_Bullet : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char*		_imageName;
	float			_range;
	int				_bulletMax;


public:
	e_Bullet();
	~e_Bullet();

	HRESULT init(const char* imageName, int bulletMax, float range);
	void	release();
	void	update();
	void	render();

	void	fire(float x, float y, float angle, float speed);
	void	move();
	void	removeEnemyBullet(int arrNum);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};

