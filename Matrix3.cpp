#include "framework.h"
//#include "Matrix3.h"

void Matrix3::Identity()
{
	_11 = 1.0f; _12 = 0.0f; _13 = 0.0f;
	_21 = 0.0f; _22 = 1.0f; _23 = 0.0f;
	_31 = 0.0f; _32 = 0.0f; _33 = 1.0f;
}

void Matrix3::Move(float dx, float dy)
{
	_11 = 1.0f; _12 = 0.0f; _13 = 0.0f;
	_21 = 0.0f; _22 = 1.0f; _23 = 0.0f;
	_31 = dx; _32 = dy  ; _33 = 1.0f;
}

void Matrix3::Scale(float scale)
{
	_11 = scale; _12 = 0.0f;  _13 = 0.0f;
	_21 = 0.0f; _22 = scale; _23 = 0.0f;
	_31 = 0.0f; _32 = 0.0f; _33 = scale;
}

void Matrix3::Rotate(float theta)
{
	float rad = theta * PI / 180.f;
	float cs = cos(rad);
	float sn = sin(rad);
	_11 = cs  ; _12 = sn; _13 = 0.0f;
	_21 = -sn; _22 = cs; _23 = 0.0f;
	_31 = 0.0f; _32 = 0.0f; _33 = 1.0f;
}

Matrix3 Multiple(Matrix3 n, Matrix3 m)
{
	Matrix3 Mat;
	Mat._11 = n._11 * m._11 + n._12 * m._21 + n._13 * m._31;
	Mat._12 = n._11 * m._12 + n._12 * m._22 + n._13 * m._32;
	Mat._13 = n._11 * m._13 + n._12 * m._23 + n._13 * m._33;

	Mat._21 = n._21 * m._11 + n._22 * m._21 + n._23 * m._31;
	Mat._22 = n._21 * m._12 + n._22 * m._22 + n._23 * m._32;
	Mat._23 = n._21 * m._13 + n._22 * m._23 + n._23 * m._33;

	Mat._31 = n._31 * m._11 + n._32 * m._21 + n._33 * m._31;
	Mat._32 = n._31 * m._12 + n._32 * m._22 + n._33 * m._32;
	Mat._33 = n._31 * m._13 + n._32 * m._23 + n._33 * m._33;

	return Mat;
}

VERTEX2Dh Translate(VERTEX2Dh v, Matrix3 m)
{
	VERTEX2Dh Temp;

	Temp.x = v.x * m._11 + v.y * m._21 + v.w * m._31;
	Temp.y = v.x * m._12 + v.y * m._22 + v.w * m._32;
	Temp.w = v.x * m._13 + v.y * m._23 + v.w * m._33;
	Temp.w = 1.0f;

	return Temp;
}

//Operator를 추가하기
