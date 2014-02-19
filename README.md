TerraSDL
========

My SDL2.0 Framework. A Good starting point for those aiming to get into C++ Game Development.


A simple enough project, this outlines a basic framework for making 2D games in C++.

Features:
Sprite Drawing and Rendering
Scene Management
Event Management and Input
Easy collision detection
Music and Sound


The Project comes with a basic example, A 3 Scene Structure with a Menu and 2 "Levels". Levels and Menus are "Scenes".
Each Level or Menu or Credits must inherit from "Scene" for the scene manager to work.
The Scene Manager is a singleton that can be called anywhere in the program, as long as you're using the Instance()
function. Use this to change scenes, I have examples in the code.

You don't need to alter anything in TextureManager for Sprite Drawing, just pass in your required values into the
LoadImage() and Draw() functions respctively. Use AnimationDraw() for... well, Animations.


Don't forget to inlcude the SDL dll's and lib file in your Visual Studio Project, as well as SDL_image and SDL_mixer.

Any questions, e-mail me at podge-2006@hotmail.com
