#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int vertices=6; //initializing number of vertices
int infinity=INT_MAX;
void prims(vector<vector<int>> graph, int source){
    vector<int> key(vertices,infinity); //to store the distances to the other vertices from accessed vertices
    vector<bool> mstSet(vertices,false); //to store the visited vertices
    vector<int> MST(vertices); //to store MST

    key[source]=0; //distance is zero for the source from itself    
    for(int j=0;j<vertices;j++){
        int min=infinity;
        int minIndex=-1;

        //find the vertex with the minimum value in the key vector
        for(int i=0;i<vertices;i++){
            if(mstSet[i]==false && key[i]<min){
                min=key[i];
                minIndex=i;
            }   
        }

        mstSet[minIndex]=true; //mark it as visited 

        for(int k=0;k<vertices;k++){
            if(graph[minIndex][k]!=0 && mstSet[k]==false){ //if there exist an edge with selected minIndex value and if it has not been visited
                if(key[k]>graph[minIndex][k]){ //if the stored value is higher than the edge value of the selected minIndex
                    MST[k]=minIndex;
                    key[k]=graph[minIndex][k];
                }
            }
        }
        
    }

    //printing MST
    for(int i=0;i<vertices;i++){
        if(graph[i][MST[i]]!=0){
            cout<<MST[i]<<"-->"<<i<<" "<<graph[i][MST[i]]<<endl;
        }
    }
}

int main(){
    vector<vector<int>> graph={
        {0,3,0,0,0,1},
        {3,0,2,1,10,0},
        {0,2,0,3,0,5},
        {0,1,3,0,5,0},
        {0,10,0,5,0,4},
        {1,0,5,0,4,0}
    };

    prims(graph,0);


}

    






