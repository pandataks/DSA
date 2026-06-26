#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Codec {

public:

    void encode(TreeNode* root, string &s) {

        if(root == NULL) {
            s += "# ";
            return;
        }

        s += to_string(root->val) + " ";

        encode(root->left, s);
        encode(root->right, s);
    }

    TreeNode* decode(stringstream &ss) {

        string val;
        ss >> val;

        if(val == "#")
            return NULL;

        TreeNode* root = new TreeNode(stoi(val));

        root->left = decode(ss);
        root->right = decode(ss);

        return root;
    }

    string serialize(TreeNode* root) {

        string s;
        encode(root, s);
        return s;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);
        return decode(ss);
    }
};

void preorder(TreeNode* root) {

    if(root == NULL) {
        cout << "# ";
        return;
    }

    cout << root->val << " ";

    preorder(root->left);
    preorder(root->right);
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Codec obj;

    string s = obj.serialize(root);

    cout << "Serialized: " << s << endl;

    TreeNode* newRoot = obj.deserialize(s);

    cout << "Preorder: ";
    preorder(newRoot);

    return 0;
}