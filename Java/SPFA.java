    static class edge implements Comparable<edge>{
        int dest,cost;
        edge(int dest, int cost){
            this.dest=dest;
            this.cost=cost;
        }
        public int compareTo(edge other){
            return Integer.compare(this.cost,other.cost);
        }
    }
    public static void main (String [] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); // nodes
        int m = Integer.parseInt(br.readLine()); // edges
        LinkedList<edge>adj[] = new LinkedList[n]; // assume nodes are 0 indexed
        for(int i = 0; i < n; i++) adj[i]=new LinkedList<>();
        for(int i = 0; i < m; i++){
            String [] tok = br.readLine().split(" ");
            // node 1, node 2, edge cost
            int a = Integer.parseInt(tok[0]), b = Integer.parseInt(tok[1]), w = Integer.parseInt(tok[2]);
            adj[a].add(new edge(b,w));
            adj[b].add(new edge(a,w));
        }
        int [] dis = new int[n];
        Arrays.fill(dis,Integer.MAX_VALUE);
        int src = Integer.parseInt(br.readLine());
        int tar = Integer.parseInt(br.readLine());
        dis[src]=0;
        PriorityQueue<edge>pq = new PriorityQueue<>();
        pq.add(new edge(src,0));
        while(pq.size()>0){
            edge e = pq.poll();
            int curr = e.dest;
            for(edge next : adj[curr]){
                if(dis[next.dest]>dis[curr]+next.cost){
                    dis[next.dest]=dis[curr]+next.cost;
                    pq.add(new edge(next.dest,dis[next.dest]));
                }
            }
        }
        System.out.println(dis[tar]);
    }
