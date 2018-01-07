#include <stdio.h>
#include <stdbool.h>

void update_matrix(int matrix[1000][1000], int u, int v) {
    bool u_flag = false;
    bool v_flag = false;

    int i = 0;
    for (; i<1000; i++) {
        if (matrix[i][0] == 0) break;
        else if (!u_flag && matrix[i][0] == u) {
            u_flag = true;
            for (int j=1; j<1000; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = v;
                    break;
                }
            }
        }
        else if (!u_flag && matrix[i][0] == v) {
            v_flag = true;
            for (int j=1; j<1000; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = u;
                    break;
                }
            }
        }
    }
    if (!u_flag) {
        matrix[i][0] = u;
        matrix[i][1] = v;
        i++;
    }
    if (!v_flag) {
        matrix[i][0] = v;
        matrix[i][1] = u;
    }
}

bool is_bipartite_graph(int matrix[1000][1000]) {
    for (int i=0; i<1000; i++) {
        if (matrix[i][0] == 0) break;
        else {
            for (int j=i+1; j<1000; j++) {
                if (matrix[j][0] == 0) break;
                else {
                    // compare matrix[i] against matrix[j]
                    int count = 0;
                    for (int k=0; k<1000; k++) {
                        if (matrix[i][k] == 0) break;
                        else {
                            // count++ if matrix[i][k] exists in matrix[j] list
                            for (int l=0; l<1000; l++) {
                                if (matrix[j][l] == 0) break;
                                else if (matrix[j][l] == matrix[i][k]) {
                                    count++;
                                    break;
                                }
                            }
                        }
                    }
                    // printf("DEBUG: count = %d\n", count);
                    if (count > 2) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        int n, m;
        scanf("%d %d", &n, &m);

        int matrix[1000][1000] = { 0 };
        for (int j=0; j<m; j++) {
            int u, v;
            scanf("%d %d", &u, &v);

            // update matrix
            update_matrix(matrix, u, v);
        }

        // DEBUG: dump matrix
        /*
        for (int j=0; j<1000; j++) {
            if (matrix[j][0] == 0) break;
            else {
                for (int k=0; k<1000; k++) {
                    if (matrix[j][k] == 0) break;
                    else printf("%d ", matrix[j][k]);
                }
                printf("\n");
            }
        }*/

        // analyze matrix
        if (is_bipartite_graph(matrix)) printf("Yes\n");
        else printf("No\n");
    }
}
