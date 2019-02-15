import java.io.*;
import java.util.*;

public class Main {
    static int [] dis;
    static LinkedList<Integer>[]adj;
    static boolean [] vis;
    static void dfs(int curr, int parent){
        for(int neigh : adj[curr]) {
            if (neigh != parent && !vis[neigh]) {
                vis[neigh]=true;
                dfs(neigh, curr);
                dis[neigh] = dis[curr] + 1;
            }
        }
    }
    public static void main (String [] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); // nodes
        int m = Integer.parseInt(br.readLine()); // edges
        dis = new int[n]; vis = new int[n];// assume nodes are 0 indexed
        for(int i = 0; i < n; i++) adj[i]=new LinkedList<>();
        for(int i = 0; i < m; i++){
            String [] tok = br.readLine().split(" ");
            int a = Integer.parseInt(tok[0]), b = Integer.parseInt(tok[1]);
            adj[a].push(b);
            adj[b].push(a);
        }
        int src = Integer.parseInt(br.readLine()); // source
        int tar = Integer.parseInt(br.readLine()); // target
        vis[src]=true;
        dfs(src,-1);
        System.out.println(dis[tar]);
    }
}


