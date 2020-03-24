#include <iostream>

using namespace std;

class node{
public:
    node();
    ~node();
    void push(int a);
    void print();
    bool find_el(int a);
    void delete_element(int a);
    int min_el();
    int max_el();
private:
    bool v;
    int value;
    node* left;
    node* right;
};

class Container
{
public:
    // Виртуальные методы, должны быть реализованы вашим контейнером
    virtual void insert(int value) = 0;
    virtual bool exists(int value) = 0;
    virtual void remove(int value) = 0;

    // И этот тоже, хотя к нему потом ещё вернёмся
    virtual void print() = 0;

    // Виртуальный деструктор (пока просто поверьте, что он нужен)
    virtual ~Container() { };
};

class tree: public Container{
public:
    tree();
    ~tree();
    void insert(int a);
    void print();
    bool exists(int a);
    void remove(int a);
private:
    node* root;
    int Size;
};

tree::tree()
{
    this->root=new node();
    this->Size=0;
};

tree::~tree()
{
    delete(this->root);
}

void tree::insert(int a)
{
    this->root->push(a);
    this->Size++;
};

void tree::print()
{
    root->print();
}

bool tree::exists(int a)
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

void tree::remove(int a)
{
    this->root->delete_element(a);
}

node::node()
{
    this->left=NULL;
    this->right=NULL;
    this->v=false;
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
    if(!this->v)
    {
        this->value=a;
        this->v=true;
    }
    else
       if (this->value>a)
       {
           if (this->left!=NULL)
           {
               this->left->push(a);
           }
           else
           {
               node* element = new node();
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
                   node* element = new node();
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
        {
            if (this->right!=NULL)
            {
                this->value=this->right->min_el();
            }
            else
            {
                this->value=this->left->max_el();
            }
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
    tree* c = new tree();

    for(int i = 1; i < 10; i++)
        c->insert(i*i);

    cout << "Container after creation:" << endl;
    c->print();

    if(c->exists(25))
        cout << "Search for value 25: found" << endl;

    if(!c->exists(111))
        cout << "Search for value 111: not found" << endl;

    c->remove(25);
    cout << "Container after deletion of the element:" << endl;
    c->print();

    delete c;
    return 0;
}
