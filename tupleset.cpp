#include "tupleset.h"
using namespace std;

tupleSet::tupleSet(vector<vector<string> > lines, int n)
{
    int r = lines.size();
    for (int row = 0; row < r; row++)
    {
        tupleInLine(lines[row], n);
    }
}

void tupleSet::tupleInLine(vector<string> line, int n)
{
    int e = line.size();
    int te = n-1;
    for(int i = 0; i < e && te < e; i++, te++)
    {
        string tu;
        for(int t = i; t <= te; t++)
        {
            tu +=line[t]+" ";
        }
        ts.insert(tu);
    }
}

string tupleSet::find(string tuple)
{
    set<string>::const_iterator it = ts.find(tuple);
    if(it != ts.end()) 
        return *it;
    else
        return "";
} 
