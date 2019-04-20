// ##### 本誌に書けなかったダイクストラ法の実装です #####

// 隣接リストでは相手の頂点番号だけ持っておけばよかったので、
// vector<vector<int>> で大丈夫だった、今回は辺の重みも
// 保持する必要があるので、データ構造 edge を用意する
// pair でもできるが、わかりやすいのはこっち？
struct edge{
    int to, cost;
};

const int INF = 999999999;

// startからの最短経路をすべての頂点に対して求める
vector<int> dijkstra(vector<vector<edge>> &G, int start){
    vector<int> dist(G.size(), INF);
    using pi = pair<int, int>;
    // 自動的にソートしておいてくれるqueueであるpriority_queueを使う
    // costが小さい順に並ぶようにする
    // pair(その時点での最短経路, 頂点番号)
    priority_queue<pi, vector<pi>, greater<pi>> que;
    dist[start] = 0;
    que.push(make_pair(dist[start], start));
    while(!que.empty()){
        int cost = que.top().first;
        int idx = que.top().second;
        que.pop();
        if(dist[idx] < cost) continue;
        for(edge e: G[idx]){   // vector<edge> G[idx]の中身を順に取り出しeに入れる
            if(dist[e.to] <= cost+e.cost) continue;
            dist[e.to] = cost+e.cost;
            que.push(make_pair(dist[e.to], e.to));
        }
    }
    return dist;
}

// 頂点 s -> t へ 重み d で結ぶ辺の追加方法
G[s].push_back((edge){t,d});

// 頂点 start からの最短経路長を保持したvectorを O(NlogN) で構築する!
vector<int> ans = dijkstra(G, start);
