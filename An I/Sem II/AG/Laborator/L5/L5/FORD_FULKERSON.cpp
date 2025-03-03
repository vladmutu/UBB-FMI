#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

std::ifstream in;
std::ofstream out;

bool BFS(std::vector<std::vector<int>>& graph, int source, int destination, std::vector<int>& parent) {
    std::queue<int> queue;

    int size = (int) parent.size();
    std::vector<bool> visited(size, false);

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

int FORD_FULKERSON(std::vector<std::vector<int>>& graph, int source, int destination) {
    int max_flow = 0;
    int size = (int) graph.size();
    std::vector<int> parent(size);

    while (BFS(graph, source, destination, parent)) {
        int path_flow = INT_MAX;

        for (int i = destination; i != source; i = parent[i]) {
            int temp = parent[i];
            path_flow = std::min(path_flow, graph[temp][i]);
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
    if (argc != 3) {
        std::cerr << "[ERROR] Invalid number of arguments\n";
        std::cerr << "[USAGE] $1 - input file | $2 - output file\n";
        exit(1);
    }

    in.open(argv[1]);
    if (!in.is_open()) {
        std::cerr << "[ERROR] Unable to open file\n";
    }

    out.open(argv[2]);
    if (!out.is_open()) {
        std::cerr << "[ERROR] Unable to open file\n";
    }

    int nodes, edges;
    in >> nodes >> edges;

    std::vector<std::vector<int>> graph(nodes, std::vector<int>(nodes));

    int x, y, capacity;
    for (int i = 0; i < edges; i++) {
        in >> x >> y >> capacity;
        graph[x][y] = capacity;
    }

    int max_flow = FORD_FULKERSON(graph, 0, nodes - 1);
    out << max_flow;

    return 0;
}
