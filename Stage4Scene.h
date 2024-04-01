#pragma once

typedef struct _Vertex2D
{
	float x;
	float y;
}VERTEX2D;

class Stage4Scene : public Scene
{
	using Super = Scene;
public:
	Stage4Scene();
	virtual ~Stage4Scene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Pos ScreenCenter;
	VERTEX2D P0, P1, P2;
	VERTEX2D SP0, SP1, SP2;

};

