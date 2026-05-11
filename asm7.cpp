#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RU");
    int a, b, c, d, e, y;

    char prn[] = "Введите a, b, c, d, e:\n";
    char scn[] = "%d %d %d %d %d";
    char out[] = "y = %d\n";

    __asm {
        lea eax, prn
        push eax
        call printf
        add esp, 4

        lea eax, e
        push eax
        lea eax, d
        push eax
        lea eax, c
        push eax
        lea eax, b
        push eax
        lea eax, a
        push eax
        lea eax, scn
        push eax
        call scanf
        add esp, 24  

        mov eax, a       
        add eax, b       
        cdq              
        idiv c           

        mov ecx, eax     

        mov eax, d       
        imul eax, e      

        sub ecx, eax     
        mov y, ecx       

        push y
        lea eax, out
        push eax
        call printf
        add esp, 8      
    }

    return 0;
}
