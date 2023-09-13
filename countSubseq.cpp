int sameSeq(int idx, int n, int* a, vector<int>seq){
    if(idx == n){
        // subsequence is ready check it
        int val = 0;
        for(auto it : seq){
            val ^= it;
        }
        if(val != 0) return 0;
        else return 1;
    }

    seq.push_back(a[idx]);
    int pick = sameSeq(idx+1, n, a, seq);
    seq.pop_back();
    int notPick = sameSeq(idx+1, n, a, seq);
    return pick+notPick;
}

long countSubsequences(int* arr, int n) {
    // first find the subsequence and then check if elements are
    // all equal or not
    vector<int>seq;
    return sameSeq(0, n, arr, seq);
}