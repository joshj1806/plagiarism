#ifndef TUPLESET_H 
#define TUPLESET_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
using namespace std;
class tupleSet {
    public:
        tupleSet(vector<vector<string> > lines, int n);
        string find(string tuple);
        int size() { return ts.size(); }
        string operator[] (int i) {
            set<string>::iterator it = ts.begin();
            advance(it, i);
            return *it;
        }

    private:
        set<string> ts; 
        void tupleInLine(vector<string> line, int n);
};
#endif
