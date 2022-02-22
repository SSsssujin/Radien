#include"framework.h"
#include"bossBullet.h"

HRESULT bossBullet::init()
{
	IMAGE->addFrameImage("bullet1", "images/bossbullet1.bmp", 20, 20, 1, 1, true, RGB(255,0,255));
	IMAGE->addFrameImage("bullet2", "images/bossbullet2.bmp", 18, 16, 1, 1, true, RGB(255,0,255));

	for (int i = 0; i < MAXBULLET_BOSS; i++)
	{
		tagBossBullet bul;
		ZeroMemory(&bul, sizeof(tagBossBullet));
		bul.img = new image;
		bul.img = IMAGE->findImage("bullet1");
		bul.speed = 1.0f;
		bul.isFire = false;
		bul._count = 0;
		bul._index = 0;
		bul.width = bul.img->getFrameWidth();
		bul.height = bul.img->getFrameHeight();
		v_BossBullet.push_back(bul);
	}
	for (int i = 0; i < MAXBULLET_BOSS; i++)
	{
		tagBossBullet bul;
		ZeroMemory(&bul, sizeof(tagBossBullet));
		bul.img = IMAGE->findImage("bullet2");
		bul.speed = 1.0f;
		bul.isFire = false;
		bul._count = 0;
		bul._index = 0;
		bul.width = bul.img->getFrameWidth();
		bul.height = bul.img->getFrameHeight();
		v_BossBullet2.push_back(bul);
	}

	return S_OK;
}

void bossBullet::release()
{
}

void bossBullet::update()
{
	bulletMove();
	bulletOut();
}


void bossBullet::render(HDC hdc)
{
	for (int i = 0; i < v_BossBullet.size(); i++)
	{
		if (!v_BossBullet[i].isFire) continue;
		v_BossBullet[i].img->frameRender(hdc, v_BossBullet[i].x, v_BossBullet[i].y);
	}

	for (int i = 0; i < v_BossBullet2.size(); i++)
	{
		if (!v_BossBullet2[i].isFire) continue;
		v_BossBullet2[i].img->frameRender(hdc, v_BossBullet2[i].x, v_BossBullet2[i].y);
	}
}


void bossBullet::fire(float p_x, float p_y, float angle, PATTRN pt)
{
	switch (pt)
	{
	case PATTRN1:
		for (int i = 0; i < v_BossBullet.size(); i++)
		{
			if (v_BossBullet[i].isFire) continue;

			v_BossBullet[i].x = p_x;
			v_BossBullet[i].y = p_y;
			v_BossBullet[i].angle = angle;
			v_BossBullet[i].isFire = true;
			break;

		}
		break;

	case PATTRN2:
		for (int i = 0; i < v_BossBullet2.size(); i++)
		{
			if (v_BossBullet2[i].isFire) continue;
			v_BossBullet2[i].x = p_x;
			v_BossBullet2[i].y = p_y;
			v_BossBullet2[i].angle = angle;
			v_BossBullet2[i].isFire = true;
			break;
		}
		break;

	default:
		break;
	}

}


void bossBullet::bulletMove()
{
	//pattern 1
	for (int i = 0; i < v_BossBullet.size(); i++)
	{
		if (!v_BossBullet[i].isFire) continue;

		v_BossBullet[i].x += cosf(v_BossBullet[i].angle) * v_BossBullet[i].speed;
		v_BossBullet[i].y += -sinf(v_BossBullet[i].angle) * v_BossBullet[i].speed;
		v_BossBullet[i]._rc = RectMakeCenter(v_BossBullet[i].x + v_BossBullet[i].width / 2, v_BossBullet[i].y + v_BossBullet[i].height / 2, v_BossBullet[i].width / 2, v_BossBullet[i].height / 2);
	}

	//pattern 2
	for (int i = 0; i < v_BossBullet2.size(); i++)
	{
		if (!v_BossBullet2[i].isFire) continue;

		v_BossBullet2[i].x += cosf(v_BossBullet2[i].angle) * v_BossBullet2[i].speed;
		v_BossBullet2[i].y += -sinf(v_BossBullet2[i].angle) * v_BossBullet2[i].speed;
		v_BossBullet2[i]._rc = RectMakeCenter(v_BossBullet2[i].x + v_BossBullet2[i].width / 2, v_BossBullet2[i].y + v_BossBullet2[i].height / 2, v_BossBullet2[i].width / 2, v_BossBullet2[i].height / 2);
	}

}


//boss bullet이 window 창밖을 벗어나면 false 처리
void bossBullet::bulletOut()
{
	for (int i = 0; i < v_BossBullet.size(); i++)
	{
		if (v_BossBullet[i].x > WINSIZEX || v_BossBullet[i].x < 0 ||
			v_BossBullet[i].y > WINSIZEY || v_BossBullet[i].y < 0) {
			v_BossBullet[i].isFire = false;
			v_BossBullet[i]._count = 0;
			v_BossBullet[i]._index = 0;
		}
	}
	for (int i = 0; i < v_BossBullet2.size(); i++)
	{
		if (v_BossBullet2[i].x > WINSIZEX || v_BossBullet2[i].x < 0 ||
			v_BossBullet2[i].y > WINSIZEY || v_BossBullet2[i].y < 0) {
			v_BossBullet2[i].isFire = false;
			v_BossBullet2[i]._count = 0;
			v_BossBullet2[i]._index = 0;
		}
	}

}


bool bossBullet::collision(RECT p_rc)
{
	RECT tmp;
	for (int i = 0; i < v_BossBullet.size(); i++)
	{
		if (!v_BossBullet[i].isFire) continue;
		if (IntersectRect(&tmp, &v_BossBullet[i]._rc, &p_rc))
		{
			v_BossBullet[i].isFire = false;
			return true;
		}
	}
	for (int i = 0; i < v_BossBullet2.size(); i++)
	{
		if (!v_BossBullet2[i].isFire) continue;
		if (IntersectRect(&tmp, &v_BossBullet2[i]._rc, &p_rc))
		{
			v_BossBullet2[i].isFire = false;
			return true;
		}
	}

	return false;
}