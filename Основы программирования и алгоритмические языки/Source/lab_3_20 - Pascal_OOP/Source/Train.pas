Unit Train;
Interface
	uses crt;
	Type
		int = longint;	
		Time =	record		{������� �६�}
					hour:byte;		
					minute:byte;	
					second:byte;	
				end;			
		TrainInfo = record			{������� ���ଠ樨}
					number:int;		{� ������}
					StartPoint:string[20];		
					EndPoint:string[20];	
					StartTime:Time;			
					EndTime:Time;			
					TicketPrice:int;			
				end;		
		TrainFile = File of TrainInfo;	{䠩� � �����.���}		
		PTrain = ^Tree;					{* �� 㧥� ��ॢ�}
		Tree =	record					{���ᠭ�� 㧫� ��ॢ�}
					key:TrainInfo;		
					Left:PTrain;		
					Right:PTrain; 	
				end;				
		TrainTree = object	{���ᠭ�� ����� ��ॢ� �������}
						constructor Init();	{���������}
						procedure Add(key:TrainInfo);{���������� 㧫�}
						procedure Print();		{�뢮� ᯨ᪠}
						procedure PrintStruct();{�뢮� �������� ��ॢ�}
						procedure LoadTrainFile(var f:trainfile);{����㧪� 䠩��}
						Procedure SaveTrainFile(var f:trainfile);{���. 䠩��}
						Procedure Search(); {���� ������ � ��ॢ�}
						procedure Count(); {���-�� ������� �� N �஢��}
						destructor	Done();	 {��������}
					private
						Root:PTrain;		{��७� ��ॢ�}
					end;		
		function  NewTrain():TrainInfo;	{ᮧ����� ����� �����}
Implementation
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

	{���� ������ � ��ॢ� �� �����}
	function SearchTrain(Node:Ptrain; number:int):Ptrain;
	begin
		while (Node <> NIL) do 
		begin
			if ((Node^.key.number = number) or (Node = NIL)) then 
			begin {��諨 ����}
				SearchTrain:= Node;	
				break;
			end
			else {���� �� ��ॢ�}
			if (Node^.key.number < number) then
				Node := Node^.Right
			else
				Node := Node^.Left;
		end;
	end;
	
	function NewTrain():TrainInfo; {ᮧ����� ����� �����}
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
	
	{�뢮� ������ ���� �� �࠭}
	procedure PrintTrainInfo(key:TrainInfo);
	Begin
		write(key.number);
		write(key.StartPoint:11,key.EndPoint:11);
		write(key.StartTime.hour:4,':',key.StartTime.minute);
		write(key.EndTime.hour:5,':',key.EndTime.minute);
		writeln(key.TicketPrice:10);
	End;
	
	{���������� ��ॢ� � ���⮥ ����}
	function AddTrain(Node,nt:PTrain):Ptrain; 
	Begin
		if (Node = NIL) then {��⠢�� � ���⮥ ����}
			Node := nt
		else {���� �� ��ॢ�}
			if (Node^.key.number > nt^.key.number) then
				Node^.Left := AddTrain(Node^.Left,nt)
			else
				Node^.Right := AddTrain(Node^.Right,nt);
		AddTrain := Node;
	End;
	
	{�뢮� ��ॢ� ᫥�� �� �ࠢ�}
	procedure PrintTrain(Node:Ptrain);
	Begin
		if (Node = NIL) then Exit();
		PrintTrain(Node^.Left);
		PrintTrainInfo(Node^.key);
		PrintTrain(Node^.Right);
	End;
	
	{�뢮� �������� ��ॢ� �� �࠭}
	procedure PrintTreeStruct(Node:Ptrain; level:int);
	var i:int;
	Begin
		if (Node <> NIL) then
		begin
			PrintTreeStruct(Node^.Right,level+1);
			for i:=1 to level do write('   ');
			writeln(Node^.key.number);
			PrintTreeStruct(Node^.Left,level+1);
		end;
	End;
	
	{���⪠ �����}
	Procedure DeleteTrainTree(Node:PTrain);
	Begin
		if (Node = NIL) then exit();
		DeleteTrainTree(Node^.Left);
		DeleteTrainTree(Node^.Right);
		Dispose(Node);
	End;
	
	{������ ������ � 䠩�}
	procedure PrintTrainFile(var f:trainfile; Node:ptrain); 
	Begin
		if (Node=NIL) then exit();
		write(f,Node^.key); 	
		printtrainfile(f,Node^.left); {���� �� ��ॢ�}
		printtrainfile(f,Node^.right);
	End;
	
	{��������� �����}
	Constructor TrainTree.Init();
	Begin
		Root := NIL; 
	End;
	
	{ᮧ����� ������ ������}
	procedure TrainTree.Add(key:TrainInfo);
	var nt:Ptrain;
	Begin
		new(nt);
		nt^.key := key;
		nt^.left := NIL;
		nt^.right := NIL;
		Root:=AddTrain(Root,nt); {��ࠢ�� � ��ॢ�}
	End;
	
	{�뢮� ᯨ᪠ ��ॢ�}
	procedure TrainTree.Print();	
	Begin
		clrscr();
		if (Root = NIL) then {�஢�ઠ ������ ��ॢ�}
		begin
			writeln('���᮪ ������� ����.');
			readkey();
			exit();
		end;
		writeln('�','StPoint':11,'EndPoint':11,'StTime':7,'EndTime':8,'Price':10);
		PrintTrain(Root); {�뢮� ᫥�� �� �ࠢ�}
		readkey();
	End;	
	
	{�뢮� �������� ��ॢ�}
	procedure TrainTree.PrintStruct();
	Begin
		clrscr();
		if (Root = NIL) then {�஢�ઠ ������ ��ॢ�}
		begin
			writeln('���᮪ ������� ����.');
			readkey();
			exit();
		end;
		writeln('������� ��ॢ� �������:');
		PrintTreeStruct(Root,1); {�뢮� �������� ��ॢ�}
		readkey();
	End;
	
	{�������� �����}
	Destructor TrainTree.Done();
	Begin
		DeleteTrainTree(Root);
	End;	

	{��࠭���� ������ � 䠩�}
	Procedure TrainTree.SaveTrainFile(var f:trainfile);
	begin
		rewrite(f);
		PrintTrainFile(f,root); {������ ������}
		close(f);
	end;

	{����㧪� ������ �� 䠩��}
	procedure TrainTree.LoadTrainFile(var f:trainfile);
	var nt:TrainInfo;
	begin
		{$I-}
		reset(f);
		{$I+}
		if (IOResult=0) and (FileSize(f)<>0) then
		while not eof(f) do
		begin
			read(f,nt); {���뢠��� � ����������}
			Add(nt); 	{������ � ��ॢ�}
		end;		
	end;
	
	{�뢮� ���-�� ������ n �஢��}
	procedure TrainTree.Count();
	var n:int;
	Begin
		clrscr();
		writeln('������ ����� �஢��.');
		readln(n);
		writeln('�� �஢�� ',n,' ',NodeCount(root,n),' �e�(��)');
		readkey();
	End;
	
	{���� ������ �� ��� ������}
	procedure TrainTree.Search();
	var ST:Ptrain; n:int;
	Begin
		clrscr();
		writeln('������ ����� ������');
		readln(n);
		clrscr();
		ST:= SearchTrain(Root,n); {���� 㪠��⥫� �� ��������}
		if (ST <> NIL) then
		begin					  {�뢮� ������ �� �࠭}
			writeln('�','StPoint':11,'EndPoint':11,'StTime':7,'EndTime':8,'Price':10);
			PrintTrainInfo(ST^.key);
		end
		else writeln('����� �� ������.');
		readkey;
	End;
	
Begin
End.