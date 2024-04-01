#include "framework.h"
#include "Stage1Scene.h"

Stage1Scene::Stage1Scene()
{

}

Stage1Scene::~Stage1Scene()
{

}

void Stage1Scene::Init()
{
	Super::Init();
}

void Stage1Scene::Update()
{
	Super::Update();

	float countTime = GET_SINGLETON(TimeManager)->GetTime();

	if (countTime >= 360.f) //오류 (1번만 작동됨)
		PosX -= 360.f;

	PosX = countTime;
	PosY = 250 * sin(PosX * PI / 180);

	//Utils::DrawCircle(hdc, Pos())
}

void Stage1Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	Utils::DrawCircle(hdc, Pos(300.f, 300.f), 250);
	Utils::DrawLine(hdc, Pos(550, 50), Pos(550, 600));
	Utils::DrawLine(hdc, Pos(550, 300), Pos(1500, 300));

	int16 theta;
	float radian;
	float x, y;
	float oldx = 0, oldy = 0;

	for (int i = 0; i < 360; i++)
	{
		radian = i * PI/180;
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
} //qp QP
  //db DB

//DrawCircle로 그래프에 하나, 원에 하나를 만들어서 두 개가 선을 따라가게 만들어라