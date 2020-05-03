//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
struct node
{
	int data;
	struct node * next;
};
struct node * first, * last;
struct node * first_s, * last_s;
struct node * first_q, * last_q;

struct node * NewNode(int element){
	struct node * p;
	p = (struct node *) malloc(sizeof(struct node));
	p ->data = element;
	p->next = NULL;
	return p;
}

void insertFirst(int element)
{
	struct node *p = NewNode(element);
	p -> next = first->next;
	first-> next = p;
	if (last == first) {
		last= p;
	}
}

void insertLast(int element)
{
	struct node *p = NewNode(element);
	p -> next = last->next;
	last -> next = p;
	last = p;
}

void printList(struct node * first)
{
	struct node *p;
	String list = "";
	for (p=first->next; p!=first ; p=p->next) {
		list += IntToStr(p->data)+"->";
	}
	Form1->Memo1->Lines->Add(list+"<-");

}



void insertAfter(int element,struct node * x)
{
	struct node *p = NewNode(element);
	p->next = x->next;
	x -> next = p;
}
struct node * searchTarget(int target)
{
	struct node *p;
	for (p=first->next; (p!=first && p->data!=target); p=p->next);
	if (p==first) return NULL;
	return p;
}
struct node * searchTargetBefore(int target)
{
	struct node *p, *q;
	for (q=first, p=first->next; (p!=first && p->data!=target); q=p, p=p->next);
	if (p==first) return NULL;
	return q;
}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Lines->Clear();
	Memo2->Lines->Clear();
	Memo3->Lines->Clear();

	first = NewNode(0);
	first->next = first;
	last = first;

	first_q = NewNode(0);
	first_q->next = first_q;
	last_q = first_q;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int element = StrToInt(Edit1->Text);
	insertFirst(element);
	printList(first);

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int element = StrToInt(Edit1->Text);
	insertLast(element);
	printList(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int target = StrToInt(Edit2->Text);
	struct node * x;
	x = searchTarget(target);
	if (x) {
		Form1->Memo1->Lines->Add(IntToStr(x->data)+" has been found.");
	}
	else{
		Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");
	}
}

void deleteAfter(struct node * x)
{
	struct node *p = x ->next;
	x->next = p->next;
	if (p==last) {
		last = x;
	}
	free(p);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int target = StrToInt(Edit2->Text);
	int element = StrToInt(Edit1->Text);
	struct node * x;
	x = searchTarget(target);
	if (x) {
		insertAfter(element, x);
	}
	else{
		Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");
	}
	printList(first);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int target = StrToInt(Edit2->Text);
	int element = StrToInt(Edit1->Text);
	struct node * x;
	x = searchTargetBefore(target);
	if (x) {
		insertAfter(element, x);
	}
	else{
		Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");
	}
	printList(first);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int target = StrToInt(Edit2->Text);
	struct node * x;
	x = searchTargetBefore(target);
	if (x) {
		deleteAfter(x);
	}
	else{
		Form1->Memo1->Lines->Add(IntToStr(target)+" has NOT been found.");
	}
	printList(first);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	int n = StrToInt(Edit3->Text);
	int range = StrToInt(Edit4->Text);
	int * data = new int [n];
	String line = "";
	for (int i = 0; i < n; i++) {
		data[i] = rand() % range +1;
		line += IntToStr(data[i])+" ";
		insertLast(data[i]);
	}
	Form1->Memo1->Lines->Add(IntToStr(n)+" random numbers:"+line);
    printList(first);
}
//---------------------------------------------------------------------------




struct Node {
    int data;
    struct Node* link;
};

struct Node* top;


void push(int data)
{
    struct Node* temp;
    temp = new Node();

	if (!temp) {
        Form1->Memo2->Lines->Add("Stack Overflow");
    }

	temp->data = data;

    temp->link = top;

    top = temp;
}

int isEmpty()
{
    return top == NULL;
}

void pop()
{
    struct Node* temp;

	if (top == NULL) {
		Form1->Memo2->Lines->Add("Stack Underflow");

	}
    else {

		temp = top;

        top = top->link;

		temp->link = NULL;

		free(temp);
    }
}

void display()
{
    struct Node* temp;

	// check for stack underflow
	if (top == NULL) {
		Form1->Memo2->Lines->Add("Stack Underflow");

	}
    else {
		temp = top;
        String list;
        while (temp != NULL) {

			list += IntToStr(temp->data)+"->";

			temp = temp->link;
		}
		Form1->Memo2->Lines->Add(list);
	}
}

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	int element = StrToInt(Edit5->Text);
	push(element);
	display();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button9Click(TObject *Sender)
{
	pop();
	display();
}
//---------------------------------------------------------------------------

void enqueue_q(int element)
{
	struct node *p = NewNode(element);
	p -> next = last_q->next;
	last_q -> next = p;
	last_q = p;
}

void printList_q(struct node * first_q)
{
	struct node *p;
	String list = "";
	for (p=first_q->next; p!=first_q ; p=p->next) {
		list += IntToStr(p->data)+"->";
	}
	Form1->Memo3->Lines->Add(list+"<-");

}

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	int element = StrToInt(Edit6->Text);
	enqueue_q(element);
	printList_q(first_q);
}
//---------------------------------------------------------------------------
void dequeue()
{
	struct node *p;
    p = first_q;
	last_q->next = first_q->next;
	first_q = p->next;
	free(p);
    printList_q(first_q);
}


void __fastcall TForm1::Button11Click(TObject *Sender)
{
    dequeue();
}
//---------------------------------------------------------------------------

