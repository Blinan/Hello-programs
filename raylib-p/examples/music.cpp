#include <raylib.h>
#include <cmath>

int main()
{
    const int kWindowWidth = 1280;
    const int kWindowHeigth = 720;

    
    InitWindow(kWindowWidth, kWindowHeigth, "raylib-p");
    InitAudioDevice();
    SetTraceLogLevel(LOG_WARNING);
    SetTargetFPS(30);

    Music bgm=LoadMusicStream("../music/bgm.mp3");
    bgm.looping=true;
    PlayMusicStream(bgm);

    Image img_background = LoadImage("../img/background.png");


    while(!WindowShouldClose()){


        UpdateMusicStream(bgm);
        Texture t_background = LoadTextureFromImage(img_background);

        BeginDrawing();

        ClearBackground(WHITE);
        DrawTexture(t_background, 0, 0, WHITE);
        
        EndDrawing();
    }
    UnloadMusicStream(bgm);
    CloseWindow();
    CloseAudioDevice();

    return 0;
}
