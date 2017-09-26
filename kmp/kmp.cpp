#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
using namespace std;

void BuildPatchMatchTable(int *partMatchTable, char *findstr)
{
    if(findstr == NULL)
        return;
    partMatchTable[0] = 0;
    int sizefind = strlen(findstr);
    for(int i = 1; i < sizefind; ++i)
    {
        set<string> preset;
        string tmppre = "";
        tmppre = findstr[0];
        preset.insert(tmppre);
        for(int j = 1; j < i; ++j)
        {
            tmppre = tmppre + findstr[j];
            preset.insert(tmppre);
        }

        set<string> postset;
        string tmppost = "";
        tmppost = findstr[i];
        postset.insert(tmppost);
        for(int j = i - 1; j > 0; --j)
        {
            tmppost =  findstr[j] + tmppost;
            postset.insert(tmppost);
        }
        set<string> comset;
        for(set<string>::iterator beg = preset.begin(); beg != preset.end(); ++beg)
        {
            if(postset.count(*beg) > 0)
                comset.insert(*beg);
        }
        int maxlen = 0;
        for(set<string>::iterator beg = comset.begin(); beg != comset.end(); ++beg)
        {
            if((*beg).size() > maxlen)
                maxlen = (*beg).size();
        }
        partMatchTable[i] = maxlen;
    }
}    

int kmp(char *srcstr, char *findstr)
{
    if(srcstr == NULL || findstr == NULL)
        return -1;
    int lensrc = strlen(srcstr);
    int lenfind = strlen(findstr);
    int *partMatchTable = new int[lenfind];
    BuildPatchMatchTable(partMatchTable, findstr);
    for(int i = 0; i < lenfind; ++i)
        cout << findstr[i] << "\t" << partMatchTable[i] << endl;
    int curFind = 0;
    for(int i = 0; i < lensrc; )
    {
        if(findstr[curFind] == srcstr[i])
        {
            ++i;
            ++curFind;
        }
        else
        {
            if(curFind == 0)
                ++i;
            else
            {
                int movestep = curFind - partMatchTable[curFind-1];
                i += movestep;
                curFind = 0;
            }
        }
        if(curFind == lenfind)
        {
            delete []partMatchTable;
            return i - lenfind;
        }
    }
    return -1;
    delete []partMatchTable;
}
int main()
{
    char srcStr[] = "bbc abcdab abcdabcdabde";
    char findStr[] = "abcdabd";
    cout << "pos:" << kmp(srcStr, findStr) << endl;

    char srcStr2[] = "bbc abcdab abcdabcdabdezzz";
    char findStr2[] = "zzz";
    cout << "pos:" << kmp(srcStr2, findStr2) << endl;

    char srcStr3[] = "bbc abcdab abcdabcdabde";
    char findStr3[] = "zzz";
    cout << "pos:" << kmp(srcStr3, findStr3) << endl;
}