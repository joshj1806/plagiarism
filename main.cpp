#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "dictionary.h"
#include "tupleset.h"
using namespace std;

string usage = "Missing input files. It requires at least 3 files.\n 1. file name for a list of synonyms\n 2. input file 1\n 3. input file 2\n (optional) the number N, the tuple size.  If not supplied, the default should be N=3. "; 

vector<vector<string> > replaceSynonyms(const synonymDictionary &dict, string file);
float compareTupleSet(tupleSet audited, tupleSet auth);

int main(int argc, char* argv[])
{  
    if (argc < 4)
    {
        cout << usage << endl;
        return 0;
    }

    const synonymDictionary synDic(argv[1]); 

   vector<vector<string> > audited = replaceSynonyms(synDic, argv[2]);
   vector<vector<string> > authoritative = replaceSynonyms(synDic, argv[3]);

   int tupleSize = 3;
   if(argv[4]) 
       tupleSize = stoi(argv[4]);

   tupleSet f1(audited, tupleSize);
   tupleSet f2(authoritative, tupleSize);

   float result = compareTupleSet(f1, f2);

   cout << result*100 << " % " << endl;
   
   return 0; 
}

vector<vector<string> > replaceSynonyms(const synonymDictionary &dict, string file)
{
    ifstream input(file);
    string word;
    string line;
    vector<vector<string> > lines;

    if(input.is_open())
    {
        while(getline(input,line))
        {
            stringstream iss(line);
            vector<string> l;
            while (getline(iss, word, ' '))
            {
                word = dict.find(word);
                l.push_back(word);
            }
            lines.push_back(l);
       }
       
    } else {
        cout << "Unable to open " << file << endl; 
    }

    return lines;
}

float compareTupleSet(tupleSet audited, tupleSet auth)
{
   int audited_size = audited.size();
   int found = 0;
   for (int i = 0; i < audited_size; i++)
   {
       if (auth.find(audited[i]) != "")
       {
           found++; 
       }
   }

   return (float) found/audited_size; 
}


