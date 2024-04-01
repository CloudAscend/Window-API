#pragma once
#include "Scene.h"

//동차좌표가 포함된 Vertex2D
typedef struct _Vertex3D
{
	float x;
	float y;
	float z;
	float w;
}VERTEX3D ;

typedef struct _IndexTriangle3D //삼각형 만들기
{
	Pos pos1;
	Pos pos2;
	Pos pos3;
}INDEX3D;

class Stage6Scene : public Scene
{
	using Super = Scene;
public:
	Stage6Scene();
	virtual ~Stage6Scene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Pos ScreenCenter;
	VERTEX3D P0, P1, P2, P3;
	//VERTEX3D SP0, SP1, SP2;

};

