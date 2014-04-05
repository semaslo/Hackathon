#include <windows.h>
#include <gl/gl.h>
#include "GenerateTexture.h"
#include <cstdio>
#include "Building.h"
#include "Point.h"
#include "Player.h"
#include "Country.h"
#include <WindowsX.h>
#include <math.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);
void LeftMouseDown(LPARAM lParam);
void RightMouseDown(LPARAM lParam);
void InitiateCountries(char* filename);

Country* Countries;
int num_countries;
Player* Players;
//Buildings* Buildings;

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
    float theta = 0.0f;

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


    int width = 924;
    int height = 693;
    MoveWindow(hwnd, 0, 0, width, height, true);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);

    FILE* fp = fopen("texture5.bmp", "rb");
    GLuint texture1 = generatetexture(fp);
    fclose(fp);

    /* program main loop */
    while (!bQuit)
    {
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
        else
        {
            glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            //glPushMatrix();
            //glRotatef(theta, 0.0f, 0.0f, 1.0f);

           glBegin(GL_QUADS);
                glColor3f(1.0f, 1.0f, 1.0f);
                glTexCoord2f(0.0f, 1.0f);   glVertex2f(-1.0f,   1.0f);
                glTexCoord2f(0.0f, 0.0f);  glVertex2f(-1.0f, -1.0f);
                glTexCoord2f(1.0f, 0.0f);  glVertex2f(1.0f, -1.0f);
                glTexCoord2f(1.0f, 1.0f);  glVertex2f(1.0f, 1.0f);

            glEnd();

            //glPopMatrix();

            SwapBuffers(hDC);

            theta += 1.0f;
            Sleep (1);
        }
    }
    glDeleteTextures(1, &texture1);
    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

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
    int x = GET_X_LPARAM(lParam);
    int y = GET_Y_LPARAM(lParam);
    for(int i = 0; i < num_countries; i++){
        Country* country = &(Countries[i]);
    }
}

void RightMouseDown(LPARAM lParam){
    int x = GET_X_LPARAM(lParam);
    int y = GET_Y_LPARAM(lParam);
    printf("Right: %d %d\n", x, y);
}

void InitiateCountries(char* filename){
    FILE* file = fopen(filename, "rb");
    if(file == NULL){
        printf("File did not open");
        return;
    }
    fscanf(file, "%d\n", &num_countries);
    char name[20];
    int x;
    int y;
    Point temp = Point(0, 0);
    Countries = (Country*)calloc(num_countries, sizeof(Country));
    for(int i = 0; i < num_countries; i++){
        fscanf(file, "%s %d %d\n", name, &x, &y);
        temp = Point(x, y);
        Countries[i] = Country(&temp, 1.5f);
    }
}
