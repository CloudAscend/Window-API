#include "framework.h"
#include "Stage3Scene.h"

Stage3Scene::Stage3Scene()
{

}

Stage3Scene::~Stage3Scene()
{

}

void Stage3Scene::Init()
{
	Super::Init();
}

void Stage3Scene::Update()
{
	Super::Update();

}

void Stage3Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	int16 theta;
	float radian;
	float x, y;
	float oldx = 0, oldy = 0;
	float r = 250.f;

	for (int i = 0; i < 360; i++)
	{
		radian = i * PI / 180;
		x = r * sin(radian);
		y = r * cos(radian);
		Utils::DrawLine(hdc, Pos(oldx + w / 2.f, -oldy + h / 2.f), Pos(x + w / 2.f, -y + h / 2.f));
		Utils::DrawPixel(hdc, Pos(x + w / 2.f, -y + h / 2.f), RGB(255, 0, 0));
		oldx = x;
		oldy = y;
	}
}