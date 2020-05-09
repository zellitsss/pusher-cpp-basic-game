#include "ResourceManager.h"
#include <fstream>
#include <string>

ResourceManager* ResourceManager::s_instance = nullptr;

ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
	m_Images.clear();
	m_Animations.clear();
	m_Buttons.clear();
	m_Fonts.clear();
}

ResourceManager* ResourceManager::GetInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new ResourceManager();
	}
	return s_instance;
}

void ResourceManager::DestroyInstance()
{
	delete s_instance;
}

void ResourceManager::AddImage(std::string name, std::shared_ptr<Image> image)
{
	m_Images[name] = std::move(image);
}

Image* ResourceManager::GetImage(std::string name)
{
	return m_Images[name].get();
}

void ResourceManager::AddAnimation(std::string name, std::shared_ptr<Animation> animation)
{
	m_Animations[name] = animation;
}

Animation* ResourceManager::GetAnimation(std::string name)
{
	return m_Animations[name].get();
}

void ResourceManager::AddFont(std::string name, std::shared_ptr<Font> font)
{
	m_Fonts[name] = font;
}

Font* ResourceManager::GetFont(std::string name)
{
	return m_Fonts[name].get();
}

void ResourceManager::AddButton(std::string name, std::shared_ptr<UIButton> button)
{
	m_Buttons[name] = button;
}

UIButton* ResourceManager::GetButton(std::string name)
{
	return m_Buttons[name].get();
}

void ResourceManager::LoadData(std::string dataPath)
{
	std::string line;
	std::ifstream inFile;
	inFile.open(dataPath);
	std::getline(inFile, line);

	std::string type;
	int num;

	size_t begin = line.find("#");
	size_t end = line.find(" ");

	if (begin != std::string::npos && end != std::string::npos)
	{
		type = line.substr(begin + 1, end - 1);
		line.erase(begin, end + 1);
		num = std::stoi(line);
	}

	if (type.compare("IMAGES") == 0)
	{
		for (int i = 0; i < num; i++)
		{
			std::getline(inFile, line);
			size_t found = line.find("|");
			if (found != std::string::npos)
			{
				std::string name = line.substr(0, found);
				std::string path = line.substr(found + 1);
				AddImage(name, std::make_shared<Image>(path.c_str()));
			}
		}
	}
	else if (type == "ANIMATIONS")
	{
		for (int i = 0; i < num; i++)
		{
			std::getline(inFile, line);
			size_t found = line.find("|");
			std::string name;
			int numAnimations;
			if (found != std::string::npos)
			{
				name = line.substr(0, found);
				numAnimations = std::stoi(line.substr(found + 1));
				std::list<Image*> imgList;
				std::string path;
				for (int j = 0; j < numAnimations; j++)
				{
					std::getline(inFile, path);
					imgList.push_back(new Image(path.c_str()));
				}
				std::shared_ptr<Animation> anim = std::make_shared<Animation>(imgList, 5.0f);
				anim->PlayAnimation();
				AddAnimation(name, anim);
			}
		}
	}
	else if (type == "BUTTONS")
	{
		for (int i = 0; i < num; i++)
		{
			std::getline(inFile, line);
			size_t found = line.find("|");
			std::string name;
			std::string normalPath;
			std::string pressedPath;
			if (found != std::string::npos)
			{
				name = line.substr(0, found);
				line.erase(0, found + 1);
				found = line.find("|");
				normalPath = line.substr(0, found);
				pressedPath = line.substr(found + 1);
				std::shared_ptr<UIButton> button = std::make_shared<UIButton>(normalPath.c_str(), pressedPath.c_str());
				AddButton(name.c_str(), button);
			}
		}
	}
	else if (type == "FONTS")
	{

	}
}
