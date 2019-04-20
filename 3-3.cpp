int main(){
    int ans = 0;
    bool div_by_2 = true;
    while(div_by_2){
        for(int i=0; i<N; i++){
            if(A[i] % 2 == 1){
                div_by_2 = false;
                break;
            }else{
                A[i] /= 2;
            }
        }
        // すべて2で割り切れる
        if(div_by_2){
            ans++;
        }
    }
    cout << ans << endl;
}