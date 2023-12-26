#ifndef MODE
#define MODE

#include <SFML/Graphics.hpp>

/// \todo
/// > Make buttons to change modes rather than keybinds.
/// Vals: 
/// 0 -> pause
/// 1 -> draw
/// 2 -> play

class Mode
{
private:
	int modeVal;

public:
	Mode();

	int getModeVal();
	void setModeVal(int);

	void setPause();
	void setDraw();
	void setPlay();

	bool isPause();
	bool isDraw();
	bool isPlay();
};

#endif MODE


