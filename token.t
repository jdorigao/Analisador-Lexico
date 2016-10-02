{Programa em TINY_FATORIAL}	
read x; {Leitura do fatorial}
fact := 1;
repeat;
		fact := 0;
		x := x - 100;
unitil x = 0;
write fact;