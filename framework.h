// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#include "Types.h"

// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <math.h>

// C++ 헤더
#include <iostream>
#include <vector>
#include <string>
#include <locale>

using namespace std;

// C++ 20
#include <format>
#include <filesystem>
namespace fs = std::filesystem;

// C++ 메모리 릭 체크
#define _CRTDEBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

// TransparentBlt()를 사용하기 위한 라이브러리 추가
#pragma comment(lib, "msimg32.lib")

//#include "framework.h"
#include "Types.h"
#include "Defines.h" //추후
#include "Utils.h"
#include "Vector.h"
#include "Enums.h"

#include "Scene.h"
#include "Stage1Scene.h"
#include "Stage2Scene.h"
#include "Stage3Scene.h"
#include "Stage4Scene.h"
#include "Stage5Scene.h"
#include "Stage6Scene.h"

#include "Matrix3.h"
#include "Matrix4.h"

#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"

#include "Object.h"
