#include <iostream>
#include <fstream>
#include <vector>

std::ifstream in;
std::ofstream out;

std::vector<int> cycle = {};
int points = 0;

void CICLU_EULERIAN(std::vector<std::vector<int>>& graph, int point) {
    for (int i = 0; i < (int) graph.size(); i++) {
        if (graph[point][i]) {
            graph[point][i] = graph[i][point] = 0;
            CICLU_EULERIAN(graph, i);
        }
    }

    cycle[++points] = point;
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
    cycle = std::vector<int>(nodes);

    int x, y;
    for (int i = 0; i < edges; i++) {
        in >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    CICLU_EULERIAN(graph, 0);
    for (int i = 1; i < points; i++) {
        out << cycle[i] << ' ';
    }

    return 0;
}
