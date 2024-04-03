#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "double_read.h"
#include "double_vector.h"
#include "distance.h"

using namespace std;

int main() {
    vector<double_vector> vectors;
    ifstream file("vectors1.txt");
    int id = 0;

    
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return -1;
    }

    
    while (file) {
        vector<double> elements = doubles_read_one_line(file);
        if (!elements.empty()) {
            vectors.emplace_back(elements, id++);
        }
    }
    file.close();

    vector<my_distance> distances;

    
    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            double dist = cosine_distance(vectors[i], vectors[j]);
            distances.emplace_back(vectors[i].id, vectors[j].id, dist);
        }
    }

    
    sort(distances.begin(), distances.end(), [](const my_distance& a, const my_distance& b) {
        return a.cos_distance < b.cos_distance;
    });

    
    for (const auto& dist : distances) {
        cout << "Pair (" << dist.id_1 << ", " << dist.id_2 << ") with cosine distance: " << dist.cos_distance << endl;
    }

    return 0;
}