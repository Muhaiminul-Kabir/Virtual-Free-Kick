/*******************************************************************************************
*
*   raylib [core] examples - Mouse wheel input
*
*   This test has been created using raylib 1.1 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "math.h"
#define RAD  (3.1416/180)
//global var initalization//start

int screenWidth = 1020;
int screenHeight = 750;

const float g = 9.8f ;
float  u = 16.93302;
float c = 20 * RAD;
float x = 0.0f,y ,z;  


//end


//functions//start


float projectileDis(float theta, float v0) {
    float dis;
    dis = (v0*v0*sin(2*theta))/g ;
    return dis;
}

float projectileMaxH(float theta, float v0) {
    float maxH;
    maxH = (v0*v0*pow(sin(theta),2))/(2*g) ;
    return maxH;
}

float projectileV0(float theta, float dis) {
    float v0;
    v0 = sqrt(g/sin(2*theta)) ;
    return v0;
}


float projectileTime(float theta, float v0) {
    float t;
    t = (2*v0*sin(theta))/(g) ;
    return t;
}


void projectile(){
    
    y = 0.09+(tan(c)*x - ((g*x*x)/((2*u*cos(c))*(2*u*cos(c)))));
    z = tan(c)*x - ((g*x*x)/((2*u*cos(c))*(2*u*cos(c))));
}


//end

int main(void)
{
    // Initialization
    
    //--------------------------------------------------------------------------------------


    InitWindow(screenWidth, screenHeight, "raylib [core] example - input mouse wheel");
    
    Camera3D camera = { 0 };
    camera.position = (Vector3){ -40,1,0 };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode typeZ
    SetCameraMode(camera, CAMERA_FREE);
    
    int boxPositionY = screenHeight/2 - 40;
    int scrollSpeed = 4;            // Scrolling speed in pixels

    SetTargetFPS(30);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        UpdateCamera(&camera);   
        //----------------------------------------------------------------------------------
        SetExitKey(KEY_L); 
        Vector3 pos = { x, y,z};
        Vector3 centerPos = {0,0,0};
        Vector3 startPos = {50,0,0};
        Vector3 endPos = {50,0.9,0};
        Vector2 size = {50,100};
        Vector3 startPos2 = {50,0,2};
        Vector3 endPos2 = {50,0.9,2};
       
        boxPositionY -= (GetMouseWheelMove()*scrollSpeed);
        if(IsKeyDown(KEY_RIGHT)){
           z++;
        }
        if(IsKeyDown(KEY_UP)){
          x = 0;     
        }
      
        if(IsKeyDown(KEY_LEFT)){
          x+=1;
        }
        if(IsKeyDown(KEY_K)){
            x= 0;
        }

        
      
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(SKYBLUE);
            BeginMode3D(camera);
            //start
               
                
                DrawPlane(centerPos,size, GREEN);
                DrawLine3D(startPos,endPos, WHITE);
                DrawLine3D(startPos2,endPos2, WHITE);
                DrawSphere(pos,0.1f,RED);
                // DrawSphere(pos2,1.0f,RED);
             
                // DrawGrid(10,10);
                projectile();
        
        
             //end
             EndMode3D();
             //  DrawText("j", y, 10, 20, MAROON);
          
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
