class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.empty())
            return res;
        printS(str, 0, res);
        return res;
    }
    void printS(string str, int index, vector<string> &res){
        if(index == str.size())
            res.push_back(str);
        for(int i = index; i < str.size(); i++){
            if(i != index && str[i] == str[index])
                continue;
            char tmp = str[index];
            str[index] = str[i];
            str[i] = tmp;
            printS(str, index+1, res);
        }
    }
};