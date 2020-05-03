object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Magic Square by S.Y. Chen 2019/10/05 Ver. 0.5'
  ClientHeight = 667
  ClientWidth = 1021
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
    Left = 185
    Top = 0
    Height = 667
    ExplicitLeft = 680
    ExplicitTop = 480
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 185
    Height = 667
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 56
      Top = 136
      Width = 60
      Height = 13
      Caption = 'Square Size:'
    end
    object Label2: TLabel
      Left = 48
      Top = 224
      Width = 80
      Height = 13
      Caption = '1 <= size <= 21'
    end
    object Edit1: TEdit
      Left = 24
      Top = 155
      Width = 121
      Height = 21
      TabOrder = 0
      Text = '5'
    end
    object Button1: TButton
      Left = 48
      Top = 322
      Width = 75
      Height = 25
      Caption = 'Magic Square'
      TabOrder = 1
      OnClick = Button1Click
    end
  end
  object PageControl1: TPageControl
    Left = 188
    Top = 0
    Width = 833
    Height = 667
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Left-Top'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 825
        Height = 100
        Align = alTop
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object StringGrid1: TStringGrid
        Left = 0
        Top = 100
        Width = 825
        Height = 539
        Align = alClient
        TabOrder = 1
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Right-Bottom'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 825
        Height = 100
        Align = alTop
        Lines.Strings = (
          'Memo2')
        TabOrder = 0
      end
      object StringGrid2: TStringGrid
        Left = 0
        Top = 100
        Width = 825
        Height = 539
        Align = alClient
        TabOrder = 1
        ExplicitLeft = 16
        ExplicitTop = 97
      end
    end
  end
end
