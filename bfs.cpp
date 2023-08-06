#include <bits/stdc++.h>
using namespace std;
typedef struct node Node;

struct node {
  int data;
  Node *left;
  Node *right;
};

Node *root;

Node *createNode(int data) {
  Node *temp = new Node();
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

void insertNode(Node *root, int data) {
  if (root == NULL) {
    root = createNode(data);
    return;
  }
  Node *temp = root;
  Node *newNode = createNode(data);
  while (temp != NULL) {
    if (data <= temp->data) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }

  if (data <= temp->data) {
    temp->left = newNode;
  } else {
    temp->right = newNode;
  }
}

void InOrder(Node *p) {
  if (p != NULL) {
    InOrder(p->left);
    cout << p->data << " ";
    InOrder(p->right);
  }
}

void preOrder(Node *p) {
  if (p != NULL) {
    cout << p->data << " ";
    preOrder(p->left);
    preOrder(p->right);
  }
}

void postOrder(Node *p) {
  if (p != NULL) {
    postOrder(p->left);
    postOrder(p->right);
    cout << p->data << " ";
  }
}

int main() {
  insertNode(root, 3), insertNode(root, 4);
  insertNode(root, 5);
  insertNode(root, 6);

  cout << "In order: ";
  InOrder(root);
  cout << endl;

  cout << "Pre order : ";
  preOrder(root);
  cout << endl;
  cout << "postOrder: ";
  postOrder(root);
  cout << endl;
  return 0;
}
