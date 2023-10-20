#include "../inc/pathfinder.h"

void print_distance(int* path, int** matrix) {
    int sum = 0;
    int i = 0;
    int num_bridges = 0;

    while (path[i + 1] != -1) {
        int left = path[i];
        int right = path[i + 1];
        sum += matrix[left][right];
        num_bridges++;

        if (path[i + 2] != -1) {
            mx_printint(matrix[left][right]);
            mx_printstr(" + ");
        } else {
            mx_printint(matrix[left][right]);

            if (num_bridges > 1) {
                mx_printstr(" = ");
                mx_printint(sum);
            }
        }
        i++;
    }
}

void printPath(int start, int end, int** matrix, int* distances, char** str_of_isl, int size, int* path) {
    int VERTICES = size;
    if (end == start) {
        mx_printstr(str_of_isl[end]);
        path[0] = start;
        path[1] = -1;
        }
    else {
        for (int j = 0; j < VERTICES; ++j) {
            if (matrix[j][end]) {
                int temp = distances[end] - matrix[j][end];
                if (temp == distances[j]) {
                    printPath(start, j, matrix, distances, str_of_isl, VERTICES, path);
                    mx_printstr(" -> ");
                    mx_printstr(str_of_isl[end]);
                    int i = 0;
                    while (path[i] != -1) {
                            i++;
                    }
                    path[i] = end;
                    path[i + 1] = -1;
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

        int* path = (int*)malloc(size*sizeof(int));
        for (int i = 0; i < size; i++) {
            path[i] = -1;
        }

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
                printPath(START, i, matrix, distances, str_of_isl, size, path);
                mx_printstr("\nDistance: ");
                print_distance(path, matrix);
                mx_printchar('\n');
                mx_printstr("========================================\n");
            }
        }
        free(distances);
        free(visited);
        free(path);
    }
}






