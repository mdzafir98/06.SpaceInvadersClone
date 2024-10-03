#include "raylib.h"
#include "src/Game.h"
#include "src/SoundManager.h"

int main(void)
{
    Color grey ={29,29,27,255};

    InitWindow(512,512,"Space Invaders!");
    InitAudioDevice();
    SetTargetFPS(60);
    Game game;
    SoundManager soundmanager;

    soundmanager.playMusic();

    while(WindowShouldClose()==false)
    {
        //1. event handling
        game.handleInput();

        //2. updating positions
        game.update();
        soundmanager.updateMusic();
        
        //3. Drawing
        BeginDrawing();
        ClearBackground(grey);
        game.draw();
        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();
}