#include<iostream>
#include<vector>
#include<map>
#include<list>

using namespace std;

struct node
{
	int left = -1, right = -1;
};
map<int, node>tree;

void get_tree(vector<int> post, vector<int>in)
{
	if (post.size() <= 1) return;
	int boot = post[post.size() - 1];
	int boot_pos = 0;
	for (; boot_pos < in.size(); ++boot_pos)
	{
		if (in[boot_pos] == boot)
			break;
	}
	vector<int>l_post, r_post, l_in, r_in;
	for (int i = 0; i < in.size(); ++i)
	{
		if (i < boot_pos)
			l_in.push_back(in[i]);
		if (i > boot_pos)
			r_in.push_back(in[i]);
	}
	for (int i = 0; i < post.size() - 1; ++i)
	{
		if (i < l_in.size())
			l_post.push_back(post[i]);
		else
			r_post.push_back(post[i]);
	}
	if (l_post.size() != 0)
	{
		tree[boot].left = l_post[l_post.size() - 1];
		get_tree(l_post, l_in);
	}
	if (r_post.size() != 0)
	{
		tree[boot].right = r_post[r_post.size() - 1];
		get_tree(r_post, r_in);
	}
	
	return;
}

int main()
{
	int N, boot;
	
	cin >> N;
	vector<int> post(N, 0), in(N, 0), level;
	for (int i = 0; i < N; ++i)
	{
		cin >> post[i];
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> in[i];
	}
	boot = post[post.size() - 1];
	get_tree(post, in);

	list<int>deq(1,boot);
	while (!deq.empty())
	{
		int front = deq.front();
		deq.pop_front();
		level.push_back(front);
		if (tree[front].left != -1)
			deq.push_back(tree[front].left);
		if (tree[front].right != -1)
			deq.push_back(tree[front].right);
	}
	cout << level[0];
	for (int i = 1; i < level.size(); ++i)
		cout << " " << level[i];
	system("pause");
	return 0;
}