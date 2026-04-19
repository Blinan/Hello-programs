#include <raylib.h>

int main() {
	const int kWindowWidth = 1280;
	const int kWindowHight = 720;
	InitWindow(1280,720,"test");
	SetTraceLogLevel(LOG_WARNING);
	SetTargetFPS(30);
	
	//读入图片文件
	Image imgBackground=LoadImage("../img/background.png");
	Image imgEnemyLeft[6];
	for(int enemy_right_ = 0; enemy_right_ != 6; ++enemy_right_){
		const char * filename = TextFormat("../img/enemy_right_%d.png",enemy_right_);
		imgEnemyLeft[enemy_right_] = LoadImage(filename);
	}
	
	struct enemy{
		int x=0;
		int y=0;
		int speed = 10;
		int now_frame = 0;
		int frame = 6;
	};
	enemy pig;
	while(!WindowShouldClose()) {
		pig.now_frame = ++pig.now_frame < pig.frame ? pig.now_frame : 0;
		pig.x = pig.x < kWindowWidth-80 ? pig.x+pig.speed : pig.y+=80,0;
		Texture tBackground = LoadTextureFromImage(imgBackground);
		Texture tenemy = LoadTextureFromImage(imgEnemyLeft[pig.now_frame]);
		BeginDrawing();
			//叠加显示图层。注意显示的顺序
			DrawTexture(tBackground,0,0,WHITE);
			DrawTexture(tenemy,pig.x,pig.y,WHITE);
			DrawLine(0,0,720,720,BLACK);
		EndDrawing();
		UnloadTexture(tenemy);
		UnloadTexture(tBackground);
	}
	for(int i = 0; i < 6; ++i)
	UnloadImage(imgEnemyLeft[i]);
	UnloadImage(imgBackground);
	CloseWindow();
}