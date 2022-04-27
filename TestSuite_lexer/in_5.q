# DFS

const int N = 10;
int g[N,N];
bool visited[N];
int topoSort[N];

int pos = 0;

def dfs(int node) => void{
    
    visited[node] = true;

    for i in (0,N)
        if(!visited[node , i])
            dfs(i);
    
    topoSort[pos++] = node;

    return;

}


def main() => int{

    for i in (0 , N){
        visited[i] = false;
        for j in (0 , N)
            g[i,j] = 0;
    }
    
    int m;
    input("Enter number of edges: " , m);

    for i in (0 , m){
        int u , v;
        input("Enter u-v" , u , v);
        g[u-1][v-1] = 1;
    }

    for i in (0 , N)
        if(!visited[i])
            dfs(i);
    
    reverse(topoSort , N);

    print("TopoSort:\n");
    for i in (0 , N)
        print(i + " ");
    print("\n");

    return 0;
}