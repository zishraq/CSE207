#include <stdio.h>
#include <math.h>

typedef struct Coordinate {
    float x;
    float y;
} coordinate;

float calculate_distance(coordinate * point1, coordinate * point2) {
    float result = sqrt(pow((point2->x - point1->x), 2) + pow((point2->y - point1->y), 2));

    return result;
}

int main() {
    float x1, y1;
    float x2, y2;
    float distance;

    printf("Input point A: ");
    scanf("%f %f", &x1, &y1);

    printf("Input point B: ");
    scanf("%f %f", &x2, &y2);

    coordinate A = {x1, y1};
    coordinate B = {x2, y2};

    distance = calculate_distance(&A, &B);

    printf("Distance is: %f\n", distance);

    return 0;
}