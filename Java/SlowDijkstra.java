import java.io.*;
import java.util.*;

public class Main {
    public static void main (String [] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); // nodes
        int m = Integer.parseInt(br.readLine()); // edges
        int [][] adj = new int[n][n];
        boolean [] vis = new boolean[n];
        for(int [] row : adj) Arrays.fill(row,Integer.MAX_VALUE);
        for(int i = 0; i < m; i++){
            String [] tok = br.readLine().split(" ");
            // node 1, node 2, edge cost
            int a = Integer.parseInt(tok[0]), b = Integer.parseInt(tok[1]), w = Integer.parseInt(tok[2]);
            adj[a][b]=Math.min(adj[a][b],w);
            adj[b][a]=Math.min(adj[b][a],w);
        }
        int [] dis = new int[n];
        Arrays.fill(dis,Integer.MAX_VALUE);
        int src = Integer.parseInt(br.readLine());
        int tar = Integer.parseInt(br.readLine());
        dis[src]=0;
        Queue<Integer>q = new LinkedList<>();
        q.add(src);
        while(q.size()>0){
            int curr = q.poll();
            vis[curr]=true;
            for(int i = 0 ; i < n; i++){
                if(!vis[i]&&adj[curr][i]!=Integer.MAX_VALUE){
                    if(dis[i]>dis[curr]+adj[curr][i]){
                        dis[i]=dis[curr]+adj[curr][i];
                    }
                }
            }
            // find least cost node that hasn't been visited yet
            int minNode = -1;
            int minCost = Integer.MAX_VALUE;
            for(int i = 0; i < n; i++){
                if(minCost>dis[i]&&!vis[i]){
                    minCost=dis[i];
                    minNode=i;
                }
            }
            if(minNode!=-1) q.add(minNode);
        }
        System.out.println(dis[tar]);
    }
}


