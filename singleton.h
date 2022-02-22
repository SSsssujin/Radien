#pragma once

template <typename T>
class Singleton
{
protected:
	//싱글톤 인스턴스 선언하기
	static T* singleton;

	Singleton() {};
	~Singleton() {};

public:
	static T* getSingleton();
	void		releaseSingleton();

};



//싱글톤 인스턴스 선언
//null값으로 초기화
template <typename T>
T* Singleton<T>::singleton = nullptr;



//싱글톤 객체를 가져오자
template<typename T>
T* Singleton<T>::getSingleton()
{
	//싱글톤 객체가 없으면 새로 만든다.
	if (!singleton)singleton = new T;
	return singleton;
}

template<typename T>
void Singleton<T>::releaseSingleton()
{
	//싱글톤 있으면 해제
	if (singleton)
	{
		delete singleton;
		singleton = nullptr;
	}
}
