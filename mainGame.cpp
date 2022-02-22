#include"framework.h"
#include"mainGame.h"

mainGame::mainGame()
{
}

mainGame::~mainGame()
{
}

HRESULT mainGame::init()
{
	gameNode::init(true);

	_bgImage = IMAGE->addImage("배경화면", "images/stage1_small.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGE->addImage("bullet", "images/enemy_bullet.bmp", 15, 15, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("ufo", "images/ufo.bmp", 530, 32, 10, 1, true, RGB(255, 0, 255));

	_player	= new player;
	_player->init();

	_boss = new boss;
	_boss->init();

	_enemyManager = new enemyManager;
	_enemyManager->init();

	_player->setEnemyMemoryLink(_enemyManager);
	_enemyManager->setRocketMemoryLink(_player);

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();

	SAFE_DELETE(_player);
	SAFE_DELETE(_enemyManager);
	SAFE_DELETE(_boss);	
}

void mainGame::update()
{
	gameNode::update();

	_player->update();
	_enemyManager->update();

	_boss->setBossHp(_player->getBossHP());
	_boss->update();	

	m_loopY--;
}

void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============================================

	IMAGE->render("배경화면", getMemDC());
	_bgImage->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), m_loopX, m_loopY / 5);
	_player->render();
	_enemyManager->render();
	_boss->render();

	//==============================================
	//백버퍼의 내용을 HDC그린다.(건드리지 말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
