#include "framework.h"
#include "SceneManager.h"
#include "Scene.h"


void SceneManager::Init()
{

}

void SceneManager::Update()
{
	if (_scene)
	{
		_scene->Update();
	}
}

void SceneManager::Render(HDC hdc)
{
	if (_scene)
	{
		_scene->Render(hdc);
	}
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType)
	{
		return;
	}

	Scene* newScene = nullptr;

	switch (sceneType)
	{
	case SceneType::Stage1Scene:
		newScene = new Stage1Scene();
		break;
	case SceneType::Stage2Scene:
		newScene = new Stage2Scene();
		break;
	case SceneType::Stage3Scene:
		newScene = new Stage3Scene();
		break;
	case SceneType::Stage4Scene:
		newScene = new Stage4Scene();
		break;
	case SceneType::Stage5Scene:
		newScene = new Stage5Scene();
		break;
	case SceneType::Stage6Scene:
		newScene = new Stage6Scene();
		break;
	}

	SAFE_DELETE(_scene);

	_scene = newScene;
	_sceneType = sceneType;

	newScene->Init();
}