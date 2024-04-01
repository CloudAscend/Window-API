#pragma once

class Stage3Scene : public Scene
{
	using Super = Scene;
public:
	Stage3Scene();
	virtual ~Stage3Scene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	RECT rtScreen;
	int w = 1100, h = 600;
};

