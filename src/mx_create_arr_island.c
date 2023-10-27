#include "../inc/pathfinder.h"

char** mx_get_unique_islands(bridges* bridgeArray, int numBridges) {
    char** uniqueIslands = (char**)malloc(numBridges * 2 * sizeof(char*));

    int uniqueCount = 0;

    for (int i = 0; i < numBridges; i++) {
        int found_l = 0;
        int found_r = 0;

        for (int j = 0; j < uniqueCount; j++) {
            if (mx_strcmp(bridgeArray[i].island_l, uniqueIslands[j]) == 0) {
                found_l = 1;
            }
            if (mx_strcmp(bridgeArray[i].island_r, uniqueIslands[j]) == 0) {
                found_r = 1;
            }
        }

        if (!found_l) {
            uniqueIslands[uniqueCount++] = mx_strdup(bridgeArray[i].island_l);
        }

        if (!found_r) {
            uniqueIslands[uniqueCount++] = mx_strdup(bridgeArray[i].island_r);
        }
    }

    return uniqueIslands;
}




