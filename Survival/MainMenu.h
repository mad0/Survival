#pragma once
#include <SFML\Graphics.hpp>
#include "GameState.h"
#include "Text.h"
#include <vector>
#include <memory>

class MainMenu : public GameState {
private:
	std::vector <std::unique_ptr<Text>> mItems;
	std::vector<std::string> mTxt;
public:
	MainMenu(Engine* _menu);
	~MainMenu();
	virtual void inputs();
	virtual void update();
	virtual void draw();
};
