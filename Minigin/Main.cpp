#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "TextComponent.h"
#include "RenderComponent.h"
#include "FpsComponent.h"
#include "Scene.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	//Background
	auto backgroundObject = std::make_shared<dae::GameObject>();
	auto textureComponent = std::make_unique<dae::RenderComponent>(backgroundObject.get());
	textureComponent->SetTexture("background.tga");
	backgroundObject->AddComponent(std::move(textureComponent));
	scene.Add(backgroundObject);

	//DAE Picture
	auto logoObject = std::make_shared<dae::GameObject>();
	textureComponent = std::make_unique<dae::RenderComponent>(logoObject.get());
	textureComponent->SetTexture("logo.tga");
	logoObject->SetPosition(320, 180);
	logoObject->AddComponent(std::move(textureComponent));
	scene.Add(logoObject);

	//Assignment Text
	auto textObject = std::make_shared<dae::GameObject>();
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto textComponent = std::make_unique<dae::TextComponent>("Programming 4 Assignment", std::move(font), textObject.get());
	textObject->SetPosition(160, 2);
	textObject->AddComponent(std::move(textComponent));
	scene.Add(textObject);

	//FPS Counter
	auto fpsObject = std::make_shared<dae::GameObject>();
	font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto fpsTextComponent = std::make_unique<dae::TextComponent>("FPS: ", font, fpsObject.get());
	auto fpsComponent = std::make_unique<dae::FpsComponent>(fpsObject.get());
	fpsObject->SetPosition(2, 2);
	fpsObject->AddComponent(std::move(fpsTextComponent));
	fpsObject->AddComponent(std::move(fpsComponent));
	scene.Add(fpsObject);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}