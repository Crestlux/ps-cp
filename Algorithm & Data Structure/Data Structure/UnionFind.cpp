template<typename T>
class unionfind {
private:
    std::vector<T> parent, height;
    size_t sz = 0;
public:
    unionfind(size_t x) : sz(x), parent(x), height(x, 1) {
        static_assert(std::is_integral_v<T>, "T must be an integral type.");
        for (size_t i = 0; i < sz; ++i) {
            parent[i] = i;
        }
    }
    unionfind() : sz(0), parent(), height() {}
    ~unionfind() = default;
    void validate(T u) const {
        if (u < 0 || static_cast<size_t>(u) >= sz) {
            throw std::out_of_range("Index out of bounds");
        }
    }
    size_t size() const {
        return sz;
    }
    T findRoot(T u) {
        validate(u);
        if (u == parent[u]) return u;
        return parent[u] = findRoot(parent[u]);
    }
    void merge(T u, T v) {
        validate(u), validate(v);
        u = findRoot(u);
        v = findRoot(v);
        if (u == v) return;
        if (height[u] > height[v]) std::swap(u, v);
        parent[u] = v;
        if (height[u] == height[v]) height[v]++;
    }
    inline bool isCycle(T u, T v) {
        validate(u), validate(v);
        return (findRoot(u) == findRoot(v));
    }
    void resize(size_t x) {
        size_t prev_sz = sz;
        sz = x;
        parent.resize(x);
        height.resize(x);
        for (size_t i = prev_sz; i < sz; ++i) {
            parent[i] = i;
            height[i] = 1;
        }
    }
};

template<typename T>
class unordered_unionfind {
private:
    std::unordered_map<T, T> parent;
    std::unordered_map<T, size_t> height;
public:
    unordered_unionfind() = default;
    ~unordered_unionfind() = default;
    size_t size() const {
        return parent.size();
    }
    T findRoot(T u) {
        if (!parent.contains(u)) {
            parent[u] = u;
            height[u] = 1;
        }
        if (u == parent[u]) return u;
        return parent[u] = findRoot(parent[u]);
    }
    void merge(T u, T v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u == v) return;
        if (height[u] > height[v]) std::swap(u, v);
        parent[u] = v;
        if (height[u] == height[v]) height[v]++;
    }
    inline bool isCycle(T u, T v) {
        return (findRoot(u) == findRoot(v));
    }
};
