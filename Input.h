#pragma once
#include"singleton.h"
#include<bitset>

using namespace std;
#define KEYMAX 256


class Input : public Singleton<Input>
{
private:
	//bitset�� true, false�� ���� ���� �� �ִ�.
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;

public:
	Input();
	~Input();

	HRESULT init();

	void release();

	bool isOnceKeyDown(int key);		//�ѹ��� �����°�
	bool isOnceKeyUp(int key);			//�����ٰ� �ô°�
	bool isStayKeyDown(int key);		//������ �ִ°�
	bool isToggleKey(int key);			//���Ű�ΰ�
};
