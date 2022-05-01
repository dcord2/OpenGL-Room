# OpenGL-Room
OpenGL Experiment

I built this following an anonymous swedish author's tutorial here: https://openglcornellbox.wordpress.com/
The tutorial is fairly comprehensive but I needed to reference other sites occasionally and figure out a few parts where he doesn't show all steps explicitely.
Lazy Foo's SDL tutorials were helpful for getting started with SDL2 - http://www.lazyfoo.net/tutorials/SDL/index.php

//////////////////////////////////////////////////////////////////////

The .exe and is in the folder called Release:
To run the program put the you need to put the resources folder with the shader files is in the same directory as the .exe

Controls:
-Move your view around with the mouse and WASD
-The light source can be moved around with the arrow keys and m/n
-1/2/3 will change the background color
-Escape quits

/////////////////////////////////////////////////////////////////////

Source code is in the folder called Project3:
To play around with source code and try to make it compile using visual studio, do the following:

1.
Include all the files cpp and h files in this repository in your project. Ensure the paths in the View.cpp's LoadShader function calls reflect where you put the two s
shader.txt files.


2.
Download the following libraries:
SDL2
GLEW
GLM


3.
Create a new C++ project and add at least the library and include files these libraries to a new directory in the same folder as your solution file and project directory.


4.
Then go into the project settings and make these changes (change paths as appropriate after $(SolutionDir) for your directories)

- Project Properties
-- Select All Configurations drop down


- C/C++
-- General
--- Additional Include Directories
Add path to each library's definitions include folder
$(SolutionDir)Path\To\Include\Folder

ex:
$(SolutionDir)ogl_dep\SDL2\include
$(SolutionDir)ogl_dep\GLEW\include
$(SolutionDir)ogl_dep\GLM\include


- Linker
-- General
--- Additional Library Directories
Add path to each .lib file
$(SolutionDir)Path\To\Library\Folder

ex:
$(SolutionDir)ogl_dep\SDL2\lib
$(SolutionDir)ogl_dep\GLEW\lib


- Linker
-- Input
--- Additional Dependencies
Append names of library files

ex.
SDL2.lib;SDL2main.lib;glew32s.lib;opengl32.lib;




