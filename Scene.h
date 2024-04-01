#pragma once

// 화면을 그리고 싶을 때 화면에 있는 모든 처리(물체를 들고있는 등) 역할을 합니다.
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hdc);

};