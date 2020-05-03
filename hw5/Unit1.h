//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TSplitter *Splitter1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TPageControl *PageControl2;
	TTabSheet *TabSheet4;
	TTabSheet *TabSheet5;
	TTabSheet *TabSheet6;
	TButton *Button1;
	TEdit *Edit1;
	TLabel *Label1;
	TMemo *Memo1;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label2;
	TEdit *Edit2;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TLabel *Label3;
	TEdit *Edit3;
	TLabel *Label4;
	TEdit *Edit4;
	TButton *Button7;
	TMemo *Memo2;
	TMemo *Memo3;
	TButton *Button8;
	TEdit *Edit5;
	TLabel *Label5;
	TButton *Button9;
	TLabel *Label6;
	TEdit *Edit6;
	TButton *Button10;
	TButton *Button11;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
