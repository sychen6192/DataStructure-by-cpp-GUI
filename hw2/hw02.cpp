//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
#include "hw02.h"
#include <iostream>
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
#define SWAP(x, y, t) (t=x, x=y, y=t)
int count=0;
int n;
char my_list[255];
//---------------------------------------------------------------------------
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n == 1)
	{
		Form1->Memo3->Lines->Add("Step "+IntToStr(++count)+": Move disk 1 from rod "+String(from_rod)+" to rod "+String(to_rod));
		return;
	}
	towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
	Form1->Memo3->Lines->Add("Step "+IntToStr(++count)+": Move disk "+IntToStr(n)+" from rod "+String(from_rod)+" to rod "+String(to_rod));
	towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
void trace(char *my_list, char *list, int n, int i, int k){
	memcpy(my_list, list, n);
	my_list[n] = '\0';
	String s(my_list);
	Form1->Memo2->Lines->Add(">i="+IntToStr(i)+">(k,n)=("+IntToStr(k)+", "+IntToStr(n)+"), swap[k, x]=["+IntToStr(k)+", "+IntToStr(i)+"], list[]="+s);
}

void perm(char *list, int k, int n)

{   int i, tmp;
	if (k == n-1)

	{   String a = list;     // Convert char * list to String a

	   a = a.SubString(1, n);   // The first n characters of a

	   // a.SubString(1, n) ==> the n-char starting from a[1]

	   Form1->Memo1->Lines->Add(a+"  ["+IntToStr(count++)+"]");
	   if (Form1->CheckBox1->Checked) Form1->Memo2->Lines->Add("==>(k,n)=("+IntToStr(k)+", "+IntToStr(n)+")! k==n-1 print!");
	   if (Form1->CheckBox1->Checked) Form1->Memo2->Lines->Add(a+"  ["+IntToStr(count-1)+"]");

	}

	else

	{   for (i=k; i<n; i++)

	   {  SWAP(list[k], list[i], tmp);
		  if (Form1->CheckBox1->Checked){
		  trace(my_list, list, n, i, k);
		  }
		  perm(list, k+1, n);
		  SWAP(list[k], list[i], tmp);
		  if (Form1->CheckBox1->Checked){
		  trace(my_list, list, n, i, k);
		  }

	   }

	}

}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{   count = 0;
	int k = StrToInt(Edit1->Text);
	int n = StrToInt(Edit2->Text);
	char list [9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
	Memo1->Lines->Clear();
	Memo2->Lines->Clear();
	Memo2->Lines->Add("Go==>(k, n)=("+ Edit1->Text + ", "+ Edit2->Text +")");
	perm(list, k, n);
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button2Click(TObject *Sender)
{
	count = 0;
	Memo3->Lines->Clear();
	int n = StrToInt(Edit3->Text);
	towerOfHanoi(n, 'A', 'B', 'C');
	Form1->Memo3->Lines->Add("--------- "+IntToStr(count)+" steps in total for "+IntToStr(n)+" disks --------");
}
//---------------------------------------------------------------------------





