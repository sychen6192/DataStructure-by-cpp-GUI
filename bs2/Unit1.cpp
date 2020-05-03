//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define max_size 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
TForm1 *Form1;
//---------------------------------------------------------------------------
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (int*) malloc(stack->capacity * sizeof(int));

    if (!stack->array)
        return NULL;
    return stack;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}


// A utility function to check if the given character is operand
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}


String infixToPostfix(char* exp)
{
    int i, k;

	// Create a stack of capacity equal to expression size
	struct Stack* stack = createStack(strlen(exp));
    if(!stack) // See if stack was created successfully
		return -1 ;

    for (i = 0, k = -1; exp[i]; ++i)
    {
        // If the scanned character is an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        // If the scanned character is an ．(．, push it to the stack.
        else if (exp[i] == '(')
            push(stack, exp[i]);

        // If the scanned character is an ．)・, pop and output from the stack
        // until an ．(． is encountered.
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // invalid expression
            else
                pop(stack);
        }
        else // an operator is encountered
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }

    }

    // pop all the operators from the stack
    while (!isEmpty(stack))
		exp[++k] = pop(stack);

	exp[++k] = '\0';
	return exp;
}

//========================================
String Stack[max_size];

String Stack_another[max_size];

int top = -1;

int top_another = -1;



void print_stack_another()

{ int i;

String data1 = "", data2 = "" ;

  for (i = 0; i <= top; i++) data1 += Stack[i]+" ";

  for (i = 0; i <= top_another; i++) data2 += Stack_another[i]+" ";

  Form1->Memo1->Lines->Add("Stack 1 => "+data1);

  Form1->Memo1->Lines->Add("Stack 2 => "+data2);

}

void push(int flag, String data)

{ switch (flag)

  {   case (1):

         if (top == max_size-1) Form1->Memo1->Lines->Add("Full");

         else Stack[++top] = data;

         break;

      case (2):

         if (top_another == max_size-1) Form1->Memo1->Lines->Add("Full");

         else Stack_another[++top_another] = data;

         break;

 }

}



String pop(int flag)

{ switch (flag)

  {   case (1):

           if (top == -1) Form1->Memo1->Lines->Add("Empty");

           else return Stack[top--];

           break;

      case (2):

           if (top_another == -1) Form1->Memo1->Lines->Add("Empty");

           else return Stack_another[top_another--];

           break;

  }

}



int p(String op)

{ if ((op == '+') || (op == '-') ) return 3 ;

  if ((op == '*') || (op == '/') ) return 4 ;

  if ((op == '^') || (op == '&') || (op == '|') ) return 5 ;

  if ((op == '(') ) return 8 ;

  if (op == '#') return 0 ;

}

int q(String op)

{ if ((op == '+') || (op == '-') ) return 3 ;

  if ((op == '*') || (op == '/') ) return 4 ;

  if ((op == '^') || (op == '&') || (op == '|') ) return 5 ;

  if ((op == '(')) return 1 ;

  if (op == '#') return 0 ;

}

void get_fix(String x, int flag)

{ String a = pop(2);

     a = (flag == 1) ? x+pop(2)+a : pop(2)+a+x;

     push(2, a) ;

}



boolean IsOperand(String s)

{ if (   (s!="+") && (s!="-") && (s!="*") && (s!="/")

   && (s!="(") && (s!=")")  && (s!="&") && (s!="|")

   && (s!="^") ) return true;

  return false;

}

String postfixTOprefix(String postfix)

{  int n = postfix.Length();

   int i;

 String s, x;

     for (i=1; i<=n; i++)

     {   s = postfix[i];

         if ( IsOperand(s) ) push(2, s);

         else get_fix(s, 1);

     }

     return pop(2);

}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Form1->Memo1->Lines->Clear();
	ComboBox1->Items->Add("(A+B)*(C+D)");
	ComboBox1->Items->Add("(A-B*C)+D^(E+F/G)");
	ComboBox1->Items->Add("A+(B*C-(D/E-F)*G)*H");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	AnsiString str = Edit1->Text;
	char *expp = str.c_str();

//	for (int i=1; i<=n; i++)
//	{
//		expp[i] = str[i];
//		ShowMessage(expp);
//	}


	AnsiString OutString = AnsiString(expp);

	Form1->Memo1->Lines->Add("infix:	"+OutString);
	Form1->Memo1->Lines->Add("postfix:	"+infixToPostfix(expp));
	Form1->Edit2->Text = infixToPostfix(expp);
//    Edit2->Text = "8787";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	AnsiString str = Edit1->Text;
	char *exp = str.c_str();
	AnsiString OutString = AnsiString(exp);
	Form1->Memo1->Lines->Add("infix:	"+OutString);
	Form1->Memo1->Lines->Add("prefix:	"+postfixTOprefix(infixToPostfix(exp)));
	Form1->Edit3->Text = postfixTOprefix(infixToPostfix(exp));
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Edit1->Text = ComboBox1->Text;
    Form1->Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------



