//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
String tree;
//---------------------------------------------------------------------------
struct BSTreeNode

{   struct BSTreeNode *leftchild;

    int data;

    struct BSTreeNode *rightchild;

};

struct StackNode

{   struct BSTreeNode *treenode;

    struct StackNode *next;

};

struct QNode

{   struct BSTreeNode *treenode;

    struct QNode *next;

};

struct BSTreeCNode

{   struct BSTreeCNode *leftchild;

    char * data;

    struct BSTreeCNode *rightchild;

};

struct DrawTreeNode

{   struct DrawTreeNode* leftchild;

    int data;

    int index;

    // int x;

    // int y;

    struct DrawTreeNode* rightchild;

};

struct BSTreeCNode *Croot;

struct BSTreeNode *root;

struct StackNode *top;

struct DrawTreeNode* DrawRoot;

int* X;

int* Y;

//String tree;

int count_node;

int** treenode;

void push_node(struct BSTreeNode *node )

{ struct StackNode *old_top;

  old_top = top;

  top = (struct StackNode *) malloc (sizeof(struct StackNode));

  top->treenode = node;

  top->next = old_top;

}

struct BSTreeNode *pop_node()

{ struct BSTreeNode *Tnode;

  struct StackNode *old_top;

  if (top == NULL)

  ;       // StackEmpty();

  else

  {  Tnode = top->treenode;

     old_top = top;

     top = top->next;

     free(old_top);

     return Tnode;

  }

}

struct QNode *front, *rear;

void AddQueue(struct BSTreeNode *Tnode)

{  struct QNode *node;

	node = (struct QNode *) malloc(sizeof(struct QNode));

    node->treenode = Tnode;

    node->next = NULL;

    if (front == NULL) front = node;

    else rear->next = node;

    rear = node;

}

struct BSTreeNode *DeleteQueue()

{ struct BSTreeNode *Tnode;

 struct QNode *old_front;

 if (front == NULL) ; //QueueEmpty();

 else

 {   Tnode = front->treenode;

     old_front = front;

     front = front->next;

     free(old_front);

     return Tnode;

 }

}

void LevelOrder (struct BSTreeNode *node)

{ AddQueue(node);

  while (front != NULL)

  {  node = DeleteQueue();

     tree += IntToStr(node->data)+", ";

     if (node->leftchild != NULL) AddQueue(node->leftchild);

     if (node->rightchild != NULL) AddQueue(node->rightchild);

  }

}

int InsertBST(int x)

{

	struct BSTreeNode *p, *q;

	p = root; q = NULL;

    while (p != NULL)

    { q = p;

      // if (x == p->data) return 0;

      if (x < p->data)

          p = p->leftchild;

      else

          p = p->rightchild;

    }

    // p = (struct BSTreeNode *) malloc (sizeof(BSTreeNode));

    p = new struct BSTreeNode;

    p->data = x;

    p->leftchild = p->rightchild = NULL;

    if (root == NULL)

    {   root = p;

        count_node++;

    }

    else if (x < q->data)

         {  q->leftchild = p;

            count_node++;

         }

         else

         {  q->rightchild = p;

            count_node++;

         }

    return 1;

}

int DeleteBSTree(int x)

{   struct BSTreeNode *p , *father, *k, *f;

     p = root; father = NULL;

     while (p != NULL)

     {  if (x == p->data) // ��� x �Ҧb���`�I p �F

        {  if ((p->leftchild == NULL) && (p->rightchild == NULL))

               k = NULL; // p ���𸭸`�I

           else if (p->leftchild != NULL ) // p �t�����l��

                {  f = p; // ��X p ���l�𪺳̥k��

                   k = p->leftchild;

                   while (k->rightchild !=NULL)

                   {  f = k;

                      k = k->rightchild;

                   }  // k �Y�� p ���l�𪺳̥k��

                   if (p == f)     // k �Y�� p ������l

                      f->leftchild = k->leftchild;

                   else

                      f->rightchild = k->leftchild;

                }

                else    // p �L���l��, �ˬd�k�l��

                {   f = p; //��X p �k�l�𪺳̥���

                    k = p->rightchild;

                    while (k->leftchild != NULL)

                    {  f = k;

                       k = k ->leftchild;

                    }  // k �Y�� p �k�l�𪺳̥���

                    if (p == f)    // k �Y�� p ���k��l

                       f->rightchild = k->rightchild;

                    else

                       f->leftchild = k->rightchild;

                 }

                 if (k != NULL)   // k ���ܭ� p �B, �~�� p �����k����

                 {   k->leftchild = p->leftchild;

                     k->rightchild = p->rightchild;

                 }

                 if (father == NULL) root = k;

                 else

                 {  if (x < father->data)  //�M�wk�Ofather�����Υk��l

                       father->leftchild = k;

                    else

                       father->rightchild = k;

                 }

                 free(p);

                 count_node--;

                 return 1; //���\�a�R�� x�A�󦹶Ǧ^1��^�I�s�B

        }

        else //�|�����x�A�~�򩹤U�@���h��

            {  father = p;

               if (x < p->data)

                   p = p->leftchild;

               else

                   p = p->rightchild;

            }

     }

     return 0; //�����x�A�Ǧ^0

}

void print_BSTree(struct BSTreeNode * node)

{

	if (node != NULL)

   {  print_BSTree(node->leftchild);

	  tree += IntToStr(node->data)+", ";

	  print_BSTree(node->rightchild);

   }
}

void print_BSTree_preorder(struct BSTreeNode * node)

{  if (node != NULL)

   {  tree += IntToStr(node->data)+", ";

	  print_BSTree_preorder(node->leftchild);

	  print_BSTree_preorder(node->rightchild);

   }

}

void print_BSTree_postorder(struct BSTreeNode * node)

{  if (node != NULL)

   {
	  print_BSTree_preorder(node->leftchild);

	  print_BSTree_preorder(node->rightchild);

      tree += IntToStr(node->data)+", ";
   }

}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Form1->Memo1->Lines->Clear();
	Form1->Memo2->Lines->Clear();
	Form1->Memo3->Lines->Clear();
    Form1->Memo4->Lines->Clear();
    Form1->RadioButton1->Checked = True;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	Form1->Edit3->Text = IntToStr(TrackBar1->Position);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
    Form1->Edit4->Text = IntToStr(TrackBar2->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (Form1->RadioButton2->Checked) {
		Form1->Memo2->Lines->Add("Insert: "+Form1->Edit1->Text);
		InsertBST(StrToInt(Form1->Edit1->Text));
		tree = "";
		print_BSTree_preorder(root);
		Form1->Memo2->Lines->Add("Result: "+tree);
	}
	else if (Form1->RadioButton3->Checked) {
		Form1->Memo3->Lines->Add("Insert: "+Form1->Edit1->Text);
		InsertBST(StrToInt(Form1->Edit1->Text));
		tree = "";
		print_BSTree_postorder(root);
		Form1->Memo3->Lines->Add("Result: "+tree);
	}
	else{
		Form1->Memo1->Lines->Add("Insert: "+Form1->Edit1->Text);
		InsertBST(StrToInt(Form1->Edit1->Text));
		tree = "";
		print_BSTree(root);
		Form1->Memo1->Lines->Add("Result: "+tree);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{

	if (Form1->RadioButton2->Checked) {
		Form1->Memo2->Lines->Add("Delete: "+Form1->Edit2->Text);
		DeleteBSTree(StrToInt(Form1->Edit2->Text));
		tree = "";
		print_BSTree_preorder(root);
		Form1->Memo2->Lines->Add("Result: "+tree);
	}
	if (Form1->RadioButton3->Checked) {
		Form1->Memo3->Lines->Add("Delete: "+Form1->Edit2->Text);
		DeleteBSTree(StrToInt(Form1->Edit2->Text));
		tree = "";
		print_BSTree_postorder(root);
		Form1->Memo3->Lines->Add("Result: "+tree);
	}
	else{
		Form1->Memo1->Lines->Add("Delete: "+Form1->Edit2->Text);
		DeleteBSTree(StrToInt(Form1->Edit2->Text));
		tree = "";
		print_BSTree(root);
		Form1->Memo1->Lines->Add("Result: "+tree);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	srand(time(NULL));
	String total = "";
	int tmp, x;
	int range = StrToInt(Form1->Edit4->Text);
	int n = StrToInt(Form1->Edit3->Text);
	for (int i=0; i < n; i++) {
	   tmp = rand()%range+1;
	   total += IntToStr(tmp)+", ";
	   InsertBST(tmp);
	}

	if (Form1->RadioButton2->Checked) {
	   Form1->Memo2->Lines->Add("Random Element: "+total);
		tree = "";
		print_BSTree_preorder(root);
		Form1->Memo2->Lines->Add("Result: "+tree);
	}
	else if (Form1->RadioButton3->Checked) {
		Form1->Memo3->Lines->Add("Random Element: "+total);
		tree = "";
		print_BSTree_postorder(root);
		Form1->Memo3->Lines->Add("Result: "+tree);
	}

	else{
		Form1->Memo1->Lines->Add("Random Element: "+total);
		tree = "";
		print_BSTree(root);
		Form1->Memo1->Lines->Add("Result: "+tree);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
	tree="";
	LevelOrder(root);
	Form1->Memo4->Lines->Add("Result: "+tree);
}
//---------------------------------------------------------------------------

