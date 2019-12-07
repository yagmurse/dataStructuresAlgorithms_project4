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
using namespace std;
const int INF = numeric_limits<int>::max();
HelpStudents::HelpStudents(int  N, int  M, int K, vector < pair< pair <int,int> , int > > ways) {
    // IMPLEMENT ME!
    pair <int,int> p;
    this->K=K;
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
    vector<int> costNode;

    vector<int> visited;

    for(int i=0;i<N;i++) {
        visited.push_back(0);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<N;i++) {
       costNode.push_back(0);
    }
    int c=costNode[0];

    pq.push(make_pair(0,0));
    while (!pq.empty()) {
        pair<int,int> tmp=pq.top();
        int cost=tmp.first;
        int vertex=tmp.second;
        //vertex: tmp.second............. cost:temp.first
        pq.pop();
        if(visited[vertex]==1){
        continue;}

        visited[vertex]=1;
        costNode[vertex] = cost;
            for (int i = 0; i < (int) vec[vertex].size(); i++) {
                int v = vec[vertex][i].first;
                if (visited[v] == 1) {
                    continue; }

                    int c = vec[vertex][i].second + cost;
                    pq.push(make_pair(c, v));


        }


    }

    long long int m;
    m=costNode[K-1];
    return m;


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