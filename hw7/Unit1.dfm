object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 
    'Shortest Path (SSAD, All Pairs, Transitive Closure) by S.Y. Chen' +
    ' 2019_1230 Ver 0.1'
  ClientHeight = 755
  ClientWidth = 984
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
    Width = 345
    Height = 755
    Align = alLeft
    TabOrder = 0
    ExplicitLeft = -2
    object Label1: TLabel
      Left = 24
      Top = 32
      Width = 42
      Height = 13
      Caption = 'G=(V, E)'
    end
    object Label2: TLabel
      Left = 48
      Top = 104
      Width = 101
      Height = 13
      Caption = 'Randomly Generated'
    end
    object Label3: TLabel
      Left = 64
      Top = 144
      Width = 20
      Height = 13
      Caption = 'n = '
    end
    object Label4: TLabel
      Left = 64
      Top = 176
      Width = 72
      Height = 13
      Caption = 'range(w(e)) = '
    end
    object Label5: TLabel
      Left = 64
      Top = 208
      Width = 45
      Height = 13
      Caption = ' if w(e) >'
    end
    object Label6: TLabel
      Left = 64
      Top = 240
      Width = 36
      Height = 13
      Caption = 'w(e) = '
    end
    object Label7: TLabel
      Left = 64
      Top = 272
      Width = 63
      Height = 13
      Caption = 'Source no. ='
    end
    object Label8: TLabel
      Left = 46
      Top = 424
      Width = 99
      Height = 13
      Caption = 'Shortest Path Solver'
    end
    object Button1: TButton
      Left = 144
      Top = 32
      Width = 145
      Height = 33
      Caption = 'Read G'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 176
      Top = 141
      Width = 73
      Height = 21
      TabOrder = 1
      Text = '12'
    end
    object Edit2: TEdit
      Left = 176
      Top = 173
      Width = 73
      Height = 21
      TabOrder = 2
      Text = '500'
    end
    object Edit3: TEdit
      Left = 176
      Top = 205
      Width = 73
      Height = 21
      TabOrder = 3
      Text = '80'
    end
    object Edit4: TEdit
      Left = 176
      Top = 237
      Width = 73
      Height = 21
      TabOrder = 4
      Text = '999999'
    end
    object Edit5: TEdit
      Left = 176
      Top = 269
      Width = 73
      Height = 21
      TabOrder = 5
      Text = '0'
    end
    object Button2: TButton
      Left = 80
      Top = 312
      Width = 169
      Height = 25
      Caption = 'Generate G'
      TabOrder = 6
      OnClick = Button2Click
    end
    object CheckBox1: TCheckBox
      Left = 48
      Top = 370
      Width = 97
      Height = 17
      Caption = 'Undirected G'
      TabOrder = 7
    end
    object CheckBox2: TCheckBox
      Left = 168
      Top = 370
      Width = 97
      Height = 17
      Caption = 'Echo Print G'
      TabOrder = 8
    end
    object Button3: TButton
      Left = 61
      Top = 544
      Width = 228
      Height = 25
      Caption = 'Single Source All Destinations'
      TabOrder = 9
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 61
      Top = 585
      Width = 228
      Height = 25
      Caption = 'All Pairs'
      TabOrder = 10
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 61
      Top = 624
      Width = 228
      Height = 25
      Caption = 'Transitive Closure'
      TabOrder = 11
      OnClick = Button5Click
    end
    object CheckBox3: TCheckBox
      Left = 48
      Top = 464
      Width = 97
      Height = 17
      Caption = 'Print Results'
      TabOrder = 12
    end
  end
  object PageControl1: TPageControl
    Left = 345
    Top = 0
    Width = 639
    Height = 755
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'G'#39's adjacent matrix'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 631
        Height = 727
        Align = alClient
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Graph in adjacent matrix'
      ImageIndex = 1
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 631
        Height = 727
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 2
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'SSAD Tables'
      ImageIndex = 2
      ExplicitLeft = 6
      ExplicitTop = 28
      object StringGrid3: TStringGrid
        Left = 0
        Top = 0
        Width = 631
        Height = 727
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 2
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'ALL Pairs'
      ImageIndex = 3
      object StringGrid4: TStringGrid
        Left = 0
        Top = 0
        Width = 631
        Height = 727
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 311
        ExplicitTop = 240
        ExplicitWidth = 320
        ExplicitHeight = 120
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Transitive Closure'
      ImageIndex = 4
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 631
        Height = 727
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 311
        ExplicitTop = 224
        ExplicitWidth = 320
        ExplicitHeight = 120
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 240
    Top = 32
  end
end
