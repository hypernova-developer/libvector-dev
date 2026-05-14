#include "include/vector.h"

/* Instantiate vector for 'int' and 'float' types */
VECTOR_TYPE(int)
VECTOR_TYPE(float)

int main()
{
    /* Integer Vector Example */
    Vector_int grades;
    vector_init_int(&grades);

    for (int i = 1; i <= 10; i++)
    {
        vector_push_int(&grades, i * 10);
    }

    printf("--- Integer Vector ---\n");
    printf("Vector Size: %zu\n", grades.size);
    printf("Fifth Element: %d\n\n", grades.data[4]);

    /* Floating Point Vector Example */
    Vector_float coordinates;
    vector_init_float(&coordinates);

    vector_push_float(&coordinates, 34.05f);
    vector_push_float(&coordinates, 41.01f);

    printf("--- Float Vector ---\n");
    printf("Latitude: %.2f\n", coordinates.data[0]);
    printf("Longitude: %.2f\n", coordinates.data[1]);

    /* Cleanup */
    vector_free_int(&grades);
    vector_free_float(&coordinates);

    return 0;
}
