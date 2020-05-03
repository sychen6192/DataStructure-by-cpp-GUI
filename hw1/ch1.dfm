object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Selection Sort vs. Bubble Sort by S.Y Chen 2019/09/10'
  ClientHeight = 1003
  ClientWidth = 915
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 94
    Top = 65
    Width = 20
    Height = 13
    Caption = 'n = '
  end
  object Label2: TLabel
    Left = 72
    Top = 96
    Width = 42
    Height = 13
    Caption = 'range = '
  end
  object Label3: TLabel
    Left = 680
    Top = 99
    Width = 44
    Height = 13
    Caption = 'target = '
  end
  object Button1: TButton
    Left = 72
    Top = 152
    Width = 153
    Height = 33
    Caption = 'Gnerate Random Numbers'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 128
    Top = 62
    Width = 73
    Height = 21
    NumbersOnly = True
    TabOrder = 1
    Text = '10'
  end
  object Memo1: TMemo
    Left = 72
    Top = 216
    Width = 153
    Height = 281
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object Edit2: TEdit
    Left = 128
    Top = 96
    Width = 73
    Height = 21
    TabOrder = 3
    Text = '1000'
  end
  object Button2: TButton
    Left = 264
    Top = 152
    Width = 153
    Height = 33
    Caption = 'Selection Sort'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Memo2: TMemo
    Left = 264
    Top = 216
    Width = 153
    Height = 281
    Lines.Strings = (
      'Memo2')
    ScrollBars = ssVertical
    TabOrder = 5
  end
  object CheckBox1: TCheckBox
    Left = 264
    Top = 64
    Width = 97
    Height = 17
    Caption = 'Echo print'
    Checked = True
    State = cbChecked
    TabOrder = 6
  end
  object Memo3: TMemo
    Left = 456
    Top = 216
    Width = 153
    Height = 281
    Lines.Strings = (
      'Memo3')
    ScrollBars = ssVertical
    TabOrder = 7
  end
  object CheckBox2: TCheckBox
    Left = 264
    Top = 98
    Width = 97
    Height = 17
    Caption = 'Self-check'
    TabOrder = 8
  end
  object Button3: TButton
    Left = 456
    Top = 152
    Width = 153
    Height = 33
    Caption = 'Bubble Sort'
    TabOrder = 9
    OnClick = Button3Click
  end
  object Memo4: TMemo
    Left = 648
    Top = 216
    Width = 225
    Height = 281
    Lines.Strings = (
      'Memo4')
    ScrollBars = ssVertical
    TabOrder = 10
  end
  object Edit3: TEdit
    Left = 744
    Top = 96
    Width = 81
    Height = 21
    TabOrder = 11
    Text = '200'
  end
  object Button4: TButton
    Left = 648
    Top = 152
    Width = 225
    Height = 33
    Caption = 'Binary Search'
    TabOrder = 12
    OnClick = Button4Click
  end
  object Chart1: TChart
    Left = 72
    Top = 568
    Width = 801
    Height = 417
    Title.Text.Strings = (
      'TChart')
    TabOrder = 13
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TBarSeries
      SeriesColor = 16711808
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
    object Series2: TBarSeries
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
    object Series3: TBarSeries
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object Button5: TButton
    Left = 72
    Top = 520
    Width = 801
    Height = 25
    Caption = 
      'An example to map the CPU time information onto the serieses of ' +
      'a chart in C++ Builder ( The First Five )'
    TabOrder = 14
    OnClick = Button5Click
  end
end
