#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }

};

//It will return the address of the root node
node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void bfsLevel(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();

            //This conditon for the endings
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<f->data<<", ";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }

        }
        
    }
    return;
}

void printRightView(node*root,int level,int &maxlevel){

    if(root == NULL){
        return;
    }
    if(maxlevel<level){
        //we have discovered a new level
        cout<< root->data <<" ";
        maxlevel = level;

        //root
        //right
        //left
        printRightView(root->right,level+1,maxlevel);
        printRightView(root->left,level+1,maxlevel);
    }

}

int main(){
    node *root;
    root = buildTree();
    int maxlevel = -1;

    printRightView(root,0,maxlevel);



    return 0;
}