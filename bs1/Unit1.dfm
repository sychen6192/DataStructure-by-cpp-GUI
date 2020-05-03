object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 
    'Exponentiation (x^n) by S.Y Chen [32-bit Debug] 2019/10/21 Ver 0' +
    '.1'
  ClientHeight = 608
  ClientWidth = 782
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
    Height = 608
    ExplicitLeft = 288
    ExplicitTop = 336
    ExplicitHeight = 100
  end
  object PageControl1: TPageControl
    Left = 292
    Top = 0
    Width = 490
    Height = 608
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 452
    ExplicitTop = 8
    ExplicitWidth = 333
    object TabSheet1: TTabSheet
      Caption = 'TabSheet1'
      ExplicitWidth = 586
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 482
        Height = 580
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'TabSheet2'
      ImageIndex = 1
      ExplicitWidth = 586
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 482
        Height = 580
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
  object PageControl2: TPageControl
    Left = 0
    Top = 0
    Width = 289
    Height = 608
    ActivePage = TabSheet3
    Align = alLeft
    TabOrder = 1
    object TabSheet3: TTabSheet
      Caption = 'Power / Exponential '
      ExplicitLeft = 108
      ExplicitTop = 8
      ExplicitHeight = 165
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 281
        Height = 580
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 200
        object Label1: TLabel
          Left = 21
          Top = 64
          Width = 17
          Height = 13
          Caption = 'x ='
        end
        object Label2: TLabel
          Left = 21
          Top = 104
          Width = 20
          Height = 13
          Caption = 'n = '
        end
        object Edit1: TEdit
          Left = 56
          Top = 61
          Width = 97
          Height = 21
          TabOrder = 0
          Text = '2'
        end
        object Edit2: TEdit
          Left = 57
          Top = 101
          Width = 96
          Height = 21
          TabOrder = 1
          Text = '30'
        end
        object Button1: TButton
          Left = 40
          Top = 184
          Width = 91
          Height = 25
          Caption = 'x^n'
          TabOrder = 2
          OnClick = Button1Click
        end
        object Edit3: TEdit
          Left = 32
          Top = 144
          Width = 121
          Height = 21
          TabOrder = 3
          Text = '100000000'
        end
        object CheckBox1: TCheckBox
          Left = 48
          Top = 360
          Width = 97
          Height = 17
          Caption = 'pow(x, n)'
          TabOrder = 4
        end
        object CheckBox2: TCheckBox
          Left = 48
          Top = 400
          Width = 97
          Height = 17
          Caption = 'for-loop'
          TabOrder = 5
        end
        object CheckBox3: TCheckBox
          Left = 48
          Top = 440
          Width = 97
          Height = 17
          Caption = 'squaring'
          TabOrder = 6
        end
        object CheckBox4: TCheckBox
          Left = 48
          Top = 480
          Width = 97
          Height = 17
          Caption = 'squaring _>>'
          TabOrder = 7
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Polynomial '
      ImageIndex = 1
      ExplicitLeft = 9
      object Label3: TLabel
        Left = 40
        Top = 88
        Width = 45
        Height = 13
        Caption = 'poly[ ] = '
      end
      object Label4: TLabel
        Left = 40
        Top = 128
        Width = 19
        Height = 13
        Caption = 'k = '
      end
      object Label5: TLabel
        Left = 40
        Top = 168
        Width = 20
        Height = 13
        Caption = 'n = '
      end
      object Label6: TLabel
        Left = 91
        Top = 48
        Width = 75
        Height = 13
        Caption = '(0<=coff < 10)'
      end
      object Edit4: TEdit
        Left = 91
        Top = 85
        Width = 121
        Height = 21
        TabOrder = 0
        Text = '1234'
      end
      object Edit5: TEdit
        Left = 91
        Top = 125
        Width = 121
        Height = 21
        TabOrder = 1
        Text = '3'
      end
      object Edit6: TEdit
        Left = 91
        Top = 165
        Width = 121
        Height = 21
        TabOrder = 2
        Text = '4'
      end
      object Button2: TButton
        Left = 91
        Top = 240
        Width = 75
        Height = 25
        Caption = 'compute'
        TabOrder = 3
        OnClick = Button2Click
      end
    end
  end
end
