int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    int sum = 0;
    for(int i=0; i<N; i++){
        // sum に a[i] を 足す
        // sum = sum + a[i] と同じ意味
        sum += a[i];
    }
    cout << sum << endl;
}