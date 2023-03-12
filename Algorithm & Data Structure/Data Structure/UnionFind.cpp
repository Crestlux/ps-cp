namespace UnionFind {
    using ll = long long;
    vector<ll> parent, height;
    ll sz = 0;
    void init(ll x) {
        sz = x;
        parent.resize(x);
        height.resize(x);
        for (ll i : views::iota(0LL, sz)) {
            parent[i] = i;
            height[i] = 1;
        }
    }
    ll findRoot(ll u) {
        if (u == parent[u]) return u;
        return parent[u] = findRoot(parent[u]);
    }
    void merge(ll u, ll v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u == v) return;
        if (height[u] > height[v]) swap(u, v);
        parent[u] = v;
        if (height[u] == height[v]) height[v]++;
    }
}
