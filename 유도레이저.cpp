
#include <math.h> 
#include <stdio.h> // �������� ���κ��� ��Ÿ���� ����ü 
typedef struct LASER_STRUCT
{
	float X, Y;							// ��ǥ 
	float VX, VY;						// �ӵ� 
	float OldX, OldY;					// ���� ��ǥ
	float Angle;						// ȸ�� ���� 
	float OldAngle;						// ���� ȸ�� ���� 
	struct LASER_STRUCT* Prec;			// �ϳ� �� �κ��� ����Ű�� ������ (���κκ��� ���� NULL) 
}

	LASER_TYPE;
	void MoveHoming(LASER_TYPE* laser);
	
	LASER_TYPE* NewLaserType(); // �������� �����̴� �Լ� 
	void MoveHomingLaser(LASER_TYPE* laser) // �������� ���� Ȥ�� �� �̿��� ��ü�� ���� �κ� 
	{ 
	// ���� �κ��� ���: 
	// ����ź�� �����Ӱ� ���� 
	// �����ϴ� ��ü���� ó���� MoveHoming�Լ����� �����ϱ�� ������ 
	if (laser->Prec == NULL) { MoveHoming(laser); } 

	// ���� �̿��� �κ��� ���: 
	// �ϳ� ���� �κ��� ���ư� 
	// ���� ��ǥ�� ���� ȸ�������� ������ 
	else 
	{ 
		laser->X = laser->Prec->OldX; 
		laser->Y = laser->Prec->OldY; 
		laser->Angle = laser->Prec->OldAngle; } 
	} 
	
	// �������� �߻� 
	void ShootHomingLaser( float x, float y, int length) // �߻������� ��ǥ ,����
	{ LASER_TYPE* laser; // �������� ��Ÿ���� ����ü�� ������ 
	LASER_TYPE* prec=NULL; // �ϳ� ���� �κ��� ����Ű�� ������ 
						   // �������� �� �κ��� �����: 
						   // �������� ����ü�� �����Ͽ� ��ǥ�� �ʱ�ȭ�ϱ� 
						   // ����ü�� �����ϴ� ��ü���� ó���� NewLaserType�Լ����� �����Ѵٰ� ������ 
	
	for (int i=0; i<length; i++, prec=laser)
	{ 
		laser=NewLaserType(); 
		laser->X=laser->OldX=x; 
		laser->Y=laser->OldY=y; 
		laser->Angle=laser->OldAngle=0; // ��ü�� ���� �κ��� �ϳ� �պκ��� �����ϵ��� ��
										// ���θ� �������� ���� NULL�� ��ȯ��
		laser->Prec=prec; 
	} 
	}