/*
    MCS+优先队列
    一个无向图称为弦图当图中任意长度大于3的环都至少有一个弦。
    Example：用最少的颜色给每个点染色使得相邻的点染的颜色不同：
    Solution：通过完美消除序列从后往前依次给每个点染色，给每个点染上可以染的最小的颜色
    Example：最大独立集问题：选择最多的点使得任意两个点不相邻
    solution：通过完美消除序列从前往后能选就选。
*/
const int N = 1010;
int n, m;
vector<int> g[N];
bool mp[N][N];
int label[N], seq[N], id[N];
struct Stat {
    int lab, u;
    Stat(int lab, int u) : lab(lab), u(u) {}
    bool operator<(const Stat &b) const { return lab < b.lab; }
};
void MCS() {
    priority_queue<Stat> q;
    memset(label, 0, sizeof(label));
    memset(id, 0, sizeof(id));
    for (int u = 1; u <= n; u++) q.push(Stat(0, u));
    for (int i = n; i; i--) {
        while (id[q.top().u]) q.pop();
        int u = q.top().u;
        q.pop();
        id[u] = i;
        for (int t = 0; t < g[u].size(); t++) {
            int v = g[u][t];
            if (!id[v]) {
                label[v]++;
                q.push(Stat(label[v], v));
            }
        }
    }
    for (int u = 1; u <= n; u++) seq[id[u]] = u;
}
/*
    Example
    弦图判定
*/
bool check() {
    vector<int> c;
    for (int i = 1; i <= n; i++) {
        int u = seq[i];
        c.clear();
        for (int t = 0; t < g[u].size(); t++) {
            int v = g[u][t];
            if (id[v] > id[u]) c.push_back(v);
        }
        if (c.empty()) continue;
        int sc = c[0];
        for (int t = 1; t < c.size(); t++)
            if (id[c[t]] < id[sc]) sc = c[t];
        for (int t = 0; t < c.size(); t++) {
            int v = c[t];
            if (v == sc) continue;
            if (!mp[sc][v]) return false;
        }
    }
    return true;
}
void init(int n) {
    memset(mp, false, sizeof(mp));
    for (int i = 1; i <= n; i++) g[i].clear();
}
int main() {
    while (~scanf("%d%d", &n, &m)) {
        init(n);
        for (int i = 1, u, v; i <= m; i++) {
            scanf("%d%d", &u, &v);
            mp[u][v] = mp[v][u] = true;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        MCS();
        printf("%s\n", check() ? "Perfect" : "Imperfect");
    }
    return 0;
}
