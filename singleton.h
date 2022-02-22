#pragma once

template <typename T>
class Singleton
{
protected:
	//�̱��� �ν��Ͻ� �����ϱ�
	static T* singleton;

	Singleton() {};
	~Singleton() {};

public:
	static T* getSingleton();
	void		releaseSingleton();

};



//�̱��� �ν��Ͻ� ����
//null������ �ʱ�ȭ
template <typename T>
T* Singleton<T>::singleton = nullptr;



//�̱��� ��ü�� ��������
template<typename T>
T* Singleton<T>::getSingleton()
{
	//�̱��� ��ü�� ������ ���� �����.
	if (!singleton)singleton = new T;
	return singleton;
}

template<typename T>
void Singleton<T>::releaseSingleton()
{
	//�̱��� ������ ����
	if (singleton)
	{
		delete singleton;
		singleton = nullptr;
	}
}
