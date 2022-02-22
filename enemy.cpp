#include"framework.h"
#include"enemy.h"
#include"player.h"

enemy::enemy()
{
}

enemy::~enemy()
{
}

HRESULT enemy::init()
{
    return S_OK;
}

HRESULT enemy::init(const char* imageName, POINT position)
{
    _count = 0;
    _currentFrameX = 0;
    _currentFrameY = 0;

    _fireCount = 0;
    _rndfireCount = RND->getFromIntTo(1, 5);

    x = position.x;
    y = position.y;
    speed = RND->getFromIntTo(3, 5) / 5.0f;

    _enemy = IMAGE->findImage(imageName);

    return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
    animation();

    enemy_rc = RectMakeCenter(x, y, _enemy->getFrameWidth(), _enemy->getFrameHeight());
    
    if (enemy_rc.bottom > WINSIZEY) { y = 0; }
    else { y += speed; }
}

void enemy::render()
{
    draw();
}

void enemy::draw()
{
   _enemy->frameRender(getMemDC(), enemy_rc.left, enemy_rc.top, _currentFrameX, _currentFrameY);

}

void enemy::animation()
{
    _count++;
    if (_count % 10 == 0)
    {
        _enemy->setFrameX(_enemy->getFrameX() + 1);
        _currentFrameX++;

        if (_currentFrameX >= _enemy->getMaxFrameX())
        {
            _currentFrameX = 0;
        }
    }
}

bool enemy::bulletCountFire()
{
    _fireCount++;
    if (_fireCount % _rndfireCount == 0)
    {
        _rndfireCount = RND->getFromIntTo(900, 2000);           //ÃÑ¾Ëºóµµ
        _fireCount = 0;
        return true;
    }
    return false;
}
