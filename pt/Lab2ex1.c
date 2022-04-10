#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

#define MAX_N 1

struct gshape {
    int type;
    int ID;
    union {
        struct {
            float radius;
            float x, y;
        }circle;

        struct {
            float x1, y1, x2, y2, x3, y3;
        }triangle;

        struct {
            float x1, y1;
            float x4, y4;
        }rectangle;
    }gshape;
    void (*read_gshape)(struct gshape *gs);
    void (*write_gshape)(struct gshape *gs);
    float (*area_gshape)(struct gshape *gs);
};



void read_circle (struct gshape *gs) {
    printf("radius ? ");
    scanf("%f", &(gs->gshape.circle.radius));

    printf("X center ? ");
    scanf("%f", &(gs->gshape.circle.x));
}

void write_circle (struct gshape *gs) {
    printf("Printing circle ID = %d :\n", gs->ID);
}

float area_circle (struct gshape *gs) {
    return M_PI*(gs->gshape.circle.radius*gs->gshape.circle.radius);
}

void read_triangle (struct gshape *gs) {
    printf("Reading triangle :\n");
}

void write_triangle (struct gshape *gs) {
    printf("Triangle (%f, %f) (%f, %f), (%f, %f)\n", gs->gshape.triangle.x1, gs->gshape.triangle.y1, 
            gs->gshape.triangle.x2, gs->gshape.triangle.y2, gs->gshape.triangle.x3, gs->gshape.triangle.y3);           
}

float area_triangle (struct gshape *gs) {
    float a, b, c, p;
    float x1, x2, x3, y1, y2, y3;

    x1 = gs->gshape.triangle.x1;
    x2 = gs->gshape.triangle.x2;
    x3 = gs->gshape.triangle.x3;

    y1 = gs->gshape.triangle.y1;
    y2 = gs->gshape.triangle.y2;
    y3 = gs->gshape.triangle.y3;

    a = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    b = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    c = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));

    p = (a+b+c)/2;

    return sqrt(p*(p-a)*(p-b)*(p-c));
}

void read_rectangle (struct gshape *gs) {
    printf("Reading rectangle :\n");
}

void write_rectangle (struct gshape *gs) {
    printf("Printing rectangle :\n");
}

float area_rectangle (struct gshape *gs) {
    float width = fabs(gs->gshape.rectangle.x1 - gs->gshape.rectangle.x4);
    float heigth =  fabs(gs->gshape.rectangle.y1 - gs->gshape.rectangle.y4);

    return width*heigth;
}

int main(void) {
    int i, type;
    struct gshape gs[MAX_N];

    printf("Initializing the geometric shapes collection : \n");
    for(i = 0; i < MAX_N; ++i) {
        do {
            printf("Shape ID %d : ", i);
            printf("What type of shape is it ? (0 = circle, 1 = triangle, 2 = rectangle)");
            scanf("%d", &type);
            gs[i].type = type;
            gs[i].ID = i;

            switch (gs[i].type){
                case 0:
                    gs[i].read_gshape = &read_circle;
                    gs[i].write_gshape = &write_circle;
                    gs[i].area_gshape = &area_circle;
                    break;
                case 1:
                    gs[i].read_gshape = &read_triangle;
                    gs[i].write_gshape = &write_triangle;
                    gs[i].area_gshape = &area_triangle;

                    printf("x1 =");
                    scanf("%f", &(gs[i].gshape.triangle.x1));

                    printf("y1 =");
                    scanf("%f", &(gs[i].gshape.triangle.y1));

                    printf("x2 =");
                    scanf("%f", &(gs[i].gshape.triangle.x2));

                    printf("y2 =");
                    scanf("%f", &(gs[i].gshape.triangle.y2));

                    printf("x3 =");
                    scanf("%f", &(gs[i].gshape.triangle.x3));

                    printf("y3 =");
                    scanf("%f", &(gs[i].gshape.triangle.y3));
                    break;
                case 2:
                    gs[i].read_gshape = &read_rectangle;
                    gs[i].write_gshape = &write_rectangle;
                    gs[i].area_gshape = &area_rectangle;
                    break;
                default :
                    printf("Yikes!\n");
            }

        }while ((gs[i].type != 0) && (gs[i].type != 1) && (gs[i].type != 2));
    }

    printf("Printing all the circles from our collection :\n");
    for(i = 0; i < MAX_N; ++i){
        if(gs[i].type == 0)
            gs[i].write_gshape(&gs[i]);
    }

    for(i = 0; i < MAX_N; ++i){
        printf("The area of the triangle number %d is %.2f\n", i, gs[i].area_gshape(&gs[i]));
    }

    return 0;
}
