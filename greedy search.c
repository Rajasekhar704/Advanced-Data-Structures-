#include <stdio.h>
#define MAX 10
#define INF 9999

/* Find vertex with minimum distance not yet visited */
int minDistance(int dist[], int visited[], int n)
{
    int i;
    int min = INF, index = -1;

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

/* Dijkstra's algorithm */
void dijkstra(int graph[MAX][MAX], int n, int src)
{
    int i, v, count;
    int dist[MAX], visited[MAX];

    /* Initialize distances and visited array */
    for(i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for(v = 0; v < n; v++)
        {
            if(!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    /* Print distances */
    printf("\nVertex\tDistance from Source\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main()
{
    int i, j;
    int n, graph[MAX][MAX], src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}
