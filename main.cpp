#include <windows.h>
#include <gl/gl.h>
#include "GenerateTexture.h"
#include <cstdio>
#include "Building.h"
#include "Point.h"
#include "Country.h"
#include <WindowsX.h>
#include <math.h>
#include "GameTurn.h"
#include "Player.h"
#include <iostream>
#include "setup.h"
#include "Drawing.h"

using namespace std;
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);
void LeftMouseDown(LPARAM lParam);
void RightMouseDown(LPARAM lParam);
void CloseOut();
void DrawBoard(int width, int height);

Country** Countries;
int num_countries;
extern Player *player;
extern Country *country;
extern int numPlayers;
extern char** roads;

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{

    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "Amaranth",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          256,
                          256,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    //Initiation and Setup
    char* countries = (char*)malloc(strlen("Countries.txt")*sizeof(char));
    sprintf(countries, "Countries.txt");
    InitiateCountries(countries);
    free(countries);
    setup();

    int width = 924;
    int height = 693;
    MoveWindow(hwnd, 0, 0, width, height, true);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);

    FILE* fp = fopen("texture5.bmp", "rb");
    GLuint texture1 = generatetexture(fp);
    fclose(fp);
    int a = 0;

    DrawBoard(width, height);
    SwapBuffers(hDC);
    /* program main loop */
    while (!bQuit)
    {
        Player* player2 = &(player[a]);
        GameTurn(player2);
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        DrawBoard(width, height);
        SwapBuffers(hDC);
        a = a % numPlayers;
    }
    glDeleteTextures(1, &texture1);
    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);
    CloseOut();

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                break;
            }
        }
        case WM_LBUTTONDOWN:
        {
            LeftMouseDown(lParam);
        }
        case WM_RBUTTONDOWN:
        {
            RightMouseDown(lParam);
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

void LeftMouseDown(LPARAM lParam){
    //int x = GET_X_LPARAM(lParam);
    //int y = GET_Y_LPARAM(lParam);
    /*Country* currentCountry = NULL;
    for(int i = 0; i < num_countries; i++){
        Country* country = &(Countries[i]);
        Point* center = country->GetCenter();
        float distance = sqrt(pow(abs(x - center->GetX()), 2) + pow(abs(y-center->GetX()), 2));
        if(distance <= country->GetRadius()){
            printf("%f\n", country->GetRadius());
            currentCountry=country;
            break;
        }
    }*/
    /*printf("Left Click\n");
    if(currentCountry != NULL){
        printf("%s\n", currentCountry->GetName());
    }*/
}

void RightMouseDown(LPARAM lParam){
    //int x = GET_X_LPARAM(lParam);
    //int y = GET_Y_LPARAM(lParam);
    //printf("Right: %d %d\n", x, y);
}

void CloseOut(){
    free(Countries);
}

void DrawBoard(int width, int height){
    for(int i = 0; i < num_countries; i++){
        printf("%d %d\n", Countries[i]->GetCenter()->GetX(), Countries[i]->GetCenter()->GetY());

    }
    glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f);   glVertex2f(-1.0f,   1.0f);
        glTexCoord2f(0.0f, 0.0f);  glVertex2f(-1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f);  glVertex2f(1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f);  glVertex2f(1.0f, 1.0f);

    glEnd();
    Sleep (1);
    printf("\n\n");
    for(int i = 0; i < num_countries; i++){
        vector<Building> buildings = Countries[i]->buildings;
        int size = buildings.size();
        for(int j = 0; j < size; j++){
            Building building = buildings[j];
            if(building.GetType().compare("soldier") == 0){
                glColor3f(1.0, 0.0, 0.0);
                DrawSoldier(Countries[i]->GetCenter()->GetX(), Countries[i]->GetCenter()->GetY(), width, height);
            }
        }
    }
    for(int i = 0; i < num_countries; i++){
        for(int j = 0; j < num_countries;j ++){
            if(roads[i][j] == 2){
                printf("Building Road!!!\n");
                DrawRoads(Countries[i], Countries[j], width, height);
            }
        }

    }


}
