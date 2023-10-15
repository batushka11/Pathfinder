#include "../inc/pathfinder.h"

void printPath(int start, int end, int **matrix, int *distances, char **str_of_isl,int size) {
    int VERTICES = size;
    if (end == start) {
        mx_printstr(str_of_isl[end]);
    } else {
        for (int j = 0; j < VERTICES; ++j) {
            if (matrix[j][end]) {
                int temp = distances[end] - matrix[j][end];
                if (temp == distances[j]) {
                    printPath(start, j, matrix, distances, str_of_isl, VERTICES);
                    mx_printstr(" -> ");
                    mx_printstr(str_of_isl[end]);
                    return;
                }
            }
        }
    }
}

void simplePathfindingAlgorithm(int** matrix, int size, char** str_of_isl) {
    int VERTICES = size;

    for (int START = 0; START < VERTICES; START++) {
        int* distances = (int*)malloc(VERTICES * sizeof(int));
        bool* visited = (bool*)malloc(VERTICES * sizeof(bool));
        int minimalWeight, minimalIndex;

        for (int i = 0; i < VERTICES; ++i) {
            visited[i] = false;
            distances[i] = INT_MAX;
        }

        distances[START] = 0;

        do {
            minimalIndex = INT_MAX;
            minimalWeight = INT_MAX;

            for (int i = 0; i < VERTICES; ++i) {
                if (!visited[i] && distances[i] < minimalWeight) {
                    minimalIndex = i;
                    minimalWeight = distances[i];
                }
            }

            if (minimalIndex != INT_MAX) {
                for (int i = 0; i < VERTICES; ++i) {
                    if (matrix[minimalIndex][i]) {
                        int temp = minimalWeight + matrix[minimalIndex][i];

                        if (temp < distances[i])
                            distances[i] = temp;
                    }
                }

                visited[minimalIndex] = true;
            }
        } while (minimalIndex < INT_MAX);

        for (int i = START + 1; i < VERTICES; ++i) {
            if (distances[i] != INT_MAX) {
            mx_printstr("========================================\n");
            mx_printstr("Path: ");
            mx_printstr(str_of_isl[START]);
            mx_printstr(" -> ");
            mx_printstr(str_of_isl[i]);
            mx_printchar('\n');
            mx_printstr("Route: ");
            printPath(START, i, matrix, distances, str_of_isl, size);
            mx_printstr("\nDistance: ");
            mx_printint(distances[i]);
            mx_printchar('\n');
            mx_printstr("========================================\n");
            }
        }
        free(distances);
        free(visited);
    }
}



