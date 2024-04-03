#include "double_read.h"
#include <sstream>

vector<double> doubles_read_one_line(istream & in_stream) {
    string line;
    getline(in_stream, line);
    istringstream iss(line);
    vector<double> result;
    double value;
    while (iss >> value) {
        result.push_back(value);
    }
    return result;
}