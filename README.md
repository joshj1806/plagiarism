# Plagiarism detector using a N-tuple comparison algorithm

## Design

 Hash map and set are data structure of choice in order to compare text in O(logN) time. Hash map is used to build the synonyms dictionary. This dictionary is referenced for replace a word with synonyms. Once the words are replaced to synonyms, the application begin to store tuples of N size. Both audited and authoritative tuples made out of given files are stored in set structure. 
Finally, these two sets are compared to get intersection of tuples. In other words, if a tuple appears in both set structure, it belongs to the intersection. The ratio of the number of tuples in the audited text and the intersection is the end result. For example, there are 5 tuples in the text and two of them are in the intersection, the ratio is 5:2 and the end result is 40%.

### Reusability

Virtual Functions are used for future extension. Synonym dictioanry can be made out different input sources other than file input. In that case using different implementation for the input keeps the application reusable in the future without major refactoring. 

### Scalability

Recently data storage has became cheaper resource than computation. To leverage this trend, this program uses extra space to build the synonyms dictionary and sets of tuples. 

## Performance
It's time complexity is O(N+logN).

## Assumptions and Limitations
1. Tuples are built on line not a paragraph nor entire text. For example, a line with 4 words have two 3-Tuples. If next line has the same number of words, the next line also has two 3-Tuples. Thus, four 3-Tuples are made out the text.

2. C++ 11 is required for building the application.

3. It only takes Mac/Linux text format and does not take MS-DOS format.
