#include "solution.h"

using namespace std;

vector<int> Solution:: V_color = {-1};

// BFS_Algorithm
bool Solution::isBipartite_BFS(vector<vector<bool> > G, int source)
{
    // V_color 陣列尚未著色的狀態
    for (int i = 0; i < G.size() - 1; ++i) {
        V_color.push_back(-1);
    }

    for(source = 0; source < G.size(); source++) {
        while(V_color[source] == -1) {
            // 將起點 source 著成紅色
            V_color[source] = 1;
            // 創造一個存放頂點的 queue 用來進行 BFS 演算法的遍歷
            queue <int> queue_BFS;
            // 將 source 的標號先放到 queue 裡
            queue_BFS.push(source);
            // 只要 queue 裡還有頂點就持續判斷
            while (!queue_BFS.empty())
            {
                // 先把 queue 裡的頂點拿出來另存，並把該點從 queue 中移除
                int u = queue_BFS.front();
                queue_BFS.pop();
                // 不能有 self-loop
                if (G[u][u] == 1)
                    return false;
                // 找出所有尚未被塗色的相鄰頂點
                for (int v = 0; v < G.size(); ++v) {
                    // 給定的圖 G edge 存在，而且 v 點尚未被著色
                    if (G[u][v] && V_color[v] == -1) {
                        // 相鄰兩點不同色
                        V_color[v] = 1 - V_color[u];
                        // 把新被著色的點放到 queue 裡
                        queue_BFS.push(v);
                    }
                    // 給定的圖 G edge 存在，而且 v 點已被著上與 u 點同樣的顏色
                    // 即表示此圖非二部圖
                    else if (G[u][v] && V_color[v] == V_color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    // 如果全部資料都遍歷完，都符合條件的話，此圖為二部圖
    return true;
}

bool Solution::colorGraph(vector<vector<bool> > G, int pos, int c) {
    
    if(V_color[pos] != -1 && V_color[pos] != c)
        return false;
    // 當前的點著色為 c，與該點相鄰的所有其他點著色為 1 - c
    V_color[pos] = c;
    bool ans = true;
    for(int i = 0; i < G.size(); i++) {
        if(G[pos][i]) {
            // 如果尚未著色
            if(V_color[i] == -1)
                ans &= colorGraph(G, i, 1 - c);
            // 如果已經著色，且被著成同一個顏色
            if(V_color[i] != -1 && V_color[i] != 1 - c)
                return false;
        }
        if (!ans)
            return false;
    }        
    return true;
}
 
bool Solution::isBipartite_DFS(vector<vector<bool> > G){
    // V_color 陣列尚未著色的狀態
    for(int i = 0; i < G.size(); i++) {
        V_color[i] = -1;
    }
    // 起點在第一個頂點 0
    int pos = 0;
    for(pos = 0; pos < G.size(); pos++) {
        while(V_color[pos] == -1) {
            if(!colorGraph(G, pos, 1)){
                return false;
            };
        }
    }
    return true;
}


// 如果和點 u 可能匹配（和點 u 相連），則 bpm (Bipartite Match) 判斷為 True
bool Solution::bpm(vector<vector<bool> > bpGraph, int u, bool seen[], int matchR[]) {
    // 將所有著藍色的點拿來做測試
    for (int v = 0; v < bpGraph[0].size(); v++){
        // 如果紅色的點 u，和藍色的點 v 相連，且 v 尚未被其他點相連
        if (bpGraph[u][v] && !seen[v]) {
            // 先將 v 標示為已配對
            seen[v] = true;
            // 如果藍色的點 v 沒有被其他點相連，或者先前與藍色的點相連的紅點（即 matchR[v]）有其他可以相連的點。
            // 由於 v 在上一行中被標記為已配對，因此 matchR[v] 將不會再次遞迴點 v
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

// 回傳最大匹配數
int Solution::maxBPM(vector<vector<bool> > bpGraph) {

    // 儲存與藍色的點相連的紅點
    // matchR[i] 是與藍色的點 i 相連的紅點數
    // 若為 -1 則該點沒有被相連
    int N = bpGraph[0].size();

    // 初始條件：所有的 v 點都可以被連線
    int matchR[N];
    memset(matchR, -1, sizeof(matchR));
    // 用來計算匹配數
    int result = 0;

    for (int u = 0; u < bpGraph.size(); u++) {
        // 對下一個紅點 u 初始化為尚未連接
        bool seen[N];
        memset(seen, 0, sizeof(seen));
        // 判斷紅點 u 是否匹配，有的話匹配數加一
        if (bpm(bpGraph, u, seen, matchR)) {
            result++;
        }
    }
    return result;
}

// 1. 定義一個大小為 G.size() 的數組 parent，其中 G.size() 是節點的總數。
// 2. 對於數組 parent 的每個索引 i，該值表示第 i 個頂點的父節點是誰。 比如 parent[1] = 3，那麼我們可以說頂點 1 的 parent 節點是 3。
// 3. 將每個節點初始化為自身的 parent 節點，然後在將它們相加的同時，相應地更改它們的 parent 節點。
int Solution::merge(vector<int> parent, int x)
{
    if (parent[x] == x)
        return x;
    return merge(parent, parent[x]);
}

int Solution::connectedcomponents(int n, vector<vector<int>>& edges, vector<vector<bool> > G)
{
    // 定義一個大小為 G.size() 的數組 arr，其中 G.size() 是節點的總數。
    vector<int> parent;
    // 將每個節點初始化為自身的 parent 節點
    for (int i = 0; i < G.size(); i++) {
        parent.push_back(i);
    }
    // 找出各個頂點的 parent
    for (auto x : edges) {
        parent[merge(parent, x[0])] = merge(parent, x[1]);
    }
    // 如果該節點為自身的 parent 節點，代表存在一個 Component
    int Component = 0;
    for (int i = 0; i < G.size(); i++) {
        Component += (parent[i] == i);
    }

    // 找出 parent 陣列，表示法為上述第二點所提及的
    for (int i = 0; i < G.size(); i++) {
        parent[i] = merge(parent, parent[i]);
    }

    // 定義一個 map，紀錄每個 parent 節點裡有哪些元素 
    map<int, list<int>> m;
    for (int i = 0; i < G.size(); i++) {
        m[parent[i]].push_back(i);
    }
    // 輸出各 Components 裡有哪些元素
    for (auto it = m.begin(); it != m.end(); it++) {
        list<int> l = it->second;
        int i = 1;
        cout << "Components => ";
        for (auto x : l) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
    return Component;
}