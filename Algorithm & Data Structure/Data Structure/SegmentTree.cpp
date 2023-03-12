namespace segment_tree {
    using ll = long long;
    void build(vector<ll> &arr, vector<ll> &segtree, ll vtx, ll tl, ll tr) {
        if (tl == tr)  segtree[vtx] = arr[tl];
        else {
            ll tm = (tl + tr) / 2;
            build(arr, segtree, vtx * 2, tl, tm);
            build(arr, segtree, vtx * 2 + 1, tm + 1, tr);
            segtree[vtx] = segtree[vtx * 2] + segtree[vtx * 2 + 1];
        }
    }
    ll sum(vector<ll> &segtree, ll vtx, ll tl, ll tr, ll l, ll r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return segtree[vtx];
        ll tm = (tl + tr) / 2;
        return sum(segtree, vtx * 2, tl, tm, l, min(r, tm))
            + sum(segtree, vtx * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    void update(vector<ll> &segtree, ll vtx, ll tl, ll tr, ll pos, ll new_val) {
        if (tl == tr) segtree[vtx] = new_val;
        else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm) update(segtree, vtx * 2, tl, tm, pos, new_val);
            else update(segtree, vtx * 2 + 1, tm + 1, tr, pos, new_val);
            segtree[vtx] = segtree[vtx * 2] + segtree[vtx * 2 + 1];
        }
    }
}
