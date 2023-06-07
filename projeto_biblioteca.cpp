/*
    Trabalho Biblioteca - Algoritmos e estruturas de dados

    Nome: Felipe Sferra de Oliveira
    RA: 2211600147
    Curso: 2º BCC - T1
*/

#include <iostream>
#include <string.h>
#include <ctime>
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
    char nome[25];
    int codEditora;
    char editora[25];
    int codAutor;
    char autor[40];
    int codGenero;
    char genero[15];
    int codPessoa;
    char pessoa[40];
    int qtde_emprestado;
    Data data_ultemprestimo;
};

// Funções (protótipos)

void lerData(Data &);
void lerPessoa(Pessoas *, int &);
void lerEditora(Editoras *, int &);
void lerAutor(Autores *, int &);
void lerGenero(Generos *, int &);
void lerLivro(Livros *, int &, Editoras *, Autores *, Generos *, Data *, int, int, int, int);

void imprimirPessoa(Pessoas *, int);
void imprimirEditora(Editoras *, int);
void imprimirAutor(Autores *, int);
void imprimirGenero(Generos *, int);
void imprimirLivro(Livros *, int);

void menuPessoas(Pessoas *, int &, Pessoas *, int &, Pessoas *, int &);
void menuEditoras(Editoras *, int &, Editoras *, int &, Editoras *, int &);
void menuAutores(Autores *, int &, Autores *, int &, Autores *, int &);
void menuGeneros(Generos *, int &, Generos *, int &, Generos *, int &);
void menuLivros(Livros *, int &, Livros *, int &, Livros *, int &, Editoras *, Autores *, Generos *, Pessoas *, Data *, int, int, int, int);

bool confPessoa(Pessoas *, int &, int &, int);
bool confEditora(Editoras *, int &, int &, int);
bool confAutor(Autores *, int &, int &, int);
bool confGenero(Generos *, int &, int &, int);
bool confLivro(Livros *, int &, int &, int);

void atualizarPessoa(Pessoas *, int &, Pessoas *, int &, Pessoas *, int &);
void atualizarEditora(Editoras *, int &, Editoras *, int &, Editoras *, int &);
void atualizarAutor(Autores *, int &, Autores *, int &, Autores *, int &);
void atualizarGenero(Generos *, int &, Generos *, int &, Generos *, int &);
void atualizarLivro(Livros *, int &, Livros *, int &, Livros *, int &, Editoras *, Autores *, Generos *, Data *);

void emprestimoLivros(Livros *, int &, Pessoas *, int);
void devolucaoLivros(Livros *, int &);
void livrosEmprestados(Livros *, int &);
void rankingLivros(Livros *, int &);
void livrosAtrasados(Livros *, int &);

bool DataValida(int, int, int);
Data calcDataEntrega(int, int, int);
int calcDiasAtraso(Data, Data);

// Programa Principal

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();

    SetConsoleOutputCP(CPAGE_UTF8);

    // variaveis
    Pessoas PessoaS[10], PessoaT[10], PessoaA[20];
    int contPS, contPT, contPA;

    Editoras EditoraS[10], EditoraT[10], EditoraA[20];
    int contES, contET, contEA;

    Autores AutorS[10], AutorT[10], AutorA[20];
    int contAS, contAT, contAA;

    Generos GeneroS[10], GeneroT[10], GeneroA[20];
    int contGS, contGT, contGA;

    Livros LivroS[10], LivroT[10], LivroA[20];
    int contLS, contLT, contLA;

    Data Datas[20];

    // menu principal
    char op = 'X';

    while (op != '0')
    {
        system("cls");

        cout << "\n\t<==|Menu - Principal|==>\n\n";

        cout << "[1] - Menu - Pessoas\n";
        cout << "[2] - Menu - Editoras\n";
        cout << "[3] - Menu - Autores\n";
        cout << "[4] - Menu - Generos\n";
        cout << "[5] - Menu - Livros\n";
        cout << "[0] - Fechar o programa\n";

        cout << "Selecione uma das opções: ";
        cin >> op;

        switch (op)
        {
        case '1':
            menuPessoas(PessoaS, contPS, PessoaT, contPT, PessoaA, contPA);
            break;
        case '2':
            menuEditoras(EditoraS, contES, EditoraT, contET, EditoraA, contEA);
            break;
        case '3':
            menuAutores(AutorS, contAS, AutorT, contAT, AutorA, contAA);
            break;
        case '4':
            menuGeneros(GeneroS, contGS, GeneroT, contGT, GeneroA, contGA);
            break;
        case '5':
            menuLivros(LivroS, contLS, LivroT, contLT, LivroA, contLA, EditoraA, AutorA, GeneroA, PessoaA, Datas, contEA, contAA, contGA, contPA);
            break;
        case '0':
            system("cls");
            cout << "\n\tObrigado por usar o programa!\n\n";
            break;
        default:
            cout << "Opção inválida!\n";
            Sleep(1500);
            break;
        }
    }

    SetConsoleOutputCP(CPAGE_DEFAULT);
}

// Menus

void menuPessoas(Pessoas *PessoaS, int &contPS, Pessoas *PessoaT, int &contPT, Pessoas *PessoaA, int &contPA)
{
    char op = 'X';

    while (op != '0')
    {
        system("cls");
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
            lerPessoa(PessoaS, contPS);
            break;
        case '2':
            atualizarPessoa(PessoaT, contPT, PessoaS, contPS, PessoaA, contPA);
            break;
        case '3':
            imprimirPessoa(PessoaA, contPA);
            break;
        case '0':
            break;
        default:
            cout << "Opção inválida!\n";
            Sleep(1500);
            break;
        }
    }
}

void menuEditoras(Editoras *EditoraS, int &contES, Editoras *EditoraT, int &contET, Editoras *EditoraA, int &contEA)
{
    char op = 'X';

    while (op != '0')
    {
        system("cls");
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
            lerEditora(EditoraS, contES);
            break;
        case '2':
            atualizarEditora(EditoraT, contET, EditoraS, contES, EditoraA, contEA);
            break;
        case '3':
            imprimirEditora(EditoraA, contEA);
            break;
        case '0':
            break;
        default:
            cout << "Opção inválida!\n";
            Sleep(1500);
            break;
        }
    }
}

void menuAutores(Autores *AutorS, int &contAS, Autores *AutorT, int &contAT, Autores *AutorA, int &contAA)
{
    char op = 'X';

    while (op != '0')
    {
        system("cls");
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
            lerAutor(AutorS, contAS);
            break;
        case '2':
            atualizarAutor(AutorT, contAT, AutorS, contAS, AutorA, contAA);
            break;
        case '3':
            imprimirAutor(AutorA, contAA);
            break;
        case '0':
            break;
        default:
            cout << "Opção inválida!\n";
            Sleep(1500);
            break;
        }
    }
}

void menuGeneros(Generos *GeneroS, int &contGS, Generos *GeneroT, int &contGT, Generos *GeneroA, int &contGA)
{
    char op = 'X';

    while (op != '0')
    {
        system("cls");
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
            lerGenero(GeneroS, contGS);
            break;
        case '2':
            atualizarGenero(GeneroT, contGT, GeneroS, contGS, GeneroA, contGA);
            break;
        case '3':
            imprimirGenero(GeneroA, contGA);
            break;
        case '0':
            break;
        default:
            cout << "Opção inválida!\n";
            Sleep(1500);
            break;
        }
    }
}

void menuLivros(Livros *LivroS, int &contLS, Livros *LivroT, int &contLT, Livros *LivroA, int &contLA, Editoras *EditoraA, Autores *AutorA, Generos *GeneroA, Pessoas *PessoaA, Data *Date, int contEA, int contAA, int contGA, int contPA)
{
    char op = 'X';

    while (op != '0')
    {
        system("cls");
        cout << "\n\t<==|Menu - Livros|==>\n\n";

        cout << "[1] - Cadastrar Livros\n";
        cout << "[2] - Atualizar Lista\n";
        cout << "[3] - Emprestimo de Livros\n";
        cout << "[4] - Devolução de Livros\n";
        cout << "[5] - Lista de Livros emprestados\n";
        cout << "[6] - Ranking de Livros\n";
        cout << "[7] - Lista de Livros atrasados\n";
        cout << "[0] - Voltar para o menu principal\n";

        cout << "Selecione uma das opções: ";
        cin >> op;

        switch (op)
        {
        case '1':
            lerLivro(LivroS, contLS, EditoraA, AutorA, GeneroA, Date, contEA, contAA, contGA, contPA);
            break;
        case '2':
            atualizarLivro(LivroT, contLT, LivroS, contLS, LivroA, contLA, EditoraA, AutorA, GeneroA, Date);
            break;
        case '3':
            emprestimoLivros(LivroA, contLA, PessoaA, contPA);
            break;
        case '4':
            devolucaoLivros(LivroA, contLA);
            break;
        case '5':
            livrosEmprestados(LivroA, contLA);
            break;
        case '6':
            rankingLivros(LivroA, contLA);
            break;
        case '7':
            livrosAtrasados(LivroA, contLA);
            break;
        case '0':
            break;
        default:
            cout << "Opção inválida!\n";
            Sleep(1500);
            break;
        }
    }
}

// Funções de leitura

void lerData(Data &Date)
{
    cout << "Digite o dia: ";
    cin >> Date.dia;
    cout << "Digite o mês: ";
    cin >> Date.mes;
    cout << "Digite o ano: ";
    cin >> Date.ano;
    if (!DataValida(Date.dia, Date.mes, Date.ano))
    {
        cout << "Data inválida" << endl;
    }
    Date = calcDataEntrega(Date.dia, Date.mes, Date.ano);
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

void lerEditora(Editoras *Editora, int &contE)
{
    system("cls");
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
    system("cls");
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
    system("cls");
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

void lerLivro(Livros *Livro, int &contL, Editoras *EditoraA, Autores *AutorA, Generos *GeneroA, Data *Date, int contEA = 0, int contAA = 0, int contGA = 0, int contPA = 0)
{
    system("cls");
    int i = 0;
    int codEdt, codAut, codGen, posEdt, posAut, posGen;

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
            Date[i].dia = 0;
            Date[i].mes = 0;
            Date[i].ano = 0;
            cout << "Título: ";
            gets(Livro[i].nome);

            cout << "Código da editora: ";

            cin >> codEdt;
            cin.ignore();

            if (confEditora(EditoraA, codEdt, posEdt, contEA))
            {
                Livro[i].codEditora = EditoraA[posEdt].codigo;
                strcpy(Livro[i].editora, EditoraA[posEdt].nome);
                cout << "Editora: " << Livro[i].editora << endl;
            }
            else
            {
                cout << "Editora não encontrada!\n";
                system("pause");
                break;
            }

            cout << "Código do Autor: ";
            cin >> codAut;
            cin.ignore();
            if (confAutor(AutorA, codAut, posAut, contAA))
            {
                Livro[i].codAutor = AutorA[posAut].codigo;
                strcpy(Livro[i].autor, AutorA[posAut].nome);
                cout << "Autor: " << Livro[i].autor << endl;
            }
            else
            {
                cout << "Autor não encontrado!\n";
                system("pause");
                break;
            }

            cout << "Código do Gênero: ";
            cin >> codGen;
            cin.ignore();
            if (confGenero(GeneroA, codGen, posGen, contGA))
            {
                Livro[i].codGenero = GeneroA[posGen].codigo;
                strcpy(Livro[i].genero, GeneroA[posGen].nome);
                cout << "Gênero: " << Livro[i].genero << endl;
            }
            else
            {
                cout << "Gênero não encontrado!\n";
                system("pause");
                break;
            }

            Livro[i].codPessoa = 0;
            strcpy(Livro[i].pessoa, " ");
            Livro[i].qtde_emprestado = 0;
            Livro[i].data_ultemprestimo = Date[i];
        }
    }
    contL = i - 1;
}

// Funções de impressão

void imprimirPessoa(Pessoas *Pessoa, int contP)
{
    system("cls");
    cout << "\n\t<==|Lista - Pessoas|==>\n";

    for (int i = 0; i < contP; i++)
    {
        cout << "\n-> Código: " << Pessoa[i].codigo << endl;
        cout << "\t-> Nome: " << Pessoa[i].nome << endl;
        cout << "\t-> Endereço: " << Pessoa[i].endereco << "\n\n";
    }
    system("pause");
}

void imprimirEditora(Editoras *Editora, int contE)
{
    system("cls");
    cout << "\n\t<==|Lista - Editoras|==>\n";

    for (int i = 0; i < contE; i++)
    {
        cout << "\n-> Código: " << Editora[i].codigo << endl;
        cout << "\t-> Editora: " << Editora[i].nome << "\n\n";
    }
    system("pause");
}

void imprimirAutor(Autores *Autor, int contA)
{
    system("cls");
    cout << "\n\t<==|Lista - Autores|==>\n";

    for (int i = 0; i < contA; i++)
    {
        cout << "\n-> Código: " << Autor[i].codigo << endl;
        cout << "\t-> Autor: " << Autor[i].nome << "\n\n";
    }
    system("pause");
}

void imprimirGenero(Generos *Genero, int contG)
{
    system("cls");
    cout << "\n\t<==|Lista - Gêneros|==>\n";

    for (int i = 0; i < contG; i++)
    {
        cout << "\n-> Código: " << Genero[i].codigo << endl;
        cout << "\t-> Gênero: " << Genero[i].nome << "\n\n";
    }
    system("pause");
}

void imprimirLivro(Livros *Livro, int i)
{
    cout << "\n-> Código: " << Livro[i].codigo << endl;
    cout << "\t-> Título: " << Livro[i].nome << endl;
    cout << "\t-> Código Editora: " << Livro[i].codEditora << endl;
    cout << "\t\t-> Editora: " << Livro[i].editora << endl;
    cout << "\t-> Código Autor: " << Livro[i].codAutor << endl;
    cout << "\t\t-> Autor: " << Livro[i].autor << endl;
    cout << "\t-> Código Gênero: " << Livro[i].codGenero << endl;
    cout << "\t\t-> Gênero: " << Livro[i].genero << endl;
    cout << "\t-> Emprestado para: " << Livro[i].pessoa << endl;
    cout << "\t-> Foi emprestado " << Livro[i].qtde_emprestado << " vezes\n";
    if (Livro[i].data_ultemprestimo.dia > 0 && Livro[i].data_ultemprestimo.mes > 0 && Livro[i].data_ultemprestimo.ano > 0)
    {
        cout << "\t-> Data de último emprestimo: " << Livro[i].data_ultemprestimo.dia << "/"
             << Livro[i].data_ultemprestimo.mes << "/"
             << Livro[i].data_ultemprestimo.ano << "\n\n";
    }
    else
    {
        cout << "\t-> Data de último emprestimo: Este livro ainda não foi emprestado!\n\n";
    }
}

// Funções de confirmação

bool confPessoa(Pessoas *Pessoa, int &cod, int &pos, int cont)
{
    int i = 0, f = cont;
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

bool confAutor(Autores *Autor, int &cod, int &pos, int cont)
{
    int i = 0, f = cont;
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

bool confGenero(Generos *Genero, int &cod, int &pos, int cont)
{
    int i = 0, f = cont;
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

bool confEditora(Editoras *Editora, int &cod, int &pos, int cont)
{
    int i = 0, f = cont;
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

bool confLivro(Livros *Livro, int &cod, int &pos, int cont)
{
    int i = 0, f = cont;
    int m = (i + f) / 2;

    for (; f >= i && cod != Livro[m].codigo; m = (i + f) / 2)
    {
        if (cod > Livro[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == Livro[m].codigo)
    {
        pos = m;
        return true;
    }
    else
    {
        return false;
    }
}

// Funções de inclusão

void atualizarPessoa(Pessoas *T, int &contT, Pessoas *S, int &contS, Pessoas *A, int &contA)
{
    system("cls");

    int i = 0, j = 0, k = 0;

    cout << "\t\t<==|Atualizar lista de Pessoas|==>\n\n";

    cout << "Faça a leitura dos clientes que deseja incluir na lista: \n";
    lerPessoa(T, contT);

    for (; i < contS && j < contT; k++)
    {
        if (S[i].codigo < T[j].codigo)
        {
            A[k].codigo = S[i].codigo;
            strcpy(A[k].nome, S[i].nome);
            strcpy(A[k].endereco, S[i].endereco);
            i++;
        }
        else
        {
            A[k].codigo = T[j].codigo;
            strcpy(A[k].nome, T[j].nome);
            strcpy(A[k].endereco, T[j].endereco);
            j++;
        }
    }
    while (i < contS)
    {
        A[k].codigo = S[i].codigo;
        strcpy(A[k].nome, S[i].nome);
        strcpy(A[k].endereco, S[i].endereco);
        i++;
        k++;
    }
    while (j < contT)
    {
        A[k].codigo = T[j].codigo;
        strcpy(A[k].nome, T[j].nome);
        strcpy(A[k].endereco, T[j].endereco);
        j++;
        k++;
    }
    contA = k;
}

void atualizarEditora(Editoras *T, int &contT, Editoras *S, int &contS, Editoras *A, int &contA)
{
    system("cls");

    int i = 0, j = 0, k = 0;

    cout << "\t\t<==|Atualizar lista de Editoras|==>\n\n";

    cout << "Faça a leitura das editoras que deseja incluir na lista: \n";
    lerEditora(T, contT);

    for (; i < contS && j < contT; k++)
    {
        if (S[i].codigo < T[j].codigo)
        {
            A[k].codigo = S[i].codigo;
            strcpy(A[k].nome, S[i].nome);
            i++;
        }
        else
        {
            A[k].codigo = T[j].codigo;
            strcpy(A[k].nome, T[j].nome);
            j++;
        }
    }
    while (i < contS)
    {
        A[k].codigo = S[i].codigo;
        strcpy(A[k].nome, S[i].nome);
        i++;
        k++;
    }
    while (j < contT)
    {
        A[k].codigo = T[j].codigo;
        strcpy(A[k].nome, T[j].nome);
        j++;
        k++;
    }
    contA = k;
}

void atualizarAutor(Autores *T, int &contT, Autores *S, int &contS, Autores *A, int &contA)
{
    system("cls");

    int i = 0, j = 0, k = 0;

    cout << "\t\t<==|Atualizar lista de Autores|==>\n\n";

    cout << "Faça a leitura das autores que deseja incluir na lista: \n";
    lerAutor(T, contT);

    for (; i < contS && j < contT; k++)
    {
        if (S[i].codigo < T[j].codigo)
        {
            A[k].codigo = S[i].codigo;
            strcpy(A[k].nome, S[i].nome);
            i++;
        }
        else
        {
            A[k].codigo = T[j].codigo;
            strcpy(A[k].nome, T[j].nome);
            j++;
        }
    }
    while (i < contS)
    {
        A[k].codigo = S[i].codigo;
        strcpy(A[k].nome, S[i].nome);
        i++;
        k++;
    }
    while (j < contT)
    {
        A[k].codigo = T[j].codigo;
        strcpy(A[k].nome, T[j].nome);
        j++;
        k++;
    }
    contA = k;
}

void atualizarGenero(Generos *T, int &contT, Generos *S, int &contS, Generos *A, int &contA)
{
    system("cls");

    int i = 0, j = 0, k = 0;

    cout << "\t\t<==|Atualizar lista de Gêneros|==>\n\n";

    cout << "Faça a leitura das gêneros que deseja incluir na lista: \n";
    lerGenero(T, contT);

    for (; i < contS && j < contT; k++)
    {
        if (S[i].codigo < T[j].codigo)
        {
            A[k].codigo = S[i].codigo;
            strcpy(A[k].nome, S[i].nome);
            i++;
        }
        else
        {
            A[k].codigo = T[j].codigo;
            strcpy(A[k].nome, T[j].nome);
            j++;
        }
    }
    while (i < contS)
    {
        A[k].codigo = S[i].codigo;
        strcpy(A[k].nome, S[i].nome);
        i++;
        k++;
    }
    while (j < contT)
    {
        A[k].codigo = T[j].codigo;
        strcpy(A[k].nome, T[j].nome);
        j++;
        k++;
    }
    contA = k;
}

void atualizarLivro(Livros *T, int &contT, Livros *S, int &contS, Livros *A, int &contA, Editoras *Editora, Autores *Autor, Generos *Genero, Data *Date)
{
    system("cls");

    int i = 0, j = 0, k = 0;

    cout << "\t\t<==|Atualizar lista de Livros|==>\n\n";

    cout << "Faça a leitura das livros que deseja incluir na lista: \n";
    lerLivro(T, contT, Editora, Autor, Genero, Date);

    for (; i < contS && j < contT; k++)
    {
        if (S[i].codigo < T[j].codigo)
        {
            A[k].codigo = S[i].codigo;
            strcpy(A[k].nome, S[i].nome);
            A[k].codEditora = S[i].codEditora;
            strcpy(A[k].editora, S[i].editora);
            A[k].codAutor = S[i].codAutor;
            strcpy(A[k].autor, S[i].autor);
            A[k].codGenero = S[i].codGenero;
            strcpy(A[k].genero, S[i].genero);
            A[k].codPessoa = S[i].codPessoa;
            strcpy(A[k].pessoa, S[i].pessoa);
            A[k].qtde_emprestado = S[i].qtde_emprestado;
            A[k].data_ultemprestimo = S[i].data_ultemprestimo;
            i++;
        }
        else
        {
            A[k].codigo = T[j].codigo;
            strcpy(A[k].nome, T[j].nome);
            A[k].codEditora = T[j].codEditora;
            strcpy(A[k].editora, T[j].editora);
            A[k].codAutor = T[j].codAutor;
            strcpy(A[k].autor, T[j].autor);
            A[k].codGenero = T[j].codGenero;
            strcpy(A[k].genero, T[j].genero);
            A[k].codPessoa = T[j].codPessoa;
            strcpy(A[k].pessoa, T[j].pessoa);
            A[k].qtde_emprestado = T[j].qtde_emprestado;
            A[k].data_ultemprestimo = T[j].data_ultemprestimo;
            j++;
        }
    }
    while (i < contS)
    {
        A[k].codigo = S[i].codigo;
        strcpy(A[k].nome, S[i].nome);
        A[k].codEditora = S[i].codEditora;
        strcpy(A[k].editora, S[i].editora);
        A[k].codAutor = S[i].codAutor;
        strcpy(A[k].autor, S[i].autor);
        A[k].codGenero = S[i].codGenero;
        strcpy(A[k].genero, S[i].genero);
        A[k].codPessoa = S[i].codPessoa;
        strcpy(A[k].pessoa, S[i].pessoa);
        A[k].qtde_emprestado = S[i].qtde_emprestado;
        A[k].data_ultemprestimo = S[i].data_ultemprestimo;
        i++;
        k++;
    }
    while (j < contT)
    {
        A[k].codigo = T[j].codigo;
        strcpy(A[k].nome, T[j].nome);
        A[k].codEditora = T[j].codEditora;
        strcpy(A[k].editora, T[j].editora);
        A[k].codAutor = T[j].codAutor;
        strcpy(A[k].autor, T[j].autor);
        A[k].codGenero = T[j].codGenero;
        strcpy(A[k].genero, T[j].genero);
        A[k].codPessoa = T[j].codPessoa;
        strcpy(A[k].pessoa, T[j].pessoa);
        A[k].qtde_emprestado = T[j].qtde_emprestado;
        A[k].data_ultemprestimo = T[j].data_ultemprestimo;
        j++;
        k++;
    }
    contA = k;
}

// Funções de empréstimo de livros e devolução

void emprestimoLivros(Livros *Livro, int &contL, Pessoas *Pessoa, int contPA)
{
    system("cls");
    int codL, codPes, posL, posPes;

    cout << "\n\t<==|Empréstimo de Livros|==>\n\n";

    cout << "Digite o código do livro que deseja: ";
    cin >> codL;
    cin.ignore();
    if (confLivro(Livro, codL, posL, contL))
    {
        imprimirLivro(Livro, posL);

        if (Livro[posL].codPessoa == 0)
        {
            cout << "Digite o código da pessoa que irá receber o livro: ";
            cin >> codPes;
            if (confPessoa(Pessoa, codPes, posPes, contPA))
            {
                cout << "Nome: " << Pessoa[posPes].nome << endl;
                Livro[posL].codPessoa = Pessoa[posPes].codigo;
                strcpy(Livro[posL].pessoa, Pessoa[posPes].nome);
                Livro[posL].qtde_emprestado++;
                cout << "Digite a data que o livro está sendo emprestado: \n";
                lerData(Livro[posL].data_ultemprestimo);
                cout << "A data de entrega prevista é: " << Livro[posL].data_ultemprestimo.dia << "/"
                     << Livro[posL].data_ultemprestimo.mes << "/"
                     << Livro[posL].data_ultemprestimo.ano << "\n\n";
            }
            else
            {
                cout << "Pessoa não encontrada!\n";
            }
        }
        else
        {
            cout << "O livro não está disponível para empréstimo no momento\n";
            cout << "Estará disponível em: " << Livro[posL].data_ultemprestimo.dia << "/"
                 << Livro[posL].data_ultemprestimo.mes << "/"
                 << Livro[posL].data_ultemprestimo.ano << "\n\n";
        }
    }
    else
    {
        cout << "Livro não encontrado!\n\n";
    }
    system("pause");
}

void devolucaoLivros(Livros *Livro, int &contL)
{
    system("cls");
    int codL, posL;
    char op = 'x';
    cout << "\n\t<==|Devolução de Livros|==>\n\n";

    cout << "Digite o código do livro que deseja devolver: ";
    cin >> codL;
    cin.ignore();
    if (confLivro(Livro, codL, posL, contL))
    {
        cout << "Título: " << Livro[posL].nome << endl;
        cout << "Editora: " << Livro[posL].editora << endl;
        cout << "Autor: " << Livro[posL].autor << endl;

        if (Livro[posL].codPessoa != 0)
        {
            while (op != '0')
            {
                cout << "O livro está com: " << Livro[posL].pessoa << endl;
                cout << "Deseja seguir com a devolução? (S/N)";
                cin >> op;
                op = toupper(op);
                switch (op)
                {
                case 'S':
                    Livro[posL].codPessoa = 0;
                    strcpy(Livro[posL].pessoa, " ");
                    cout << "Livro devolvido com sucesso!\n\n";
                    op = '0';
                    break;
                case 'N':
                    op = '0';
                    break;

                default:
                    break;
                }
            }
        }
        else
        {
            cout << "O livro não está emprestado!\n";
        }
    }
    else
    {
        cout << "Livro não encontrado!\n\n";
    }
    system("pause");
}

void livrosEmprestados(Livros *Livro, int &contL)
{
    system("cls");
    int contEmp = 0, contDisp = 0;
    cout << "\n\t<==|Lista de Livros emprestados|==>\n\n";
    for (int i = 0; i < contL; i++)
    {
        if (Livro[i].codPessoa != 0)
        {
            imprimirLivro(Livro, i);
            contEmp++;
        }
        else
        {
            contDisp++;
        }
    }
    cout << "Total emprestados: " << contEmp << endl;
    cout << "Total disponíveis: " << contDisp << "\n\n";
    system("pause");
}

void rankingLivros(Livros *Livro, int &contL)
{
    system("cls");
    Livros maisEmp, menosEmp;
    maisEmp = Livro[0];
    menosEmp = Livro[0];
    cout << "\n\t<==|Ranking de Livros emprestados|==>\n\n";
    for (int i = 1; i < contL; i++)
    {
        if (Livro[i].qtde_emprestado > maisEmp.qtde_emprestado)
        {
            maisEmp = Livro[i];
        }
        if (Livro[i].qtde_emprestado < menosEmp.qtde_emprestado)
        {
            menosEmp = Livro[i];
        }
    }
    cout << "Livro mais emprestado: \n";
    cout << "\t->Código: " << maisEmp.codigo << endl;
    cout << "\t->Título: " << maisEmp.nome << endl;
    cout << "\t->Editora: " << maisEmp.editora << endl;
    cout << "\t->Autor: " << maisEmp.autor << endl;
    cout << "\t->Quantidade de vezes que foi emprestado: " << maisEmp.qtde_emprestado << "\n\n";

    cout << "Livro menos emprestado: \n";
    cout << "\t->Código: " << menosEmp.codigo << endl;
    cout << "\t->Título: " << menosEmp.nome << endl;
    cout << "\t->Editora: " << menosEmp.editora << endl;
    cout << "\t->Autor: " << menosEmp.autor << endl;
    cout << "\t->Quantidade de vezes que foi emprestado: " << menosEmp.qtde_emprestado << "\n\n";

    system("pause");
}

void livrosAtrasados(Livros *Livro, int &contL)
{
    system("cls");
    time_t tAtual = time(nullptr);
    tm *hoje = localtime(&tAtual);

    Data data_emprestimo, data_atual;

    data_atual.dia = hoje->tm_mday;
    data_atual.mes = hoje->tm_mon + 1;
    data_atual.ano = hoje->tm_year + 1900;

    int diasAtraso;

    cout << "\n\t<==|Livros atrasados|==>\n\n";

    cout << "Data atual: " << data_atual.dia << "/" << data_atual.mes << "/" << data_atual.ano << endl;

    for (int i = 0; i < contL; i++)
    {
        data_emprestimo = Livro[i].data_ultemprestimo;
        if ((data_emprestimo.dia > 0 && data_emprestimo.mes > 0 && data_emprestimo.ano > 0) && Livro[i].codPessoa != 0)
        {
            if (!DataValida(data_emprestimo.dia, data_emprestimo.mes, data_emprestimo.ano))
            {
                cout << "Data de emprestimo inválida!" << endl;
            }

            diasAtraso = calcDiasAtraso(data_atual, data_emprestimo);

            if (diasAtraso >= 1)
            {
                cout << "Código: " << Livro[i].codigo << endl;
                cout << "Título: " << Livro[i].nome << endl;
                cout << "Editora: " << Livro[i].editora << endl;
                cout << "Autor: " << Livro[i].autor << endl;
                cout << "Data de entrega prevista: " << Livro[i].data_ultemprestimo.dia << "/"
                     << Livro[i].data_ultemprestimo.mes << "/"
                     << Livro[i].data_ultemprestimo.ano << endl;
                cout << "Dias em atraso: " << diasAtraso << "\n\n";
            }
            else if (diasAtraso == -1)
            {
                cout << "Datas fornecidas são inválidas!\n\n";
                system("pause");
            }
            else if (diasAtraso <= 0)
            {
                cout << "Não tem nenhum livro em atraso no momento!\n\n";
            }
        }
    }
    system("pause");
}

// Funções de calculo de data e validação

Data calcDataEntrega(int dia, int mes, int ano)
{
    tm dataEntrega = {0, 0, 0, dia, mes - 1, ano - 1900};
    time_t tEntrega = mktime(&dataEntrega);

    time_t tDisponivel = tEntrega + (5 * 60 * 60 * 24);

    tm *tDisponivel_tm = localtime(&tDisponivel);

    Data data_entrega;

    data_entrega.dia = tDisponivel_tm->tm_mday;
    data_entrega.mes = tDisponivel_tm->tm_mon + 1;
    data_entrega.ano = tDisponivel_tm->tm_year + 1900;

    return data_entrega;
}

bool DataValida(int dia, int mes, int ano)
{
    if (ano < 1900 || ano > 3000)
    {
        return false;
    }
    if (mes < 1 || mes > 12)
    {
        return false;
    }

    int dias;

    if (mes == 2)
    {
        if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
        {
            dias = 29;
        }
        else
        {
            dias = 28;
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        dias = 30;
    }
    else
    {
        dias = 31;
    }

    if (dia < 1 || dia > dias)
    {
        return false;
    }

    return true;
}

int calcDiasAtraso(Data data_atual, Data data_emprestimo)
{
    if (!DataValida(data_atual.dia, data_atual.mes, data_atual.ano) || !DataValida(data_emprestimo.dia, data_emprestimo.mes, data_emprestimo.ano))
    {
        return -1;
    }

    tm dataAtual = {0, 0, 0, data_atual.dia, data_atual.mes - 1, data_atual.ano - 1900};
    tm dataVencimento = {0, 0, 0, data_emprestimo.dia, data_emprestimo.mes - 1, data_emprestimo.ano - 1900};

    time_t tAtual = mktime(&dataAtual);
    time_t tVencimento = mktime(&dataVencimento);

    double diferenca = difftime(tAtual, tVencimento);

    int diasAtraso = static_cast<int>(diferenca / (60 * 60 * 24)); // (60 seg * 60 min * 24h = seg em um dia)
    return diasAtraso;
}
