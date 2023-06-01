#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>

using namespace std;

int vertices= 6; //number of cities
int infinity=INT_MAX;

void dijsktra(vector<vector<int>> graph, int source){
    vector<int> distances(vertices,infinity); // creating a vector to store the distances from the source city, initial values are infinity
    vector<bool> visited(vertices,false); //creating a vector to keep track of the vertices that has been visited

    distances[source]=0; //distance to the source city from itself is 0

    for(int i=0;i<vertices;i++){
        //finding the one that has the minimum distance that has not been visited
        int minDis=infinity;
        int minIndex=-1;

        for(int j=0;j<vertices;j++){
            if(!visited[j] && (distances[j]<minDis)){
                minDis=distances[j];
                minIndex=j;
            }
        }
        int u=minIndex; //storing the index of the city having minimum distance in the distance vector
        visited[u]=true; //mark it as visited

        //updating distance vector
        for(int k=0;k<vertices;k++){
            if(!visited[k] && graph[u][k]!=0){ //if the vertices from the vertice which having the shortest distance, are not visited and has an edge
                if(distances[u]+graph[u][k]<distances[k]){ //relaxation 
                    distances[k]=distances[u]+graph[u][k];
                }
            }
        }
    }
    int totalDis=0;
    for(int i=0;i<vertices;i++){
        cout<<source<<" -> "<<i<<" : "<<distances[i]<<endl;
        totalDis+=distances[i];
    }
    double avg = static_cast<double>(totalDis) / (vertices-1);
    cout<<fixed<<setprecision(2);
    cout<<"Average distance to a city from the source city: "<<avg<<endl;

    
}

int main(){
    vector<vector<int>> map={
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0}
    };

    dijsktra(map,4);
}