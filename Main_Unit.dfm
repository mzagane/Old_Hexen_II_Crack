object Main_Form: TMain_Form
  Left = 389
  Top = 198
  BorderStyle = bsNone
  Caption = 'Crack v1.27.12.2007 de editplus v2.21 (330)'
  ClientHeight = 201
  ClientWidth = 309
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 309
    Height = 201
    BevelInner = bvSpace
    BevelOuter = bvLowered
    BevelWidth = 3
    Color = clBackground
    TabOrder = 0
    OnMouseDown = Panel1MouseDown
    object Femer_SpeedButton: TSpeedButton
      Left = 276
      Top = 6
      Width = 22
      Height = 19
      Caption = 'X'
      Flat = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = Femer_SpeedButtonClick
    end
    object Minimise_SpeedButton: TSpeedButton
      Left = 251
      Top = 6
      Width = 22
      Height = 19
      Caption = '---'
      Flat = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnClick = Minimise_SpeedButtonClick
    end
    object GroupBox1: TGroupBox
      Left = 9
      Top = 144
      Width = 289
      Height = 49
      TabOrder = 0
      OnMouseDown = GroupBox1MouseDown
      object Cracker_SpeedButton: TSpeedButton
        Left = 16
        Top = 14
        Width = 129
        Height = 29
        Hint = 'Clicker ici pour cracker le programme'
        Caption = '&Cracker'
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clYellow
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        OnClick = Cracker_SpeedButtonClick
      end
      object Restaurer_SpeedButton: TSpeedButton
        Left = 160
        Top = 14
        Width = 121
        Height = 28
        Hint = 'Clicker ici pour restaurer le programme '
        Caption = '&Restaurer'
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clYellow
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        OnClick = Restaurer_SpeedButtonClick
      end
    end
    object GroupBox2: TGroupBox
      Left = 8
      Top = 25
      Width = 291
      Height = 112
      Color = clBackground
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 1
      OnMouseDown = GroupBox2MouseDown
      object Label1: TLabel
        Left = 33
        Top = 16
        Width = 208
        Height = 13
        Caption = 'Crack v2.25.01.2008 pour Hexen II (No CD)'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMoneyGreen
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 88
        Top = 40
        Width = 82
        Height = 13
        Caption = 'Cracker : Arbman'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMoneyGreen
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 72
        Top = 64
        Width = 133
        Height = 13
        Caption = 'E-mail : arbman84@yahoo.fr'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMoneyGreen
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 98
        Top = 88
        Width = 124
        Height = 13
        Cursor = crHandPoint
        Hint = 
          'Clicker ici pour visiter mon site web o'#249' vous trouvez le code so' +
          'urce de ce crack et d'#39'autres crack avec leurs codes sources  et ' +
          'autre  open source software.'
        Caption = 'http://arbman.ifrance.com'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clLime
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        OnClick = Label5Click
      end
      object Label3: TLabel
        Left = 45
        Top = 88
        Width = 50
        Height = 13
        Caption = 'Site web : '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMoneyGreen
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 264
    Top = 120
  end
end
