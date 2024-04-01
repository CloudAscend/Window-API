#pragma once
#include "Scene.h"

//동차좌표가 포함된 Vertex2D
typedef struct _Vertex2Dh
{
	float x;
	float y;
	float w;
}VERTEX2Dh;

class Stage5Scene : public Scene
{
	using Super = Scene;
public:
	Stage5Scene();
	virtual ~Stage5Scene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Pos ScreenCenter;
	VERTEX2Dh P0, P1, P2;
	VERTEX2Dh SP0, SP1, SP2;

};

