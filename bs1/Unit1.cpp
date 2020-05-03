//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream>
#include <sstream>
#include <string>
#include "Unit1.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void power(double x, int n, int t){
	clock_t t_begin, t_end;
	t_begin = clock();
	for (int i = 0; i < t; i++)  pow(x, n);
	t_end = clock();

	Form1->Memo1->Lines->Add("pow(k, n) = "+FloatToStr(pow(x, n))+" ["+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC)+" (sec.)] "+IntToStr(t)+" times");
}
void power_loop(double x, int n, int t){
	clock_t t_begin, t_end;
	t_begin = clock();
	double ans = 1;
	for (int i = 0; i < t; i++){
		for (int i = 0; i < n; i++) {
		   ans *= x;
		}
		ans = 1;
	}
	t_end = clock();

	Form1->Memo1->Lines->Add("        k^n = "+FloatToStr(pow(x, n))+" ["+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC)+" (sec.)] "+IntToStr(t)+" times");
}
double power_recursive(double x, int n)
{

	if(n == 0)
		return 1;

	else
		return x * power_recursive(x, n-1);
}

double recursive_log(double x, int n)
{
	if(n == 0) return 1;

	double d = recursive_log(x, n/2);

	if(n % 2 == 0) return d*d;
	else return x*d*d;
}

int horner(String poly, int n, int x)
{
	int result = StrToInt(poly[1]);  // Initialize result

	// Evaluate value of polynomial using Horner's method
	for (int i=2; i<=n; i++)
		result = result*x + StrToInt(poly[i]);

    return result;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{

	int x = StrToInt(Edit1->Text);
	int n = StrToInt(Edit2->Text);
	int t = StrToInt(Edit3->Text);
	Memo1->Lines->Clear();
	if (Form1->CheckBox1->Checked) {
		power(x,n,t);
	}
	if (Form1->CheckBox2->Checked) {
		power_loop(x,n,t);
	}
	if (Form1->CheckBox3->Checked) {
		clock_t t_begin, t_end;
		t_begin = clock();
		for (int i = 0 ; i < t ; i++) power_recursive(x,n);
		t_end = clock();
		Form1->Memo1->Lines->Add("       =k^n = "+FloatToStr(power_recursive(x,n))+" ["+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC)+" (sec.)] "+IntToStr(t)+" times");
	}
	if (Form1->CheckBox3->Checked) {
		clock_t t_begin, t_end;
		t_begin = clock();
		for (int i = 0 ; i < t ; i++) recursive_log(x,n);
		t_end = clock();
		Form1->Memo1->Lines->Add("      ==k^n = "+FloatToStr(recursive_log(x,n))+" ["+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC)+" (sec.)] "+IntToStr(t)+" times");
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Memo2->Lines->Clear();
	int x = StrToInt(Edit5->Text);
	int n = StrToInt(Edit6->Text);
	String poly = Edit4->Text;
//	poly = ss(poly);
//	String token;
//	int * arr;
//	arr = new int (n);
//	int i = 0;

	Form1->Memo2->Lines->Add(IntToStr(horner(poly, n, x)));
}
//---------------------------------------------------------------------------
