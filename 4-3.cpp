stack<string> st;
st.push("");
// stが空でない限り
while(!st.empty()){
    string now = st.top();
    st.pop();
    if(now.size() == 3){
        cout << now << endl;
    }else{
        for(int select=1; select>=0; select--){
            string next = now + to_string(select);
            st.push(next);
        }
    }
}

-----

void dfs(int now){
    if(now.size() == 3){
        cout << now << endl;
    }else{
        for(int select=1; select>=0; select--){
            string next = now + to_string(select);
            dfs(next);
        }
    }
}