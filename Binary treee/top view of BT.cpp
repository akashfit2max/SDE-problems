void topView(struct Node *root)
{
    map<int, int> mp; // to store the levels of the tree and print them is ascending order
    queue<pair<Node *, int>> q;
    int hd = 0;
    q.push({root, hd}); // or u can use make_pair also
    while (!q.empty())
    {
        Node *curr = q.front().first;
        hd = q.front().second;
        q.pop();
        if (mp.find(hd) == mp.end())
        {
            mp[hd] = curr->data;
        }
        if (curr->left != nullptr)
        {
            q.push({curr->left, hd - 1});
        }
        if (curr->right != nullptr)
        {
            q.push({curr->right, hd + 1});
        }
    }
    for (auto i : mp)
    {
        cout << i.second << " ";
    }
    //Your code here
}
