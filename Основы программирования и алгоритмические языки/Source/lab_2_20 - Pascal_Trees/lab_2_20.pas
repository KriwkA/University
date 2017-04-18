program lab12_20;
uses crt;
type
	time = record {������ �६�}
		hour:integer;
		minute:integer;
	end;
	
	TrainInfo = record {������ � ������}
		number:integer;
		StartPoint:string[20];
		EndPoint:string[20];
		StartTime:time;
		EndTime:time;
		TicketPrice:longint;
	end;
	
	ptrain = ^traintree;
	TrainTree = record {���ᠭ�� 㧫� ��ॢ�}
		train:traininfo;
		left:ptrain;
		right:ptrain;
	end;
	
	trainfile = file of traininfo;

function NewTrain():TrainInfo; {���� ���ଠ樨 � ������}
begin
	clrscr();
	writeln('������ ����� ������.');
	readln(NewTrain.number);
	writeln('������ ���� ��ࠢ��.');
	readln(NewTrain.StartPoint);
	writeln('������ ���� �ਡ���.');
	readln(NewTrain.EndPoint);
	writeln('������ �६� ��ࠢ��.');
	readln(NewTrain.StartTime.hour, NewTrain.StartTime.minute);
	writeln('������ �६� �ਡ���.');
	readln(NewTrain.EndTime.hour, NewTrain.EndTime.minute);
	writeln('������ �⮨����� �����.');
	readln(NewTrain.TicketPrice);
end;

procedure PrintTrainInfo(const Train:TrainInfo);	{�뢮� ���ଠ樨 � ������}
begin
	write(Train.number);
	write(Train.StartPoint:11,Train.EndPoint:11);
	write(Train.StartTime.hour:4,':',Train.StartTime.minute);
	write(Train.EndTime.hour:5,':',Train.EndTime.minute);
	write(Train.TicketPrice:10);
end;

Function AddTrain(root:ptrain; nt:traininfo):ptrain; {���������� 㧫� ��ॢ�}
begin
	if root=NIL then		
	begin						{ᮧ����� ������ 㧫�}
		new(root);
		root^.train:=nt;
		root^.left:=NIL;
		root^.right:=NIL;
	end
	else
	if Root^.train.number>nt.number then	{��宦����� �� ��ॢ�}
		Root^.left:=addtrain(Root^.left,nt)
	else
		Root^.right:=addtrain(Root^.Right,nt);
	AddTrain:=root;
end;

Procedure ShowAll(Root:ptrain);	{�⮡ࠦ���� ��ॢ�}
Begin
	if Root<>Nil then
	begin
		Showall(Root^.left); {��宦����� �� ��ॢ�}
		PrintTrainInfo(Root^.train); {�뢮� ���ଠ樨 � 㧫�}
		writeln();
		Showall(Root^.right); {��宦����� �� ��ॢ�}
	end;
End;

Procedure Free(Root:ptrain);	{�᢮�������� �����}
begin
	if Root=NIL then exit();
	Free(Root^.right); {��宦����� �� ��ॢ�}
	Free(Root^.left);
	Dispose(Root);	{㤠����� 㧫�}
end;

procedure PrintTrainFile(var f:trainfile; root:ptrain); {������ 㧫�� � 䠩�}
Begin
	if Root=NIL then exit();
	write(f,root^.train); 	{������ 㧫� � 䠩�}
	printtrainfile(f,root^.left); 
	printtrainfile(f,root^.right);
End;

Procedure SaveTrainFile(var f:trainfile; root:ptrain); {��࠭���� 䠩��}
begin
	rewrite(f);
		PrintTrainFile(f,root);
	close(f);
end;

procedure LoadTrainFile(var f:trainfile; var root:ptrain); {����㧪� 䠩��}
var nt:TrainInfo;
begin
	{$I-}
	reset(f);
	{$I+}
	if (IOResult=0) and (FileSize(f)<>0) then
	while not eof(f) do {���뢠��� ������ �� 䠩��}
	begin
		read(f,nt); 
		root:=AddTrain(root,nt); {���������� 㧫� � ��ॢ�}
	end;		
end;

Function NodeCount(root:ptrain; Level:Integer):integer; {������ k 㧫�� n �஢��}
var n:integer;
Begin
	n:=0;
	If (Level>=1) and (root<>Nil) Then
	Begin
		If Level=1 Then N:=N+1;
		n:=n+NodeCount(root^.Left,Level-1); {���室 �� ᫥�. �஢���}
		n:=n+NodeCount(root^.Right,Level-1);
	End;
	NodeCount:=n;
End;


var root:ptrain;
	key:char;
	f:TrainFile;
	nt:traininfo;
	n:integer;
Begin
	assign(f,'Train.dat'); {�ਢ離� 䠩��}
	LoadTrainFile(f,root);	{����㧪� 䠩��}
	while true do
	begin
		clrscr();
		writeln('1.Add 2.ShowAll 3.NodeCount  Esc.Exit'); {�뢮� ��.����}
		key:=' ';
		while not (key in ['1','2','3',#27]) do key:=readkey; {ࠡ�� � �㭪⠬� ����}
		case key of
		'1': 	begin
					nt:=NewTrain();
					root:=AddTrain(root,nt);
				end;
		'2':	begin
					clrscr();
					writeln('�','StPoint':11,'EndPoint':11,'StTime':7,'EndTime':8,'Price':10);
					ShowAll(root);
					readkey;
				end;
		'3':	begin
					clrscr();
					writeln('������ ����� �஢��.');
					readln(n);
					writeln('�� �஢�� ',n,' ',NodeCount(root,n),' �e�(��)');
					readkey;
				end;
		#27: break;			
		end;
	end;
	SaveTrainFile(f,root); {��࠭���� ������ ��ॢ� � 䠩�}
	Free(root);	{���⪠ �����}
End.