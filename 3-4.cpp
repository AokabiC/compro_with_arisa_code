int main(){
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int ans = 0;
    for(int a = 0; a <= A; ++a) {
        for(int b = 0; b <= B; ++b) {
            for(int c = 0; c <= C; ++c) {
                // 合計
                int total = 500*a + 100*b + 50*c;
                if(total == X) ans++;
            }
        }
    }
    cout << res << endl;
}