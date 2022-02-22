#pragma once
#include"singleton.h"
#include<bitset>

using namespace std;
#define KEYMAX 256


class Input : public Singleton<Input>
{
private:
	//bitset은 true, false의 값을 가질 수 있다.
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;

public:
	Input();
	~Input();

	HRESULT init();

	void release();

	bool isOnceKeyDown(int key);		//한번만 눌렀는가
	bool isOnceKeyUp(int key);			//눌렀다가 뗐는가
	bool isStayKeyDown(int key);		//누르고 있는가
	bool isToggleKey(int key);			//토글키인가
};
