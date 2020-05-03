object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Maze Generator By Sychen 2019/11/04 Ver 1.0'
  ClientHeight = 652
  ClientWidth = 933
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 257
    Top = 0
    Height = 652
    ExplicitLeft = 328
    ExplicitTop = 320
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 257
    Height = 652
    Align = alLeft
    Alignment = taLeftJustify
    TabOrder = 0
    object Label6: TLabel
      Left = 36
      Top = 235
      Width = 55
      Height = 13
      Caption = 'Grid Size = '
    end
    object GroupBox1: TGroupBox
      Left = 32
      Top = 80
      Width = 177
      Height = 129
      Caption = 'Size'
      TabOrder = 0
      object Label1: TLabel
        Left = 24
        Top = 32
        Width = 35
        Height = 13
        Caption = 'Height:'
      end
      object Label2: TLabel
        Left = 27
        Top = 88
        Width = 32
        Height = 13
        Caption = 'Width:'
      end
      object Edit1: TEdit
        Left = 65
        Top = 29
        Width = 76
        Height = 21
        TabOrder = 0
        Text = '19'
      end
      object Edit2: TEdit
        Left = 65
        Top = 80
        Width = 76
        Height = 21
        TabOrder = 1
        Text = '19'
      end
    end
    object Button1: TButton
      Left = 32
      Top = 322
      Width = 177
      Height = 25
      Caption = 'Generate Maze'
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 32
      Top = 353
      Width = 177
      Height = 25
      Caption = 'Save Maze'
      TabOrder = 2
    end
    object Button3: TButton
      Left = 32
      Top = 384
      Width = 177
      Height = 25
      Caption = 'Load Maze'
      TabOrder = 3
      OnClick = Button3Click
    end
    object GroupBox2: TGroupBox
      Left = 32
      Top = 455
      Width = 185
      Height = 105
      Caption = 'Array Info'
      TabOrder = 4
      object Label3: TLabel
        Left = 24
        Top = 24
        Width = 26
        Height = 13
        Caption = 'Size: '
      end
      object Label4: TLabel
        Left = 24
        Top = 53
        Width = 21
        Height = 13
        Caption = 'Cell:'
      end
      object Label5: TLabel
        Left = 24
        Top = 72
        Width = 3
        Height = 13
      end
    end
    object Edit3: TEdit
      Left = 97
      Top = 232
      Width = 76
      Height = 21
      TabOrder = 5
      Text = '50'
    end
    object Button4: TButton
      Left = 179
      Top = 233
      Width = 38
      Height = 20
      Caption = 'Set'
      TabOrder = 6
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 88
      Top = 279
      Width = 75
      Height = 25
      Caption = 'Run'
      TabOrder = 7
      OnClick = Button5Click
    end
  end
  object Panel2: TPanel
    Left = 260
    Top = 0
    Width = 673
    Height = 652
    Align = alClient
    TabOrder = 1
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 671
      Height = 650
      ActivePage = TabSheet2
      Align = alClient
      TabOrder = 0
      ExplicitLeft = -3
      ExplicitTop = 2
      object TabSheet1: TTabSheet
        Caption = 'Memo'
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 663
          Height = 622
          Align = alClient
          Lines.Strings = (
            'Memo1')
          TabOrder = 0
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Maze'
        ImageIndex = 1
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 663
          Height = 622
          Align = alClient
          TabOrder = 0
          OnClick = StringGrid1Click
          OnDrawCell = StringGrid1DrawCell
          ExplicitLeft = 1
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'Color'
        ImageIndex = 2
        object StringGrid2: TStringGrid
          Left = 0
          Top = 0
          Width = 663
          Height = 622
          Align = alClient
          DefaultDrawing = False
          TabOrder = 0
          OnClick = StringGrid2Click
          OnDrawCell = StringGrid2DrawCell
          RowHeights = (
            24
            24
            24
            24
            24)
        end
      end
      object TabSheet4: TTabSheet
        Caption = 'Trace'
        ImageIndex = 3
        object Memo2: TMemo
          Left = 0
          Top = 0
          Width = 663
          Height = 622
          Align = alClient
          Lines.Strings = (
            'Memo2')
          ScrollBars = ssVertical
          TabOrder = 0
        end
      end
      object TabSheet5: TTabSheet
        Caption = 'Mouse'
        ImageIndex = 4
        object StringGrid3: TStringGrid
          Left = 0
          Top = 0
          Width = 663
          Height = 622
          Align = alClient
          DefaultDrawing = False
          TabOrder = 0
          OnDrawCell = StringGrid3DrawCell
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 184
    Top = 384
  end
end
