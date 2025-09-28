#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    string reversed = "";

    vector<string> words;
    string word = "";
    bool inside = false;
    for(int i = 0; i < s.size(); i++){
        if(inside && s[i]==' '){
            words.push_back(word);
            word = "";
            inside = false;
        }
        if(s[i] != ' '){
            inside = true;
            word += s[i];
        }
    }
    if(word != "") words.push_back(word);

    for(int i = words.size()-1; i >= 0; i--){
        reversed += words[i];
        if(i != 0) reversed += " ";
    }

    return reversed;
}

int main(){
    // Given a string of words, reverse the order of them but the words should be intact. Input can contain any amount of spaces anywhere but output should be properly trimmed from both side and only single space between words.
    string str = "  a good   example  "; // return "example good a"

    // My solution: O(n + w), O(n + w), where w is the number of words
    // Store all the words in a vector, iterate from the back and add the words with single space(except for the first word which will be last in reversed string) to the reversed string
    cout<<reverseWords(str);

    // There is an alternative solution without the vector, you just reverse the string, then iterate thorugh it and reverse each word, altho the time complexity increases but space complexity decreases.

    cout<<"\n\n";
    return 0;
}