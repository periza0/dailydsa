
unordered_map<int,vector<int>> adj;
for (int i=0;i<V;i++){
    for (auto it=mp[i].beigin();it!=mp[i].end()){
    adj[i].pushback[*it];
}
}
