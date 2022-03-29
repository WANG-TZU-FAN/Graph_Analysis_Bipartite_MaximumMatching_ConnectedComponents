#include "graph_input.h"

using namespace std;

// for calculating the execution time of this program
struct timespec diff(struct timespec start, struct timespec end) {
  struct timespec temp;
  if ((end.tv_nsec-start.tv_nsec)<0) {
    temp.tv_sec = end.tv_sec-start.tv_sec-1;
    temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
  } else {
    temp.tv_sec = end.tv_sec-start.tv_sec;
    temp.tv_nsec = end.tv_nsec-start.tv_nsec;
  }
  return temp;
}

int main()
{
    Solution S;
    vector<vector<bool>> G_input;
    vector<vector<bool>> bpGraph_input;
    vector<vector<int>> edges_input;
    struct timespec time_start, time_end;
    double time_used_sub;
    int input_number;

    cout << "Which graph would you like to input: " << endl;
    cin >> input_number;

    if(input_number == 1){
        G_input = G;
        bpGraph_input = bpGraph;
        edges_input = edges;
    }

    else if(input_number == 2){
        G_input = G_2;
        bpGraph_input = bpGraph_2;
        edges_input = edges_2;
    }

    else if(input_number == 3){
        G_input = G_3;
        bpGraph_input = bpGraph_3;
        edges_input = edges_3;
    }

    else if(input_number == 4){
        G_input = G_4;
        bpGraph_input = bpGraph_4;
        edges_input = edges_4;
    }

    else if(input_number == 5){
        G_input = G_5;
        edges_input = edges_5;
    }

    else if(input_number == 6){
        G_input = G_6;
        edges_input = edges_6;
    }
    else if(input_number == 7){
        G_input = G_7;
        bpGraph_input = bpGraph_7;
        edges_input = edges_7;
    }
    else if(input_number == 8){
        G_input = G_8;
        bpGraph_input = bpGraph_8;
        edges_input = edges_8;
    }
    else if(input_number == 9){
        G_input = G_9;
        edges_input = edges_9;
    }
    else if(input_number == 10){
        G_input = G_10;
        bpGraph_input = bpGraph_10;
        edges_input = edges_10;
    }

    cout << "Result of the test" << endl;
    cout << "============================" << endl;
    // 計時器開始
    clock_gettime(CLOCK_MONOTONIC, &time_start);
    if(S.isBipartite_BFS(G_input, 0)) {
        cout << "According to BFS Algorithm, " << endl;
        cout << "The graph given is BIPARTITE." << endl;
        cout << "Time Consumed by BFS: ";
    }
    else {
        cout << "According to BFS Algorithm, " << endl;
        cout << "The graph given is NOT BIPARTITE." << endl;
        cout << "Time Consumed by BFS: ";
    }
    clock_gettime(CLOCK_MONOTONIC, &time_end);
    struct timespec temp = diff(time_start, time_end);
    time_used_sub = temp.tv_sec + (double) temp.tv_nsec / 1000000.0;
    cout << time_used_sub << "ms" << endl;
    // 計時器結束
    cout << "----------------------------" << endl;
    // 計時器開始
    clock_gettime(CLOCK_MONOTONIC, &time_start);
    if(S.isBipartite_DFS(G_input)) {
        cout << "According to DFS Algorithm, " << endl;
        cout << "The graph given is BIPARTITE." << endl;
        cout << "Time Consumed by DFS: ";
    }
    else {
        cout << "According to DFS Algorithm, " << endl;
        cout << "The graph given is NOT BIPARTITE." << endl;
        cout << "Time Consumed by DFS: ";
    }
    clock_gettime(CLOCK_MONOTONIC, &time_end);
    struct timespec temp2 = diff(time_start, time_end);
    time_used_sub = temp2.tv_sec + (double) temp2.tv_nsec / 1000000.0;
    cout << time_used_sub << "ms" << endl;
    // 計時器結束
    cout << "----------------------------" << endl;

    vector<int> Red_Group;
    vector<int> Blue_Group;

    if(S.isBipartite_DFS(G_input)) {
        for(int i = 0; i < G_input.size(); i++){
            if(S.V_color[i] == 1) {
                Red_Group.push_back(i);
            }
            else if(S.V_color[i] == 0) {
                Blue_Group.push_back(i);
            }
            else {
                cout << "fail";
            }
        }
        cout << "Red Group Members: ";
        for(int i = 0; i < Red_Group.size(); i++){
            if(i != Red_Group.size() - 1) {
                cout << Red_Group[i] + 1 << ",";
            }
            else {
                cout << Red_Group[i] + 1;
            }
        }
        cout << endl;
        cout << "Blue Group Members: ";
        for(int i = 0; i < Blue_Group.size(); i++){
            if(i != Blue_Group.size() - 1) {
                cout << Blue_Group[i] + 1 << ",";
            }
            else {
                cout << Blue_Group[i] + 1;
            }
        }
    }
    else {
        cout << "It cannot divide into 2 Groups!";
    }
    cout << endl;

    cout << "----------------------------" << endl;
    if(bpGraph_input.size()!=0) {
        cout << "Maximum Matching is " << S.maxBPM(bpGraph_input);
    }
    else {
        cout << "It is not Bipartite!" << endl;
        cout << "Please enter bipartite graph to calculate Maximum Match!";
    }
    cout << endl;

    cout << "----------------------------" << endl;
    
    int Component_Number = S.connectedcomponents(G_input.size(), edges_input, G_input);

    cout << "----------------------------" << endl;

    cout << "There are " << Component_Number << " components." << endl;

    cout << "============================" << endl;

    return 0;
}
