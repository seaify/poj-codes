#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 21;
const int MAXM = 10010;
const int KEYSIZE = 26;
struct Node {
     int id;
     Node *branch[KEYSIZE];
     Node() {
          id = -1;
          for(int i = 0; i < KEYSIZE; i ++)
               branch[i] = NULL;
     }
     ~Node() {
          delete []branch;
     }
};
struct Word {
     int wordLen;
     char word[MAXN];
     char newWord[MAXN];
     bool operator < (const Word &w) const {
          return wordLen < w.wordLen;
     }
}wo[MAXM];
struct Trie {
     Node *root;
     void insert(char *word, int id) {
          Node *temp = root;
          int i = 0;
          while(word[i]) {
               int num = word[i] - 'a';
               if(num < 0 || num >= 26) {
                    printf("invalid input\n");
                    return;
               }
               if(temp -> branch[num] == NULL)
                    temp -> branch[num] = new Node();
               temp = temp -> branch[num];
               i ++;
          }
          temp -> id = id;
          //printf("%d ++\n", temp -> id);
     }
     int query(char *word) {
          Node *temp = root;
          int i = 0;
          while(word[i]) {
               int num = word[i] - 'a';
               if(num < 0 || num >= 26) return -1;
               if(temp -> branch[num] == NULL) return -1;
               temp = temp -> branch[num];
               i ++;
          }
          //printf("@@@%d\n", temp -> id);
          return temp -> id;
     }
};
int main() {
     int cnt = 0;
     while(scanf("%s", wo[cnt].word) != EOF) {
          strcpy(wo[cnt].newWord, wo[cnt].word);
          wo[cnt].wordLen = strlen(wo[cnt].newWord);
          sort(wo[cnt].newWord, wo[cnt].newWord + wo[cnt].wordLen);
          cnt ++;
          //if(cnt == 11) break;
     }
     sort(wo, wo + cnt);
     //for(int i = 0; i < cnt; i ++)
          //printf("%s ==> %s\n", node[i].word, node[i].newWord);
     Trie trie;
     char str[MAXN];
     int i, j, k, end, maximum = 0;
     int best[MAXM], pre[MAXM];
     trie.root = new Node();
     memset(best, 0, sizeof(best));
     for(i = 0; i < cnt; i ++) {
          int last = -1, mx = 1;
          if(i == 0) {
               trie.insert(wo[i].newWord, i);
          }else {
               for(j = 0; j < wo[i].wordLen; j ++) {
                    strcpy(str, wo[i].newWord);
                    strcpy(&str[j], &str[j + 1]);
                    int id = trie.query(str);
                    if(id != -1 && best[id] + 1 > mx) {
                         mx = best[id] + 1;
                         last = id;
                    }
               }
               trie.insert(wo[i].newWord, i);
          }
          best[i] = mx;
          pre[i] = last;
          if(mx > maximum) {
               maximum = mx;
               end = i;
          }
     }
     stack<int> st;
     while(end != -1) {
          st.push(end);
          end = pre[end];
     }
     while(! st.empty()) {
          k = st.top();
          st.pop();
          printf("%s\n", wo[k].word);
     }
     return(0);
}


