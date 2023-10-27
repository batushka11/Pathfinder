void mx_simple_pathfinding_algorithm(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 999) {
                for (int k = 0; k < size; k++) {
                    if ((matrix[i][k] > matrix[i][j] + matrix[j][k] || matrix[i][k] == 999) && matrix[j][k] != 999 && (i != k)) {
                        matrix[i][k] = matrix[i][j] + matrix[j][k];
                    }
                }      
            }
        }
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if (matrix[i][j] == 999) {
                matrix[i][j] = 0;
            }
        }
    }
}


