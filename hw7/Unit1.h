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
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TLabel *Label1;
	TButton *Button1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TButton *Button2;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TMemo *Memo1;
	TStringGrid *StringGrid1;
	TOpenDialog *OpenDialog1;
	TTabSheet *TabSheet4;
	TTabSheet *TabSheet5;
	TStringGrid *StringGrid2;
	TStringGrid *StringGrid3;
	TStringGrid *StringGrid4;
	TLabel *Label8;
	TCheckBox *CheckBox3;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
