object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Permutations by S.Y.Chen 2019/09/24 Ver.01'
  ClientHeight = 591
  ClientWidth = 891
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
    Left = 289
    Top = 0
    Height = 591
    ExplicitLeft = 201
  end
  object Label5: TLabel
    Left = 632
    Top = 384
    Width = 31
    Height = 13
    Caption = 'Label5'
  end
  object PageControl1: TPageControl
    Left = 292
    Top = 0
    Width = 599
    Height = 591
    ActivePage = TabSheet5
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 291
    object TabSheet1: TTabSheet
      Caption = 'permutations'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 591
        Height = 563
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'Memo1')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
        ExplicitLeft = -5
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'permutations with tracing'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 591
        Height = 563
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'Memo2')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
        ExplicitLeft = -7
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'tower of hanoi'
      ImageIndex = 2
      object Memo3: TMemo
        Left = 0
        Top = 0
        Width = 591
        Height = 563
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'Memo3')
        ParentFont = False
        TabOrder = 0
        ExplicitLeft = 216
        ExplicitTop = 3
      end
    end
  end
  object PageControl2: TPageControl
    Left = 0
    Top = 0
    Width = 289
    Height = 591
    ActivePage = TabSheet4
    Align = alLeft
    TabOrder = 1
    object TabSheet3: TTabSheet
      Caption = 'Permutations'
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 281
        Height = 563
        Align = alClient
        TabOrder = 0
        object Label1: TLabel
          Left = 39
          Top = 64
          Width = 19
          Height = 13
          Caption = 'k = '
        end
        object Label2: TLabel
          Left = 39
          Top = 104
          Width = 20
          Height = 13
          Caption = 'n = '
        end
        object Label3: TLabel
          Left = 100
          Top = 152
          Width = 36
          Height = 13
          Caption = '(n<=9)'
        end
        object Edit1: TEdit
          Left = 64
          Top = 61
          Width = 72
          Height = 21
          TabOrder = 0
          Text = '0'
        end
        object Edit2: TEdit
          Left = 65
          Top = 101
          Width = 71
          Height = 21
          TabOrder = 1
          Text = '4'
        end
        object CheckBox1: TCheckBox
          Left = 100
          Top = 187
          Width = 97
          Height = 17
          Caption = 'Tracing'
          TabOrder = 2
        end
        object Button1: TButton
          Left = 65
          Top = 270
          Width = 75
          Height = 25
          Caption = 'Permutation'
          TabOrder = 3
          OnClick = Button1Click
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Tower of Hanoi'
      ImageIndex = 1
      ExplicitLeft = 5
      object Label4: TLabel
        Left = 60
        Top = 163
        Width = 20
        Height = 13
        Caption = 'n = '
      end
      object Edit3: TEdit
        Left = 88
        Top = 160
        Width = 87
        Height = 21
        TabOrder = 0
        Text = '3'
      end
      object Button2: TButton
        Left = 60
        Top = 240
        Width = 115
        Height = 41
        Caption = 'Tower of Hanoi'
        TabOrder = 1
        OnClick = Button2Click
      end
    end
  end
end
