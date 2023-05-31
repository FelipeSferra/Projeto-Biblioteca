/*
    Trabalho Biblioteca - Algoritmos e estruturas de dados

    Nome: Felipe Sferra de Oliveira
    RA: 2211600147
    Curso: 2º BCC - T1
*/

#include <iostream>
#include <string.h>
#include <iomanip>
#include <windows.h>

using namespace std;

// Structs
struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Pessoas
{
    int codigo;
    char nome[40];
    char endereco[30];
};

struct Editoras
{
    int codigo;
    char nome[20];
};

struct Autores
{
    int codigo;
    char nome[40];
};

struct Generos
{
    int codigo;
    char nome[15];
};

struct Livros
{
    int codigo;
    char nome[30];
    char editora[20];
    char autor[40];
    char genero[15];
    char emprestado[40];
    int qtde_emprestado;
    Data data_emprestimo;
};

// Funções (protótipos)
void lerData(Data *, int &);
void lerPessoa(Pessoas *, int &);
void lerEditora(Editoras *, int &);
void lerAutor(Autores *, int &);
void lerGenero(Generos *, int &);
void lerLivro(Livros *, Pessoas *, Editoras *, Autores *, Generos *, int &);

void imprimirPessoa(Pessoas *, int);
void imprimirEditora(Editoras *, int);
void imprimirAutor(Autores *, int);
void imprimirGenero(Generos *, int);
void imprimirLivro(Livros *, int);

void menuPessoas(Pessoas *, int &);
void menuEditoras(Editoras *, int &);
void menuAutores(Autores *, int &);
void menuGeneros(Generos *, int &);
void menuLivros(Livros *, int &);

bool confPessoa(Pessoas *, int &, int &);
bool confEditora(Editoras *, int &, int &);
bool confAutor(Autores *, int &, int &);
bool confGenero(Generos *, int &, int &);

// Programa Principal

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);

    Pessoas teste[20];
    int contP = 0;
    int cod = 25;
    int i = 0;
    // menuPessoas(teste, contP);
    /*
    lerPessoa(teste,contP);
    if(confPessoa(teste,cod, i)){
        cout << "Passou como true";
        cout << teste[i].codigo << endl;
        cout << teste[i].nome << endl;
        cout << teste[i].endereco << endl;
    }
    else
        cout << "Entrou no else ;(";
    */

    SetConsoleOutputCP(CPAGE_DEFAULT);
}

// Menus

void menuPessoas(Pessoas *Pessoa, int &contP)
{
    system("cls");

    char op = 'X';

    while (op != '0')
    {
        cout << "\n\t<==|Menu - Pessoas|==>\n\n";

        cout << "[1] - Cadastrar Pessoa\n";
        cout << "[2] - Atualizar Lista\n";
        cout << "[3] - Imprimir Lista\n";
        cout << "[0] - Voltar para o menu principal\n";

        cout << "Selecione uma das opções: ";
        cin >> op;

        switch (op)
        {
        case '1':
            lerPessoa(Pessoa, contP);
            break;
        case '2':
            break;
        case '3':
            imprimirPessoa(Pessoa, contP);
            break;

        default:
            break;
        }
    }
}

void menuEditoras()
{
    system("cls");

    char op = 'X';

    while (op != '0')
    {
        cout << "\n\t<==|Menu - Editoras|==>\n\n";

        cout << "[1] - Cadastrar Editora\n";
        cout << "[2] - Atualizar Lista\n";
        cout << "[3] - Imprimir Lista\n";
        cout << "[0] - Voltar para o menu principal\n";

        cout << "Selecione uma das opções: ";
        cin >> op;

        switch (op)
        {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;

        default:
            break;
        }
    }
}

void menuAutores()
{
    system("cls");

    char op = 'X';

    while (op != '0')
    {
        cout << "\n\t<==|Menu - Autores|==>\n\n";

        cout << "[1] - Cadastrar Autores\n";
        cout << "[2] - Atualizar Lista\n";
        cout << "[3] - Imprimir Lista\n";
        cout << "[0] - Voltar para o menu principal\n";

        cout << "Selecione uma das opções: ";
        cin >> op;

        switch (op)
        {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;

        default:
            break;
        }
    }
}

void menuGeneros()
{
    system("cls");

    char op = 'X';

    while (op != '0')
    {
        cout << "\n\t<==|Menu - Gêneros|==>\n\n";

        cout << "[1] - Cadastrar Gêneros\n";
        cout << "[2] - Atualizar Lista\n";
        cout << "[3] - Imprimir Lista\n";
        cout << "[0] - Voltar para o menu principal\n";

        cout << "Selecione uma das opções: ";
        cin >> op;

        switch (op)
        {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;

        default:
            break;
        }
    }
}

void menuLivros()
{
    system("cls");

    char op = 'X';

    while (op != '0')
    {
        cout << "\n\t<==|Menu - Livros|==>\n\n";

        cout << "[1] - Cadastrar Livros\n";
        cout << "[2] - Atualizar Lista\n";
        cout << "[3] - Imprimir Lista\n";
        cout << "[0] - Voltar para o menu principal\n";

        cout << "Selecione uma das opções: ";
        cin >> op;

        switch (op)
        {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;

        default:
            break;
        }
    }
}

// Funções de leitura

void lerData(Data *Date, int &contD)
{
}

void lerPessoa(Pessoas *Pessoa, int &contP)
{
    system("cls");
    int i = 0;

    cout << "\t\t<==|Cadastro de Pessoas|==>\n\n";

    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\tCliente " << (i + 1) << endl;

        cout << "\nCódigo: ";
        cin >> Pessoa[i].codigo;
        cin.ignore();
        if (Pessoa[i].codigo == 0)
            saida = 0;
        else
        {
            cout << "Nome: ";
            gets(Pessoa[i].nome);
            cout << "Endereço: ";
            gets(Pessoa[i].endereco);
        }
    }
    contP = i - 1;
}

void lerEditora(Editoras *Editora, int contE)
{
    int i = 0;

    cout << "\t\t<==|Cadastro de Editoras|==>\n\n";

    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\tEditora " << (i + 1) << endl;

        cout << "\nCódigo: ";
        cin >> Editora[i].codigo;
        cin.ignore();
        if (Editora[i].codigo == 0)
            saida = 0;
        else
        {
            cout << "Nome: ";
            gets(Editora[i].nome);
        }
    }
    contE = i - 1;
}

void lerAutor(Autores *Autor, int &contA)
{
    int i = 0;

    cout << "\t\t<==|Cadastro de Autores|==>\n\n";

    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\tAutor " << (i + 1) << endl;

        cout << "\nCódigo: ";
        cin >> Autor[i].codigo;
        cin.ignore();
        if (Autor[i].codigo == 0)
            saida = 0;
        else
        {
            cout << "Nome: ";
            gets(Autor[i].nome);
        }
    }
    contA = i - 1;
}

void lerGenero(Generos *Genero, int &contG)
{
    int i = 0;

    cout << "\t\t<==|Cadastro de Gêneros|==>\n\n";

    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nGênero " << (i + 1) << endl;

        cout << "\nCódigo: ";
        cin >> Genero[i].codigo;
        cin.ignore();
        if (Genero[i].codigo == 0)
            saida = 0;
        else
        {
            cout << "Nome: ";
            gets(Genero[i].nome);
        }
    }
    contG = i - 1;
}

void lerLivro(Livros *Livro, Pessoas *Pessoa, Editoras *Editora, Autores *Autor, Generos *Genero, int &contL)
{
    system("cls");
    int i = 0;
    int codEdt, codAut, codPes, codGen, posEdt, posAut, posPes, posGen;
    cout << "\t\t<==|Cadastro de Livros|==>\n\n";

    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\tLivro " << (i + 1) << endl;

        cout << "\nCódigo: ";
        cin >> Livro[i].codigo;
        cin.ignore();
        if (Livro[i].codigo == 0)
            saida = 0;
        else
        {
            cout << "Nome: ";
            gets(Livro[i].nome);

            cout << "Código da editora: ";
            cin >> codEdt;
            if (confEditora(Editora, codEdt, posEdt))
            {
                strcpy(Livro[i].editora, Editora[posEdt].nome);
            }
            else
            {
                cout << "Editora não encontrada!\n";
                system("pause");
                break;
            }

            cout << "Código do Autor: ";
            cin >> codAut;
            if (confAutor(Autor, codAut, posAut))
            {
                strcpy(Livro[i].autor, Autor[posAut].nome);
            }
            else
            {
                cout << "Autor não encontrado!\n";
                system("pause");
                break;
            }

            cout << "Código do Gênero: ";
            cin >> codGen;
            if (confGenero(Genero, codGen, posGen))
            {
                strcpy(Livro[i].genero, Genero[posGen].nome);
            }
            else
            {
                cout << "Gênero não encontrado!\n";
                system("pause");
                break;
            }

            cout << "Código da Pessoa: ";
            cin >> codPes;
            if (confPessoa(Pessoa, codPes, posPes))
            {
                strcpy(Livro[i].emprestado, Pessoa[codPes].nome);
            }
            else
            {
                cout << "Pessoa não encontrada!\n";
                system("pause");
                break;
            }
        }
    }
    contL = i - 1;
}

// Funções de impressão

void imprimirPessoa(Pessoas *Pessoa, int contP)
{
    system("cls");
    cout << "\n\t<==|Tabela - Pessoas|==>\n";
    cout << setw(15) << left << "|Código|" << setw(10) << left << "|Nome|" << setw(10) << left << "|Endereço|" << endl;
    for (int i = 0; i < contP; i++)
    {
        cout << setw(15) << left << Pessoa[i].codigo << setw(10) << left << Pessoa[i].nome << setw(10) << left << Pessoa[i].endereco << endl;
    }
    system("pause");
}

void imprimirEditora(Editoras *Editora, int contE) {}

void imprimirAutor(Autores *Autor, int contA) {}

void imprimirGenero(Generos *Genero, int contG) {}

void imprimirLivro(Livros *Livro, int contL) {}

// Funções de confirmação

bool confPessoa(Pessoas *Pessoa, int &cod, int &pos)
{
    int i = 0, f = 20;
    int m = (i + f) / 2;

    for (; f >= i && cod != Pessoa[m].codigo; m = (i + f) / 2)
    {
        if (cod > Pessoa[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == Pessoa[m].codigo)
    {
        pos = m;
        return true;
    }

    return false;
}

bool confAutor(Autores *Autor, int &cod, int &pos)
{
    int i = 0, f = 20;
    int m = (i + f) / 2;

    for (; f >= i && cod != Autor[m].codigo; m = (i + f) / 2)
    {
        if (cod > Autor[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == Autor[m].codigo)
    {
        pos = m;
        return true;
    }

    return false;
}

bool confGenero(Generos *Genero, int &cod, int &pos)
{
    int i = 0, f = 20;
    int m = (i + f) / 2;

    for (; f >= i && cod != Genero[m].codigo; m = (i + f) / 2)
    {
        if (cod > Genero[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == Genero[m].codigo)
    {
        pos = m;
        return true;
    }

    return false;
}

bool confEditora(Editoras *Editora, int &cod, int &pos)
{
    int i = 0, f = 20;
    int m = (i + f) / 2;

    for (; f >= i && cod != Editora[m].codigo; m = (i + f) / 2)
    {
        if (cod > Editora[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == Editora[m].codigo)
    {
        pos = m;
        return true;
    }

    return false;
}
