#include <raylib.h>

int main() {
	
	InitWindow(800,600,"世界你好");
	
	Image img=GenImageColor(800,600,WHITE);
	int fileSize;
	unsigned char *fontFileData = LoadFileData("../LangKeJiangHuLianMeng.ttf", &fileSize);
	//ImageDrawCircleEx(&img, 400,300,200,10,BLACK);
	SetTraceLogLevel(LOG_WARNING);
	SetTargetFPS(120);
    //Font font = LoadFont("../LangKeJiangHuLianMeng.ttf");
    int codepointsCount;
    const char* text = "农好，世界";
	int *codepoints=LoadCodepoints(text,&codepointsCount);


        Font font = LoadFontFromMemory(".ttf",fontFileData,fileSize,32,codepoints,codepointsCount);
	while (!WindowShouldClose()) {

        
        

        
		BeginDrawing();
		ClearBackground(WHITE);

        DrawTextEx(font, text, {50, 50}, 32, 10, RED);
		EndDrawing();
	}
	UnloadImage(img);
	//释放字体文件内容
    UnloadFont(font);

	return 0;
}