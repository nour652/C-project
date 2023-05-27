#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 20
#define MAX_VERTICES 3 * MAX_N + 2
#define INF 1e9

typedef struct {
    double x, y;
} Point;

typedef struct {
    int from, to;
    double weight;
} Edge;

typedef struct {
    Edge edges[MAX_VERTICES * MAX_VERTICES];
    int n, m;
} Graph;

typedef struct {
    double dist;
    int prev;
} Result;

Graph graph;
Point points[MAX_VERTICES];
Result results[MAX_VERTICES];

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void add_edge(int from, int to, double weight) {
    graph.edges[graph.m].from = from;
    graph.edges[graph.m].to = to;
    graph.edges[graph.m].weight = weight;
    graph.m++;
}

void build_graph(int n, Point start, Point end) {
    graph.n = 2 * n + 2;
    graph.m = 0;

    // Add edges between start and rectangles
    for (int i = 0; i < n; i++) {
        Point a = points[3 * i];
        Point b = points[3 * i + 1];
        Point c = points[3 * i + 2];

        double d1 = distance(start, a);
        double d2 = distance(start, b);
        double d3 = distance(start, c);

        double min_distance = fmin(d1, fmin(d2, d3));

        add_edge(0, i + 1, min_distance);
    }

    // Add edges between rectangles
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Point a = points[3 * i];
            Point b = points[3 * i + 1];
            Point c = points[3 * i + 2];

            Point d = points[3 * j];
            Point e = points[3 * j + 1];
            Point f = points[3 * j + 2];

            double distance_ab = distance(a, b);
            double distance_bc = distance(b, c);
            double distance_cd = distance(c, d);
            double distance_de = distance(d, e);
            double distance_ef = distance(e, f);
            double distance_fa = distance(f, a);

            if (distance_ab < distance_cd) {
                add_edge(i + 1, j + 1, distance_ab);
            } else {
                add_edge(i + 1, j + 1, distance_cd);
            }

            if (distance_bc < distance_de) {
                add_edge(i + 1, j + 1, distance_bc);
            } else {
                add_edge(i + 1, j + 1, distance_de);
            }

            if (distance_cd < distance_ef) {
                add_edge(i + 1, j + 1, distance_cd);
            } else {
                add_edge(i + 1, j + 1, distance_ef);
            }

            if (distance_de < distance_fa) {
                add_edge(i + 1, j + 1, distance_de);
            } else {
                add_edge(i + 1, j + 1, distance_fa);
            }
        }
    }

    // Add edges between rectangles and end
    for (int i = 0; i < n; i++) {
        Point a = points[3 * i];
        Point b = points[3 * i + 1];
        Point c = points[3 * i + 2];

        double d1 = distance(end, a);
        double d2 = distance(end, b);
        double d3 = distance(end, c);

        double min_distance = fmin(d1, fmin(d2, d3));

        add_edge(i + 1, 2 * n + 1, min_distance);
    }
}

    void dijkstra(int start) {
    for (int i = 0; i < graph.n; i++) {
        results[i].dist = INF;
        results[i].prev = -1;
    }

    results[start].dist = 0;

    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < graph.n; i++) {
        int u = -1;
        for (int j = 0; j < graph.n; j++) {
            if (!visited[j] && (u == -1 || results[j].dist < results[u].dist)) {
                u = j;
            }
        }

        if (results[u].dist == INF) {
            break;
        }

        visited[u] = 1;

        for (int j = 0; j < graph.m; j++) {
            int from = graph.edges[j].from;
            int to = graph.edges[j].to;
            double weight = graph.edges[j].weight;

            if (from == u && results[u].dist + weight < results[to].dist) {
                results[to].dist = results[u].dist + weight;
                results[to].prev = u;
            }
        }
    }
}

int main() {
    int scenario = 1;

    while (1) {
        int n;
        scanf("%d", &n);

        if (n == -1) {
            break;
        }

        Point start, end;
        scanf("%lf %lf %lf %lf", &start.x, &start.y, &end.x, &end.y);

        for (int i = 0; i < n; i++) {
            scanf("%lf %lf %lf %lf %lflf", &points[3 * i].x, &points[3 * i].y, &points[3 * i + 1].x, &points[3 * i + 1].y, &points[3 * i + 2].x, &points[3 * i + 2].y);
        }

        build_graph(n, start, end);
        dijkstra(0);

        printf("Scenario #%d\n", scenario);
        printf("  route distance: %.2lf\n", results[2 * n + 1].dist);
        printf("\n");

        scenario++;
    }

    return 0;
}




