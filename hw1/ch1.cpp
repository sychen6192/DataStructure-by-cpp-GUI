//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ch1.h"
#include <time.h>
//---------------------------------------------------------------------------
//#include "SimpleChart.h"
//#pragma link "Chart"
//#pragma link "TeEngine"
//#pragma link "TeeProcs"
//#pragma link "Series"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n;
int data [100000];
int original_data [ 100000 ];
double SelSortTime [10];    // declare Time arrays, which would keep real CPU times
double BubSortTime [10];
double RandGenTime [10];
int count_n[10];
int count_sel = -1;
int count_bub = -1;
int count_ran = -1;
#define SWAP(x, y, t) (t=x, x=y, y=t)
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void SelectionSort(int data[], int n)
{   int i, j, temp, min;
	for (i = 0; i < n; i++)
	{   min = i;
		for(j = i+1; j < n; j++)
		{   if (data[j] < data[min])
			{   min = j;
			}
		}
		SWAP(data[min], data[i], temp);
	}
}

void BubbleSort(int data[], int n)
{
	int i, j, temp;
	for (i = n-1; i >= 0; i--)
	{   for (j = 1; j < i+1; j++)
		{   if (data[j-1] > data[j])
			{
				SWAP(data[j-1], data[j], temp);
			}
		}
	}

	}

int BinarySearch(int data[], int n, int target)
{   int left = 0, right = n, middle;
		while (left <= right)
			{   middle = (left+right)/2;
				if(data[middle] == target){
					return middle;}
				else if (data[middle] < target) {
						 left = middle+1;
					 }
				else{
					right = middle-1;}
			}
		return -1;

}
void printData(int data[], int n, int flag)
{   if (flag == 1)
	{	for (int i = 0; i < n; i++)
		{Form1->Memo1->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
		}
	}
	else if (flag == 2)
	{	for (int i = 0; i < n; i++)
		{Form1->Memo2->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
		}
	}
	else
	{	for (int i = 0; i < n; i++)
		{Form1->Memo3->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
		}
	}

}

void checkData(int data[], int n, int flag)
{   int stat = 0;
	for (int i = 0; i < n-1; i++)
	{
	if (data[i] > data[i+1])
		stat = 1;
	}

	if (stat == 0) {
	if (flag == 1){
		Form1->Memo1->Lines->Add("Correct Sorting!");}
	else if (flag == 2){
		Form1->Memo2->Lines->Add("Correct Sorting!");}
	else{
		Form1->Memo3->Lines->Add("Correct Sorting");}
	}

	else {
	if (flag == 1){
		Form1->Memo1->Lines->Add("Wrong Sorting!");}
	else if (flag == 2){
		Form1->Memo2->Lines->Add("Wrong Sorting!");}
	else{
		Form1->Memo3->Lines->Add("Wrong Sorting!");}
	}

    }


void getData(int data[], int original_data[], int n)
{
	for (int i = 0; i < n; i++) {
        data[i] = original_data[i];
	}
}
void RandData(int data[], int n, int range)
{   srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
	data[i] = rand() % range +1;
	original_data[i] = data[i]; //backup
	}
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{	n = StrToInt(Edit1->Text);        // 直接蓋掉全域變數
	int range =StrToInt(Edit2->Text);
	int i;
	clock_t t_begin, t_end;
	t_begin = clock();
	RandData(data, n, range);
	if (Form1->CheckBox1->Checked) printData(data, n, 1);
	t_end = clock();
	Form1->Memo1->Lines->Add("CPU time (sec.) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
	count_ran++;
	RandGenTime[count_ran] = (float)(t_end-t_begin)/CLOCKS_PER_SEC;
	count_n[count_ran] = n;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{   clock_t t_begin, t_end;
	t_begin = clock();
    getData(data, original_data, n);
	SelectionSort(data, n);
	t_end = clock();
	if (Form1->CheckBox1->Checked) printData(data, n, 2);
	if (Form1->CheckBox2->Checked) checkData(data, n, 2);
	Form1->Memo2->Lines->Add("CPU time (sec.) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
	count_sel++;
	SelSortTime[count_sel] = (float)(t_end-t_begin)/CLOCKS_PER_SEC;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{   clock_t t_begin, t_end;
	t_begin = clock();
	getData(data, original_data, n);
	BubbleSort(data, n);
	t_end = clock();
	if (Form1->CheckBox1->Checked) printData(data, n, 3);
	if (Form1->CheckBox2->Checked) checkData(data, n, 3);
	Form1->Memo3->Lines->Add("CPU time (sec.) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
	count_bub++;
	BubSortTime[count_sel] = (float)(t_end-t_begin)/CLOCKS_PER_SEC;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{   int target = StrToInt(Edit3->Text);
	int success = -1;
	success = BinarySearch(data, n, target);
	if (success >= 0 && success < n) {
		Memo4->Lines->Add(IntToStr(target)+" has been found in data["+IntToStr(success)+"]");
	}
	else{
		 Memo4->Lines->Add(IntToStr(target)+" has not been found in data");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{		int i;
        Chart1->RemoveAllSeries();             // Remove all previous series
        Chart1->Title->Text->Clear();         // Clear chart chart title
		Chart1->Title->Text->Add("CPU time chart");
        Chart1->BottomAxis->Title->Caption = "data size";    // x-axis' title
		Chart1->LeftAxis->Title->Caption = "CPU time (sec.)";    // y-axis' title

        Chart1->AddSeries( new TBarSeries (this) );      // create a new BAR series
        Chart1->Series[0]->Title = "Selection Sort";
		Chart1->Series[0]->AddArray( SelSortTime, 5 );

                // assign the values in SelSortTime onto the series one by one from 0 to 5
        Chart1->AddSeries( new TBarSeries (this) );
		Chart1->Series[1]->Title = "Bubble Sort";

				for (i=0; i<6; i++) Chart1->Series[1]->Add( BubSortTime[i], count_n[i], clGreen );

				// assign the values in BubSortTime onto the series one by one from 0 to 5
        Chart1->AddSeries( new TLineSeries (this) );      // create a new LINE series
		Chart1->Series[2]->Title = "Data generation";
		Chart1->Series[2]->AddArray( RandGenTime, 5 );

        for (int i=0; i<3; i++)     // Set marks visible
        {      Chart1->Series[i]->Marks->Visible = true;
                Chart1->Series[i]->Marks->Style = smsValue;
		}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


