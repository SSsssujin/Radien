#include"framework.h"
#include"enemyManager.h"
#include"player.h"
#define UFOMAX 5


enemyManager::enemyManager()
{
}

enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
    this->setMinion();

    _eBullet = new e_Bullet;
    _eBullet->init("bullet", 3, 900);

    return S_OK;
}

void enemyManager::release()
{
    SAFE_DELETE(_eBullet);
}

void enemyManager::update()
{
    _viMinion = _vMinion.begin();

    for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
    {
        (*_viMinion)->update();
    }

    if (_player->getRocketImage()->getX())
    {
    }

    //�Ѿ�
    _eBullet->update();
    collision();
    this->minionBulletFire();
  
}

void enemyManager::render()
{
    _viMinion = _vMinion.begin();
    for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
    {
        (*_viMinion)->render();
    }

    _eBullet->render();
}

void enemyManager::setMinion()          //�̰Ÿ� setEnemy()�� �ٲٰ� setMinion, setBoss, �̷������� �ִ°� ��������
{
    enemy* ufo;

    for (int i = 0; i < UFOMAX; i++)     //i���� Ű��� UFO �� �þ ��
    {
        ufo = new minion;
        ufo->init("ufo", PointMake(RND->getFromIntTo(50, 950), RND->getFromIntTo(-2000, 0)));
        _vMinion.push_back(ufo);
    }
}


void enemyManager::minionBulletFire()
{
    _viMinion = _vMinion.begin();
    for (_viMinion; _viMinion != _vMinion.end(); ++_viMinion)
    {
        if ((*_viMinion)->bulletCountFire())
        {
            //player�� ������� ����ź
            RECT enemy_rc = (*_viMinion)->getRect();

            if (enemy_rc.bottom < 50 || enemy_rc.top > WINSIZEY - 50)continue;

           _eBullet->fire(enemy_rc.left + (enemy_rc.right - enemy_rc.left) / 2,            //x
               enemy_rc.bottom + (enemy_rc.top - enemy_rc.bottom) / 2,                     //y
               UTIL::getAngle                                                              //getAngle
               (enemy_rc.left + (enemy_rc.right - enemy_rc.left) / 2,
                   enemy_rc.bottom + (enemy_rc.top - enemy_rc.bottom) / 2,
                   _player->getRocketImage()->getX() + _player->getRocketImage()->getWidth() / 2,
                   _player->getRocketImage()->getY()),
                   1.2f);                                                                  //�ӵ�
        }
    }
}

void enemyManager::removeMinion(int arrNum)
{
    _vMinion.erase(_vMinion.begin() + arrNum);

    enemy* ufo;
    ufo = new minion;
    ufo->init("ufo", PointMake(RND->getFromIntTo(50, 950), RND->getFromIntTo(-500, 0)));
    _vMinion.push_back(ufo);

}


void enemyManager::collision()
{
    for (int i = 0; i < _eBullet->getVBullet().size(); i++)
    {
        RECT rc;

        if (IntersectRect(&rc, &_eBullet->getVBullet()[i].rc, &_player->getRocketImage()->getBoundingBox()))
        {
            _eBullet->removeEnemyBullet(i);
            //_player->hitDamage(10);
            _player->die();
        }
    }
}


