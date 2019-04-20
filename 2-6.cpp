int main(){
	string N;
	cin >> N;
	int S = 0;
	for(int i=0; i< N.size(); i++){
	    S += N[i] - '0';
	}
	if(stoi(N) % S == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
}