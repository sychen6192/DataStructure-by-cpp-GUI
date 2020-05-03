object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Binary search tree by S.Y. Chen 2019/12/17 Ver 0.1'
  ClientHeight = 672
  ClientWidth = 909
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
    Width = 289
    Height = 672
    Align = alLeft
    TabOrder = 0
    ExplicitLeft = -2
    object Label1: TLabel
      Left = 40
      Top = 48
      Width = 45
      Height = 13
      Caption = 'Element: '
    end
    object Label2: TLabel
      Left = 40
      Top = 168
      Width = 42
      Height = 13
      Caption = 'Element:'
    end
    object Label3: TLabel
      Left = 72
      Top = 256
      Width = 114
      Height = 13
      Caption = '# of integers (5 to 100)'
    end
    object Label4: TLabel
      Left = 72
      Top = 392
      Width = 106
      Height = 13
      Caption = 'Range (100 to 10000)'
    end
    object Edit1: TEdit
      Left = 91
      Top = 45
      Width = 86
      Height = 21
      TabOrder = 0
      Text = '15'
    end
    object Button1: TButton
      Left = 51
      Top = 96
      Width = 150
      Height = 25
      Caption = 'Insert into BST'
      TabOrder = 1
      OnClick = Button1Click
    end
    object Edit2: TEdit
      Left = 91
      Top = 165
      Width = 86
      Height = 21
      TabOrder = 2
      Text = '100'
    end
    object Button2: TButton
      Left = 48
      Top = 208
      Width = 153
      Height = 25
      Caption = 'Delete from BST'
      TabOrder = 3
      OnClick = Button2Click
    end
    object TrackBar1: TTrackBar
      Left = 48
      Top = 288
      Width = 150
      Height = 45
      Max = 100
      Min = 5
      Position = 50
      TabOrder = 4
      OnChange = TrackBar1Change
    end
    object TrackBar2: TTrackBar
      Left = 51
      Top = 424
      Width = 150
      Height = 45
      Max = 10000
      Position = 5000
      TabOrder = 5
      OnChange = TrackBar2Change
    end
    object Edit3: TEdit
      Left = 72
      Top = 339
      Width = 121
      Height = 21
      TabOrder = 6
      Text = '50'
    end
    object Edit4: TEdit
      Left = 72
      Top = 464
      Width = 121
      Height = 21
      TabOrder = 7
      Text = '5000'
    end
    object Button3: TButton
      Left = 72
      Top = 507
      Width = 114
      Height = 25
      Caption = 'Random integers'
      TabOrder = 8
      OnClick = Button3Click
    end
    object RadioGroup1: TRadioGroup
      Left = 40
      Top = 552
      Width = 106
      Height = 116
      Caption = 'Traversal ways'
      TabOrder = 9
    end
    object RadioButton1: TRadioButton
      Left = 51
      Top = 572
      Width = 113
      Height = 17
      Caption = 'Inorder'
      TabOrder = 10
    end
    object RadioButton2: TRadioButton
      Left = 51
      Top = 607
      Width = 113
      Height = 17
      Caption = 'Preorder'
      TabOrder = 11
    end
    object RadioButton3: TRadioButton
      Left = 51
      Top = 642
      Width = 113
      Height = 17
      Caption = 'Postorder'
      TabOrder = 12
    end
  end
  object PageControl1: TPageControl
    Left = 289
    Top = 0
    Width = 620
    Height = 672
    ActivePage = TabSheet4
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Inorder sequence of BST'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 612
        Height = 644
        Align = alClient
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
        ExplicitLeft = 2
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Preorder sequence of BST'
      ImageIndex = 1
      ExplicitLeft = 6
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 612
        Height = 644
        Align = alClient
        Lines.Strings = (
          'Memo2')
        TabOrder = 0
        ExplicitLeft = 168
        ExplicitTop = 229
        ExplicitWidth = 185
        ExplicitHeight = 89
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Postorder sequence of BST'
      ImageIndex = 2
      object Memo3: TMemo
        Left = 0
        Top = 0
        Width = 612
        Height = 644
        Align = alClient
        Lines.Strings = (
          'Memo3')
        TabOrder = 0
        ExplicitLeft = 427
        ExplicitTop = 288
        ExplicitWidth = 185
        ExplicitHeight = 89
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'LevelOrder Traversal'
      ImageIndex = 3
      object Memo4: TMemo
        Left = 0
        Top = 0
        Width = 612
        Height = 644
        Align = alClient
        Lines.Strings = (
          'Memo4')
        TabOrder = 0
        ExplicitLeft = 427
        ExplicitTop = 440
        ExplicitWidth = 185
        ExplicitHeight = 89
      end
    end
  end
  object Button4: TButton
    Left = 165
    Top = 639
    Width = 122
    Height = 25
    Caption = 'LevelOrder Traversal'
    TabOrder = 2
    OnClick = Button4Click
  end
end
