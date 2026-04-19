#include <raylib.h>
#include <cmath>

#include <random>

void InitGame(void);
void UpdateGame(void);
void DrawGame(void);
void UnloadGame(void);
void LimitInWindow(Vector2 &position, int frame_width, int frame_height);

    //Globle
    static const int kWindowWidth = 1280;
    static const int kWindowHeigth = 720;           

class Player{
         friend void LimitInWindow(Vector2 &position);
    public:
        
        Player()
        {
            position.x = 300;   // 强烈建议给初始位置，不然默认(0,0)可能被窗口边缘挡住
            position.y = 300;
            is_face_right = false;
            
            dir = {0,0};

            for(int i = 0; i < png_nums; ++i){
                const char* file_name = TextFormat("../img/player_left_%d.png",i);
                t_player_left[i] = LoadTexture(file_name);


                file_name = TextFormat("../img/player_right_%d.png",i);
                t_player_right[i] = LoadTexture(file_name); 
            }
        }
        ~Player()
        {
            for(int i = 0; i<6; ++i){
            UnloadTexture(t_player_left[i]);
            UnloadTexture(t_player_right[i]);
            }
        };
        
        void ProcessEvent()
        {
            dir.x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
            dir.y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);

            is_face_right = dir.x > 0 ? 1 : (dir.x < 0 ? 0 : is_face_right);

            double *len = new double;
            *len = sqrt(pow(dir.x, 2) + pow(dir.y, 2));
            if(abs(*len) >= 1){
                dir.x /= *len;
                dir.y /= *len;  
            }
            delete len;
            if(abs(dir.x)+abs(dir.y) == 2){
                position.x += int(dir.x*speed);    
                position.y +=int(dir.y*speed);    //避免摄像机画面抖动
            }
            else{
                position.x +=int(dir.x*speed);
                position.y +=int(dir.y*speed);
            }
            //LimitInWindow(position, kframe_width, kframe_height);

            
        }
        void Draw()
        {
            if(is_face_right){
                DrawTexture(t_player_right[idx_frame], position.x, position.y, WHITE);
            }
            else{
                DrawTexture(t_player_left[idx_frame], position.x, position.y, WHITE);
            }

            if(++animation_speed_count > animation_speed){
                animation_speed_count = 0;
                idx_frame = (++idx_frame) % 6;
            }    //动画帧的简陋实现
            
        }
        Vector2 Position(){return position;}
        Vector2 Dir(){return dir;}
        
    private:
        float speed = 30.0f;
        Vector2 position;
        int idx_frame = 0;

        int animation_speed_count = 1;
        int animation_speed = 3;    //control player's animation speed with animation_speed_count.
        Vector2 dir;
        bool is_face_right ;    //朝向

        const int kframe_width = 80;
        const int kframe_height = 80;
        static const int png_nums = 6;
       
        Texture2D t_player_left[png_nums];
        Texture2D t_player_right[png_nums];


        
        
};
           
            
class Enemy{
    public:
        Enemy(){
            is_face_right = false;
            idx_frame = 0;
            health = 10;
            
            // 创建一个均匀分布的随机数生成器，范围从 1 到 10
            
               
            //dist(generator) , 生成1-100的随机数
            
            enum class spawnEdge{
                UP = 0, 
                DOWN, 
                LEFT, 
                RIGHT
            };
            spawnEdge edge = (spawnEdge)(rand() % 4);
            switch(edge)
            {
            case spawnEdge::UP:
                position.x = rand() % kWindowWidth;
                position.y = -kframe_height;
                break;
            case spawnEdge::DOWN:
                position.x = rand() % kWindowWidth;
                position.y = kWindowHeigth;
                break;
            case spawnEdge::LEFT:
                position.x = -kframe_width;
                position.y = rand() % kWindowHeigth;
                break;
            case spawnEdge::RIGHT:
                position.x = kWindowWidth;
                position.y = rand() % kWindowHeigth;
                break;

            }

            
            

            rec_collision.x = position.x;
            rec_collision.y = position.y;
            rec_collision.width = kframe_width;
            rec_collision.height = kframe_height;

            

            for(int i = 0; i < png_nums; ++i){
                const char * file_name = TextFormat("../img/enemy_left_%d.png",i);
                t_enemy_left[i] = LoadTexture(file_name);
                file_name = TextFormat("../img/enemy_right_%d.png",i);
                t_enemy_right[i] = LoadTexture(file_name);
            }
        }
        void PathFinding(Vector2 target){
            dir.x = target.x - position.x;
            dir.y = target.y - position.y;
            float *temp = new float;
            *temp = sqrt(pow(dir.x, 2) + pow(dir.y, 2));

            dir.x /= *temp;
            dir.y /= *temp;
            delete temp;

            is_face_right = dir.x > 0 ? 1 : (dir.x < 0 ? 0 : is_face_right);


            position.x += speed * dir.x;
            position.y += speed * dir.y;


        }
        void Draw(){
            if(is_face_right)
            DrawTexture(t_enemy_right[idx_frame], position.x, position.y, WHITE);
            else
            DrawTexture(t_enemy_left[idx_frame], position.x, position.y, WHITE);
            ++idx_frame %= 6;
        }
        bool CheckAlive(){return (health > 0);}
        void BeHurt(int attack_damage){health -= attack_damage;};
        Vector2 Position(){return position;}
        
        void Update(int speed);
    private:
        const int kframe_width = 80;
        const int kframe_height = 80;
        static const int png_nums = 6;
        const int kenemy_born_range = 128;    //敌人出生在屏幕外的范围
        Rectangle rec_collision;
        float speed = 5.0f;

        int idx_frame;
        int animation_speed_count = 1;
        int animation_speed = 3;    //control player's animation speed with animation_speed_count.

        Vector2 position;
        Vector2 dir;
        bool is_face_right;
        float health;

        
        Texture t_enemy_left[png_nums];
        Texture t_enemy_right[png_nums];
    };

class Bullet{
public:
    Bullet(Vector2 origin, Vector2 o_dir)
    {
        speed = 10;
        radius = 10;
        attack_damage = 10;

        dir.x = o_dir.x;
        dir.y = o_dir.y;
        position.x = origin.x;
        position.y = origin.y;
        

    }
    ~Bullet() = default;
    void ProcessEven(){
        position.x += dir.x*speed;
        position.y += dir.y*speed;
        
    }
    bool CheckCollision(Vector2 point){
        return CheckCollisionPointCircle(point, position, radius);
    }
    void Draw(){
        DrawCircle(position.x, position.y, radius,RED);
    }


    int Hurt(){return attack_damage;}

private:
    Vector2 position;
    Vector2 dir;
    float radius;
    float speed;
    float attack_damage;
};
    void TryGenerateEnemy(std::vector<Enemy*>& enemy_list){
            const int k_interval = 5;
            static int counter = 0;
            if((++counter) % k_interval == 0)
            enemy_list.push_back(new Enemy());
        }

    
int main()
{
    
    
    InitWindow(kWindowWidth, kWindowHeigth, "raylib-p");
    InitGame();

    Music bgm=LoadMusicStream("../music/bgm.mp3");
    bgm.looping=true;
    PlayMusicStream(bgm);

    Player Player1;
    Enemy enemy_pig;
    std::vector<Enemy*> enemy_list;
    std::vector<Bullet*> bullet_list;

    int fileSize;
	unsigned char *fontFileData = LoadFileData("../LangKeJiangHuLianMeng.ttf", &fileSize);
    int codepointsCount;
    const char* text = "农好，世界";
	int *codepoints=LoadCodepoints(text,&codepointsCount);
    Font font = LoadFontFromMemory(".ttf",fontFileData,fileSize,32,codepoints,codepointsCount);

    
    Image img_enemy_left[6];
    Image img_enemy_right[6];


    Camera2D camera = {0};
    camera.target = (Vector2){Player1.Position().x + 20, Player1.Position().y + 20};
    camera.offset = {kWindowWidth/2,kWindowHeigth/2};
    camera.zoom = 1;
    camera.rotation = 0;
    
    
    Image img_background = LoadImage("../img/background.png");
    Texture t_background = LoadTextureFromImage(img_background);

    for(int i = 0; i<6; ++i){
        const char * file_name = TextFormat("../img/enemy_left_%d.png",i);
        img_enemy_left[i] = LoadImage(file_name);
        file_name = TextFormat("../img/enemy_right_%d.png",i);
        img_enemy_right[i] = LoadImage(file_name);
        
    }

    while(!WindowShouldClose()){
        
        

        Player1.ProcessEvent();
        
        for(Enemy * _enemy : enemy_list){
            if(1)
            _enemy->PathFinding(Player1.Position());
            for(Bullet * bullet : bullet_list){
            if(bullet->CheckCollision(_enemy->Position())){
                _enemy->BeHurt(bullet->Hurt());
            }
        }
        for(int i = 0; i < enemy_list.size(); ++i){
            Enemy* enemy = enemy_list[i];
            if(!enemy->CheckAlive()){
                std::swap(enemy_list[i], enemy_list.back());
                enemy_list.pop_back();
                delete enemy;
            }
        }
        }
        for(Bullet * bullet : bullet_list){
            bullet->ProcessEven();
        }
        

        enemy_pig.PathFinding(Player1.Position());
        if(IsKeyPressed(KEY_J))
        bullet_list.push_back(new Bullet(Player1.Position(), Player1.Dir()));
        TryGenerateEnemy(enemy_list);

        const char* text = TextFormat("FPS: %d \n敌人数量%d",GetFPS(),enemy_list.size());
	    int *codepoints=LoadCodepoints(text,&codepointsCount);
        Font font = LoadFontFromMemory(".ttf",fontFileData,fileSize,32,codepoints,codepointsCount);
        

        camera.target = Vector2{Player1.Position().x, Player1.Position().y};
        UpdateMusicStream(bgm);
        
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);
                
                DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);
                DrawTexture(t_background, 0, 0, WHITE);
                DrawTextEx(font, text, {50, 50}, 32, 10, BLACK);
                
                for(Enemy * it : enemy_list)
                it->Draw();
                for(Bullet * it : bullet_list)
                it->Draw();
                Player1.Draw();
                enemy_pig.Draw();
            EndMode2D();
        EndDrawing();

        
    }
    UnloadMusicStream(bgm);
    CloseWindow();
    CloseAudioDevice();
    return 0;
}

void InitGame(void)
{
    InitAudioDevice();
    SetTraceLogLevel(LOG_WARNING);
    SetTargetFPS(30);
}

void UpdateGame()
{

}

void DrawGame()
{

}
void LimitInWindow(Vector2 &position, int frame_width, int frame_height)
{
    int width = GetScreenWidth();
    int height = GetScreenHeight();

    if(position.x < 0 )position.x = 0;
    else if(position.x > width - frame_width)position.x = width - frame_width;
    if(position.y < 0 )position.y = 0;
    else if(position.y > height - frame_height)position.y = height - frame_height;
}