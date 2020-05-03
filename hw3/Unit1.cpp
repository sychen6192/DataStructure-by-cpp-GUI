//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define Maxsize 21
TForm1 *Form1;
using namespace std;
//---------------------------------------------------------------------------
int square[21][21];
void Clear(){
for(int i=0;i<Form1->StringGrid1->RowCount;i++){
for(int j=0;j<Form1->StringGrid1->ColCount;j++){
	Form1->StringGrid1->Cells[j][i] = "";
	Form1->StringGrid2->Cells[j][i] = "";
	}
}
}
void MagicSquare(int n)
{   Form1->Memo1->Lines->Clear();
	int i, j, k, l, data;
	if ((n>21) || (n<1)){
		Form1->Memo1->Lines->Add(TimeToStr(Now())+"  Please input the number in the range!");
	}
	else if ((n%2)==0)
	{
		Form1->Memo1->Lines->Add(TimeToStr(Now())+"  Please input odd number!");
	}
	else
	{
		Form1->Memo1->Lines->Add(TimeToStr(Now())+"  Generate success!!!");
    }

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			square[i][j]=0;
		}
	}
	i=0;
	j=(n-1)/2;
	square[i][j]=1;
	data = 2;
	while (data <= n*n)
	{
		k = (i-1<0) ? n-1 : i-1;
		l = (j-1<0) ? n-1 : j-1;
		if (square[k][l] > 0 ) {
			i = (i+1)%n;
		}
		else{
			i=k;
            j=l;
		}
        square[i][j] = data++;
    }

}
void MagicSquare2(int n)
{   Form1->Memo2->Lines->Clear();
	int i, j, k, l, data;
	if ((n>21) || (n<1)){
		Form1->Memo2->Lines->Add(TimeToStr(Now())+"  Please input the number in the range!");
	}
	else if ((n%2)==0)
	{
		Form1->Memo2->Lines->Add(TimeToStr(Now())+"  Please input odd number!");
	}
	else
	{
		Form1->Memo2->Lines->Add(TimeToStr(Now())+"  Generate success!!!");


	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			square[i][j]=0;
		}
	}
	i=0;
	j=(n-1)/2;
	square[i][j]=1;
	data = 2;
	while (data <= n*n)
	{
		k = (i+1>n-1) ? 0 : i+1;
		l = (j+1>n-1) ? 0 : j+1;
		if (square[k][l] > 0 ) {  // HAVE INT
			i = (i+4)%n;
		}
		else{
			i=k;
            j=l;
		}
        square[i][j] = data++;
	}
	}

}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n = StrToInt(Edit1->Text);
	MagicSquare(n);
	StringGrid1->RowCount = n;

	StringGrid1->ColCount = n;

	if ((n>21) || (n<1)){
		Clear();
	}
	else if ((n%2)==0)
	{
		Clear();
	}
	else{
	for (int i=0; i<n; i++)

	{   for (int j=0; j<n; j++)

		{   StringGrid1->Cells[j][i] = IntToStr(square[i][j]);

		}

	}
	}

	MagicSquare2(n);
	StringGrid2->RowCount = n;

	StringGrid2->ColCount = n;
	if ((n>21) || (n<1)){
		Clear();
	}
	else if ((n%2)==0)
	{
		Clear();
	}
	else{
	for (int i=0; i<n; i++)

	{   for (int j=0; j<n; j++)

		{   StringGrid2->Cells[j][i] = IntToStr(square[i][j]);

		}

	}
	}
}
//---------------------------------------------------------------------------





