#include <iostream>
using namespace std;
typedef enum color{black,red} Color;
class Nodo{
private:
  int Key;
  Color color;
  Nodo* Dx;
  Nodo* Sx;
  Nodo* Px; 
public:
  Nodo(int Key,Color color,Nodo *Sx,Nodo *Dx,Nodo *Px){
    this->Key = Key;
    this->color = color;
    this->Sx = Sx;
    this->Dx = Dx;
    this->Px = Px;
  }
  void setKey(int k){
    Key = k;
  }
  void setColor(Color c){
    color = c;
  }
  void setPx(Nodo* Px){
    this->Px = Px;
  }
  void setSx(Nodo* Sx){
    this->Sx = Sx;
  }
  void setDx(Nodo* Dx){
    this->Dx = Dx;
  }
  int getKey(){
    return Key;
  }
  int getColor(){
    return this->color;
  }
  Nodo* getDx(){
    return this->Dx;
  }
  Nodo* getSx(){
    return this->Sx;
  }
  Nodo* getPx(){
    return this->Px;
  }
  bool matchColor(Color c){
    bool result;
    (this->color == c) ? result = true : result = false;
    return result;
  }
};

class RB{
private:
  Nodo* root; // radice dell'albero
  Nodo* nil; // nodo NIL

  // --------------------------- right rotate
  void rightRotate(Nodo *nodo){
    Nodo *app = nodo->getSx();
    nodo->setSx(app->getDx());
    if(app->getDx() != this->nil)
        app->getDx()->setPx(nodo);
    app->setPx(nodo->getPx());
    if(nodo->getPx() == this->nil)
        this->root = app;
    else if (nodo == nodo->getPx()->getSx())
        nodo->getPx()->setSx(app);
         else
            nodo->getPx()->setDx(app);
    app->setDx(nodo);
    nodo->setPx(app);
  }
    // -------------------------- left rotate
   void leftRotate(Nodo *nodo){
    Nodo *app = nodo->getDx();
    nodo->setDx(app->getSx());
    if(app->getSx() != this->nil)
        app->getSx()->setPx(nodo);
    app->setPx(nodo->getPx());
    if(nodo->getPx() == this->nil)
        this->root = app;
    else if (nodo == nodo->getPx()->getSx())
        nodo->getPx()->setSx(app);
         else
            nodo->getPx()->setDx(app);
    app->setSx(nodo);
    nodo->setPx(app);
  }
    //-------------------------- allocazione nodo
  void insertNode(Nodo *node){
    Nodo *y = this->nil;
    Nodo *x = this->root;
    while(x != nil){
      y = x;
      if(node->getKey() < x->getKey())
  x = x->getSx();
      else
  x = x->getDx();
    }
    node->setPx(y);
    if(y == this->nil)
      this->root = node;
    else if(node->getKey() < y->getKey())
      y->setSx(node);
    else
      y->setDx(node);
  }
  //----------------------fix up 
  void fixUp(Nodo *nodo){
    while( (nodo != this->root) && (nodo->getPx()->matchColor(red))){
        if(nodo->getPx() == nodo->getPx()->getPx()->getSx()){
            Nodo* app = nodo->getPx()->getPx()->getDx();
            if(app->matchColor(red)){
                nodo->getPx()->setColor(black);
                app->setColor(black);
                nodo->getPx()->getPx()->setColor(red);
                nodo = nodo->getPx()->getPx();
            }
            else{
                if(nodo == nodo->getPx()->getDx()){
                    nodo = nodo->getPx();
                    this->leftRotate(nodo);
                }
                nodo->getPx()->setColor(black);
                nodo->getPx()->getPx()->setColor(red);
                this->rightRotate(nodo->getPx()->getPx());
            }
        }
        else{
            Nodo* app = nodo->getPx()->getPx()->getSx();
            if(app->matchColor(red)){
                nodo->getPx()->setColor(black);
                app->setColor(black);
                nodo->getPx()->getPx()->setColor(red);
                nodo = nodo->getPx()->getPx();
            }
            else{
                 if(nodo == nodo->getPx()->getSx()){
                    nodo = nodo->getPx();
                    this->rightRotate(nodo);
                }
                nodo->getPx()->setColor(black);
                nodo->getPx()->getPx()->setColor(red);
                this->leftRotate(nodo->getPx()->getPx());
            }
        }
    }
    this->root->setColor(black);
  }

  // ------------------- transplant
  void transplant(Nodo *x,Nodo *y){
    if(x->getPx() == this->nil)
      this->root = y;
    else if(x == x->getPx()->getSx())
      x->getPx()->setSx(y);
    else
      x->getPx()->setDx(y);
    y->setPx(x->getPx());
  }  
  // --------------------- fix up delete
  void deleteFixUp(Nodo *x){
   if(x  == x->getPx()->getSx()){
      Nodo *w = x->getPx()->getDx();
      // caso 1
      if(w->matchColor(red)){ 
        w->setColor(black);
        x->getPx()->setColor(red);
        this->leftRotate(x->getPx());  
        w = x->getPx()->getDx();
      }
      // caso 2
      if(w->getSx()->matchColor(black) && w->getDx()->matchColor(black)){
        w->setColor(red);
        x = x->getPx();
      }
      // caso 3
      else if(w->getDx()->matchColor(black)){
        w->getSx()->setColor(black);
        w->setColor(red);
        this->rightRotate(w);
        w = x->getPx()->getDx();
      }
      // caso 4
      w->setColor(x->getPx()->getColor());  
      x->getPx()->setColor(black);
      w->getDx()->setColor(black);
      this->leftRotate(x->getPx()); 
      x = this->root;
   }
   // speculare con x figlio destro 
   if(x == x->getPx()->getDx()){
    Nodo *w = x->getPx()->getSx();
    if(w->matchColor(red)){
      w->setColor(black);
      x->getPx()->setColor(red);
      this->rightRotate(x->getPx());
      w = x->getPx()->getSx();
    }
    // caso 2
    if(w->getSx()->matchColor(black) && w->getDx()->matchColor(black)){
      w->setColor(red);
      x = x->getPx();
    }
    // caso 3
    else if(w->getDx()->matchColor(black)){
      w->getSx()->setColor(black);
      w->setColor(red);
      this->leftRotate(w);
      w = x->getPx()->getDx();
    }
    // caso 4
    w->setColor(x->getPx()->getColor());  
    x->getPx()->setColor(black);
    w->getDx()->setColor(black);
    this->rightRotate(x->getPx()); 
    x = this->root;
   }
   x->setColor(black);
  }
  // --------------------- delete node
  void deleteNode(Nodo *z){
    Nodo *y = z;
    Nodo *x;
    Color yOrigial = y->getColor();
    if(x->getSx() == this->nil){
      x = z->getDx();
      transplant(z,z->getDx()); 
    }else if(z->getDx() == this->nil){
      x = z->getSx();
      transplant(z,z->getSx());
    }else{
      y = minumim(z->getDx());
      yOrigial = y->getColor();
      x = y->getDx();
    }if(y->getPx() == z)
      x->setPx(y);
      else{
        transplant(y,y->getDx());
        y->setDx(z->getDx());
        y->getDx()->setPx(y);
      }
      transplant(z,y);
      y->setSx(z->getSx());
      y->getsx()->setPx(y);
      y->setColor(z->getColor());
      if(yOrigial == black)
        // deleteFixUp(x); // non implementata
  }



  //------------------ visita inorder
  void inOrder(Nodo* nodo){
  if( nodo != this->nil )
    {
        inOrder( nodo->getSx() );
        cout << "nodo : " << nodo->getKey() << " colore : " << nodo->getColor() << " padre : " << nodo->getPx()->getKey()<<endl;
        inOrder( nodo->getDx() );
    }
  }
public:
  RB(){
    this->nil = new Nodo(-1,black,nullptr,nullptr,nullptr);
    root = nil;
    nil->setPx(root);
  }
  void insert(int Key){
    Nodo *aux = new Nodo(Key,red,this->nil,this->nil,this->nil);
    this->insertNode(aux);
    this->fixUp(aux);
  }
  void visit(){
    this->inOrder(this->root);
  }
};

int main(){
  RB mytree; 
  mytree.insert(22);
  mytree.insert(32);
  mytree.insert(18);
  mytree.insert(17);
  mytree.visit();
  return 0;
}
