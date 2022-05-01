# OpenGL-Room
OpenGL Experiment





To make this work in visual studio, you need to download the following libraries:
SDL2
GLEW
GLM

Create a new C++ project and add at least the library and include files these libraries to a new directory in the same folder as your solution file and project directory.

Then go into the project settings and make these changes (change paths as appropriate after $(SolutionDir) for your directories)

-> Project Properties
Select All Configurations drop down

-> C/C++
-> General
-> Additional Include Directories
$(SolutionDir)Path\To\Include\Folder
#Repeat for each library
#now can include "path/file.h" in code

$(SolutionDir)ogl_dep\SDL2\include
$(SolutionDir)ogl_dep\GLEW\include
$(SolutionDir)ogl_dep\GLM\include

-> Linker
-> General
-> Additional Library Directories
$(SolutionDir)Path\To\Library\Folder
#repeat for each library

$(SolutionDir)ogl_dep\SDL2\lib
$(SolutionDir)ogl_dep\GLEW\lib

-> Linker
-> Input
-> Additional Dependencies
Add name of library file

SDL2.lib;SDL2main.lib;glew32s.lib;opengl32.lib;



To make it work out side of Visual Studio, you need to put the resources folder with the shader files in the same directory as the .exe



