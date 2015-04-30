#Fund Comp 2 Final Project

Incendiary Regalia 2: Game of Bones
Tim Chang
Mason Prosser
Lucas Unruh
Chris Syers
4/30/2015


Project Description:

Our goal for this project was to make a Fire Emblem clone with 2 players using SDL. The game includes 7 character classes and one map.


Installation and Running:
To install, navigate to the project directory, and type "make". Then run the executable ./fire_emblem

System Requirements:
Mac or Linux systems only.
Must have installed:
- SDL2
- SDL_image
- SDL_ttf

These can be found here-
* SDL2 - https://www.libsdl.org/download-2.0.php
* SDL_image - https://www.libsdl.org/projects/SDL_image/
* SDL_ttf - https://www.libsdl.org/projects/SDL_ttf/


Gameplay:

Incendiary Regalia is a turn-based strategy game. On their turn players move their characters according to their movement range and
try to eliminate the enemy team. Different characters have different movement restrictions, attack stats and defense stats.

Controls:

Menu:
- Up/down  Select option
- Enter 	  Confirm choice

Game:
- Arrow Keys   Move Cursor
- Enter 	      Select/Attack Character
- Space	      Deselect Character while in movement mode
- E	      Force end of turn


Known Bugs:
- Random Segmentation fault. Happens about 5% of the time, reason unknown.
- Valid movment board (blue squares) sometime drawn over characters, sometimes drawn under characters

Further Improvements:
- MOAR LEVELS!
- Terrain effects on attack
- Sound effects
- Movement animation
- Attacking animation
- Character select screen
- Scrolling maps
- Enemy AI
