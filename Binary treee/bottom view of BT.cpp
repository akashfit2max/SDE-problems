vector <int> bottomView(Node *root)
{
    vector<int>ans;
    if (root==nullptr) {
        return ans;
    }
    map<int, int>mp; // to store the levels of the tree
    queue<pair<Node*, int>>q;
    int hd=0;
    q.push({ root, hd }); // or u can use make_pair also
    while (!q.empty()) {
        Node *curr = q.front().first;
        hd = q.front().second;
        mp[hd] = curr->data;
        if (curr->left!=nullptr) {
            q.push({ curr->left, hd-1 });
        }
        if (curr->right!=nullptr) {
            q.push({ curr->right, hd+1 });
        }
        q.pop();
    }
    for (auto i : mp) {
        ans.push_back(i.second);
    }
    return ans;
    // Your Code Here
}

