class Solution {
    int f[35];
 
public:
    int dfs(int n)
    {
        if(f[n] != -1) return f[n];
        if(n<=1) return n;
        f[n] = dfs(n-1) + dfs(n-2);
        return f[n];
    }

    int fib(int n) {
        memset(f,-1,sizeof f);
        return dfs(n);
    }
};
