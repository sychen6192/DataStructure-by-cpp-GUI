//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "stdio.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define MaxStack 1000
TForm1 *Form1;
int maze [100][100];
int m, n;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	FILE *fp;     // Define fp as a pointer pointing to some file (with data type FILE) in HD

	String out;

	int i, j;

	AnsiString infile;   // Use builder's string (AnsiString) to ease the conversion (into const char *)

	if (OpenDialog1->Execute())

	{
	  Form1->Memo1->Lines->Clear();
	  infile = OpenDialog1->FileName;
	  fp = fopen(infile.c_str(), "r+");
	  fscanf(fp, "%d %d", &m, &n);    // Read in two integers m & n
	  Memo1->Lines->Add("(m, n)="+IntToStr(m)+", "+IntToStr(n));
	  for (i=1; i<=m; i++)    // Read in m*n 0/1/2's into maze[][]
		for (j=1; j<=n; j++)
			fscanf(fp, "%d", &maze[i][j]);

	  fclose(fp);

	  for (i=1; i<=m; i++)      // Print out maze[][] in Memo1
	  {
	   out = "";
	   for (j=1; j<=n; j++) out += "  "+IntToStr(maze[i][j]);
	   Memo1->Lines->Add(out);
	  }
		// Print out maze[][] in StringGrid1

	 StringGrid1->RowCount = m;
	 StringGrid1->ColCount = n;
	 StringGrid2->RowCount = m;
	 StringGrid2->ColCount = n;
	 StringGrid3->RowCount = m;
	 StringGrid3->ColCount = n;
	  for (i=1; i<=m; i++)
		 for (j=1; j<=n; j++)
			StringGrid1->Cells[j-1][i-1] = maze[i][j];
	}
	StringGrid2->GridLineWidth = 0;
	int gridSize = StrToInt(Edit3->Text);
	for (i=0; i<m; i++) StringGrid1->ColWidths[i] = gridSize;
	for (i=0; i<n; i++) StringGrid1->RowHeights[i] = gridSize;
	for (i=0; i<m; i++) StringGrid2->ColWidths[i] = gridSize;
	for (i=0; i<n; i++) StringGrid2->RowHeights[i] = gridSize;
	for (i=0; i<m; i++) StringGrid3->ColWidths[i] = gridSize;
	for (i=0; i<n; i++) StringGrid3->RowHeights[i] = gridSize;
	StringGrid1->Refresh();
	StringGrid2->Refresh();
	StringGrid3->Refresh();
}
//---------------------------------------------------------------------------
struct offset

{    int x, y;

};

enum direction {E,S,W,N};    // 4 directions are considered

struct position

{    int x, y;

     direction dir;

};

position stack [MaxStack];
int top = -1;

void push(position step)

{   if (top == m*n) Form1->Memo2->Lines->Add("Stack is full");

    else stack[++top] = step;

}

position pop()

{   if (top == -1) Form1->Memo2->Lines->Add("Stack is empty");

    else return stack[top--];

}

void MouseInMaze(int Height, int Width)

{   int i, j, u, v;
	bool found = false;
	offset move[4];


	move[E].x = 0; move[E].y = 1;
	move[S].x = 1; move[S].y = 0;
	move[W].x = 0; move[W].y = -1;
	move[N].x = -1; move[N].y = 0;
	position step;


	maze[1][0] = 3;
	step.x = 1;
	step.y = 1;
	step.dir = E;
//	maze[1][1] = 3;
	push(step);
	while (top != -1 && !found)     // keep moving till stack empty OR found

	{
		step = pop();
		i = step.x; j = step.y; step.dir = step.dir;
		while (step.dir <= N && !found)

		{   u = i + move[step.dir].x;
			v = j + move[step.dir].y;

			if (u == Height - 1 && v == Width)    // whether the EXIT is found

			{ found = true;

				step.x = i; step.y = j;

				push(step);

				maze[u][v] = 3;
//                top --;



				while (top != -1)        // all positions in stack constitute the tour from entrance to exit

				{   position s = pop();

					Form1->Memo2->Lines->Add("Step :(" + IntToStr(s.x) + "," + IntToStr(s.y) + ")");

				}

				 break;

			}
			if (maze[u][v] == 0)       // a feasible step has been found

				{

					maze[u][v] = 3;        // mark this position



				step.x = i; step.y = j;
				step.dir = direction(step.dir + 1);

				push(step);                // push previous position/next direction into stack

				i = u; j = v; step.dir = E;// move to the feasible position

			}
		  else
				{
//				ShowMessage(direction(step.dir));
				step.dir = direction(step.dir + 1);
				}

		}


    }

	  for (i=1; i<=m; i++)
		 for (j=1; j<=n; j++)
			Form1->StringGrid3->Cells[j-1][i-1] = maze[i][j];

}



void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
	StringGrid1->Canvas->Brush->Color = clWhite;

	StringGrid1->Canvas->Font->Color = clBlue;

	StringGrid1->Canvas->FillRect(Rect);

	AnsiString text = StringGrid1->Cells[ACol][ARow];

	StringGrid1->Canvas->TextRect(Rect, Rect.Left+8, Rect.Top+8, text);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid1Click(TObject *Sender)
{
	TRect Recto = StringGrid1->CellRect(StringGrid1->Col, StringGrid1->Row);

	 int width = Recto.Width();
	 int height = Recto.Height();

	 Label3->Caption = "Cell: ["+IntToStr(StringGrid1->Col)+", "+IntToStr(StringGrid1->Row)+"] = "+StringGrid1->Cells[StringGrid1->Col][StringGrid1->Row];;

	 Label4->Caption = "Size: "+IntToStr(width)+"X"+IntToStr(height);

	 Label5->Caption = StringGrid1->Cells[StringGrid1->Col][StringGrid1->Row];

}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid2DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
	AnsiString text = StringGrid1->Cells[ACol][ARow];
	StringGrid2->Canvas->Brush->Color = clWhite;
	if (text == "0")
		 StringGrid2->Canvas->Brush->Color = RGB(250, 245, 135);
	else if (text == "1")
		 StringGrid2->Canvas->Brush->Color = RGB(80, 80, 80);
	else if (text == "2")
		 StringGrid2->Canvas->Brush->Color = RGB(0, 0, 0);
	else
		 StringGrid2->Canvas->Brush->Color = RGB(255, 255, 255);

	StringGrid2->Canvas->FillRect(Rect);

	StringGrid2->Canvas->TextRect(Rect, Rect.Left+6, Rect.Top+8, text);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Form1->Memo1->Lines->Clear();
	m = StrToInt(Edit1->Text);
	n = StrToInt(Edit2->Text);
	Memo1->Lines->Add("(m, n)="+IntToStr(m)+", "+IntToStr(n));
	int i, j;
	String out;
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
			maze[i][j] =  rand() % 3;

	for (i=1; i<=m; i++)      // Print out maze[][] in Memo1
	  {
	   out = "";
	   for (j=1; j<=n; j++) out += "  "+IntToStr(maze[i][j]);
	   Memo1->Lines->Add(out);
	  }
		// Print out maze[][] in StringGrid1

	 StringGrid1->RowCount = m;
	 StringGrid1->ColCount = n;
	 StringGrid2->RowCount = m;
	 StringGrid2->ColCount = n;
	  for (i=1; i<=m; i++)
		 for (j=1; j<=n; j++)
			StringGrid1->Cells[j-1][i-1] = maze[i][j];

	int gridSize = StrToInt(Edit3->Text);
	for (i=0; i<m; i++) StringGrid1->ColWidths[i] = gridSize;
	for (i=0; i<n; i++) StringGrid1->RowHeights[i] = gridSize;
	for (i=0; i<m; i++) StringGrid2->ColWidths[i] = gridSize;
	for (i=0; i<n; i++) StringGrid2->RowHeights[i] = gridSize;
    StringGrid2->GridLineWidth = 0;
	StringGrid1->Refresh();
	StringGrid2->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    // remember to use sglobal variable to get m,n
	int gridSize = StrToInt(Edit3->Text);
    int i;
	for (i=0; i<m; i++) StringGrid1->ColWidths[i] = gridSize;
	for (i=0; i<n; i++) StringGrid1->RowHeights[i] = gridSize;
	for (i=0; i<m; i++) StringGrid2->ColWidths[i] = gridSize;
	for (i=0; i<n; i++) StringGrid2->RowHeights[i] = gridSize;
	for (i=0; i<m; i++) StringGrid3->ColWidths[i] = gridSize;
	for (i=0; i<n; i++) StringGrid3->RowHeights[i] = gridSize;
	StringGrid1->Refresh();
	StringGrid2->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid2Click(TObject *Sender)
{
	TRect Recto = StringGrid2->CellRect(StringGrid2->Col, StringGrid2->Row);

	 int width = Recto.Width();
	 int height = Recto.Height();

	 Label3->Caption = "Cell: ["+IntToStr(StringGrid2->Col)+", "+IntToStr(StringGrid2->Row)+"] = "+StringGrid2->Cells[StringGrid2->Col][StringGrid2->Row];

	 Label4->Caption = "Size: "+IntToStr(width)+"X"+IntToStr(height);

	 Label5->Caption = StringGrid2->Cells[StringGrid2->Col][StringGrid2->Row];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Form1->Memo2->Clear();

	MouseInMaze(m, n);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::StringGrid3DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	AnsiString text = StringGrid3->Cells[ACol][ARow];
	StringGrid3->Canvas->Brush->Color = clWhite;
    if (text == "0")
		 StringGrid3->Canvas->Brush->Color = RGB(250, 245, 135);
	else if (text == "1")
		 StringGrid3->Canvas->Brush->Color = RGB(80, 80, 80);
	else if (text == "2")
		 StringGrid3->Canvas->Brush->Color = RGB(0, 0, 0);
	else if (text == "3")
		 StringGrid3->Canvas->Brush->Color = RGB(0, 191, 255);
	else
		 StringGrid3->Canvas->Brush->Color = RGB(255, 255, 255);
	StringGrid3->Canvas->FillRect(Rect);
    StringGrid3->GridLineWidth = 0;
//	StringGrid3->Canvas->TextRect(Rect, Rect.Left+6, Rect.Top+8, text);
}
//---------------------------------------------------------------------------


