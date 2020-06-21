
In acest proiect am implementat o functie de sistem care ofera date despre toti descendentii unui proces dat.

Antetul functiei de sistem a fost scris in kern/syscalls.master, primind ca ID urmatoarea valoare dupa cea a ultimei functii (in cazul nostru, primeste ID-ul 331):

331 STD { int sys_listPIDs(pid_t pid, bool type);}

Functia primeste ca parametru un pid si tipul afisarii pe care dorim sa il facem:
0 - afiseaza pid, nume, pid-ul parintelui pt procesul corespunzator pid-ului primit ca parametru
1 - afiseaza cele de mai sus + signal flag, nice value

In fisierul sys_generic.c din kernel am definit functia propriu-zisa.
	
Aceasta extrage argumentele prin intermediul SCARG.
Prin retval returnam numarul de procese parcurse.
Facem o parcurgere in DF(iterativ) a descendentilor procesului dat ca parametru prin pid.
Pentru a afla procesul cu ajutorul pidului ne folosim de functia prfind care primeste ca parametru un pid si returneaza un pointer de tipul struct process.
Pe parcursul pargurgerii in DF a descendentilor(cu ajutorul unei stive ce retine mereu in varf pid-ul procesului curent) se fac si afisarile cu date despre acestia.
	
Intr-un fisier de tipul nume_program.c va fi creat un program in userland care va face un apel de forma syscall(331, pid, tip), unde:
- 331 reprezinta numarul noii functii de sistem
- pid(data de intrare = pid_t) este pid-ul procesului de pornire ( pid-urile le putem gasi cu ajutorul unui package instalat: pstree)
- tip (data de intrare = bool) : 0 pt cateva informatii, 1 pt mai multe informatii despre proces.
	

