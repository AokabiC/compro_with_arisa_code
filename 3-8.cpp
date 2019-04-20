int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    vector<long long> v(N+1, 0);
    for(int i=0; i<N; i++) v[i+1] += v[i] + A[i];

    for(int k=1; k<=N; k++){
        long long max_total = 0;
        for(int i=0; i+k<=N; i++){
            long long now = v[i+k] - v[i];
            max_total = max(max_total, now);
        }
        cout << max_total << endl;
    }
}