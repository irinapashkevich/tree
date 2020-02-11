#include <iostream>

using namespace std;

class node{
public:
    node(int a);
    ~node();
    void push(int a);
    void print();
    bool find_el(int a);
    void delete_element(int a);
    int min_el();
    int max_el();
private:
    int value;
    node* left;
    node* right;
};

class tree{
public:
    tree(int a);
    ~tree();
    void incert(int a);
    void print();
    bool find_el(int a);
    void delete_element(int a);
private:
    node* root;
};

tree::tree(int a)
{
    this->root=new node(a);
};

tree::~tree()
{
    delete(this->root);
}

void tree::incert(int a)
{
    root->push(a);
};

void tree::print()
{
    root->print();
}

bool tree::find_el(int a)
{
    if(this->root->find_el(a))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void tree::delete_element(int a)
{
    this->root->delete_element(a);
}

node::node(int a)
{
    this->value=a;
    this->left=NULL;
    this->right=NULL;
};

node::~node()
{
    if (this->left!=NULL)
    {
        delete(this->left);
    }
    if (this->right!=NULL)
    {
        delete(this->right);
    }
    delete(this);
};

void node::push(int a)
{
    if (this->value>a)
    {
        if (this->left!=NULL)
        {
            this->left->push(a);
        }
        else
        {
            node* element = new node(a);
            this->left=element;
        }
    }
    else
    {
        if (this->value<a)
        {
            if (this->right!=NULL)
            {
                this->right->push(a);
            }
            else
            {
                node* element = new node(a);
                this->right=element;
            }
        }
    }
};

void node::print()
{
    if (this->left!=NULL)
    {
        left->print();
    }
    cout<<value<<" ";
    if (this->right!=NULL)
    {
        right->print();
    }
}

bool node::find_el(int a)
{
    if (this->value==a)
    {
        return true;
    }
    if ((this->value>a) && (this->left!=NULL))
    {
        if (this->left->find_el(a))
            return true;
        else
            return false;
    }
    if ((this->value<a) && (this->right!=NULL))
    {
        if (this->right->find_el(a))
            return true;
        else
            return false;
    }
    return false;
}

int node::max_el()
{
    if (this->right!=NULL)
        return this->right->max_el();
    else
    {
        if (this->left==NULL)
        {
            int a=this->value;
            delete this;
            return a;
        }
        else
        {
            int a=this->value;
            this->value=this->left->value;
            this->left=this->left->left;
            this->right=this->left->right;
            return a;
        }
    }
}

int node::min_el()
{
    if (this->left!=NULL)
        return this->left->min_el();
    else
    {
        if (this->right==NULL)
        {
            int a=this->value;
            delete this;
            return a;
        }
        else
        {
            int a=this->value;
            this->value=this->right->value;
            this->left=this->right->left;
            this->right=this->right->right;
            return a;
        }
    }
}

void node::delete_element(int a)
{
    if (this->value==a)
    {
        if ((this->right==NULL) && (this->left==NULL))
            delete (this);
        else
            if (this->right!=NULL)
            {
                this->value=this->right->min_el();
            }
            else
            {
                this->value=this->left->max_el();
            }
    }
    else
    {
        if ((this->value>a) && (this->left!=NULL))
        {
            this->left->delete_element(a);
        }
        else
        {
            if ((this->value<a) && (this->right!=NULL))
            {
                this->right->delete_element(a);
            }
            else
                cout<<"net takogo elementa"<<endl;
        }
    }
}

int main()
{
    int k, a;
    cout<<"rol-vo elementov: ";
    cin>>k;
    cin>>a;
    tree* derevo=new tree(a);
    for (int i=0; i<k-1; i++)
    {
        cin>>a;
        derevo->incert(a);
    }
    derevo->print();
    cout<<endl;
    cout<<"find: ";
    cin>>a;
    if (derevo->find_el(a))
        cout<<"yes";
    else
        cout<<"no";
/*    cout<<endl;
    cout<<"delete: ";
    cin>>a;
    derevo->delete_element(a);
    derevo->print();
    delete derevo;*/
    return 0;
}
