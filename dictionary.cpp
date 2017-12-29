#include "dictionary.h"
using namespace std;

synonymDictionary::synonymDictionary(string file)
{
    ifstream synonyms(file);
    vector<vector<string> > strs = inputToVector(synonyms);
    buildDictionary(strs); 
}

string synonymDictionary::find(string s) const
{
    map<string, string>::const_iterator it;
    it = dic.find(s);

    if (it != dic.end())
    {
        return it->second; 
    }
    else 
    {
        return s;
    }
}

vector<vector<string> > synonymDictionary::inputToVector(ifstream &input)
{
    vector<vector<string> > lines; 
    string line;
    regex reg("\\s+");

    if(input.is_open())
    {
        while (getline(input, line))
        {
            sregex_token_iterator iter(line.begin(), line.end(), reg, -1);
            sregex_token_iterator end;

            vector<string> vec(iter, end);
            lines.push_back(vec);
       }
        input.close();
    } else {
        cout << "Unable to open the file";
    }
    return lines;
}

void synonymDictionary::buildDictionary(vector<vector<string> > strs)
{
    int n = strs.size();
    for(int row = 0; row < n; row++)
    {
        int groupSize = strs[row].size();
        string val = strs[row][0];
        for(int col = 0; col < groupSize; col++)
        {
            dic.insert(pair<string,string>(strs[row][col], val));
        }
    } 
} 
