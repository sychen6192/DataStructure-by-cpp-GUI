object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 713
  ClientWidth = 1018
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1018
    Height = 321
    Align = alTop
    Caption = 'Panel1'
    TabOrder = 0
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 1016
      Height = 319
      ActivePage = TabSheet3
      Align = alClient
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'Singly linked list'
        object Label1: TLabel
          Left = 16
          Top = 51
          Width = 45
          Height = 13
          Caption = 'Element: '
        end
        object Label2: TLabel
          Left = 184
          Top = 51
          Width = 34
          Height = 13
          Caption = 'target:'
        end
        object Label3: TLabel
          Left = 408
          Top = 51
          Width = 10
          Height = 13
          Caption = 'n:'
        end
        object Label4: TLabel
          Left = 408
          Top = 101
          Width = 32
          Height = 13
          Caption = 'range:'
        end
        object Button1: TButton
          Left = 40
          Top = 96
          Width = 75
          Height = 25
          Caption = 'Insert first'
          TabOrder = 0
          OnClick = Button1Click
        end
        object Edit1: TEdit
          Left = 60
          Top = 48
          Width = 55
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object Button2: TButton
          Left = 40
          Top = 136
          Width = 75
          Height = 25
          Caption = 'Insert Last'
          TabOrder = 2
          OnClick = Button2Click
        end
        object Button3: TButton
          Left = 216
          Top = 92
          Width = 120
          Height = 30
          Caption = 'Search target'
          TabOrder = 3
          OnClick = Button3Click
        end
        object Edit2: TEdit
          Left = 224
          Top = 48
          Width = 75
          Height = 21
          TabOrder = 4
          Text = '0'
        end
        object Button4: TButton
          Left = 216
          Top = 136
          Width = 120
          Height = 32
          Caption = 'Search Insert after'
          TabOrder = 5
          OnClick = Button4Click
        end
        object Button5: TButton
          Left = 216
          Top = 184
          Width = 120
          Height = 32
          Caption = 'Search Insert before'
          TabOrder = 6
          OnClick = Button5Click
        end
        object Button6: TButton
          Left = 216
          Top = 232
          Width = 120
          Height = 32
          Caption = 'Search Delete'
          TabOrder = 7
          OnClick = Button6Click
        end
        object Edit3: TEdit
          Left = 448
          Top = 48
          Width = 73
          Height = 21
          TabOrder = 8
          Text = '10'
        end
        object Edit4: TEdit
          Left = 448
          Top = 98
          Width = 73
          Height = 21
          TabOrder = 9
          Text = '1000'
        end
        object Button7: TButton
          Left = 440
          Top = 144
          Width = 145
          Height = 25
          Caption = 'Insert n random numbers'
          TabOrder = 10
          OnClick = Button7Click
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Linked stack'
        ImageIndex = 1
        object Label5: TLabel
          Left = 80
          Top = 64
          Width = 42
          Height = 13
          Caption = 'Element:'
        end
        object Button8: TButton
          Left = 80
          Top = 152
          Width = 185
          Height = 81
          Caption = 'Push'
          TabOrder = 0
          OnClick = Button8Click
        end
        object Edit5: TEdit
          Left = 128
          Top = 61
          Width = 65
          Height = 21
          TabOrder = 1
          Text = '10'
        end
        object Button9: TButton
          Left = 344
          Top = 152
          Width = 185
          Height = 81
          Caption = 'POP'
          TabOrder = 2
          OnClick = Button9Click
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'Linked Queue'
        ImageIndex = 2
        object Label6: TLabel
          Left = 80
          Top = 64
          Width = 45
          Height = 13
          Caption = 'Element: '
        end
        object Edit6: TEdit
          Left = 131
          Top = 61
          Width = 65
          Height = 21
          TabOrder = 0
          Text = '10'
        end
        object Button10: TButton
          Left = 80
          Top = 152
          Width = 185
          Height = 81
          ParentCustomHint = False
          Caption = 'Enqueue'
          TabOrder = 1
          OnClick = Button10Click
        end
        object Button11: TButton
          Left = 344
          Top = 152
          Width = 185
          Height = 81
          Caption = 'Dequeue'
          TabOrder = 2
          OnClick = Button11Click
        end
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 321
    Width = 1018
    Height = 392
    Align = alClient
    Caption = 'Panel2'
    TabOrder = 1
    object Splitter1: TSplitter
      Left = 1
      Top = 1
      Width = 1016
      Height = 3
      Cursor = crVSplit
      Align = alTop
      ExplicitWidth = 670
    end
    object PageControl2: TPageControl
      Left = 1
      Top = 4
      Width = 1016
      Height = 387
      ActivePage = TabSheet5
      Align = alClient
      TabOrder = 0
      object TabSheet4: TTabSheet
        Caption = 'Linked list output'
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 1008
          Height = 359
          Align = alClient
          Lines.Strings = (
            'Memo1')
          TabOrder = 0
        end
      end
      object TabSheet5: TTabSheet
        Caption = 'Linked stack output'
        ImageIndex = 1
        object Memo2: TMemo
          Left = 0
          Top = 0
          Width = 1008
          Height = 359
          Align = alClient
          Lines.Strings = (
            'Memo2')
          TabOrder = 0
        end
      end
      object TabSheet6: TTabSheet
        Caption = 'Linked Queue output'
        ImageIndex = 2
        object Memo3: TMemo
          Left = 0
          Top = 0
          Width = 1008
          Height = 359
          Align = alClient
          Lines.Strings = (
            'Memo3')
          TabOrder = 0
        end
      end
    end
  end
end
