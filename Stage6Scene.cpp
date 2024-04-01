#include "framework.h"
#include "Stage6Scene.h"

extern HWND g_hWnd;

Stage6Scene::Stage6Scene()
{

}

Stage6Scene::~Stage6Scene()
{

}

void Stage6Scene::Init()
{
	Super::Init();

	P0 = { 0.f, 100.f, 0.f, 1.0f };
	P1 = { -70.f, -70.f, 0.f, 1.0f };
	P2 = { 70.f, -70.f, 0.f, 1.0f };
	P3 = { 0.f, -40.f, 0.f, 3.0f }; //P3.y = -70.f

	RECT rtTemp;
	GetClientRect(g_hWnd, &rtTemp);
	int w = rtTemp.right - rtTemp.left;
	int h = rtTemp.bottom - rtTemp.top;
	ScreenCenter.x = w / 2.0f;
	ScreenCenter.y = h / 2.0f;
}

void Stage6Scene::Update()
{
	Super::Update();
	
}

void Stage6Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	Utils::DrawCircle(hdc, Pos(P0.x + ScreenCenter.x, -P0.y + ScreenCenter.y), 2);
	Utils::DrawCircle(hdc, Pos(P1.x + ScreenCenter.x, -P1.y + ScreenCenter.y), 2);
	Utils::DrawCircle(hdc, Pos(P2.x + ScreenCenter.x, -P2.y + ScreenCenter.y), 2);
	Utils::DrawCircle(hdc, Pos(P3.x + ScreenCenter.x, -P3.y + ScreenCenter.y), 2);

	for (int i = 0; i < 4; i++)
	{

	}

	//P0 - P1 - P2 - P0 (¿Þ -> ¿À)
	Utils::DrawLine(hdc, Pos(P0.x + ScreenCenter.x, -P0.y + ScreenCenter.y), Pos(P1.x + ScreenCenter.x, -P1.y + ScreenCenter.y));
	Utils::DrawLine(hdc, Pos(P1.x + ScreenCenter.x, -P1.y + ScreenCenter.y), Pos(P2.x + ScreenCenter.x, -P2.y + ScreenCenter.y));
	Utils::DrawLine(hdc, Pos(P2.x + ScreenCenter.x, -P2.y + ScreenCenter.y), Pos(P0.x + ScreenCenter.x, -P0.y + ScreenCenter.y));
	
	//P0 - P3 - P1 - P0 (¿Þ -> ¿À)
	Utils::DrawLine(hdc, Pos(P0.x + ScreenCenter.x, -P0.y + ScreenCenter.y), Pos(P3.x + ScreenCenter.x, -P3.y + ScreenCenter.y));
	Utils::DrawLine(hdc, Pos(P3.x + ScreenCenter.x, -P3.y + ScreenCenter.y), Pos(P1.x + ScreenCenter.x, -P1.y + ScreenCenter.y));
	Utils::DrawLine(hdc, Pos(P1.x + ScreenCenter.x, -P1.y + ScreenCenter.y), Pos(P0.x + ScreenCenter.x, -P0.y + ScreenCenter.y));

	//P0 - P2 - P3 - P0 (¿Þ -> ¿À)
	Utils::DrawLine(hdc, Pos(P0.x + ScreenCenter.x, -P0.y + ScreenCenter.y), Pos(P2.x + ScreenCenter.x, -P2.y + ScreenCenter.y));
	Utils::DrawLine(hdc, Pos(P2.x + ScreenCenter.x, -P2.y + ScreenCenter.y), Pos(P3.x + ScreenCenter.x, -P3.y + ScreenCenter.y));
	Utils::DrawLine(hdc, Pos(P3.x + ScreenCenter.x, -P3.y + ScreenCenter.y), Pos(P0.x + ScreenCenter.x, -P0.y + ScreenCenter.y));

	//P3 - P1 - P2 - P3 (¿Þ -> ¿À)
	Utils::DrawLine(hdc, Pos(P3.x + ScreenCenter.x, -P3.y + ScreenCenter.y), Pos(P1.x + ScreenCenter.x, -P1.y + ScreenCenter.y));
	Utils::DrawLine(hdc, Pos(P1.x + ScreenCenter.x, -P1.y + ScreenCenter.y), Pos(P2.x + ScreenCenter.x, -P2.y + ScreenCenter.y));
	Utils::DrawLine(hdc, Pos(P2.x + ScreenCenter.x, -P2.y + ScreenCenter.y), Pos(P3.x + ScreenCenter.x, -P3.y + ScreenCenter.y));
}