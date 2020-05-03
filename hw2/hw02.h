//---------------------------------------------------------------------------

#ifndef hw02H
#define hw02H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TSplitter *Splitter1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TMemo *Memo2;
	TMemo *Memo1;
	TPageControl *PageControl2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet5;
	TMemo *Memo3;
	TTabSheet *TabSheet4;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	TCheckBox *CheckBox1;
	TEdit *Edit3;
	TButton *Button2;
	TLabel *Label5;
	TButton *Button1;
	TLabel *Label4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
