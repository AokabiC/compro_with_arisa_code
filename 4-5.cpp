int W, H;
vector<vector<char>> s;

// cost[y][x] = スタートから(x, y)までの最短経路
vector<vector<int>> cost;
int bfs(){
    // 移動可能なマスをループで簡単に列挙
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

    // 座標をpair(y, x)でもってqueueに入れる
    queue<pair<int, int>> que;
    // スタートは(0, 0) (0-indexedに読み替える)
    que.push(make_pair(0, 0));
    cost[0][0] = 0;

    while(!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        if(p == make_pair(H-1, W-1)){
            // ゴールに到達
            return cost[p.first][p.second];
        }
        for(int i = 0; i < 4; i++) {
            int ny = p.first + dy[i], nx = p.second + dx[i];
            // 壁orマスの外
            if(nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
            if(s[ny][nx] == '#') continue;
            // 既に探索済み
            if(cost[ny][nx] != -1) continue;

            cost[ny][nx] = cost[p.first][p.second] + 1;
            que.push(make_pair(ny, nx));
        }
    }
    return -1;
}

int main() {
    cin >> H >> W;
    s = vector<vector<char>>(H, vector<char>(W));
    int white = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> s[i][j];
            if(s[i][j] == '.') white++;
        }
    }
    cost = vector<vector<int>>(H, vector<int>(W, -1));
    int min_cost = bfs();
    if(min_cost == -1) cout << -1 << endl;
    else cout << white - (min_cost+1) << endl;
}