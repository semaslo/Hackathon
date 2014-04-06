#include <gl/gl.h>
#include <cstdio>
#include "Country.h"
void DrawSoldier(int x, int y, int width, int height){
    float new_x = (x - (double)width/2.0)/(double)(width/2.0);
    float new_y = -(y - (double)height/2.0)/(double)(height/2.0);
    int size = 25;
    float new_size = size/(float)height;

    glBegin(GL_TRIANGLES);
        glVertex2f(new_x - new_size, new_y - new_size);
        glVertex2f(new_x, new_y);
        glVertex2f(new_x-new_size, new_y);
    glEnd();
}

void DrawRoads(Country* one, Country* two, int width, int height){
    glColor3f(0.0f, 0.0f, 0.7f);
    float new_x = (one->GetCenter()->GetX() - (double)width/2.0)/(double)(width/2.0);
    float new_y = -(one->GetCenter()->GetY() - (double)height/2.0)/(double)(height/2.0);
    printf("%f %f\n", new_x, new_y);
    glBegin(GL_LINES);
        glVertex2f(new_x, new_y);

        new_x = (two->GetCenter()->GetX() - (double)width/2.0)/(double)(width/2.0);
        new_y = -(two->GetCenter()->GetY() - (double)height/2.0)/(double)(height/2);
        printf("%f %f\n", new_x, new_y);
        glVertex2f(new_x, new_y);
    glEnd();
}
