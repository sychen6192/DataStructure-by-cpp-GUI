object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 
    'Transformation among infix, prefix and postfix by S.Y Chen 11/18' +
    '/2019 Ver 0.1'
  ClientHeight = 518
  ClientWidth = 833
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 241
    Width = 833
    Height = 277
    ActivePage = TabSheet2
    Align = alClient
    MultiLine = True
    TabOrder = 0
    TabPosition = tpRight
    object TabSheet1: TTabSheet
      Caption = 'Tracing'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 805
        Height = 269
        Align = alClient
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
        ExplicitLeft = 1
        ExplicitTop = 1
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Author'
      ImageIndex = 1
      ExplicitLeft = 5
      ExplicitTop = 5
      object Splitter1: TSplitter
        Left = 0
        Top = 0
        Width = 805
        Height = 3
        Cursor = crVSplit
        Align = alTop
        ExplicitWidth = 190
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 833
    Height = 241
    Align = alTop
    TabOrder = 1
    object PageControl2: TPageControl
      Left = 1
      Top = 1
      Width = 831
      Height = 239
      ActivePage = TabSheet3
      Align = alClient
      TabOrder = 0
      object TabSheet3: TTabSheet
        Caption = 'Infix'
        ExplicitLeft = 3
        ExplicitTop = 23
        object Label1: TLabel
          Left = 488
          Top = 16
          Width = 307
          Height = 13
          Caption = 
            'Only binary operators in {+, -, *, /, ^, and ,or} are considered' +
            '.'
        end
        object Label2: TLabel
          Left = 104
          Top = 174
          Width = 56
          Height = 13
          Caption = 'test cases: '
        end
        object Button1: TButton
          Left = 64
          Top = 84
          Width = 89
          Height = 25
          Caption = 'infix => postfix'
          TabOrder = 0
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 64
          Top = 130
          Width = 89
          Height = 25
          Caption = 'infix => prefix'
          TabOrder = 1
          OnClick = Button2Click
        end
        object Edit1: TEdit
          Left = 192
          Top = 47
          Width = 540
          Height = 21
          TabOrder = 2
          Text = '(A-B*C)+D^(E+F/G)'
        end
        object Edit2: TEdit
          Left = 192
          Top = 86
          Width = 540
          Height = 21
          TabOrder = 3
        end
        object Edit3: TEdit
          Left = 192
          Top = 132
          Width = 540
          Height = 21
          TabOrder = 4
        end
        object ComboBox1: TComboBox
          Left = 192
          Top = 171
          Width = 204
          Height = 21
          TabOrder = 5
          Text = '(Choose one of the given cases.)'
        end
      end
    end
  end
  object Button3: TButton
    Left = 416
    Top = 194
    Width = 49
    Height = 25
    Caption = 'GET'
    TabOrder = 2
    OnClick = Button3Click
  end
end
