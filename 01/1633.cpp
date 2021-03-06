#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0x7fffffff

using namespace std;

class mcmf
{
private:
	struct edge
	{
		int to, cap, cost, rev;
		edge(int to, int cap, int cost) : to(to), cap(cap), cost(cost) {}
	};

	int n, src, sink;
	vector<vector<edge>> e;
	vector<int> d;
	vector<pair<int,int>> p;

public:
	mcmf(int n, int src, int sink) : n(n), src(src), sink(sink)
	{
		e.resize(n);
		d.resize(n);
		p.resize(n);
	}

	void add_edge(int from, int to, int cap, int cost)
	{
		e[from].push_back({to, cap, cost});
		e[to].push_back({from, 0, -cost});
		e[from].back().rev = e[to].size()-1;
		e[to].back().rev = e[from].size()-1;
	}

	int flow()
	{
		int res = 0;
		vector<bool> iq;
		iq.resize(n);

		while(1)
		{
			queue<int> q;

			fill(d.begin(), d.end(), INF);
			p[sink].first = -1;

			d[src] = 0;
			q.push(src);
			iq[src] = true;
			while(!q.empty())
			{
				int now = q.front();
				q.pop();
				iq[now] = false;

				for(int i=0; i<(int)e[now].size(); ++i)
				{
					auto &t = e[now][i];
					if(t.cap && d[t.to]>d[now]+t.cost)
					{
						d[t.to] = d[now]+t.cost;
						p[t.to] = {now, i};
						if(!iq[t.to])
						{
							q.push(t.to);
							iq[t.to] = true;
						}
					}
				}
			}
			if(p[sink].first == -1)
				break;

			int f = INF;
			for(int i=sink; i!=src; i=p[i].first)
				f = min(f, e[p[i].first][p[i].second].cap);

			for(int i=sink; i!=src; i=p[i].first)
			{
				auto &t = e[p[i].first][p[i].second];
				res += f*t.cost;
				t.cap -= f;
				e[i][t.rev].cap += f;
			}
		}

		return res;
	}
};

int main()
{
	int a, b;
	vector<pair<int,int>> p;

	while(scanf("%d %d", &a, &b) == 2)
		p.push_back({a, b});

	int n = (int)p.size();
	mcmf mf(n+4, 0, n+3);
	mf.add_edge(0, 1, 15, 0);
	mf.add_edge(0, 2, 15, 0);
	for(int i=0; i<n; ++i)
	{
		mf.add_edge(1, i+3, 1, -p[i].first);
		mf.add_edge(2, i+3, 1, -p[i].second);
		mf.add_edge(i+3, n+3, 1, 0);
	}

	printf("%d", -mf.flow());
	return 0;
}
