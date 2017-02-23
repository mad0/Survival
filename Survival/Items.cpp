#include "Items.h"

bool Items::InvPressed = false;


Items::Items() {
	font.loadFromFile("retro.ttf");
	text.setFont(font);
	text.setString("Inventory...\n");
	DialogBG.loadFromFile("dialog.png");
	DialogBox.setTexture(DialogBG);
	DialogBox.setScale(0.3f, 0.3f);
}

void::Items::Inventory() {
	if (!InvPressed)
		InvPressed = true;
	else {
		if (InvPressed == 1)
			InvPressed = false;
	}
}


Items::~Items() {

}