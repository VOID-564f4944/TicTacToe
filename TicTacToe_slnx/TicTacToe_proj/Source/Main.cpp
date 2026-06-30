#include "Types.h"
#include "Input.h"
#include "Game.h"

int main()
{
	while (true)
	{
		GameMode mode = selectMode();

		if (mode == GameMode::PVP)
		{
			playPvp();
			break;
		}
		else
		{
			playPva();
			break;
		}
	}
}