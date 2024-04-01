#pragma once

class Stage1Scene : public Scene
{
	using Super = Scene;
public:
	Stage1Scene();
	virtual ~Stage1Scene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	float PosX;
	float PosY;
};

