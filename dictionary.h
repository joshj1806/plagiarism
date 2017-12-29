#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <regex>

using namespace std;
class synonymDictionary {
    public:
        synonymDictionary(string filename);
        string find(string s) const;
    private:
        virtual vector<vector<string> > inputToVector(ifstream &input);
        virtual void buildDictionary(vector<vector<string> > strs);
        map<string, string> dic;
};
#endif
