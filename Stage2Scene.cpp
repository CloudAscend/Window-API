#include "framework.h"
#include "Stage2Scene.h"

Stage2Scene::Stage2Scene()
{

}

Stage2Scene::~Stage2Scene()
{

}

void Stage2Scene::Init()
{
	Super::Init();
}

void Stage2Scene::Update()
{
	Super::Update();

	float countTime = GET_SINGLETON(TimeManager)->GetTime();

	/*
	if (countTime >= 360.f) //오류 (1번만 작동됨)
		PosX -= 360.f;

	PosX = countTime;
	PosY = 250 * sin(PosX * PI / 180);*/

	PosX = cos(countTime * PI/180);
	PosY = sin(countTime * PI/180);

	curTime = countTime;
	//(0, 250) DOWNER
	//(0, -250) UPPER
	//(250, 0) DYNAMIC
	//(-250, 0) STATIC

	//Utils::DrawCircle(hdc, Pos())
}

void Stage2Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	Utils::DrawCircle(hdc, Pos(550.f, 300.f), 250);
	Utils::DrawCircle(hdc, Pos(550.f, 300.f), 50);

	float cosPos = cos(curTime * PI / 180);
	float sinPos = sin(curTime * PI / 180);

	Utils::DrawCircle(hdc, Pos(cosPos * 250 + 550, sinPos * 250 + 300), 30);
	Utils::DrawCircle(hdc, Pos(cosPos * 250 + 550, sinPos * 250 + 300), 10);

	float cosPos2 = -cos(curTime * 2 * PI / 180);
	float sinPos2 = -sin(curTime * 2 * PI / 180);

	Pos party = Pos(cosPos2 * 30 + (cosPos * 250 + 550), sinPos2 * 30 + (sinPos * 250 + 300));

	Utils::DrawCircle(hdc, party, 5);

	for (int i = 0; i < 720; i++) {
		Utils::DrawPixel(hdc, party, RGB(255, 0, 0));
	}

	/*
	Utils::DrawCircle(hdc, Pos(300.f, 300.f), 250);
	Utils::DrawLine(hdc, Pos(550, 50), Pos(550, 600));
	Utils::DrawLine(hdc, Pos(550, 300), Pos(1500, 300));

	int16 theta;
	float radian;
	float x, y;
	float oldx = 0, oldy = 0;

	for (int i = 0; i < 360; i++)
	{
		radian = i * PI / 180;
		y = 250 * sin(radian); //호도법만 적용 가능
		//x = i * 360 / 500;
		x = i;
		Utils::DrawPixel(hdc, Pos(x + 550, -y + 300), RGB(255, 0, 0));
		Utils::DrawLine(hdc, Pos(oldx + 550, -oldy + 300), Pos(x + 550, -y + 300));
		oldx = x;
		oldy = y;
	}

	Utils::DrawCircle(hdc, Pos(PosX + 550, -PosY + 300), 10);
	Utils::DrawCircle(hdc, Pos(-cos(PosX * PI / 180) + 550, -PosY + 300), 10);
	Utils::DrawCircle(hdc, Pos(-(PosX * cos(PosX * PI / 180)) + 550, -PosY + 300), 10);
	*/
} //qp QP