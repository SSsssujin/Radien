
#include <math.h> 
#include <stdio.h> // 레이저의 각부분을 나타내는 구조체 
typedef struct LASER_STRUCT
{
	float X, Y;							// 좌표 
	float VX, VY;						// 속도 
	float OldX, OldY;					// 이전 좌표
	float Angle;						// 회전 각도 
	float OldAngle;						// 이전 회전 각도 
	struct LASER_STRUCT* Prec;			// 하나 앞 부분을 가리키는 포인터 (선두부분일 경우는 NULL) 
}

	LASER_TYPE;
	void MoveHoming(LASER_TYPE* laser);
	
	LASER_TYPE* NewLaserType(); // 레이저를 움직이는 함수 
	void MoveHomingLaser(LASER_TYPE* laser) // 레이저의 선두 혹은 그 이외의 몸체나 꼬리 부분 
	{ 
	// 선두 부분의 경우: 
	// 유도탄의 움직임과 같음 
	// 유도하는 구체적인 처리는 MoveHoming함수에서 수행하기로 가정함 
	if (laser->Prec == NULL) { MoveHoming(laser); } 

	// 선두 이외의 부분일 경우: 
	// 하나 앞의 부분을 좇아감 
	// 이전 좌표와 이전 회전각도를 복사함 
	else 
	{ 
		laser->X = laser->Prec->OldX; 
		laser->Y = laser->Prec->OldY; 
		laser->Angle = laser->Prec->OldAngle; } 
	} 
	
	// 레이저의 발사 
	void ShootHomingLaser( float x, float y, int length) // 발사지점의 좌표 ,길이
	{ LASER_TYPE* laser; // 레이저를 나타내는 구조체의 포인터 
	LASER_TYPE* prec=NULL; // 하나 앞의 부분을 가리키는 포인터 
						   // 레이저의 각 부분을 만들기: 
						   // 레이저의 구조체를 생성하여 좌표를 초기화하기 
						   // 구조체를 생성하는 구체적인 처리는 NewLaserType함수에서 수행한다고 가정함 
	
	for (int i=0; i<length; i++, prec=laser)
	{ 
		laser=NewLaserType(); 
		laser->X=laser->OldX=x; 
		laser->Y=laser->OldY=y; 
		laser->Angle=laser->OldAngle=0; // 몸체나 꼬리 부분은 하나 앞부분을 참조하도록 함
										// 선두를 참조했을 때는 NULL이 반환됨
		laser->Prec=prec; 
	} 
	}