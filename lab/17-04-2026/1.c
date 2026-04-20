#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Point;

typedef struct {
    Point a;
    Point b;
    Point c;
} Triangle;

double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    Point points[6] = {
        {0, 0, 0},
        {3, 0, 0},
        {0, 4, 0},
        {1, 1, 1},
        {4, 1, 1},
        {1, 5, 1}
    };

    Triangle triangles[2];
    triangles[0].a = points[0];
    triangles[0].b = points[1];
    triangles[0].c = points[2];
    triangles[1].a = points[3];
    triangles[1].b = points[4];
    triangles[1].c = points[5];

    for (int i = 0; i < 2; i++) {
        double ab = distance(triangles[i].a, triangles[i].b);
        double bc = distance(triangles[i].b, triangles[i].c);
        double ca = distance(triangles[i].c, triangles[i].a);
        printf("triangle %d:\n", i + 1);
        printf("  side ab = %.2f\n", ab);
        printf("  side bc = %.2f\n", bc);
        printf("  side ca = %.2f\n", ca);
    }

    return 0;
}