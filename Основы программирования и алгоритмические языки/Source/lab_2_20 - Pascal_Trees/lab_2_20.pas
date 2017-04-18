program lab12_20;
uses crt;
type
	time = record {запись время}
		hour:integer;
		minute:integer;
	end;
	
	TrainInfo = record {запись о поезде}
		number:integer;
		StartPoint:string[20];
		EndPoint:string[20];
		StartTime:time;
		EndTime:time;
		TicketPrice:longint;
	end;
	
	ptrain = ^traintree;
	TrainTree = record {описание узла дерева}
		train:traininfo;
		left:ptrain;
		right:ptrain;
	end;
	
	trainfile = file of traininfo;

function NewTrain():TrainInfo; {ввод информации о поезде}
begin
	clrscr();
	writeln('Введите номер поезда.');
	readln(NewTrain.number);
	writeln('Введите место отправки.');
	readln(NewTrain.StartPoint);
	writeln('Введите место прибытия.');
	readln(NewTrain.EndPoint);
	writeln('Введите время отправки.');
	readln(NewTrain.StartTime.hour, NewTrain.StartTime.minute);
	writeln('Введите время прибытия.');
	readln(NewTrain.EndTime.hour, NewTrain.EndTime.minute);
	writeln('Введите стоимость билета.');
	readln(NewTrain.TicketPrice);
end;

procedure PrintTrainInfo(const Train:TrainInfo);	{вывод информации о поезде}
begin
	write(Train.number);
	write(Train.StartPoint:11,Train.EndPoint:11);
	write(Train.StartTime.hour:4,':',Train.StartTime.minute);
	write(Train.EndTime.hour:5,':',Train.EndTime.minute);
	write(Train.TicketPrice:10);
end;

Function AddTrain(root:ptrain; nt:traininfo):ptrain; {добавление узла дерева}
begin
	if root=NIL then		
	begin						{создание нового узла}
		new(root);
		root^.train:=nt;
		root^.left:=NIL;
		root^.right:=NIL;
	end
	else
	if Root^.train.number>nt.number then	{прохождение по дереву}
		Root^.left:=addtrain(Root^.left,nt)
	else
		Root^.right:=addtrain(Root^.Right,nt);
	AddTrain:=root;
end;

Procedure ShowAll(Root:ptrain);	{отображение дерева}
Begin
	if Root<>Nil then
	begin
		Showall(Root^.left); {прохождение по дереву}
		PrintTrainInfo(Root^.train); {вывод информации о узле}
		writeln();
		Showall(Root^.right); {прохождение по дереву}
	end;
End;

Procedure Free(Root:ptrain);	{освобождение памяти}
begin
	if Root=NIL then exit();
	Free(Root^.right); {прохождение по дереву}
	Free(Root^.left);
	Dispose(Root);	{удаление узла}
end;

procedure PrintTrainFile(var f:trainfile; root:ptrain); {запись узлов в файл}
Begin
	if Root=NIL then exit();
	write(f,root^.train); 	{запись узла в файл}
	printtrainfile(f,root^.left); 
	printtrainfile(f,root^.right);
End;

Procedure SaveTrainFile(var f:trainfile; root:ptrain); {сохранение файла}
begin
	rewrite(f);
		PrintTrainFile(f,root);
	close(f);
end;

procedure LoadTrainFile(var f:trainfile; var root:ptrain); {загрузка файла}
var nt:TrainInfo;
begin
	{$I-}
	reset(f);
	{$I+}
	if (IOResult=0) and (FileSize(f)<>0) then
	while not eof(f) do {считывание поезда из файла}
	begin
		read(f,nt); 
		root:=AddTrain(root,nt); {добавление узла в дерево}
	end;		
end;

Function NodeCount(root:ptrain; Level:Integer):integer; {подсчет k узлов n уровня}
var n:integer;
Begin
	n:=0;
	If (Level>=1) and (root<>Nil) Then
	Begin
		If Level=1 Then N:=N+1;
		n:=n+NodeCount(root^.Left,Level-1); {переход на след. уровень}
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
	assign(f,'Train.dat'); {привязка файла}
	LoadTrainFile(f,root);	{загрузка файла}
	while true do
	begin
		clrscr();
		writeln('1.Add 2.ShowAll 3.NodeCount  Esc.Exit'); {вывод гл.меню}
		key:=' ';
		while not (key in ['1','2','3',#27]) do key:=readkey; {работа с пунктами меню}
		case key of
		'1': 	begin
					nt:=NewTrain();
					root:=AddTrain(root,nt);
				end;
		'2':	begin
					clrscr();
					writeln('№','StPoint':11,'EndPoint':11,'StTime':7,'EndTime':8,'Price':10);
					ShowAll(root);
					readkey;
				end;
		'3':	begin
					clrscr();
					writeln('Введите номер уровня.');
					readln(n);
					writeln('На уровне ',n,' ',NodeCount(root,n),' узeл(ов)');
					readkey;
				end;
		#27: break;			
		end;
	end;
	SaveTrainFile(f,root); {сохранение данных дерева в файл}
	Free(root);	{очистка памяти}
End.