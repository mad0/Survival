#pragma once
#include <SFML\Graphics.hpp>
#include "GameState.h"
#include "Text.h"
#include <vector>
#include <memory>

class MainMenu : public GameState {
	std::vector <std::unique_ptr<Text>> mItems;
	std::vector<std::string> mTxt;
public:
	virtual void inputs();
	virtual void update();
	virtual void draw();
	MainMenu(Engine* gra);
	~MainMenu();
};
