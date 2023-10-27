void mx_simple_pathfinding_algorithm(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 2147483647) {
                for (int k = 0; k < size; k++) {
                    if ((matrix[i][k] > matrix[i][j] + matrix[j][k] || matrix[i][k] == 2147483647) && matrix[j][k] != 2147483647 && (i != k)) {
                        matrix[i][k] = matrix[i][j] + matrix[j][k];
                    }
                }      
            }
        }
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if (matrix[i][j] == 2147483647) {
                matrix[i][j] = 0;
            }
        }
    }
}




