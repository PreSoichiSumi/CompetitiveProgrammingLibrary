//lim以下のフィボナッチ数を取得する
vector<LL> getFib(LL lim){
    vector<LL> res;
    res.push_back(1);
    res.push_back(1);
    LL it=2;
    LL tmp=1;
    while(tmp<lim){
        tmp=res[it-1]+res[it-2];
        res.push_back(tmp);
        it++;
    }
    return res;
}