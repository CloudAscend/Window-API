#include "framework.h"
#include "Stage5Scene.h"

extern HWND g_hWnd;

Stage5Scene::Stage5Scene()
{
	
}

Stage5Scene::~Stage5Scene()
{

}

void Stage5Scene::Init()
{
	Super::Init();

	P0.x = 0.f;
	P0.y = 100.f;
	P0.w = 1.0f;
	P1.x = -70.f;
	P1.y = -70.f;
	P1.w = 1.0f;
	P2.x = 70.f;
	P2.y = -70.f;
	P2.w = 1.0f;

	RECT rtTemp;
	GetClientRect(g_hWnd, &rtTemp);
	int w = rtTemp.right - rtTemp.left;
	int h = rtTemp.bottom - rtTemp.top;
	ScreenCenter.x = w / 2.0f;
	ScreenCenter.y = h / 2.0f;
}

void Stage5Scene::Update()
{
	Super::Update();
	Matrix3 CTM, TTM, RTM, STM;
	TTM.Move(100.f, 100.f);
	static int theta = 0;
	(theta > 360) ? (theta = 0) : (theta++);
	RTM.Rotate(theta);
	STM.Scale(1.3f);

	CTM.Identity(); //초기화
	CTM = Multiple(CTM, STM);
	CTM = Multiple(CTM, RTM);
	CTM = Multiple(CTM, TTM);

	SP0 = Translate(P0, CTM);
	SP1 = Translate(P1, CTM);
	SP2 = Translate(P2, CTM);

	////크기 변환
	//float s = 1.1;
	//VERTEX2Dh sp0, sp1, sp2;
	//sp0.x = P0.x * s;
	//sp0.y = P0.y * s;
	//sp1.x = P1.x * s;
	//sp1.y = P1.y * s;
	//sp2.x = P2.x * s;
	//sp2.y = P2.y * s;

	////회전 변환
	//static int theta = 0;
	//(theta >= 360) ? (theta = 0) : (theta += 1);  //LSD
	//float radian;
	//VERTEX2Dh rp0, rp1, rp2;
	//radian = theta * PI / 180.f;
	///*
	//rp0.x = p0.x * sin(radian) + p0.y * cos(radian);
	//rp0.y = p0.y * cos(radian) - p0.x * sin(radian);
	//rp1.x = p1.x * sin(radian) + p1.y * cos(radian);
	//rp1.y = p1.y * cos(radian) - p1.x * sin(radian);
	//rp2.x = p2.x * sin(radian) + p2.y * cos(radian);
	//rp2.y = p2.y * cos(radian) - p2.x * sin(radian);*/

	////Normal CODE
	//rp0.x = sp0.x * cos(radian) + sp0.y * sin(radian);
	//rp0.y = sp0.y * cos(radian) - sp0.x * sin(radian);
	//rp1.x = sp1.x * cos(radian) + sp1.y * sin(radian);
	//rp1.y = sp1.y * cos(radian) - sp1.x * sin(radian);
	//rp2.x = sp2.x * cos(radian) + sp2.y * sin(radian);
	//rp2.y = sp2.y * cos(radian) - sp2.x * sin(radian); 

	////이동 변환
	//VERTEX2Dh p0, p1, p2;
	//float dx = 100.f;
	//float dy = -100.f;
	//p0.x = P0.x + dx;
	//p0.y = P0.y + dy;
	//p1.x = P1.x + dx;
	//p1.y = P1.y + dy;
	//p2.x = P2.x + dx;
	//p2.y = P2.y + dy;

	//SP0 = rp0;
	//SP1 = rp1;
	//SP2 = rp2;
}

void Stage5Scene::Render(HDC hdc)
{
	Super::Render(hdc);

	Utils::DrawCircle(hdc, Pos(SP0.x + ScreenCenter.x, -SP0.y + ScreenCenter.y), 2);
	Utils::DrawCircle(hdc, Pos(SP1.x + ScreenCenter.x, -SP1.y + ScreenCenter.y), 2);
	Utils::DrawCircle(hdc, Pos(SP2.x + ScreenCenter.x, -SP2.y + ScreenCenter.y), 2);

	Utils::DrawPixel(hdc, Pos(SP0.x + ScreenCenter.x, -SP0.y + ScreenCenter.y), RGB(255, 0, 0));
	Utils::DrawPixel(hdc, Pos(SP1.x + ScreenCenter.x, -SP1.y + ScreenCenter.y), RGB(255, 0, 0));
	Utils::DrawPixel(hdc, Pos(SP2.x + ScreenCenter.x, -SP2.y + ScreenCenter.y), RGB(255, 0, 0));

	Utils::DrawLine(hdc, Pos(SP0.x + ScreenCenter.x, -SP0.y + ScreenCenter.y), Pos(SP1.x + ScreenCenter.x, -SP1.y + ScreenCenter.y));
	Utils::DrawLine(hdc, Pos(SP1.x + ScreenCenter.x, -SP1.y + ScreenCenter.y), Pos(SP2.x + ScreenCenter.x, -SP2.y + ScreenCenter.y));
	Utils::DrawLine(hdc, Pos(SP2.x + ScreenCenter.x, -SP2.y + ScreenCenter.y), Pos(SP0.x + ScreenCenter.x, -SP0.y + ScreenCenter.y));
}