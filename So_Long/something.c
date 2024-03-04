#include <stdio.h>

#include "so_long.h"

typedef struct {
    char **map;
} t_array;

typedef struct {
    int length;
    int breadth;
} t_measurements;

int game_objects_conditions_check(t_array map, t_measurements size)
{
    char **temp = map.map;
    int i, j;
    int length = size.length;
    int breadth = size.breadth;

    // Check the top and bottom boundaries
    j = 0;
    while (j < breadth)
    {
        if (temp[0][j] != '1' || temp[length - 1][j] != '1')
        {
            printf("Give a valid map...!\n");
            printf("Give valid boundaries...!\n");
            return 0;
        }
        j++;
    }

    // Check the left and right boundaries
    i = 0;
    while (i < length)
    {
        if (temp[i][0] != '1' || temp[i][breadth - 1] != '1')
        {
            printf("Give a valid map...!\n");
            printf("Give valid boundaries...!\n");
            return 0;
        }
        i++;
    }

    return 1;
}

int main()
{
    // Example usage
    char *map_data[] = {
        "111111",
        "100001",
        "111111",
        NULL  // Null-terminate the map array
    };

    // Assuming t_array and t_measurements are properly initialized
    t_array map;
    map.map = map_data;

    t_measurements size;
    size.length = 3;
    size.breadth = 6;

    // Call the function
    int result = game_objects_conditions_check(map, size);

    // Display the result
    if (result == 1)
    {
        printf("Conditions met!\n");
    }
    else
    {
        printf("Conditions not met!\n");
    }

    return 0;
}
