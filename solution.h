#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <list>
#include <sys/time.h>
#include <queue>
#include <time.h>

using namespace std;

class Solution {

public:
    // 以廣度優先探索遍歷資料集
    bool isBipartite_BFS(vector<vector<bool> > G, int source);

    // 以深度優先探索遍歷資料集
    bool isBipartite_DFS(vector<vector<bool> > G);
    bool colorGraph(vector<vector<bool> > G, int pos, int c);

    // 找尋最大匹配
    bool bpm(vector<vector<bool> > bpGraph, int u, bool seen[], int matchR[]);
    // bool bpm(vector<vector<bool> > bpGraph, int u, vector<bool> seen, vector<int> matchR);
    int maxBPM(vector<vector<bool> > bpGraph);

    // 找尋無向圖中的 Connected Graph 個數，並輸出 Components 的集合
    int merge(vector<int> parent, int x);
    int connectedcomponents(int n, vector<vector<int> >& edges, vector<vector<bool> > G);

    // 創建一個 V_color 陣列來存取各點著色
    // 陣列的 index 為各點的標號，陣列的值則表示顏色
    // -1: 未著色；1: 紅色；0: 藍色
    static vector<int> V_color;
};
 


