#pragma once
#include <GameEngine.h>
#include <unordered_map>;
#include <string>
#include <memory>

class ResourceManager
{
private:
	ResourceManager();
	~ResourceManager();
	static ResourceManager* s_instance;

	std::unordered_map<std::string, std::shared_ptr<Image>> m_Images;
	std::unordered_map<std::string, std::shared_ptr<Animation>> m_Animations;
	std::unordered_map<std::string, std::shared_ptr<Font>> m_Fonts;
	std::unordered_map<std::string, std::shared_ptr<UIButton>> m_Buttons;

public:
	static ResourceManager* GetInstance();
	static void DestroyInstance();

	void AddImage(std::string, std::shared_ptr<Image>);
	Image* GetImage(std::string);
	void AddAnimation(std::string, std::shared_ptr<Animation>);
	Animation* GetAnimation(std::string);
	void AddFont(std::string, std::shared_ptr<Font>);
	Font* GetFont(std::string);
	void AddButton(std::string, std::shared_ptr<UIButton>);
	UIButton* GetButton(std::string);

	void LoadData(std::string);
};