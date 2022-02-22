#include"framework.h"
#include"Input.h"

Input::Input()
{
}

Input::~Input()
{
}

HRESULT Input::init()
{
	//키가 전부 눌려있지 않은 상태로 초기화
	for (int i = 0; i < KEYMAX; i++)
	{
		_keyUp.set(i, false);
		_keyDown.set(i, false);
	}
	return S_OK;
}

void Input::release()
{
}

bool Input::isOnceKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!_keyDown[key])
		{
			_keyDown.set(key, true);
			return true;
		}
	}
	else
	{
		_keyDown.set(key, false);
	}
	return false;
}

bool Input::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		_keyUp.set(key, true);
	}

	else
	{
		if (_keyUp[key])
		{
			_keyUp.set(key, false);
			return true;
		}
	}
	return false;
}

bool Input::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000) { return true; }
	return false;
}

bool Input::isToggleKey(int key)
{
	if (GetKeyState(key) & 0x0001) { return true; }
	return false;
}
