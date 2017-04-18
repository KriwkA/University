Program lab3_20;
uses Train, Crt;
var tr:traintree;	{дерево поездов}
	f:trainfile;	{файл с инф. о поездах}
    key:char;		{клавиша}
Begin
	tr.Init(); {вызов конструктора}
	assign(f,'Train.dat');	{подключение файла}
	tr.LoadTrainFile(f);
    while (true) do
    begin
        clrscr;
		writeln('1.Add 2.Show 3.ShowStruct 4.Search 5.NodeCount Esc.Exit');
        key:=' ';
		{выбор нужной клавиши}
        while (not (key in ['1','2','3','4','5',#27])) do key:=readkey;
        case key of
			'1': tr.Add(NewTrain());
			'2': tr.Print();
			'3': tr.PrintStruct();
            '4': tr.Search();
			'5': tr.Count();
			#27: break;
        end;
    end;
	tr.SaveTrainFile(f); {сохранение файла}
	tr.Done(); {вызов деструктора}
End.