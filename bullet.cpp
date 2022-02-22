#include"framework.h"
#include"bullet.h"

//┌──────────────────────────┐
//		 player bullet
//└──────────────────────────┘

p_Bullet::p_Bullet()
{
}

p_Bullet::~p_Bullet()
{
}

HRESULT p_Bullet::init(int bulletMax, float range)
{
	_missileMax = bulletMax;
	_range		= range;

	return S_OK;
}

void p_Bullet::release()
{
}

void p_Bullet::update()
{
	move();
}

void p_Bullet::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->rc.left, _viBullet->rc.top,
			_viBullet->bulletImage->getFrameX(), 0);

		_viBullet->count++;

		if (_viBullet->count % 10 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);


			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}
			_viBullet->count = 0;
		}
	}
}

void p_Bullet::fire(float x, float y)
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = new image;
	bullet.bulletImage->init("images/p_bullet2.bmp", 0, 0, 45, 30, 1, 1, true, RGB(255, 0, 255));
	bullet.speed = 3.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
	bullet.bulletImage->getFrameWidth(),
	bullet.bulletImage->getFrameHeight());
	_vBullet.push_back(bullet);
}

void p_Bullet::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(), _viBullet->bulletImage->getFrameHeight());

		if (_range < UTIL::getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
		{
			SAFE_DELETE(_viBullet->bulletImage);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}


void p_Bullet::removeNuclear(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}



//┌──────────────────────────┐
//	   player bullet 강화+
//└──────────────────────────┘

p_Bullet2::p_Bullet2()
{
}

p_Bullet2::~p_Bullet2()
{
}

HRESULT p_Bullet2::init(int bulletMax, float range)
{
	_missileMax = bulletMax;
	_range = range;

	return S_OK;
}

void p_Bullet2::release()
{
}

void p_Bullet2::update()
{
	move();
}

void p_Bullet2::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->rc.left, _viBullet->rc.top,
			_viBullet->bulletImage->getFrameX(), 0);

		_viBullet->count++;

		if (_viBullet->count % 10 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);


			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}
			_viBullet->count = 0;
		}
	}
}

void p_Bullet2::fire(float x, float y)
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = new image;
	bullet.bulletImage->init("images/p_bullet2.bmp", 0, 0, 45, 30, 1, 1, true, RGB(255, 0, 255));
	bullet.speed = 3.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());
	_vBullet.push_back(bullet);
}

void p_Bullet2::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x -= 2;
		_viBullet->y -= _viBullet->speed;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(), _viBullet->bulletImage->getFrameHeight());

		if (_range < UTIL::getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
		{
			SAFE_DELETE(_viBullet->bulletImage);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void p_Bullet2::removeNuclear(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}



//┌──────────────────────────┐
//	  player bullet 강화++
//└──────────────────────────┘

p_Bullet3::p_Bullet3()
{
}

p_Bullet3::~p_Bullet3()
{
}

HRESULT p_Bullet3::init(int bulletMax, float range)
{
	_missileMax = bulletMax;
	_range = range;

	return S_OK;
}

void p_Bullet3::release()
{
}

void p_Bullet3::update()
{
	move();
}

void p_Bullet3::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->rc.left, _viBullet->rc.top,
			_viBullet->bulletImage->getFrameX(), 0);

		_viBullet->count++;

		if (_viBullet->count % 10 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);


			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}
			_viBullet->count = 0;
		}
	}
}

void p_Bullet3::fire(float x, float y)
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = new image;
	bullet.bulletImage->init("images/p_bullet2.bmp", 0, 0, 45, 30, 1, 1, true, RGB(255, 0, 255));
	bullet.speed = 3.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());
	_vBullet.push_back(bullet);
}

void p_Bullet3::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x += 2;
		_viBullet->y -= _viBullet->speed;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(), _viBullet->bulletImage->getFrameHeight());

		if (_range < UTIL::getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
		{
			SAFE_DELETE(_viBullet->bulletImage);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void p_Bullet3::removeNuclear(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}



//┌──────────────────────────┐
//	  player bullet 강화+++
//└──────────────────────────┘

p_Bullet4::p_Bullet4()
{
}

p_Bullet4::~p_Bullet4()
{
}

HRESULT p_Bullet4::init(int bulletMax, float range)
{
	_missileMax = bulletMax;
	_range = range;

	return S_OK;
}

void p_Bullet4::release()
{
}

void p_Bullet4::update()
{
	move();
}

void p_Bullet4::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->rc.left, _viBullet->rc.top,
			_viBullet->bulletImage->getFrameX(), 0);

		_viBullet->count++;

		if (_viBullet->count % 10 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);


			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}
			_viBullet->count = 0;
		}
	}
}

void p_Bullet4::fire(float x, float y)
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = new image;
	bullet.bulletImage->init("images/p_bullet2.bmp", 0, 0, 45, 30, 1, 1, true, RGB(255, 0, 255));
	bullet.speed = 3.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());
	_vBullet.push_back(bullet);
}

void p_Bullet4::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x -= 4;
		_viBullet->y -= _viBullet->speed;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(), _viBullet->bulletImage->getFrameHeight());

		if (_range < UTIL::getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
		{
			SAFE_DELETE(_viBullet->bulletImage);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void p_Bullet4::removeNuclear(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}


//┌──────────────────────────┐
//	  player bullet 강화+++
//└──────────────────────────┘

p_Bullet5::p_Bullet5()
{
}

p_Bullet5::~p_Bullet5()
{
}

HRESULT p_Bullet5::init(int bulletMax, float range)
{
	_missileMax = bulletMax;
	_range = range;

	return S_OK;
}

void p_Bullet5::release()
{
}

void p_Bullet5::update()
{
	move();
}

void p_Bullet5::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->rc.left, _viBullet->rc.top,
			_viBullet->bulletImage->getFrameX(), 0);

		_viBullet->count++;

		if (_viBullet->count % 10 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);


			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}
			_viBullet->count = 0;
		}
	}
}

void p_Bullet5::fire(float x, float y)
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = new image;
	bullet.bulletImage->init("images/p_bullet2.bmp", 0, 0, 55, 30, 1, 1, true, RGB(255, 0, 255));
	bullet.speed = 3.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());
	_vBullet.push_back(bullet);
}

void p_Bullet5::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x += 4;
		_viBullet->y -= _viBullet->speed;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(), _viBullet->bulletImage->getFrameHeight());

		if (_range < UTIL::getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
		{
			SAFE_DELETE(_viBullet->bulletImage);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void p_Bullet5::removeNuclear(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}


//┌──────────────────────────┐
//		  enemy bullet
//└──────────────────────────┘

e_Bullet::e_Bullet()
{
}

e_Bullet::~e_Bullet()
{
}

HRESULT e_Bullet::init(const char* imageName, int bulletMax, float range)
{
	_imageName	= imageName;
	_bulletMax	= bulletMax;
	_range		= range;
	
	return S_OK;
}

void e_Bullet::release()
{
}

void e_Bullet::update()
{
	move();

}

void e_Bullet::render()
{
	_viBullet = _vBullet.begin();
	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->render(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);
	}
}

void e_Bullet::fire(float x, float y, float angle, float speed)
{
	tagBullet bullet;

	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage	= new image;
	bullet.bulletImage	= IMAGE->findImage(_imageName);
	bullet.angle		= angle;
	bullet.speed		= speed;
	bullet.x			= bullet.fireX = x;
	bullet.y			= bullet.fireY = y;
	bullet.rc			= RectMakeCenter(bullet.x, bullet.y,
								bullet.bulletImage->getWidth(),
								bullet.bulletImage->getHeight());

	_vBullet.push_back(bullet);
}

void e_Bullet::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed;
		_viBullet->y -= sinf(_viBullet->angle) * _viBullet->speed;


		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());

		if (_range < UTIL::getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void e_Bullet::removeEnemyBullet(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}

