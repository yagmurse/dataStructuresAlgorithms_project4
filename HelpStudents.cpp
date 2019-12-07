/*
Student Name:
Student Number:
Project Number: 4
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "HelpStudents.h"
#include <limits>;
#include <queue>;
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
         p.first=ways[i].first.second;
         p.second=ways[i].second;
         vec[(ways[i].first.first)-1].push_back(p);
         p.first=ways[i].first.first;
         vec[(ways[i].first.second)-1].push_back(p);
 }

}

long long int HelpStudents::firstStudent() {
    // IMPLEMENT ME!
    vector<int> costNode;
    vector<int> visited;
    for(int i=0;i<N;i++) {
        visited.push_back(0);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<N;i++) {
       costNode.push_back((i==0 ? 0 : INF));
    }
    pq.push(make_pair(costNode[0],0));
    while (!pq.empty()) {
        pair<int,int> tmp=pq.top();
        //vertex: tmp.second cost:temp.first
        pq.pop();
        visited[tmp.second]=1;
        for(int i=0;i<(int)vec[tmp.second].size();i++) {
            int vertex=vec[tmp.second][i].first;
            int edgeDist=vec[tmp.second][i].second;
            int cost=edgeDist+costNode[tmp.second];
            if(cost<costNode[vertex] && visited[vertex] != 1) {
                costNode[vertex]=cost;
            }
            pq.push(make_pair(costNode[vertex],vertex));

        }
    }

    }






long long int HelpStudents::secondStudent() {
    // IMPLEMENT ME!
}
long long int HelpStudents::thirdStudent() {
    // IMPLEMENT ME!
}
long long int HelpStudents::fourthStudent() {
    // IMPLEMENT ME!
}
long long int HelpStudents::fifthStudent() {
    // IMPLEMENT ME!
}

// YOU CAN ADD YOUR HELPER FUNCTIONS