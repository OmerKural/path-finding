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
	int8_t modeVal;


public:
	Mode();

	int8_t getModeVal();
	void setModeVal(int8_t);
};

#endif MODE


