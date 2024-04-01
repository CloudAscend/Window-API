#pragma once

// Scene의 타입을 구분하기 위한 열거형을 정의
enum class SceneType
{
	None,		// 0
	Stage1Scene,
	Stage2Scene,
	Stage3Scene,
	Stage4Scene,
	Stage5Scene,
	Stage6Scene,
	EndScene
};

enum class BtnState { None, Over, Click };