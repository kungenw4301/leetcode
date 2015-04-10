//求一个n个元素的集合的所有可能的非空子集合，集合用数组表示
vector<vector<int>> find_all_subset(int set[]){
    int n = sizeof(set)/sizeof(int);
    int max = pow(2, n);
    vector<vector<int>> result;

    for(int i = max; i > 0; --i){   //因为是非空子集，所以不用求 i == 0 时候的串
        vector<int> subset;
        int a[n]; //保存01位串
        for(int j = n-1; j>=0; j--){
            a[n-j-1] = (i >> j) & 1; // 1000 >> 3 -> 1 -> a[0] = 1,从高位开始取
        }
        for(int k = 0; k<n; k++){
            if(a[k] == 1) subset.push_back(set[k]); //a[]中第几位不为零，就保存第几位
        }
        result.push_back(subset); //这就求出一个非空子集
    }

    return result;
}
