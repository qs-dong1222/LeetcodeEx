#include <iostream>
#include <vector>

using namespace std;
string FillUpLine(vector<string>& words, int maxWidth, int startIdx, int endIdx);
vector<string> fullJustify(vector<string>& words, int maxWidth);

int main(){

    vector<string> words =
    //{"This", "is", "an", "example", "of", "text", "justification."};
    {"My","momma","always","said,","\"Life","was","like","a","box","of","chocolates.","You","never","know","what","you're","gonna","get."};

    vector<string> ans = fullJustify(words, 20);
    for(auto each : ans){
        cout << each << endl;
    }


    return 0;
}



vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    if(words.empty() || maxWidth==0) return vector<string>(1,"");

    int i=0;
    int startIdx = i;
    int currLen = -1;
    while(true){
        if(words[i].size() > maxWidth) break;
        if(currLen + 1 + words[i].size() > maxWidth){
            ans.push_back(FillUpLine(words, maxWidth, startIdx, i-1));
            ///////////////////////////
//            cout << FillUpLine(words, maxWidth, startIdx, i-1) << endl;
            ///////////////////////////
            startIdx = i;
            currLen = -1;
        }
        else{
            currLen = currLen + 1 + words[i].size();
            i++;
            if(i==words.size()){
//                cout <<"*******"<<words[i-2]<<"********"<< endl;
                ans.push_back(FillUpLine(words, maxWidth, startIdx, i-1));
                ///////////////////////////
//                cout << FillUpLine(words, maxWidth, startIdx, i-1) << endl;
                ///////////////////////////
                break;
            }
        }
    }

    return ans;
}



string FillUpLine(vector<string>& words, int maxWidth, int startIdx, int endIdx){
    int nWords = endIdx-startIdx+1;
    string res;
    int charLen = 0;
    for(int i=startIdx; i<=endIdx; i++) charLen += words[i].size();

    if(nWords==1 || endIdx==words.size()-1){
        if(nWords==1)
            res.append(words[startIdx]);
        else{
            for(int i=startIdx; i<endIdx; i++){
                res.append(words[i]);
                res.append("~");
                charLen++;
            }
            res.append(words[endIdx]);
        }
        for(int i=0; i<maxWidth-charLen; i++)
            res.append("~");
        return res;
    }



    if(nWords==2){
        res.append(words[startIdx]);
        for(int i=0; i<maxWidth-charLen; i++) res.append("~");
        res.append(words[endIdx]);
        return res;
    }

    int nSpace = maxWidth - charLen;
    int nSlot = nWords-1;
    int avgNspace = nSpace/nSlot;
    int nAdded = nSpace % nSlot;

    string largeSpliter;
    for(int j=0; j<avgNspace+1; j++) largeSpliter.append("~");
    string smallSpliter;
    for(int j=0; j<avgNspace; j++) smallSpliter.append("~");

    // normal line build up
    for(int i=startIdx; i<endIdx; i++){
        res.append(words[i]);
        if(i<startIdx+nAdded)
            res.append(largeSpliter);
        else
            res.append(smallSpliter);
    }
    res.append(words[endIdx]);

    return res;
}

