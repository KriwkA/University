#include <iostream>
#include <vector>

using namespace std;

void msInit(vector<vector<int>>& g, const int n)
{
	g.clear();
	g.resize(n);
	for (int i(0); i < n; i++)
		g[i] = vector<int>(n,INT_MAX);
}

void pushArc(vector<vector<int>>& g, const int first, const int second, const int weight)
{
	g[first][second] = weight;
	g[second][first] = weight;
}

void solve(const vector<vector<int>> g, vector<pair<int, int>>& arcs, const int n)
{
	int i, j, v, to;
	vector <bool> used(n, false);
	vector <int> min_e(n, INT_MAX);
	vector <int> sel_e(n, -1);
	pair<int, int > arc;
	min_e[0] = 0;

	for (i = 0; i < n; i++) 
	{
		v = -1;
		for (j = 0; j < n; j++)
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
		if (min_e[v] == INT_MAX)
			return;
		used[v] = true;
		if (sel_e[v] != -1)
		{
			arc.first = v;
			arc.second = sel_e[v];
			arcs.push_back(arc);
		}
		for (to = 0; to < n; to++)
			if (g[v][to] < min_e[to]) 
			{
				min_e[to] = g[v][to];
				sel_e[to] = v;
			}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<vector<int>> g;
	vector<pair<int, int>> arcs;
	int n;
	cout << "Введите кол-во узлов:" << endl;
	cin >> n;
	msInit(g, n);
	{
		cout << "Введите кол-во дуг:" << endl;
		int n, first, second, weight;
		cin >> n;
		cout << "Введиете дуги:" << endl;
		for (int i(0); i < n; i++)
		{
			cin >> first >> second >> weight;
			pushArc(g, first-1, second-1, weight);
		}
	}
	solve(g, arcs, n);
	cout << "Список дуг остового дерева:" << endl;
	for (auto a : arcs)
		cout << a.first+1 << ' ' << a.second+1 << endl;
	system("pause");
	return 0;
}