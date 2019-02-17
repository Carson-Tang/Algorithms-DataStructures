import java.io.*;
import java.util.*;

public class Main {
    static int [] dis;
    static LinkedList<Integer>[]adj;
    static boolean [] vis;
    public static void main (String [] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); // nodes
        int m = Integer.parseInt(br.readLine()); // edges
        dis = new int[n]; vis = new boolean[n]; // assume nodes are 0 indexed
        adj = new LinkedList[n];
        for(int i = 0; i < n; i++) adj[i]=new LinkedList<>();
        for(int i = 0; i < m; i++){
            String [] tok = br.readLine().split(" ");
            int a = Integer.parseInt(tok[0]), b = Integer.parseInt(tok[1]);
            adj[a].push(b);
            adj[b].push(a);
        }
        int src = Integer.parseInt(br.readLine()); // source
        int tar = Integer.parseInt(br.readLine()); // target
        Queue<Integer>q = new LinkedList<>();
        q.add(src);
        while(q.size()>0){
            int u = q.poll(); // current node 
            vis[u]=true;
            for(int v : adj[u]){ // neighbours
                if(!vis[v]){
                    vis[v]=true;
                    dis[v]=dis[u]+1;
                    q.add(v);
                }
            }
        }
        System.out.println(dis[tar]);
    }
}


