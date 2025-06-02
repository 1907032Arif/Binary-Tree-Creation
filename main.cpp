#include <bits/stdc++.h>

using namespace std;

class BinaryTree
{
private:
    struct Node
    {
        int value;
        Node* left;
        Node* right;


    Node(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }
    };

    Node* root;

    void populate(Node* node)
    {
        char choice;
        cout<<"Do you enter the left of "<<node->value<<"?(y/n)";
        cin>>choice;
        if(choice == 'y' || choice == 'Y')
        {
            int val;
            cout<<"Enter the value of the left of "<<node->value<<": ";
            cin>>val;
            node->left = new Node(val);
            populate(node->left);
        }

        cout<<"Do you enter the right of "<<node->value<<"?(y/n)";
        cin>>choice;
        if(choice == 'y' || choice == 'Y')
        {
            int val;
            cout<<"Enter the value of the right of "<<node->value<<": ";
            cin>>val;
            node->right = new Node(val);
            populate(node->right);
        }
    }

    void display(Node* node, string indent)
    {
        if(node == nullptr)
        {
            return;
        }
        cout<<indent<<node->value<<endl;
        display(node->left, indent + "\t");
        display(node->right, indent+"\t");
    }



public:
    BinaryTree()
    {
        root = nullptr;
    }

    void populate()
    {
        int val;
        cout<<"Enter the root node: ";
        cin>>val;
        root = new Node(val);
        populate(root);
    }

    void display()
    {
        cout<<"\nBinary Tree Structure:\n";
        display(root, "");
    }
};





int main()
{
    BinaryTree tree;
    tree.populate();
    tree.display();
    return 0;
}
