#include <stdio.h>
#include <stdbool.h>

#define MAX_NODE 30

int graph[MAX_NODE][MAX_NODE]; // adjacency matrix representing the graph

// perform depth-first search to count the number of different routes between two nodes
int dfs(int start, int end, bool visited[]) {
    if (start == end) { // if we've reached the end node, return 1
        return 1;
    }
    visited[start] = true; // mark the current node as visited
    int total_routes = 0;
    for (int i = 0; i < MAX_NODE; i++) {
        if (graph[start][i] && !visited[i]) { // if there's a directed edge from start to i and i hasn't been visited yet
            total_routes += dfs(i, end, visited); // recursively call dfs on i
        }
    }
    visited[start] = false; // unmark the current node as visited
    return total_routes;
}

int main() {
    int n; // number of one-way streets in the city
    int k = 0; // city number
    while (scanf("%d", &n) == 1) { // read input until end-of-file
        k++; // increment the city number
        // initialize the graph
        for (int i = 0; i < MAX_NODE; i++) {
            for (int j = 0; j < MAX_NODE; j++) {
                graph[i][j] = 0;
            }
        }
        // read the one-way streets
        int max_node = -1;
        for (int i = 0; i < n; i++) {
            int j, k;
            scanf("%d %d", &j, &k);
            graph[j][k] = 1;
            if (j > max_node) max_node = j;
            if (k > max_node) max_node = k;
        }
        // solve the problem for the current city
        printf("matrix for city %d\n", k-1);
        for (int i = 0; i <= max_node; i++) {
            for (int j = 0; j <= max_node; j++) {
                if (i == j) { // there's only one route from a node to itself
                    printf("1 ");
                } else if (!graph[i][j]) { // there's no route from i to j
                    printf("0 ");
                } else {
                    bool visited[MAX_NODE] = {false}; // reset the visited array
                    int num_routes = dfs(i, j, visited);
                    if (num_routes == 0) { // there's no route from i to j
                        printf("0 ");
                    } else if (num_routes > 1000000) { // there are too many routes to count
                        printf("-1 ");
                    } else { // print the number of different routes
                        printf("%d ", num_routes);
                    }
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
