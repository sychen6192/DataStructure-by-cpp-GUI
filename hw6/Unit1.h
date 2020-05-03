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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TEdit *Edit1;
	TLabel *Label1;
	TButton *Button1;
	TLabel *Label2;
	TEdit *Edit2;
	TButton *Button2;
	TTrackBar *TrackBar1;
	TLabel *Label3;
	TTrackBar *TrackBar2;
	TLabel *Label4;
	TEdit *Edit3;
	TEdit *Edit4;
	TMemo *Memo1;
	TButton *Button3;
	TRadioGroup *RadioGroup1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TTabSheet *TabSheet2;
	TMemo *Memo2;
	TTabSheet *TabSheet3;
	TMemo *Memo3;
	TRadioButton *RadioButton3;
	TButton *Button4;
	TTabSheet *TabSheet4;
	TMemo *Memo4;
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
