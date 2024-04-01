#pragma once

class Matrix4
{
public:
	Matrix4() {}
	~Matrix4() {}

public:
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
	float _41, _42, _43, _44;
	/*
	union {
		struct {
			float m11, m12, m13;
			float m21, m22, m23;
			float m31, m32, m33;
		};
	}M[3][3];*/
	//µ¡¼À Ç×µî¿ø : 0, °ö¼Á Ç×µî¿ø : 1

public:
	void Identity();
	void Move(float dx, float dy);
	void Scale(float scale);
	void Rotate(float theta);

};

//Matrix3 Multiple(Matrix3 n, Matrix3 m);
//VERTEX2Dh Translate(VERTEX2Dh v, Matrix3 m);
