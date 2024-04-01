#pragma once

class Stage2Scene : public Scene
{
	using Super = Scene;
public:
	Stage2Scene();
	virtual ~Stage2Scene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	float PosX;
	float PosY;

	float curTime;
};

