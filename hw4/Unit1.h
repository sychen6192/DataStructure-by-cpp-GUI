//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TSplitter *Splitter1;
	TPanel *Panel2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TGroupBox *GroupBox1;
	TMemo *Memo1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TTabSheet *TabSheet2;
	TStringGrid *StringGrid1;
	TOpenDialog *OpenDialog1;
	TTabSheet *TabSheet3;
	TStringGrid *StringGrid2;
	TGroupBox *GroupBox2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit3;
	TLabel *Label6;
	TButton *Button4;
	TTabSheet *TabSheet4;
	TMemo *Memo2;
	TButton *Button5;
	TTabSheet *TabSheet5;
	TStringGrid *StringGrid3;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall StringGrid1Click(TObject *Sender);
	void __fastcall StringGrid2DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall StringGrid2Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall StringGrid3DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
