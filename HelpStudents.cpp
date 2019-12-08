/*
Student Name:
Student Number:
Project Number: 4
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "HelpStudents.h"
#include <limits>
#include <queue>
#include <stack>
using namespace std;
const int INF = numeric_limits<int>::max();
HelpStudents::HelpStudents(int  N, int  M, int K, vector < pair< pair <int,int> , int > > ways) {
    // IMPLEMENT ME!
    pair <int,int> p;
    this->K=K-1;
    this->M=M;
    this->N=N;

    vec.resize(N);
     for(int i=0;i<M;i++) {
         p.first=ways[i].first.second-1;
         p.second=ways[i].second;
         vec[(ways[i].first.first)-1].push_back(p);
         p.first=ways[i].first.first-1;
         vec[(ways[i].first.second)-1].push_back(p);
 }

}

long long int HelpStudents::firstStudent() {
    // IMPLEMENT ME!
    vector<long long int> costNode;
    vector<int> visited;
    for(int i=0;i<N;i++) {
        visited.push_back(0);
    }
    priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>> pq;
    for(int i=0;i<N;i++) {
       costNode.push_back(i==0 ? 0 :INF);
    }
     pq.push(make_pair(0,0));
    while (!pq.empty()) {
        pair<long long int,int> tmp=pq.top();
        long long int cost=tmp.first;
        int vertex=tmp.second;
        pq.pop();
        if(visited[vertex]==1)
        continue;
        visited[vertex]=1;
        costNode[vertex] = cost;
            for (int i = 0; i < (int) vec[vertex].size(); i++) {
                int v = vec[vertex][i].first;
                if (visited[v] == 1)
                    continue;
                long long int c = vec[vertex][i].second + cost;
                if(costNode[v]>c) {
                    pq.push(make_pair(c, v));
                costNode[vertex] = cost; }
            }
    }

    return costNode[K];


    }
long long int HelpStudents::secondStudent() {
    // IMPLEMENT ME!
    vector<long long int> minEdge;
    for(int i=0;i<N;i++) {
        minEdge.push_back(0);
    }
    vector<int> visited;
    for(int i=0;i<N;i++) {
        visited.push_back(0);
    }
     priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>> pq;
    pq.push(make_pair(0,0));
    while(!pq.empty()) {
        pair<long long int,int> tmp=pq.top();
        int vertex=tmp.second;
        long long int edge=tmp.first;
        pq.pop();
        if(visited[vertex]==1) {
            continue; }
        visited[vertex]=1;
        minEdge[vertex]=max(minEdge[vertex],edge);
        for (int i = 0; i < (int) vec[vertex].size(); i++) {
            int v = vec[vertex][i].first;
            if (visited[v] == 1)
                continue;

            long long  int c =vec[vertex][i].second;
            pq.push(make_pair(max(c,edge), v));
            minEdge[v]=min(minEdge[v],edge);
        }

    }

    return minEdge[K];


}
long long int HelpStudents::thirdStudent() {
    // IMPLEMENT ME!
    vector<long long int> minNumEdge;
    vector<int> visited;
    for(int i=0;i<N;i++) {
        visited.push_back(0);
    }
    priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>> pq;

    for(int i=0;i<N;i++) {
        minNumEdge.push_back(i==0 ? 0 :INF);
    }
    pq.push(make_pair(0,0));
    while (!pq.empty()) {
        pair<long long int,int> tmp=pq.top();
        long long int cost=tmp.first;
        int vertex=tmp.second;
        pq.pop();
        if(visited[vertex]==1)
            continue;
        visited[vertex]=1;

        minNumEdge[vertex] = min(cost,minNumEdge[vertex]);
        for (int i = 0; i < (int) vec[vertex].size(); i++) {
            int v = vec[vertex][i].first;
            if (visited[v] == 1)
                continue;
            long long int c = minNumEdge[vertex] + 1;
            pq.push(make_pair(c, v));
        }
    }

    return minNumEdge[K];
}
long long int HelpStudents::fourthStudent() {
    // IMPLEMENT ME!
    vector<int> nodeVisited;
    vector<vector<int>> edgeVisited;
    vector<int> totalCost;
    for(int i=0;i<N;i++) {
        totalCost.push_back(0);
    }
    edgeVisited.resize(N);
    for(int i=0;i<N;i++) {
        int m=(int)vec[i].size();
        for(int x=0;x<m;x++) {
           edgeVisited[i].push_back(0);
        }
    }

    for(int i=0;i<N;i++) {
        nodeVisited.push_back(-1);
    }

    priority_queue<pair<long long int,pair<int,int>>,vector<pair<long long int,pair<int,int>>>,greater<pair<long long int,pair<int,int>>>> pq;
    pq.push(make_pair(0,make_pair(0,0)));

    while (!pq.empty()) {
        pair<long long int,pair<int,int>> tmp=pq.top();
        pair<long long int,pair<int,int>> tmp2;

        pq.pop();

        if(tmp.first==pq.top().first &&  tmp.second.first>pq.top().first) {
                tmp2=tmp;
                tmp=pq.top();
                pq.pop();
                pq.push(tmp2);

        }

        long long int weight=tmp.first;
        int vertex=tmp.second.first;
        int prevVer=tmp.second.second;

        nodeVisited[vertex]=1;
        totalCost[vertex]+=tmp.first;
        edgeVisited[prevVer][vertex]=1;
        for(int i=0;i<(int)vec[vertex].size();i++) {
            int v=vec[vertex][i].first;
            if(edgeVisited[v][vertex] == 1 || edgeVisited[vertex][v]==1)
                continue;
            long long int c=vec[vertex][i].second;

            pq.push(make_pair(c,make_pair(v,vertex)));
        }


    }
    return ( nodeVisited[K-1] == -1) ? (-1) : (totalCost[K-1]);



}
long long int HelpStudents::fifthStudent() {
    // IMPLEMENT ME!
}

// YOU CAN ADD YOUR HELPER FUNCTIONS