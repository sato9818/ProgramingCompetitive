template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat;
    RMQ(int n_) : n(), dat(n_ * 4, INF) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            // ここを変える
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return INF;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            // ここを変える
            return min(vl, vr);
        }
    }
};