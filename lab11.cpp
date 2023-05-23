#include <iostream>
#include <queue>
#include <vector>
#include <climits>

#define V 6

void printMST(const std::vector<int>& parent, const std::vector<std::vector<int>>& graph) {
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << std::endl;
    }
}

void primMST(const std::vector<std::vector<int>>& graph) {
    std::vector<int> parent(V, -1);
    std::vector<int> key(V, INT_MAX);
    std::vector<bool> mstSet(V, false);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    key[0] = 0;
    pq.push(std::make_pair(0, 0));

    while (!pq.empty()) {
        int source = pq.top().second;
        pq.pop();

        mstSet[source] = true;

        for (int destination = 0; destination < V; destination++) {
            if (graph[source][destination] && !mstSet[destination] && graph[source][destination] < key[destination]) {
                parent[destination] = source;
                key[destination] = graph[source][destination];
                pq.push(std::make_pair(key[destination], destination));
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    std::vector<std::vector<int>> graph = { { 0, 3, 0, 0, 0, 1 },
                                            { 3, 0, 2, 1, 10, 0 },
                                            { 0, 2, 0, 3, 0, 5 },
                                            { 0, 1, 3, 0, 5, 0 },
                                            { 0, 10, 0, 5, 0, 4 },
                                            { 1, 0, 5, 0, 4, 0 } };

    primMST(graph);

    return 0;
}