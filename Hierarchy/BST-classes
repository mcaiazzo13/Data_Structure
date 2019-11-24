#include <iostream>

using namespace std;

class Node{
private:
  int key;
  Node *Dx;
  Node *Sx;
  Node *Px;
public:
  Node(int k,Node *d,Node *s,Node *p){
    this->key = k;
    this->Sx = s;
    this->Dx = d;
    this->Px = p;
  }
  void setKey(int k){
    key = k;
  }
  void setDx(Node *pt){
    Dx = pt;
  }
  void setSx(Node *pt){
    Sx = pt;
  }
  void setPx(Node *pt){
    Px = pt;
  }
  int getKey(){
    return key;
  }
  Node* getDx(){
    return this->Dx;
  }
  Node* getSx(){
    return this->Sx;
  }
  Node* getPx(){
    return this->Px;
  }
};
//------------------------------------------- BST
class BST{
private:
  Node *root; 

  //--- PRIVATE METHODS ---\\
  // ------------------------ create the node
  void insertNode(Node *node){
    Node *y = nullptr;
    Node *x = this->root;
    while(x != nullptr){
      y = x;
      if(node->getKey() < x->getKey())
	x = x->getSx();
      else
	x = x->getDx();
    }
    node->setPx(y);
    if(y == nullptr)
      this->root = node;
    else if(node->getKey() < y->getKey())
      y->setSx(node);
    else
      y->setDx(node);
  }
  //---------------------- search node
  Node* searchNode(int info){
    Node *x = this->root;
    while(x->getKey() != info){
      if(x->getKey() > info)
	x = x->getSx();
      else
	x = x->getDx();
    }
  	return x;
  }
  //--------------------- successor
  Node* minimum(Node *x){
  	while(x->getSx() != nullptr){
  		x = x->getSx();
  	}
  	return x;
  }
  Node* successor(Node* x){
  	if(x->getDx() != nullptr){
  		return minimum(x->getDx());
  	}
  	Node *y = x->getPx();
  	while(y != nullptr && x == y->getDx()){
  		x = y;
  		y = y->getPx();
  	}
  	return y;
  }
 //----------------------- predecessor
  Node* maximum(Node *x){
	while(x->getDx() != nullptr){
  		x = x->getDx();
  	}
  	return x;
  }
  Node* predecessor(Node *x){
  	if(x->getSx() != nullptr){
  		return maximum(x->getSx());
  	}
  	Node *y = x->getPx();
  	while(y != nullptr && x == y->getDx()){
  		x = y;
  		y = y->getPx();
  	}
  	return y;
  }
  //--------------------- transplant 
  void transplant(Node* x,Node *y){
  	if(x->getPx() == nullptr)
  		this->root = y;
  	else if(x == x->getPx()->getSx())
  		x->getPx()->setSx(y);
  	else
  		x->getPx()->setDx(y);
  	if(y != nullptr)
  		y->setPx(x->getPx());
  }
  //--------------------- delete node
  void deleteNode(Node* x){
	if(x->getSx() == nullptr)
		transplant(x,x->getDx());
		else if(x->getDx() == nullptr)
			transplant(x,x->getSx());
	else{
		Node *y = minimum(x->getDx());
		if(y->getPx() != x){
			transplant(y,y->getDx());
			y->setDx(x->getDx());
			y->getDx()->setPx(y);
		}
		transplant(x,y);
		y->setSx(x->getSx());
		y->getSx()->setPx(y);
	}
  }
  //------------------ visit
  void inorder(Node *x){
    if(x != nullptr){
        inorder(x->getSx());
        cout<<"Nodo : " << x->getKey()<<endl;
        inorder(x->getDx());;
    }
  }

public:
  BST(){
    this->root = nullptr;
  }
  // -------------------- crea nodo con info
  void insert(int info){
    Node* aux = new Node(info,nullptr,nullptr,nullptr);
    this->insertNode(aux);
  }
  void search(int info){ 
    Node* aux = this->searchNode(info);
    cout << "MY node IS : " << aux->getKey()<<endl;
  }
  void remove(int info){
  	Node* aux = this->searchNode(info);
    cout << "Node to remove : " << aux->getKey()<<endl;
  	deleteNode(aux);
  }
  void visit(){
      inorder(this->root);
  }
  Node* getRoot(){
    return root;
  }
};

int main(){

  BST mytree;
  mytree.insert(25);
  mytree.insert(21);
  mytree.insert(30);
    mytree.visit();

  Node *ptr;
  ptr = mytree.getRoot();
  cout << "root " << ptr->getKey()<<endl;

  mytree.search(21);

  mytree.remove(21);
  mytree.visit();

  return 0;
}
