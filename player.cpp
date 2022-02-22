#include"framework.h"
#include"player.h"
#include"enemyManager.h"

player::player()
{
    _current_item = nullptr;
    currentItemType = 0;
}

player::~player()
{
}

HRESULT player::init()
{
    _player = IMAGE->addImage("rocket", "images/radien.bmp", WINSIZEX / 2, WINSIZEY - 200, 70, 70, true, RGB(255, 0, 255));
    IMAGE->addFrameImage("death", "images/deathExplosions.bmp", 800, 94, 12, 1, true, RGB(255,0,255));
    
    player_rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _player->getWidth(), _player->getHeight());

    _item1 = new image;
    _item1 = IMAGE->addImage("item1", "images/item1.bmp", 40, 35, true, RGB(255, 0, 255));
    _item1->setX(WINSIZEX * 2);
    _item1->setY(-100);

    _item2 = new image;
    _item2 = IMAGE->addImage("item2", "images/sigong2.bmp", 40, 40, true, RGB(255, 0, 255));
    _item2->setX(WINSIZEX * 2);
    _item2->setY(-100);

    pBullet = new p_Bullet;
    pBullet->init(30, 1000);

    pBullet2 = new p_Bullet2;
    pBullet2->init(30, 1000);

    pBullet3 = new p_Bullet3;
    pBullet3->init(30, 1000);

    pBullet4 = new p_Bullet4;
    pBullet4->init(30, 1000);

    pBullet5 = new p_Bullet5;
    pBullet5->init(30, 1000);

    isDie = false;
    isItemCollision = false;
    levelOfMissile1 = false;

    realBoss = new boss;
    realBoss->init();
    return S_OK;
}

void player::release()
{
    SAFE_DELETE(pBullet);
    SAFE_DELETE(pBullet2);
    SAFE_DELETE(pBullet3);
    SAFE_DELETE(pBullet4);
    SAFE_DELETE(pBullet5);
}

void player::update()
{
    if (InputManager->isStayKeyDown(VK_LEFT) && _player->getX() > 0)
    {
        _player->setX(_player->getX() - 0.9);
    }
    if (InputManager->isStayKeyDown(VK_RIGHT) && _player->getX() + _player->getWidth() < WINSIZEX - 10)
    {
        _player->setX(_player->getX() + 0.9);
    }
    if (InputManager->isStayKeyDown(VK_UP) && _player->getY() > 0)
    {
        _player->setY(_player->getY() - 0.9);
    }
    if (InputManager->isStayKeyDown(VK_DOWN) && _player->getY() + _player->getHeight() < WINSIZEY - 40)
    {
        _player->setY(_player->getY() + 0.7);
    }

    if (InputManager->isOnceKeyDown('Z'))
    {
        if (levelOfMissile1 > 3)  { levelOfMissile1 = 3; }

        //미사일 1
        switch (levelOfMissile1)
        {
        case 0:
            pBullet->fire(_player->getX() + _player->getWidth() / 2, _player->getY());
            break;

        case 1:
            pBullet->fire(_player->getX() - 17 + _player->getWidth() / 2, _player->getY());
            pBullet->fire(_player->getX() + 17 + _player->getWidth() / 2, _player->getY());  
            break;

        case 2:
            pBullet->fire(_player->getX() - 17 + _player->getWidth() / 2, _player->getY());
            pBullet->fire(_player->getX() + 17 + _player->getWidth() / 2, _player->getY());

            pBullet2->fire(_player->getX() - 25 + _player->getWidth() / 2, _player->getY());
            pBullet3->fire(_player->getX() + 25 + _player->getWidth() / 2, _player->getY());
            break;

        case 3:
            pBullet->fire(_player->getX() - 17 + _player->getWidth() / 2, _player->getY());
            pBullet->fire(_player->getX() + 17 + _player->getWidth() / 2, _player->getY());

            pBullet2->fire(_player->getX() - 25 + _player->getWidth() / 2, _player->getY());
            pBullet3->fire(_player->getX() + 25 + _player->getWidth() / 2, _player->getY());

            pBullet4->fire(_player->getX() - 30 + _player->getWidth() / 2, _player->getY());
            pBullet5->fire(_player->getX() + 30 + _player->getWidth() / 2, _player->getY());

        default:

            break;
        }

        //미사일2
        //스프라이트 구축하고 추가하자
        //switch (levelOfMissile2)
        //{
        ////case 0:
        ////    pCannon->fire(_player->getX() + _player->getWidth() / 2, _player->getY()); //원래 pBullet->fire
        ////    break;
        //case 1:
        //    pCannon->fire(_player->getX() - 25 + _player->getWidth() / 2, _player->getY()); //원래 pBullet->fire
        //    pCannon->fire(_player->getX() + 25 + _player->getWidth() / 2, _player->getY()); //원래 pBullet->fire
        //    break;
        //case 2:
        //    pCannon->fire(_player->getX() + _player->getWidth() / 2, _player->getY()); //원래 pBullet->fire
        //    pCannon->fire(_player->getX() - 50 + _player->getWidth() / 2, _player->getY()); //원래 pBullet->fire
        //    pCannon->fire(_player->getX() + 50 + _player->getWidth() / 2, _player->getY()); //원래 pBullet->fire
        //    break;
        //default:
        //    break;
        //}
    }


    if (InputManager->isOnceKeyDown('Q'))
    {
        int randNum = RND->getInt(2);
        switch (0)                                  //미사일 아이템 구현하면 바꾸자!
        {
        case 0:
            _current_item = _item1;
            currentItemType = 1;
            break;

        case 1:
            _current_item = _item2;
            currentItemType = 2;
            break;

        default:
            break;
        }
        _current_item->setX(WINSIZEX / 2);
        _current_item->setY(-100);
        isItemCollision = false;

    }

    pBullet->update();
    pBullet2->update();
    pBullet3->update();
    pBullet4->update();
    pBullet5->update();

    //아이템용 변수
    static bool isLeft      = true;
    float       itemSpeed   = RND->getFromIntTo(1,5) / 10.0f;

    if (_current_item)
    {
        if (!isItemCollision)
        {
            if (_current_item->getX() > 200 && isLeft == true)                                      //item의 X좌표가 300보다 클 때
            {
                _current_item->setX(_current_item->getX() - itemSpeed);                             //X좌표를 1씩 감소시키면서 왼쪽으로 이동

                if (_current_item->getX() <= 200)                                                   //item의 X좌표가 300보다 작을 때
                    isLeft = false;                                                                 //if조건이 상충되는 것을 막기 위해 지역변수 사용 (true일 때 이동)
            }                                                                                       //300보다 작을 때는 false값이니까 이동하지 않음

            else if (_current_item->getX() <= WINSIZEX - 200 && isLeft == false)
            {
                _current_item->setX(_current_item->getX() + itemSpeed);

                if (_current_item->getX() >= WINSIZEX - 200)
                    isLeft = true;
            }

            _current_item->setY(_current_item->getY() + itemSpeed);
            if (_current_item->getY() > WINSIZEY) {   }
        }
    }
    
    collision();
    realBoss->update();
}

void player::render()
{
    _player->render(getMemDC(), _player->getX(), _player->getY());
    pBullet->render();
    pBullet2->render();
    pBullet3->render();
    pBullet4->render();
    pBullet5->render();

    if (_current_item)
    {
        if (!isItemCollision)
            _current_item->render(getMemDC(), _current_item->getX(), _current_item->getY());      //좌표수정해야됨
    }
    
    
    
    TCHAR str[100];
    
    //item collision 확인용 
    //wsprintf(str, "isCollision : %d, isUpgrade : %d", isItemCollision, levelOfMissile1);
    //TextOut(getMemDC(), 100, 100, str, lstrlen(str));

    //boss hp 확인용
    //wsprintf(str, "BossHp : %d", realBoss->getBossHp());
    //TextOut(getMemDC(), 100, 400, str, lstrlen(str));

    //Rectangle(getMemDC(), boss_collision.left, boss_collision.top, boss_collision.right, boss_collision.bottom);
}

void player::removePlayerBullet(int arrNum)
{
    pBullet->removeNuclear(arrNum);
    pBullet2->removeNuclear(arrNum); 
    pBullet3->removeNuclear(arrNum); 
    pBullet4->removeNuclear(arrNum); 
    pBullet5->removeNuclear(arrNum); 
}

void player::collision()
{
    RECT playerRC = RectMakeCenter(_player->getX() + _player->getWidth() / 2,
        _player->getY() + _player->getHeight() / 2, _player->getWidth(), _player->getHeight());
    
    RECT itemRC;

    if (_current_item)
    {
        if (!isItemCollision)
        {
            itemRC = RectMakeCenter(_current_item->getX() + _current_item->getWidth() / 2,
                _current_item->getY() + _current_item->getHeight() / 2, _current_item->getWidth(), _current_item->getHeight());
        }
    
        RECT temp;
        if (IntersectRect(&temp, &playerRC, &itemRC))
        {
            isItemCollision = true;
            _current_item = nullptr;

            levelOfMissile1++;

            currentItemType = 0;
        }
 //       
 //  switch (currentItemType)
 //        {
 //        case 1:
 //            levelOfMissile1++;
 //            break;
 //          case 2:
 //              levelOfMissile2++;
 //            break;
 //        default:
 //            break;
 //        }
 //

    }

    //bullet 충돌 처리
    for (int i = 0; i < pBullet->getVBullet().size(); i++)
    {
        for (int j = 0; j < _enemyManager->getVMinion().size(); j++)
        {
            RECT rc;

            if (IntersectRect(&rc, &pBullet->getVBullet()[i].rc, &_enemyManager->getVMinion()[j]->getRect()))
            {
                pBullet->removeNuclear(i);
                _enemyManager->removeMinion(j);

                break; 
            }
        }
    }

    for (int i = 0; i < pBullet2->getVBullet().size(); i++)
    {
        for (int j = 0; j < _enemyManager->getVMinion().size(); j++)
        {
            RECT rc;

            if (IntersectRect(&rc, &pBullet2->getVBullet()[i].rc, &_enemyManager->getVMinion()[j]->getRect()))
            {
                pBullet2->removeNuclear(i);
                _enemyManager->removeMinion(j);

                break;
            }
        }
    }

    for (int i = 0; i < pBullet3->getVBullet().size(); i++)
    {
        for (int j = 0; j < _enemyManager->getVMinion().size(); j++)
        {
            RECT rc;

            if (IntersectRect(&rc, &pBullet3->getVBullet()[i].rc, &_enemyManager->getVMinion()[j]->getRect()))
            {
                pBullet3->removeNuclear(i);
                _enemyManager->removeMinion(j);

                break;
            }
        }
    }

    for (int i = 0; i < pBullet4->getVBullet().size(); i++)
    {
        for (int j = 0; j < _enemyManager->getVMinion().size(); j++)
        {
            RECT rc;

            if (IntersectRect(&rc, &pBullet4->getVBullet()[i].rc, &_enemyManager->getVMinion()[j]->getRect()))
            {
                pBullet4->removeNuclear(i);
                _enemyManager->removeMinion(j);

                break;
            }
        }
    }

    for (int i = 0; i < pBullet5->getVBullet().size(); i++)
    {
        for (int j = 0; j < _enemyManager->getVMinion().size(); j++)
        {
            RECT rc;

            if (IntersectRect(&rc, &pBullet5->getVBullet()[i].rc, &_enemyManager->getVMinion()[j]->getRect()))
            {
                pBullet5->removeNuclear(i);
                _enemyManager->removeMinion(j);

                break;
            }
        }
    }

    

    //보스 충돌처리

    for (int i = 0; i < pBullet->getVBullet().size(); i++)
    {
        RECT rc;
        
        RECT boss_RC = realBoss->getBossRC();
        RECT boss_collision = RectMake(boss_RC.left, boss_RC.top, boss_RC.right, boss_RC.bottom);
        
        if (IntersectRect(&rc, &pBullet->getVBullet()[i].rc, &boss_collision))
       // if (IntersectRect(&rc, &pBullet->getVBullet()[i].rc, &realBoss->getBossRC()))
        {
            pBullet->removeNuclear(i);
            realBoss->setBossHp(realBoss->getBossHp()-10);
            
            
            break;
        }
    }

    for (int i = 0; i < pBullet2->getVBullet().size(); i++)
    {
        RECT rc;

        RECT boss_RC = realBoss->getBossRC();
        RECT boss_collision = RectMake(boss_RC.left, boss_RC.top, boss_RC.right, boss_RC.bottom);

        if (IntersectRect(&rc, &pBullet2->getVBullet()[i].rc, &boss_collision))
        {
            pBullet2->removeNuclear(i);
            realBoss->setBossHp(realBoss->getBossHp() - 10);
            
            break;
        }
    }

    for (int i = 0; i < pBullet3->getVBullet().size(); i++)
    {
        RECT rc;

        RECT boss_RC = realBoss->getBossRC();
        RECT boss_collision = RectMake(boss_RC.left, boss_RC.top, boss_RC.right, boss_RC.bottom);

        if (IntersectRect(&rc, &pBullet3->getVBullet()[i].rc, &boss_collision))
        {
            pBullet3->removeNuclear(i);
            realBoss->setBossHp(realBoss->getBossHp() - 10);
           
            break;
        }
    }
   
    for (int i = 0; i < pBullet3->getVBullet().size(); i++)
    {
        RECT rc;

        RECT boss_RC = realBoss->getBossRC();
        RECT boss_collision = RectMake(boss_RC.left, boss_RC.top, boss_RC.right, boss_RC.bottom);

        if (IntersectRect(&rc, &pBullet3->getVBullet()[i].rc, &boss_collision))
        {
            pBullet3->removeNuclear(i);
            realBoss->setBossHp(realBoss->getBossHp() - 10);
          
            break;
        }
    }

    for (int i = 0; i < pBullet4->getVBullet().size(); i++)
    {
        RECT rc;

        RECT boss_RC = realBoss->getBossRC();
        RECT boss_collision = RectMake(boss_RC.left, boss_RC.top - 200, boss_RC.right, boss_RC.bottom - 250);

        if (IntersectRect(&rc, &pBullet4->getVBullet()[i].rc, &realBoss->getBossRC()))
        {
            pBullet4->removeNuclear(i);
            realBoss->setBossHp(realBoss->getBossHp() - 10);
          
            break;
        }
    }

    for (int i = 0; i < pBullet5->getVBullet().size(); i++)
    {
        RECT rc;

        RECT boss_RC = realBoss->getBossRC();
        RECT boss_collision = RectMake(boss_RC.left, boss_RC.top - 200, boss_RC.right, boss_RC.bottom - 250);

        if (IntersectRect(&rc, &pBullet5->getVBullet()[i].rc, &boss_collision))
        {
            pBullet5->removeNuclear(i);
            realBoss->setBossHp(realBoss->getBossHp() - 10);
           
            break;
        }
    }
}

void player::die()
{
    isDie = true;
    levelOfMissile1 = 0;
}


