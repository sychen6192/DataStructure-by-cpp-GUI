//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <limits.h> 
#include <stdio.h> 
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;  
TForm1 *Form1;
int W [100][100];
int dist [100][100];
int V;
int k;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Form1->Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
int minDistance(int dist[], bool sptSet[]) 
{ 
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 
int printSolution(int dist[]) 
{ 
	int n = V;
	Form1->StringGrid3->RowCount = n+1;
	Form1->StringGrid3->ColCount = 2;

	for (int i = 0; i < n+1; i++)
	{
		Form1->StringGrid3->Cells[0][i+1] = i;
		Form1->StringGrid3->Cells[1][i+1] = dist[i];
	}
	Form1->StringGrid3->Cells[1][0] = "最近距離";
	if (Form1->CheckBox2->Checked) {
	Form1->Memo1->Lines->Add("Vertex \t\t Distance from Source"); 
	for (int i = 0; i < V; i++)
		Form1->Memo1->Lines->Add(IntToStr(i)+" \t\t "+IntToStr(dist[i]));
	}

} 
void dijkstra(int src) 

{ 
	int dist[V]; 

	bool sptSet[V]; 

	// Initialize all distances as INFINITE and stpSet[] as false 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	// Distance of source vertex from itself is always 0 
	dist[src] = 0; 

	// Find shortest path for all vertices 
	for (int count = 0; count < V - 1; count++) { 
		int u = minDistance(dist, sptSet); 

		sptSet[u] = true; 

		// Update dist value of the adjacent vertices of the picked vertex. 
		for (int v = 0; v < V; v++) 

			if (!sptSet[v] && W[u][v] && dist[u] != INT_MAX 
				&& dist[u] + W[u][v] < dist[v]) 
				dist[v] = dist[u] + W[u][v]; 
	} 

	printSolution(dist); 
} 
//---------------------------------------------------------------------------
void floydWarshall () 
{ 

	int i, j, k; 

	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = W[i][j]; 


	for (k = 0; k < V; k++){ 
		for (i = 0; i < V; i++) 
		{ 
			for (j = 0; j < V; j++) 
			{  
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	int n = V;
	Form1->StringGrid4->RowCount = n+1;
	Form1->StringGrid4->ColCount = n+1;
	
	for (int i = 0; i < n+1; i++)
	{
		Form1->StringGrid4->Cells[i+1][0] = i;
		Form1->StringGrid4->Cells[0][i+1] = i;
	}
	Form1->Memo1->Lines->Add("結果出現 ALL Pairs 在分頁中!");
	Form1->Memo1->Lines->Add(""); 
	 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{
//			Form1->Memo1->Text = IntToStr(dist[i][j])+" ";
			Form1->StringGrid4->Cells[j+1][i+1] = dist[i][j];
		}
		
	} 
} 


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	// init

	int i, j;
	int n = StrToInt(Form1->Edit1->Text);
	V = n;
	int range = StrToInt(Form1->Edit2->Text);
	int max_range = StrToInt(Form1->Edit3->Text);
	int LargeInt = StrToInt(Form1->Edit4->Text);
	
	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++) 
			W[i][j] = 0;

	

	StringGrid1->RowCount = n+1;
	StringGrid1->ColCount = n+1;

	for (i = 0; i < n+1; i++)
	{
		Form1->StringGrid1->Cells[i+1][0] = i;
		Form1->StringGrid1->Cells[0][i+1] = i;
	}
	
	// 無向圖
	if (Form1->CheckBox1->Checked) {
		for (int i=0; i <=n; i++) {
	
		for (j = i+1; j <=n; j++) {
			W[i][j] = rand()% range +1;
			if (W[i][j] > max_range) W[i][j] = LargeInt;
		}
	
		W[i][i] = LargeInt;
		
	}
		for (i = 0; i <= n; i++)
			for (j = 0; j <= i; j++)
				W[i][j] = W[j][i];
			
	}
	// 有向圖
	else{
		for (int i=0; i <=n; i++) {
	
			for (j = 0; j <=n; j++) {
				W[i][j] = rand()% range +1;
				if (W[i][j] > max_range) W[i][j] = LargeInt;
			}
	
			W[i][i] = LargeInt;

	}
    }

		
	for (i=1; i<=n+1; i++)
		for (j=1; j<=n+1; j++)
			Form1->StringGrid1->Cells[j][i] = W[i][j];

}
//---------------------------------------------------------------------------
 void __fastcall TForm1::Button5Click(TObject *Sender)
{

	int i, j;
	int n = StrToInt(Form1->Edit1->Text);
	V = n;
	int range = StrToInt(Form1->Edit2->Text);
	int max_range = StrToInt(Form1->Edit3->Text);
	int LargeInt = StrToInt(Form1->Edit4->Text);

			
	StringGrid2->RowCount = n+1;
	StringGrid2->ColCount = n+1;
	
	for (i = 0; i < n+1; i++)
	{
		Form1->StringGrid2->Cells[i+1][0] = i;
		Form1->StringGrid2->Cells[0][i+1] = i;
	}
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (W[i][j]==LargeInt) {
				Form1->StringGrid2->Cells[j][i] = 0;
			}
			else {
			   Form1->StringGrid2->Cells[j][i] = 1;
			}
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int src_no = StrToInt(Form1->Edit5->Text);
	dijkstra(src_no);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	floydWarshall();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	FILE *fp;     // Define fp as a pointer pointing to some file (with data type FILE) in HD

	String out;

	int i, j;

	AnsiString infile;   // Use builder's string (AnsiString) to ease the conversion (into const char *)

	if (OpenDialog1->Execute())

	{
	  infile = OpenDialog1->FileName;
	  fp = fopen(infile.c_str(), "r+");
	  fscanf(fp, "%d %d", &k, &k);    // Read in two integers n & n
	  Memo1->Lines->Add("成功讀取(n, n)="+IntToStr(k)+", "+IntToStr(k));
	  for (i=1; i<=k; i++)    // Read in n*n weights
		for (j=1; j<=k; j++)
			fscanf(fp, "%d", &W[i][j]);

	  fclose(fp);	

	  }
}
//---------------------------------------------------------------------------


