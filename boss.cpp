#include"framework.h"
#include"boss.h"
//#include"player.h"

HRESULT boss::init()
{
	IMAGE->addFrameImage("boss", "images/bosss.bmp", 666, 200, 2, 1, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("bossdeath", "images/bossdeath.bmp", 2000, 200, 10, 1, true, RGB(255, 0, 255));
	
	_boss._bossImage = new image;
	_boss._bossImage = IMAGE->findImage("boss");
//	_boss._explosion = new image;
//	_boss._explosion = IMAGE->findImage("bossdeath");

	_boss.x = WINSIZEX / 2;
	_boss.y = -500;
	//_boss.y = WINSIZEY / 2;
	_boss.width = _boss._bossImage->getFrameWidth();
	_boss.height = _boss._bossImage->getFrameHeight();
	_boss.speed = 0.3f;

	_boss._maxHp = _boss._currentHp = 1500;

	_boss.time = 0;
	_boss.angle = 270;
	_boss.angle2 = 270;
	_boss._index = 0;
	_boss._count = 0;

	_boss.isActive = false;
	_boss.isDie = false;
	_boss.isBlocked = false;
	respone = true;

	BOSSBULLET->init();

	return S_OK;
}

void boss::release()
{
	BOSSBULLET->release();
}

void boss::update()
{
	_boss.time++;
	_boss._rc = RectMake(_boss.x - _boss._bossImage->getFrameWidth() / 2, _boss.y - _boss._bossImage->getFrameHeight(), _boss._bossImage->getFrameWidth(), _boss._bossImage->getFrameHeight());
	
	if (_boss.time % 300 == 0)
	{
		create();
	}

	if (_boss.isActive && !_boss.isDie)
	{
		bossMove();
		bossFire();
	}

	if (_boss._currentHp <= 0)
	{
		_boss._currentHp = 0;
		_boss.isActive = false;
		_boss.isDie = true;
	}

	if (_boss.isDie)
	{
		bossDie();
	}

	BOSSBULLET->update();
}

void boss::render()
{
	if (!_boss.isDie)
	{
		if (_boss._currentHp > 500)
		{
			_boss._bossImage->frameRender(getMemDC(), _boss.x - _boss.width / 2, _boss.y - _boss.height / 2, 0, 0);
		}

		else if (_boss._currentHp > 200 && _boss._currentHp <= 500)
		{
			_boss._bossImage->frameRender(getMemDC(), _boss.x - _boss.width / 2, _boss.y - _boss.height / 2, 1, 0);
		}
	}

	if (_boss.isDie)
	{
		//_boss._explosion->frameRender(getMemDC(), _boss.x - _boss._bossImage->getFrameWidth() / 2, _boss.y - _boss._bossImage->getFrameHeight());
		//_boss._explosion->frameRender(getMemDC(), 100, 100);
	}

	//TCHAR str[100];
	//wsprintf(str, "_currentHp : %d",getBossHp() );
	//TextOut(getMemDC(), 200, 200, str, lstrlen(str));

	BOSSBULLET->render(getMemDC());

}

void boss::create()
{
	if (respone)
	{
		if (_boss.time % 8000 == 0)				//보스 등장 타이밍
		{
			if (!_boss.isActive)
			{
				_boss.isActive = true;
				respone = false;
			}
		}
	}
}

void boss::bossMove()
{
	if (_boss.y < 50)
	{
		_boss.y += 0.5;
	}
	else if (_boss.y >= 50 && _boss.y < 150)
	{
		_boss.y += 0.5;
		_boss.x -= 0.5;
	}
	else
	{
		_boss.x += _boss.speed;

		if (_boss.x < 150 && _boss.isBlocked) { _boss.isBlocked = false; }
		if (_boss.x > WINSIZEX - 150 && !_boss.isBlocked) { _boss.isBlocked = true; }

		if (_boss.isBlocked) { _boss.speed = -0.5f; }
		else { _boss.speed = 0.5f; }
	}
}

void boss::bossFire()
{
	if (_boss._currentHp > 0)
	{
		if (_boss.time > 8500 && _boss.time < 12000)
		{
			if (_boss.time % 100 == 0)
			{
				BOSSBULLET->fire(_boss.x, _boss.y, DEGREE((int)_boss.angle), PATTRN1);
				BOSSBULLET->fire(_boss.x, _boss.y, DEGREE((int)_boss.angle - 40), PATTRN1);
				BOSSBULLET->fire(_boss.x, _boss.y, DEGREE((int)_boss.angle + 40), PATTRN1);
			}
		}
		else if (_boss.time > 12500 && _boss.time < 15000)
		{

			if (_boss.time % 60 == 0)
			{
				BOSSBULLET->fire(_boss.x, _boss.y, DEGREE((int)_boss.angle + 120), PATTRN2);
				BOSSBULLET->fire(_boss.x, _boss.y, DEGREE((int)_boss.angle + 240), PATTRN2);
				BOSSBULLET->fire(_boss.x, _boss.y, DEGREE((int)_boss.angle), PATTRN2);
				_boss.angle -= 10.0f;
			}
		}
		else if (_boss.time > 20000)
		{
			_boss.time = 0;
			_boss.angle = 270;
		}
	}
}

void boss::hitDamage(int damage)
{
	_boss._currentHp -= damage;
}

void boss::bossDie()
{
	_boss._rc.left = 1000;
	_boss._rc.top -=1;
	_boss._rc.right = 1000;
	_boss._rc.bottom -=1;

	_boss._bossImage->frameRender(getMemDC(), 1000, 1000, 5, 0);
}



