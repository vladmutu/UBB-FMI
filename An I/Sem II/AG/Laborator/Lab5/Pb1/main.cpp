#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream in;
ofstream out;

bool BFS(vector<vector<int>>& graph, int source, int destination, vector<int>& parent) {
    queue<int> queue;
    int size = (int) parent.size();
    vector<bool> visited(size, false);

    visited[source] = true;
    parent[source] = -1;

    queue.push(source);
    while (!queue.empty()) {
        int curr = queue.front();
        queue.pop();

        for (int i = 0; i < size; i++) {
            if (!visited[i] && graph[curr][i] > 0) {
                if (i == destination) {
                    parent[i] = curr;
                    return true;
                }

                queue.push(i);
                parent[i] = curr;
                visited[i] = true;
            }
        }
    }

    return false;
}

int FORD_FULKERSON(vector<vector<int>>& graph, int source, int destination) {
    int max_flow = 0;
    int size = (int) graph.size();
    vector<int> parent(size);

    while (BFS(graph, source, destination, parent)) {
        int path_flow = INT_MAX;

        for (int i = destination; i != source; i = parent[i]) {
            int temp = parent[i];
            path_flow = min(path_flow, graph[temp][i]);
        }

        for (int i = destination; i != source; i = parent[i]) {
            int temp = parent[i];
            graph[temp][i] -= path_flow;
            graph[i][temp] += path_flow;
        }

        max_flow += path_flow;
    }


    return max_flow;
}

int main(int argc, char* argv[]) {
    in.open(argv[1]);
    out.open(argv[2]);
    int nodes, edges;
    in >> nodes >> edges;

    vector<vector<int>> graph(nodes, std::vector<int>(nodes));

    int x, y, capacity;
    for (int i = 0; i < edges; i++) {
        in >> x >> y >> capacity;
        graph[x][y] = capacity;
    }

    int max_flow = FORD_FULKERSON(graph, 0, nodes - 1);
    out << max_flow;

    return 0;
}
