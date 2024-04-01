#pragma once

enum class ObjectType
{
	None,
	Player,		
	Monster,	
	Missile,	
	Env,		
};

class Object
{
public:
	Object();
	Object(ObjectType type);
	virtual	~Object();

	//순수 가상함수 //인터페이스 정의
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;

public:
	void		SetPos(Pos pos) { _Pos = pos; }
	Pos			GetPos() { return _Pos; }

	ObjectType	GetObjectType() { return _type; }

	float		GetRadius() { return _Radius; }
	void		SetRadius(float radius) { _Radius = radius; }

protected:
	ObjectType	_type = ObjectType::None;

	STAT		_Stat = {};
	Pos			_Pos = {};
	float		_Radius = 50.0f;
};

